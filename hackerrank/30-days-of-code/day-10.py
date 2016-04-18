# -*- coding: utf-8 -*-
# Objective
# Today, we're working with binary numbers. Check out the Tutorial tab for learning materials and an instructional video!

# Task
# Given a base-1010 integer, nn, convert it to binary (base-22). Then find and print the base-1010 integer denoting the maximum number of consecutive 11's in nn's binary representation.

# Input Format

# A single integer, nn.

# Constraints

# 1≤n≤1061≤n≤106
# Output Format

# Print a single base-1010 integer denoting the maximum number of consecutive 11's in the binary representation of nn.

# Sample Input 1

# 5
# Sample Output 1

# 1
# Sample Input 2

# 13
# Sample Output 2

# 2
# Explanation

# Sample Case 1:
# The binary representation of 55 is 101101, so the maximum number of consecutive 11's is 11.

# Sample Case 2:
# The binary representation of 1313 is 11011101, so the maximum number of consecutive 11's is 22.

#!/bin/python3

import sys

n = int(input().strip())
count = 0;
n_arr = bin(n)[2:].split('0')
for i in range(len(n_arr)):
    leni = len(n_arr[i])
    if (leni>count):
        count = leni
print(count)