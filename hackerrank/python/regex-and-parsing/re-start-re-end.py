# -*- coding: utf-8 -*-
# start() & end()

# These expressions return the indices of the start and end of the substring matched by the group.

# Code

# >>> import re
# >>> m = re.search(r'\d+','1234')
# >>> m.end()
# 4
# >>> m.start()
# 0
# Task
# You are given a string SS.
# Your task is to find the indices of the start and end of string kk in SS.

# Input Format

# The first line contains the string SS.
# The second line contains the string kk.

# Constraints

# 0<len(S)<1000<len(S)<100
# 0<len(k)<len(S)0<len(k)<len(S)
# Output Format

# Print the tuple in this format: (start _index, end _index).
# If no match is found, print (-1, -1).

# Sample Input

# aaadaa
# aa
# Sample Output

# (0, 1)
# (1, 2)
# (4, 5)

import re
a_str = input()
substr = input()
p = re.compile(r'(?=('+substr+'))', re.VERBOSE)

if p.search(a_str):
    for m in p.finditer(a_str):
        print((m.start(1), m.end(1)-1))
else:
    print((-1,-1))
