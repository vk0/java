#!/usr/bin/bash

from sets import Set

name = input()
hist = {}
for line in open(name, "r"):
	for pos in xrange(len(line)):
		char = line[pos]
		if (not char.isspace()) and (char in hist):
			hist[char] = hist[char] + 1
		else:
			hist[char] = 1

vals = sorted(hist.values());
vals.reverse();
prev = None
for val in vals:
	if val != prev:
		for k in hist.iterkeys():
			if hist[k] == val:
				print k,val," ",
	prev = val
