#!/usr/bin/python

for sym in range(0x03b1, 0x03cf):
	print unichr(sym),unichr(sym).upper(), "  ",
	if ((sym - 0x03b0) % 6 == 0):
		print ""
