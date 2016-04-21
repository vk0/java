# -*- coding: utf-8 -*-
# Let's dive into the interesting topic of regular expressions! You are given some input, and you are required to check whether they are valid mobile numbers.

# A valid mobile number is a ten digit number starting with a 7,87,8 or 99.

# Concept

# A valid mobile number is a ten digit number starting with a 7,87,8 or 99.

# Regular expressions are a key concept in any programming language. A quick explanation with Python examples is available here. You could also go through the link below to read more about regular expressions in Python.

# https://developers.google.com/edu/python/regular-expressions

# Input Format

# The first line contains an integer NN, the number of inputs.
# NN lines follow, each containing some string.

# Constraints

# 1≤N≤101≤N≤10

# 2≤len(Number)≤152≤len(Number)≤15

# Output Format

# For every string listed, print "YES" if it is a valid mobile number and "NO" if it is not on separate lines. Do not print the quotes.

# Sample Input

# 2
# 9587456281
# 1252478965
# Sample Output

# YES
# NO

import re
for _ in range(int(input())):
    if re.match(r'[7-9]\d{9}$',input()):
        print("YES")
    else:
        print("NO")