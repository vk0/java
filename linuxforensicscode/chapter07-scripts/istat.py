#!/usr/bin/python
#
# istat.py
#
# This is a simple Python script that will
# print out metadata in an inode from an ext2/3/4 filesystem inside
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
   print("usage " + sys.argv[0] + " <image file> <offset> <inode number> \n"+
     "Displays inode information from an image file")
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
  print "Inode %s in Block Group %s at index %s" % (str(sys.argv[3]), \
    str(inodeLoc[0]), str(inodeLoc[1]))
  inode.prettyPrint()

if __name__ == "__main__":
   main()
