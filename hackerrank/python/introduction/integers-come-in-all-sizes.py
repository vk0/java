# -*- coding: utf-8 -*-
# Integers in Python can be as big as the bytes in your machine's memory. There is no limit in size as there is: 231−1231−1 (c++ int) or 263−1263−1 (C++ long long int).

# As we know, the result of abab grows really fast with increasing bb.

# Let's do some calculations on very large integers.

# Task
# Read four numbers, aa, bb, cc, and dd, and print the result of ab+cdab+cd.

# Input Format
# Integers aa, bb, cc, and dd are given on four separate lines, respectively.

# Constraints
# 1≤a≤10001≤a≤1000
# 1≤b≤10001≤b≤1000
# 1≤c≤10001≤c≤1000
# 1≤d≤10001≤d≤1000

# Output Format
# Print the result of ab+cdab+cd on one line.

# Sample Input

# 9
# 29
# 7
# 27
# Sample Output

# 4710194409608608369201743232
# Note: This result is bigger than 263−1263−1. Hence, it won't fit in the long long int of C++ or a 64-bit integer.

a = int(raw_input())
b = int(raw_input())
c = int(raw_input())
d = int(raw_input())

print(pow(a,b)+pow(c,d))