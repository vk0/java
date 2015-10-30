#!/usr/bin/python
#
# extfs.py
#
# This is a simple Python script that will
# get metadata from an ext2/3/4 filesystem inside
# of an image file.
#
# Developed for PentesterAcademy by Dr. Phil Polstra

import sys
import os.path
import subprocess
import struct
import time
from math import log

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
  retStr = format(struct.unpack('<Q', data[8:16])[0], \
    'X').zfill(16) + \
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

"""
This class will parse the data in a superblock
from an extended (ext2/ext3/ext4) Linux filesystem.
It is up to date as of July 2015.
Usage: sb.Superblock(data) where
data is a packed string at least 1024 bytes
long that contains a superblock in the first 1024 bytes.
  sb.prettyPrint() prints out all fields in the superblock.
"""
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
    self.blockSize = pow(2, 10 + getU32(data, 0x18)) 
    # only used if bigalloc feature enabled
    self.clusterSize = pow(2, getU32(data, 0x1c)) 
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
    # should be 0xef53
    self.magic = getU16(data, 0x38) 
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
    getReadonlyCompatibleFeaturesList(self.readOnlyCompatibleFeatures)
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
    # htree hash seed
    self.hashSeed.append(getU32(data, 0xec)) 
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
    self.groupsPerFlex = pow(2, getU8(data, 0x174)) 
    # should be 1 for crc32
    self.metadataChecksumType = getU8(data, 0x175) 
    # should be zeroes
    self.reservedPad = getU16(data, 0x176) 
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
    # guilty inode
    self.firstErrorInode = getU32(data, 0x19c) 
    # guilty block
    self.firstErrorBlock = getU64(data, 0x1a0) 
    # guilty function
    self.firstErrorFunction = \
      data[0x1a8:0x1c8].split("\x00")[0] 
    # line number where error occurred
    self.firstErrorLine = getU32(data, 0x1c8) 
    # time last error detected
    self.lastErrorTime = time.gmtime(getU32(data, 0x1cc)) 
    # guilty inode
    self.lastErrorInode = getU32(data, 0x1d0) 
    # line number where error occurred
    self.lastErrorLine = getU32(data, 0x1d4) 
    # guilty block
    self.lastErrorBlock = getU64(data, 0x1d8)
    # guilty function 
    self.lastErrorFunction = \
      data[0x1e0:0x200].split("\x00")[0] 
    # mount options in null-terminated string
    self.mountOptions = \
      data[0x200:0x240].split("\x00")[0] 
    # inode of user quota file
    self.userQuotaInode = getU32(data, 0x240) 
    # inode of group quota file
    self.groupQuotaInode = getU32(data, 0x244) 
    # should be zero
    self.overheadBlocks = getU32(data, 0x248) 
    # super sparse 2 only
    self.backupBlockGroups = \
      [getU32(data, 0x24c), getU32(data, 0x250)] 
    self.encryptionAlgorithms = []
    for i in range(0, 4):
      self.encryptionAlgorithms.append(\
        getU32(data, 0x254 + i*4))
    self.checksum = getU32(data, 0x3fc)

  def blockGroups(self):
    bg = self.totalBlocks / self.blocksPerGroup
    if self.totalBlocks % self.blocksPerGroup != 0:
      bg += 1
    return bg

  def groupDescriptorSize(self):
    if '64-bit' in self.incompatibleFeaturesList:
      return 64
    else:
      return 32

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
    for k, v in sorted(self.__dict__.iteritems()) :
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

  def groupStartBlock(self, bgNo):
    return self.blocksPerGroup * bgNo

  def groupEndBlock(self, bgNo):
    return self.groupStartBlock(bgNo + 1) - 1  

  def groupStartInode(self, bgNo):
    return self.inodesPerGroup * bgNo + 1
 
  def groupEndInode(self, bgNo):
    return self.inodesPerGroup * (bgNo + 1)      

  def groupFromBlock(self, blockNo):
    return blockNo / self.blocksPerGroup

  def groupIndexFromBlock(self, blockNo):
    return blockNo % self.blocksPerGroup

  def groupFromInode(self, inodeNo):
    return (inodeNo - 1) / self.inodesPerGroup
                  
  def groupIndexFromInode(self, inodeNo):
    return (inodeNo - 1) % self.inodesPerGroup

  def groupHasSuperblock(self, bgNo):
    # block group zero always has a superblock
    if bgNo == 0:
      return True
    retVal = False
    if 'Meta Block Groups' in self.incompatibleFeaturesList and \
      bgNo >= self.firstMetaBlockGroup:
      # meta block groups have a sb and gdt in 1st and 
      # 2nd and last of each meta group
      # meta block group size is blocksize/32
      # only part of filesystem might use this feature
      mbgSize = self.blockSize / 32
      retVal = (bgNo % mbgSize == 0) or \
        ((bgNo + 1) % mbgSize == 0) or \
        ((bgNo - 1) % mbgSize == 0)
    elif 'Sparse Super 2' in self.compatibleFeaturesList: 
      # two backup superblocks in self.backupBlockGroups
      if bgNo == self.backupBlockGroups[0] or \
        bgNo == self.backupBlockGroups[1]:
        retVal = True
    elif 'Sparse Super' in self.readOnlyCompatibleFeaturesList:
      # backups in 1, powers of 3, 5, and 7
      retVal = (bgNo == 1) or \
        (bgNo == pow(3, round(log(bgNo) / log(3)))) \
        or (bgNo == pow(5, round(log(bgNo) / log(5)))) \
        or (bgNo == pow(7, round(log(bgNo) / log(7)))) 
      if retVal:
        return retVal
    else:
      # if we got this far we must have default 
      # with every bg having sb and gdt
      retVal = True
    return retVal

"""
This class stores the raw group descriptors from
a Linux extended (ext2/ext3/ext4) filesystem.  It
is little more than a glorified structure.  Both
32-bit and 64-bit (wide) filesystems are supported.
It is up to date as of July 2015.
Usage: gd = GroupDescriptor(data, wide) where
data is a 32 byte group descriptor if wide is false
or 64 byte group descriptor if wide is true.
  gd.prettyPrint() prints all the fields in an 
organized manner.
"""
class GroupDescriptor():
  def __init__(self, data, wide=False):
    self.wide = wide
    #/* Blocks bitmap block */
    self.blockBitmapLo=getU32(data)	  
    #/* Inodes bitmap block */
    self.inodeBitmapLo=getU32(data, 4)	
    #/* Inodes table block */
    self.inodeTableLo=getU32(data, 8)	
    #/* Free blocks count */
    self.freeBlocksCountLo=getU16(data, 0xc)
    #/* Free inodes count */
    self.freeInodesCountLo=getU16(data, 0xe)
    #/* Directories count */
    self.usedDirsCountLo=getU16(data, 0x10)
    #/* EXT4_BG_flags (INODE_UNINIT, etc) */	
    self.flags=getU16(data, 0x12)		
    self.flagList = self.printFlagList()
    #/* Exclude bitmap for snapshots */
    self.excludeBitmapLo=getU32(data, 0x14)
    #/* crc32c(s_uuid+grp_num+bbitmap) LE */   
    self.blockBitmapCsumLo=getU16(data, 0x18) 
    #/* crc32c(s_uuid+grp_num+ibitmap) LE */
    self.inodeBitmapCsumLo=getU16(data, 0x1a) 
    #/* Unused inodes count */
    self.itableUnusedLo=getU16(data, 0x1c)	
    #/* crc16(sb_uuid+group+desc) */
    self.checksum=getU16(data, 0x1e)		
    if wide==True:      	
      #/* Blocks bitmap block MSB */
      self.blockBitmapHi=getU32(data, 0x20)	
      #/* Inodes bitmap block MSB */
      self.inodeBitmapHi=getU32(data, 0x24)	
      #/* Inodes table block MSB */
      self.inodeTableHi=getU32(data, 0x28)	
      #/* Free blocks count MSB */
      self.freeBlocksCountHi=getU16(data, 0x2c) 
      #/* Free inodes count MSB */
      self.freeInodesCountHi=getU16(data, 0x2e) 
      #/* Directories count MSB */
      self.usedDirsCountHi=getU16(data, 0x30)	
      #/* Unused inodes count MSB */
      self.itableUnusedHi=getU16(data, 0x32)    
      #/* Exclude bitmap block MSB */
      self.excludeBitmapHi=getU32(data, 0x34)  
      #/* crc32c(s_uuid+grp_num+bbitmap) BE */ 
      self.blockBitmapCsumHi=getU16(data, 0x38)
      #/* crc32c(s_uuid+grp_num+ibitmap) BE */
      self.inodeBitmapCsumHi=getU16(data, 0x3a)
      self.reserved=getU32(data, 0x3c)

  def printFlagList(self):
    flagList = []
    #inode table and bitmap are not initialized (EXT4_BG_INODE_UNINIT).
    if self.flags & 0x1: 
      flagList.append('Inode Uninitialized')
    #block bitmap is not initialized (EXT4_BG_BLOCK_UNINIT).
    if self.flags & 0x2: 
      flagList.append('Block Uninitialized')
    #inode table is zeroed (EXT4_BG_INODE_ZEROED).
    if self.flags & 0x4: 
      flagList.append('Inode Zeroed')
    return flagList

  def prettyPrint(self):
    for k, v in sorted(self.__dict__.iteritems()) :
      print k+":", v
"""
This class combines informaton from the block group descriptor
and the superblock to more fully describe the block group. It
is up to date as of July 2015.
Usage egd = ExtendedGroupDescriptor(bgd, sb, bgNo) where 
bgd is a GroupDescriptor object, sb is a Superblock object,
and bgNo is a block group number.
  egd.prettyPrint() prints out various statistics for the 
block group and also its layout.
"""
class ExtendedGroupDescriptor():
  def __init__(self, bgd, sb, bgNo):
    self.blockGroup = bgNo
    self.startBlock = sb.groupStartBlock(bgNo)
    self.endBlock = sb.groupEndBlock(bgNo)
    self.startInode = sb.groupStartInode(bgNo)
    self.endInode = sb.groupEndInode(bgNo)
    self.flags = bgd.printFlagList()
    self.freeInodes = bgd.freeInodesCountLo
    if bgd.wide:
      self.freeInodes += bgd.freeInodesCountHi * pow(2, 16)
    self.freeBlocks = bgd.freeBlocksCountLo
    if bgd.wide:
      self.freeBlocks += bgd.freeBlocksCountHi * pow(2, 16)
    self.directories = bgd.usedDirsCountLo
    if bgd.wide:
      self.directories += bgd.usedDirsCountHi * pow(2, 16)
    self.checksum = bgd.checksum
    self.blockBitmapChecksum = bgd.blockBitmapCsumLo
    if bgd.wide:
      self.blockBitmapChecksum += bgd.blockBitmapCsumHi * pow(2, 16)
    self.inodeBitmapChecksum = bgd.inodeBitmapCsumLo
    if bgd.wide:
      self.inodeBitmapChecksum += bgd.inodeBitmapCsumHi * pow(2, 16)
    # now figure out the layout and store it in a list (with lists inside)
    self.layout = []
    self.nonDataBlocks = 0
    # for flexible block groups must make an adjustment
    fbgAdj = 1
    if 'Flexible Block Groups' in sb.incompatibleFeaturesList:
      # only first group in flex block affected
      if bgNo % sb.groupsPerFlex == 0: 
        fbgAdj = sb.groupsPerFlex   
    if sb.groupHasSuperblock(bgNo):
      self.layout.append(['Superblock', self.startBlock, self.startBlock])
      gdSize = sb.groupDescriptorSize() * sb.blockGroups() / sb.blockSize
      self.layout.append(['Group Descriptor Table', \
        self.startBlock + 1, self.startBlock + gdSize])
      self.nonDataBlocks += gdSize + 1
      if sb.reservedGdtBlocks > 0:
        self.layout.append(['Reserved GDT Blocks', \
          self.startBlock + gdSize + 1, \
          self.startBlock + gdSize + sb.reservedGdtBlocks])
        self.nonDataBlocks += sb.reservedGdtBlocks
    bbm = bgd.blockBitmapLo
    if bgd.wide:
      bbm += bgd.blockBitmapHi * pow(2, 32)
    self.layout.append(['Data Block Bitmap', bbm, bbm])
    # is block bitmap in this group (not flex block group, etc) 
    if sb.groupFromBlock(bbm) == bgNo:
      self.nonDataBlocks += fbgAdj
    ibm = bgd.inodeBitmapLo
    if bgd.wide:
      ibm += bgd.inodeBitmapHi * pow(2, 32)
    self.layout.append(['Inode Bitmap', ibm, ibm])
    # is inode bitmap in this group?
    if sb.groupFromBlock(ibm) == bgNo:
      self.nonDataBlocks += fbgAdj 
    it = bgd.inodeTableLo
    if bgd.wide:
      it += bgd.inodeTableHi * pow(2, 32)
    self.inodeTable = it
    itBlocks = (sb.inodesPerGroup * sb.inodeSize) / sb.blockSize
    self.layout.append(['Inode Table', it, it + itBlocks - 1])
    # is inode table in this group?
    if sb.groupFromBlock(it) == bgNo:
      self.nonDataBlocks += itBlocks * fbgAdj
    self.layout.append(['Data Blocks', self.startBlock \
      + self.nonDataBlocks, self.endBlock])

  def prettyPrint(self):
    print ""
    print 'Block Group: ' + str(self.blockGroup)
    print 'Flags: %r ' % self.flags
    print 'Blocks: %s - %s ' % (self.startBlock, self.endBlock)
    print 'Inodes: %s - %s ' % (self.startInode, self.endInode)
    print 'Layout:'
    for item in self.layout:
      print '   %s %s - %s' % (item[0], item[1], item[2])
    print 'Free Inodes: %u ' % self.freeInodes
    print 'Free Blocks: %u ' % self.freeBlocks
    print 'Directories: %u ' % self.directories
    print 'Checksum: 0x%x ' % self.checksum
    print 'Block Bitmap Checksum: 0x%x ' % self.blockBitmapChecksum
    print 'Inode Bitmap Checksum: 0x%x ' % self.inodeBitmapChecksum

"""
This class reads the superblock and block group descriptors
from an image file containing a Linux extended (ext2/ext3/ext4)
filesystem and then stores the filesystem metadata in an organized
manner.  It is up to date as of July 2015.
Usage: emd = ExtMetadata(filename, offset) where filename is a
raw image file and offset is the offset in 512 byte sectors from
the start of the file to the first sector of the extended filesystem.
  emd.prettyPrint() will print out the superblock information and
then iterate over each block group printing statistics and layout
information.
"""
class ExtMetadata():
  def __init__(self, filename, offset):
    # read first sector
    if not os.path.isfile(sys.argv[1]):
       print("File " + str(filename) + \
         " cannot be openned for reading")
       exit(1)
    with open(str(filename), 'rb') as f:
      f.seek(1024 + int(offset) * 512)
      sbRaw = str(f.read(1024))
    self.superblock = Superblock(sbRaw)  

    # read block group descriptors
    self.blockGroups = self.superblock.blockGroups()
    if self.superblock.descriptorSize != 0:
      self.wideBlockGroups = True
      self.blockGroupDescriptorSize = 64
    else:
      self.wideBlockGroups = False
      self.blockGroupDescriptorSize = 32
    # read in group descriptors starting in block 1
    with open(str(filename), 'rb') as f:
      f.seek(int(offset) * 512 + self.superblock.blockSize)
      bgdRaw = str(f.read(self.blockGroups * \
        self.blockGroupDescriptorSize))
  
    self.bgdList = []
    for i in range(0, self.blockGroups):
      bgd = GroupDescriptor(bgdRaw[i * self.blockGroupDescriptorSize:]\
        , self.wideBlockGroups)
      ebgd = ExtendedGroupDescriptor(bgd, self.superblock, i) 
      self.bgdList.append(ebgd)

  def prettyPrint(self):
    self.superblock.prettyPrint()
    for bgd in self.bgdList:
      bgd.prettyPrint()

"""
This helper function parses the mode bitvector
stored in an inode.  It accepts a 16-bit mode
bitvector and returns a list of strings.
"""      
def getInodeModes(mode):
  retVal = []

  if mode & 0x1:
    retVal.append("Others Exec")
  if mode & 0x2:
    retVal.append("Others Write")
  if mode & 0x4:
    retVal.append("Others Read")
  if mode & 0x8:
    retVal.append("Group Exec")
  if mode & 0x10:
    retVal.append("Group Write")
  if mode & 0x20:
    retVal.append("Group Read")
  if mode & 0x40:
    retVal.append("Owner Exec")
  if mode & 0x80:
    retVal.append("Owner Write")
  if mode & 0x100:
    retVal.append("Owner Read")
  if mode & 0x200:
    retVal.append("Sticky Bit")
  if mode & 0x400:
    retVal.append("Set GID")
  if mode & 0x800:
    retVal.append("Set UID")

  return retVal

"""
This helper function parses the mode bitvector
stored in an inode in order to get file type.  
It accepts a 16-bit mode bitvector and 
returns a string.
"""  
def getInodeFileType(mode):
  fType = (mode & 0xf000) >> 12   
  if fType == 0x1:
    return "FIFO"
  elif fType == 0x2:
    return "Char Device"
  elif fType == 0x4:
    return "Directory"
  elif fType == 0x6:
    return "Block Device"
  elif fType == 0x8:
    return "Regular File"
  elif fType == 0xA:
    return "Symbolic Link"
  elif fType == 0xc:
    return "Socket"
  else:
    return "Unknown Filetype"

"""
This helper function parses the flags bitvector
stored in an inode.  It accepts a 32-bit flags
bitvector and returns a list of strings.
"""  
def getInodeFlags(flags):
  retVal = []

  if flags & 0x1:
    retVal.append("Secure Deletion")
  if flags & 0x2:
    retVal.append("Preserve for Undelete")
  if flags & 0x4:
    retVal.append("Compressed File")
  if flags & 0x8:
    retVal.append("Synchronous Writes")
  if flags & 0x10:
    retVal.append("Immutable File")
  if flags & 0x20:
    retVal.append("Append Only")
  if flags & 0x40:
    retVal.append("Do Not Dump")
  if flags & 0x80:
    retVal.append("Do Not Update Access Time")
  if flags & 0x100:
    retVal.append("Dirty Compressed File")
  if flags & 0x200:   
    retVal.append("Compressed Clusters")
  if flags & 0x400:
    retVal.append("Do Not Compress")
  if flags & 0x800:
    retVal.append("Encrypted Inode")
  if flags & 0x1000:
    retVal.append("Directory Hash Indexes")
  if flags & 0x2000:
    retVal.append("AFS Magic Directory")
  if flags & 0x4000:
    retVal.append("Must Be Written Through Journal")
  if flags & 0x8000:
    retVal.append("Do Not Merge File Tail")
  if flags & 0x10000:
    retVal.append("Directory Entries Written Synchronously")
  if flags & 0x20000:
    retVal.append("Top of Directory Hierarchy")
  if flags & 0x40000:
    retVal.append("Huge File")
  if flags & 0x80000:
    retVal.append("Inode uses Extents")
  if flags & 0x200000:
    retVal.append("Large Extended Attribute in Inode")
  if flags & 0x400000:
    retVal.append("Blocks Past EOF")
  if flags & 0x1000000:
    retVal.append("Inode is Snapshot")
  if flags & 0x4000000:
    retVal.append("Snapshot is being Deleted")
  if flags & 0x8000000:
    retVal.append("Snapshot Shrink Completed")
  if flags & 0x10000000:
    retVal.append("Inline Data")
  if flags & 0x80000000:
    retVal.append("Reserved for Ext4 Library")
  if flags & 0x4bdfff:
    retVal.append("User-visible Flags")
  if flags & 0x4b80ff:
    retVal.append("User-modifiable Flags")
    
  return retVal  

"""
This helper function will convert an inode
number to a block group and index with the
block group.  
Usage: [bg, index ] = getInodeLoc(inodeNo, inodesPerGroup)
"""  
def getInodeLoc(inodeNo, inodesPerGroup):
  bg = (int(inodeNo) - 1) / int(inodesPerGroup)
  index = (int(inodeNo) - 1) % int(inodesPerGroup)
  return [bg, index ]

"""
Class Inode.  This class stores extended filesystem
inode information in an orderly manner and provides
a helper function for pretty printing.  The constructor accepts
a packed string containing the inode data and inode size
which is defaulted to 128 bytes as used by ext2 and ext3.
For inodes > 128 bytes the extra fields are decoded.
Usage inode = Inode(dataInPackedString, inodeSize)
  inode.prettyPrint()
"""
class Inode():
  def __init__(self, data, inodeSize=128):
    # store both the raw mode bitvector and interpretation
    self.mode = getU16(data)
    self.modeList = getInodeModes(self.mode)
    self.fileType = getInodeFileType(self.mode)
    self.ownerID = getU16(data, 0x2)
    self.fileSize = getU32(data, 0x4)
    # get times in seconds since epoch
    # note: these will rollover in 2038 without extra
    # bits stored in the extra inode fields below
    self.accessTime = time.gmtime(getU32(data, 0x8))
    self.changeTime = time.gmtime(getU32(data, 0xC))
    self.modifyTime = time.gmtime(getU32(data, 0x10))
    self.deleteTime = time.gmtime(getU32(data, 0x14))
    self.groupID = getU16(data, 0x18)
    self.links = getU16(data, 0x1a)
    self.blocks = getU32(data, 0x1c)
    # store both the raw flags bitvector and interpretation
    self.flags = getU32(data, 0x20)
    self.flagList = getInodeFlags(self.flags)
    # high 32-bits of generation for Linux
    self.osd1 = getU32(data, 0x24)
    # store the 15 values from the block array
    # note: these may not be actual blocks if
    # certain features like extents are enabled 
    self.block = []
    for i in range(0, 15):
      self.block.append(getU32(data, 0x28 + i * 4))
    self.generation = getU32(data, 0x64)
    # the most common extened attributes are ACLs
    # but other EAs are possible 
    self.extendAttribs = getU32(data, 0x68)
    self.fileSize += pow(2, 32) * getU32(data, 0x6c)
    # these are technically only correct for Linux ext4 filesystems
    # should probably verify that that is the case
    self.blocks += getU16(data, 0x74) * pow(2, 32)
    self.extendAttribs += getU16(data, 0x76) * pow(2, 32)
    self.ownerID += getU16(data, 0x78) * pow(2, 32)
    self.groupID += getU16(data, 0x7a) * pow(2, 32)
    self.checksum = getU16(data, 0x7c)
    # ext4 uses 256 byte inodes on the disk
    # as of July 2015 the logical size is 156 bytes
    # the first word is the size of the extra info 
    if inodeSize > 128:
      self.inodeSize = 128 + getU16(data, 0x80)
    # this is the upper word of the checksum
    if self.inodeSize > 0x82:
      self.checksum += getU16(data, 0x82) * pow(2, 16)
    # these extra bits give nanosecond accuracy of timestamps
    # the lower 2 bits are used to extend the 32-bit seconds
    # since the epoch counter to 34 bits
    # if you are still using this script in 2038 you should
    # adjust this script accordingly :-)
    if self.inodeSize > 0x84:
      self.changeTimeNanosecs = getU32(data, 0x84) >> 2
    if self.inodeSize > 0x88:
      self.modifyTimeNanosecs = getU32(data, 0x88) >> 2
    if self.inodeSize > 0x8c:
      self.accessTimeNanosecs = getU32(data, 0x8c) >> 2
    if self.inodeSize > 0x90:
      self.createTime = time.gmtime(getU32(data, 0x90))
      self.createTimeNanosecs = getU32(data, 0x94) >> 2
    else:
      self.createTime = time.gmtime(0)
      
  def prettyPrint(self):
    for k, v in sorted(self.__dict__.iteritems()) :
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
     print("File " + sys.argv[1] + " cannot be openned for reading")
     exit(1)
  emd = ExtMetadata(sys.argv[1], sys.argv[2])
  emd.prettyPrint()

if __name__ == "__main__":
   main()

