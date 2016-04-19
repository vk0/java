# -*- coding: utf-8 -*-
# re.split()

# The re.split() expression splits the string by occurrence of a pattern.

# Code

# >>> import re
# >>> re.split("-","+91-011-2711-1111")
# ['+91', '011', '2711', '1111']
# Task
# You are given a string SS, containing , and/or . and 0-9 digits.
# Your task is to re.split() all of the , and . symbols.

# Input Format

# A single line of input containing the string SS.

# Output Format

# Print the numbers obtained after splitting the string on separate lines.

# Sample Input

# 100,000,000.000
# Sample Output

# 100
# 000
# 000
# 000
# Note: Each line of output should only be the numbers.
# # False

# .172..16.52.207,172.16.52.117
# 172
# 16
# 52
# 207
# 172
# 16
# 52
# 117

import re
regex = r'[\,\.]*'
lst = filter(None, re.split(regex, input().strip()))
print("\n".join(lst))