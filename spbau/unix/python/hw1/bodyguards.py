#!/usr/bin/python

import sys
import re

text = sys.stdin.read()

m=re.findall('[^A-Z][A-Z]{3}([a-z])[A-Z]{3}[^A-Z]', text) 

print m
