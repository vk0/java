#!/usr/bin/python
import SubnetTree
import sys

t = SubnetTree.SubnetTree()
t["192.168.1.1/24"] = "Network 1"

if len(sys.argv) != 2:
    print "Need params"
sys.exit(1)

print sys.argv[1] in t
