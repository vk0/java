#!/usr/bin/python

import sys

text = sys.stdin.read()

for i in range(len(text)):
	if (text[i].isalpha()) or (text[i]==' '):
		sys.stdout.write("%c"%text[i])

print
