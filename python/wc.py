#!/usr/bin/env python
# unix wc cmd analog
from __future__ import print_function
import sys
num_lines = 0
num_words = 0
num_chars = 0
for line in sys.stdin:
    num_lines += 1
    num_words += len(line.split())
    num_chars += len(line)
print("lines: ", num_lines,"words: ", num_words,"chars: ", num_chars)
