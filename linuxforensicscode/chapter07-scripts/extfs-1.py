#!/usr/bin/python
#
# extfs.py
#
# This is a simple Python script that will
# get metadata from an ext2/3/4 filesystem inside
# of an image file.
#
# Developed for PentesterAcademy 
# by Dr. Phil Polstra (@ppolstra)

import sys
import os.path
import subprocess
import struct
import time

# these are simple functions to make conversions easier
def getU32(data, offset=0):
   return struct.unpack('<L', data[offset:offset+4])[0]

def getU16(data, offset=0):
   return struct.unpack('<H', data[offset:offset+2])[0]

def getU8(data, offset=0):
   return struct.unpack('B', data[offset:offset+1])[0]

def getU64(data, offset=0):
   return struct.unpack('<Q', data[offset:offset+8])[0]

# this function doesn't unpack the string because 
# it isn't really a number but a UUID
def getU128(data, offset=0):
   return data[offset:offset+16]

def printUuid(data):
  retStr = \
    format(struct.unpack('<Q', data[8:16])[0], 'X').zfill(16) + \
    format(struct.unpack('<Q', data[0:8])[0], 'X').zfill(16)
  return retStr

def getCompatibleFeaturesList(u32):
  retList = []
  if u32 & 0x1:
    retList.append('Directory Preallocate')
  if u32 & 0x2:
    retList.append('Imagic Inodes')
  if u32 & 0x4:
    retList.append('Has Journal')
  if u32 & 0x8:
    retList.append('Extended Attributes')
  if u32 & 0x10:
    retList.append('Resize Inode')
  if u32 & 0x20:
    retList.append('Directory Index')
  if u32 & 0x40:
    retList.append('Lazy Block Groups')
  if u32 & 0x80:
    retList.append('Exclude Inode')
  if u32 & 0x100:
    retList.append('Exclude Bitmap')
  if u32 & 0x200:
    retList.append('Sparse Super 2')
  return retList

def getIncompatibleFeaturesList(u32):
  retList = []
  if u32 & 0x1:
    retList.append('Compression')
  if u32 & 0x2:
    retList.append('Filetype')
  if u32 & 0x4:
    retList.append('Recover')
  if u32 & 0x8:
    retList.append('Journal Device')
  if u32 & 0x10:
    retList.append('Meta Block Groups')
  if u32 & 0x40:
    retList.append('Extents')
  if u32 & 0x80:
    retList.append('64-bit')
  if u32 & 0x100:
    retList.append('Multiple Mount Protection')
  if u32 & 0x200:
    retList.append('Flexible Block Groups')
  if u32 & 0x400:
    retList.append('Extended Attributes in Inodes')
  if u32 & 0x1000:
    retList.append('Directory Data')
  if u32 & 0x2000:
    retList.append('Block Group Metadata Checksum')
  if u32 & 0x4000:
    retList.append('Large Directory')
  if u32 & 0x8000:
    retList.append('Inline Data')
  if u32 & 0x10000:
    retList.append('Encrypted Inodes')
  return retList

def getReadonlyCompatibleFeaturesList(u32):
  retList = []
  if u32 & 0x1:
    retList.append('Sparse Super')
  if u32 & 0x2:
    retList.append('Large File')
  if u32 & 0x4:
    retList.append('Btree Directory')
  if u32 & 0x8:
    retList.append('Huge File')
  if u32 & 0x10:
    retList.append('Group Descriptor Table Checksum')
  if u32 & 0x20:
    retList.append('Directory Nlink')
  if u32 & 0x40:
    retList.append('Extra Isize')
  if u32 & 0x80:
    retList.append('Has Snapshot')
  if u32 & 0x100:
    retList.append('Quota')
  if u32 & 0x200:
    retList.append('Big Alloc')
  if u32 & 0x400:
    retList.append('Metadata Checksum')
  if u32 & 0x800:
    retList.append('Replica')
  if u32 & 0x1000:
    retList.append('Read-only')
  return retList

# This class will parse the data in a superblock
class Superblock():
  def __init__(self, data):
    self.totalInodes = getU32(data)
    self.totalBlocks = getU32(data, 4)
    self.restrictedBlocks = getU32(data, 8)
    self.freeBlocks = getU32(data, 0xc)
    self.freeInodes = getU32(data, 0x10)
    # normally 0 unless block size is <4k
    self.firstDataBlock = getU32(data, 0x14) 
    # block size is 1024 * 2^(whatever is in this field)
    self.blockSize = 2^(10 + getU32(data, 0x18)) 
    # only used if bigalloc feature enabled
    self.clusterSize = 2^(getU32(data, 0x1c)) 
    self.blocksPerGroup = getU32(data, 0x20)
    # only used if bigalloc feature enabled
    self.clustersPerGroup = getU32(data, 0x24) 
    self.inodesPerGroup = getU32(data, 0x28)
    self.mountTime = time.gmtime(getU32(data, 0x2c))
    self.writeTime = time.gmtime(getU32(data, 0x30))
    # mounts since last fsck
    self.mountCount = getU16(data, 0x34) 
    # mounts between fsck
    self.maxMountCount = getU16(data, 0x36) 
    self.magic = getU16(data, 0x38) # should be 0xef53
    #0001/0002/0004 = cleanly unmounted/errors/orphans
    self.state = getU16(data, 0x3a)
    # when errors 1/2/3 continue/read-only/panic 
    self.errors = getU16(data, 0x3c) 
    self.minorRevision = getU16(data, 0x3e)
    # last fsck time
    self.lastCheck = time.gmtime(getU32(data, 0x40)) 
    # seconds between checks
    self.checkInterval = getU32(data, 0x44) 
    # 0/1/2/3/4 Linux/Hurd/Masix/FreeBSD/Lites
    self.creatorOs = getU32(data, 0x48) 
    # 0/1 original/v2 with dynamic inode sizes
    self.revisionLevel = getU32(data, 0x4c) 
    # UID for reserved blocks
    self.defaultResUid = getU16(data, 0x50) 
    # GID for reserved blocks
    self.defaultRegGid = getU16(data, 0x52) 
    # for Ext4 dynamic revisionLevel superblocks only!
    # first non-reserved inode
    self.firstInode = getU32(data, 0x54) 
    # inode size in bytes
    self.inodeSize = getU16(data, 0x58) 
    # block group this superblock is in
    self.blockGroupNumber = getU16(data, 0x5a) 
    # compatible features
    self.compatibleFeatures = getU32(data, 0x5c) 
    self.compatibleFeaturesList = \
      getCompatibleFeaturesList(self.compatibleFeatures)
    #incompatible features
    self.incompatibleFeatures = getU32(data, 0x60) 
    self.incompatibleFeaturesList = \
      getIncompatibleFeaturesList(self.incompatibleFeatures)
    # read-only compatible features
    self.readOnlyCompatibleFeatures = getU32(data, 0x64) 
    self.readOnlyCompatibleFeaturesList = \
      getReadonlyCompatibleFeaturesList(\
      self.readOnlyCompatibleFeatures)
    #UUID for volume left as a packed string
    self.uuid = getU128(data, 0x68)     
    # volume name - likely empty
    self.volumeName = data[0x78:0x88].split("\x00")[0] 
    # directory where last mounted
    self.lastMounted = data[0x88:0xc8].split("\x00")[0] 
    # used with compression
    self.algorithmUsageBitmap = getU32(data, 0xc8) 
    # not used in ext4
    self.preallocBlocks = getU8(data, 0xcc) 
    #only used with DIR_PREALLOC feature
    self.preallocDirBlock = getU8(data, 0xcd)
    # blocks reserved for future expansion 
    self.reservedGdtBlocks = getU16(data, 0xce)
    # UUID of journal superblock 
    self.journalUuid = getU128(data, 0xd0) 
    # inode number of journal file
    self.journalInode = getU32(data, 0xe0) 
    # device number for journal if external journal used
    self.journalDev = getU32(data, 0xe4) 
    # start of list of orphaned inodes to delete
    self.lastOrphan = getU32(data, 0xe8) 
    self.hashSeed = []
    self.hashSeed.append(getU32(data, 0xec)) # htree hash seed
    self.hashSeed.append(getU32(data, 0xf0))
    self.hashSeed.append(getU32(data, 0xf4))
    self.hashSeed.append(getU32(data, 0xf8))
    # 0/1/2/3/4/5 legacy/half MD4/tea/u-legacy/u-half MD4/u-Tea
    self.hashVersion = getU8(data, 0xfc) 
    self.journalBackupType = getU8(data, 0xfd)
    # group descriptor size if 64-bit feature enabled 
    self.descriptorSize = getU16(data, 0xfe) 
    self.defaultMountOptions = getU32(data, 0x100) 
    # only used with meta bg feature
    self.firstMetaBlockGroup = getU32(data, 0x104) 
    # when was the filesystem created
    self.mkfsTime = time.gmtime(getU32(data, 0x108)) 
    self.journalBlocks = []
    # backup copy of journal inodes and size in last two elements
    for i in range(0, 17): 
      self.journalBlocks.append(getU32(data, 0x10c + i*4))
    # for 64-bit mode only
    self.blockCountHi = getU32(data, 0x150)
    self.reservedBlockCountHi = getU32(data, 0x154)
    self.freeBlocksHi = getU32(data, 0x158)
    # all inodes such have at least this much space
    self.minInodeExtraSize = getU16(data, 0x15c) 
    # new inodes should reserve this many bytes
    self.wantInodeExtraSize = getU16(data, 0x15e)
    #1/2/4 signed hash/unsigned hash/test code 
    self.miscFlags = getU32(data, 0x160) 
    # logical blocks read from disk in RAID before moving to next disk
    self.raidStride = getU16(data, 0x164) 
    # seconds to wait between multi-mount checks
    self.mmpInterval = getU16(data, 0x166)
    # block number for MMP data 
    self.mmpBlock = getU64(data, 0x168) 
    # how many blocks read/write till back on this disk
    self.raidStripeWidth = getU32(data, 0x170)
    # groups per flex group 
    self.groupsPerFlex = 2^(getU8(data, 0x174))
    # should be 1 for crc32 
    self.metadataChecksumType = getU8(data, 0x175) 
    self.reservedPad = getU16(data, 0x176) # should be zeroes
    # kilobytes written for all time
    self.kilobytesWritten = getU64(data, 0x178)
    # inode of active snapshot 
    self.snapshotInode = getU32(data, 0x180)
    # id of the active snapshot 
    self.snapshotId = getU32(data, 0x184) 
    # blocks reserved for snapshot
    self.snapshotReservedBlocks = getU64(data, 0x188)
    # inode number of head of snapshot list 
    self.snapshotList = getU32(data, 0x190) 
    self.errorCount = getU32(data, 0x194)
    # time first error detected
    self.firstErrorTime = time.gmtime(getU32(data, 0x198)) 
    self.firstErrorInode = getU32(data, 0x19c) # guilty inode
    self.firstErrorBlock = getU64(data, 0x1a0) # guilty block
    # guilty function
    self.firstErrorFunction = data[0x1a8:0x1c8].split("\x00")[0] 
    # line number where error occurred
    self.firstErrorLine = getU32(data, 0x1c8) 
    # time last error detected
    self.lastErrorTime = time.gmtime(getU32(data, 0x1cc)) 
    self.lastErrorInode = getU32(data, 0x1d0) # guilty inode
    # line number where error occurred
    self.lastErrorLine = getU32(data, 0x1d4) 
    self.lastErrorBlock = getU64(data, 0x1d8) # guilty block
    # guilty function
    self.lastErrorFunction = data[0x1e0:0x200].split("\x00")[0] 
    # mount options in null-terminated string
    self.mountOptions = data[0x200:0x240].split("\x00")[0] 
    # inode of user quota file
    self.userQuotaInode = getU32(data, 0x240)
    # inode of group quota file 
    self.groupQuotaInode = getU32(data, 0x244) 
    self.overheadBlocks = getU32(data, 0x248) # should be zero
    self.backupBlockGroups = [getU32(data, 0x24c), \
      getU32(data, 0x250)] # super sparse 2 only
    self.encryptionAlgorithms = []
    for i in range(0, 4):
      self.encryptionAlgorithms.append(getU32(data, 0x254 + i*4))
    self.checksum = getU32(data, 0x3fc)

  def printState(self):
    #0001/0002/0004 = cleanly unmounted/errors/orphans
    retVal = "Unknown"
    if self.state == 1:
      retVal = "Cleanly unmounted"
    elif self.state == 2:
      retVal = "Errors detected"
    elif self.state == 4:
      retVal = "Orphans being recovered"
    return retVal

  def printErrorBehavior(self):
    # when errors 1/2/3 continue/read-only/panic
    retVal = "Unknown"
    if self.errors == 1:
      retVal = "Continue"
    elif self.errors == 2:
      retVal = "Remount read-only"
    elif self.errors == 3:
      retVal = "Kernel panic"
    return retVal

  def printCreator(self):
    # 0/1/2/3/4 Linux/Hurd/Masix/FreeBSD/Lites
    retVal = "Unknown"
    if self.creatorOs == 0:
      retVal = "Linux"
    elif self.creatorOs == 1:
      retVal = "Hurd"
    elif self.creatorOs == 2:
      retVal = "Masix"
    elif self.creatorOs == 3:
      retVal = "FreeBSD"
    elif self.creatorOs == 4:
      retVal = "Lites"
    return retVal
 
  def printHashAlgorithm(self):
    # 0/1/2/3/4/5 legacy/half MD4/tea/u-legacy/u-half MD4/u-Tea 
    retVal = "Unknown"   
    if self.hashVersion == 0:  
      retVal = "Legacy"
    elif self.hashVersion == 1:
      retVal = "Half MD4"
    elif self.hashVersion == 2:
      retVal = "Tea"
    elif self.hashVersion == 3:
      retVal = "Unsigned Legacy"
    elif self.hashVersion == 4:
      retVal = "Unsigned Half MD4"
    elif self.hashVersion == 5:
      retVal = "Unsigned Tea"
    return retVal 

  def printEncryptionAlgorithms(self):
    encList = []
    for v in self.encryptionAlgorithms:
      if v == 1:
        encList.append('256-bit AES in XTS mode')
      elif v == 2:
        encList.append('256-bit AES in GCM mode')
      elif v == 3:
        encList.append('256-bit AES in CBC mode')
      elif v == 0:
        pass
      else:
        encList.append('Unknown')
    return encList

  def prettyPrint(self):
    for k, v in self.__dict__.iteritems() :
      if k == 'mountTime' or k == 'writeTime' or \
         k == 'lastCheck' or k == 'mkfsTime' or \
         k == 'firstErrorTime' or k == 'lastErrorTime' :
        print k+":", time.asctime(v)
      elif k == 'state':
        print k+":", self.printState()
      elif k == 'errors':
        print k+":", self.printErrorBehavior()
      elif k == 'uuid' or k == 'journalUuid':
        print k+":", printUuid(v)
      elif k == 'creatorOs':
        print k+":", self.printCreator()
      elif k == 'hashVersion':
        print k+":", self.printHashAlgorithm()
      elif k == 'encryptionAlgorithms':
        print k+":", self.printEncryptionAlgorithms()
      else:
        print k+":", v

def usage():
   print("usage " + sys.argv[0] + \
     " <image file> <offset in sectors>\n" + \
     "Reads superblock from an image file")
   exit(1)

def main():
  if len(sys.argv) < 3: 
     usage()

  # read first sector
  if not os.path.isfile(sys.argv[1]):
     print("File " + sys.argv[1] + \
       " cannot be openned for reading")
     exit(1)
  with open(sys.argv[1], 'rb') as f:
    f.seek(1024 + int(sys.argv[2]) * 512)
    sbRaw = str(f.read(1024))
  sb = Superblock(sbRaw)  
  sb.prettyPrint()


if __name__ == "__main__":
   main()

