#!/usr/bin/python
#
# icat.py
#
# This is a simple Python script that will
# print out file for in an inode from an ext2/3/4 filesystem inside
# of an image file.
#
# Developed for PentesterAcademy 
# by Dr. Phil Polstra (@ppolstra)

import extfs
import sys
import os.path
import subprocess
import struct
import time
from math import log

def usage():
   print("usage " + sys.argv[0] + " <image file> <offset> <inode number> \n"\
     "Displays file for an inode from an image file")
   exit(1)

def main():
  if len(sys.argv) < 3: 
     usage()

  # read first sector
  if not os.path.isfile(sys.argv[1]):
     print("File " + sys.argv[1] + " cannot be openned for reading")
     exit(1)
  emd = extfs.ExtMetadata(sys.argv[1], sys.argv[2])
  # get inode location
  inodeLoc = extfs.getInodeLoc(sys.argv[3], emd.superblock.inodesPerGroup)
  offset = emd.bgdList[inodeLoc[0]].inodeTable * emd.superblock.blockSize + \
    inodeLoc[1] * emd.superblock.inodeSize 
  with open(str(sys.argv[1]), 'rb') as f:
    f.seek(offset + int(sys.argv[2]) * 512)
    data = str(f.read(emd.superblock.inodeSize))
  inode = extfs.Inode(data, emd.superblock.inodeSize)
  datablock = extfs.getBlockList(inode, sys.argv[1], sys.argv[2], \
    emd.superblock.blockSize)
  for db in datablock:
    sys.stdout.write(extfs.getDataBlock(sys.argv[1], long(sys.argv[2]), \
      db, emd.superblock.blockSize)) 


if __name__ == "__main__":
   main()
