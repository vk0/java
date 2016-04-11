# # -*- coding: utf-8 -*-
# Objective
# In this challenge, we're getting started with conditional statements. Check out the Tutorial tab for learning materials and an instructional video!

# Task
# Given an integer, nn, perform the following conditional actions:

# If nn is odd, print WeirdWeird.
# If nn is even and in the inclusive range of 22 to 55, print Not WeirdNot Weird.
# If nn is even and in the inclusive range of 66 to 2020, print WeirdWeird.
# If nn is even and greater than 2020, print Not WeirdNot Weird.
# Complete the stub code provided in your editor to print whether or not nn is weird.

# Input Format

# A single line containing a positive integer, nn.

# Constraints

# 1≤n≤1001≤n≤100
# Output Format

# Print WeirdWeird if the number is weird; otherwise, print Not WeirdNot Weird.

# Sample Input 0

# 3
# Sample Output 0

# Weird
# Sample Input 1

# 24
# Sample Output 1

# Not Weird
# Explanation

# Sample Case 0: n=3n=3
# nn is odd and odd numbers are weird, so we print WeirdWeird.

# Sample Case 1: n=24n=24
# n>20n>20 and nn is even, so it isn't weird. Thus, we print Not WeirdNot Weird.

#!/bin/python3

import sys
l=range(2,6)
l1=range(6,21)

N = int(input().strip())
if (N%2 == 1):
    print("Weird")
if (N%2 == 0 and N in l):
    print("Not Weird")
if (N%2 == 0 and N in l1):
    print("Weird")
if (N%2 == 0 and N > 20):
    print("Not Weird")