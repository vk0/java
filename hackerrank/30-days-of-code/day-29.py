# -*- coding: utf-8 -*-
# Objective
# Welcome to the last day! Today, we're discussing bitwise operations. Check out the Tutorial tab for learning materials and an instructional video!

# Task
# Given set S={1,2,3,…,N}S={1,2,3,…,N}. Find two integers, AA and BB (where A<BA<B), from set SS such that the value of A&BA&B is the maximum possible and also less than a given integer, KK. In this case, && represents the bitwise AND operator.

# Input Format

# The first line contains an integer, TT, the number of test cases.
# Each of the TT subsequent lines defines a test case as 22 space-separated integers, NN and KK, respectively.

# Constraints

# 1≤T≤1031≤T≤103
# 2≤N≤1032≤N≤103
# 2≤K≤N2≤K≤N
# Output Format

# For each test case, print the maximum possible value of A&BA&B on a new line.

# Sample Input

# 3
# 5 2
# 8 5
# 2 2
# Sample Output

# 1
# 4
# 0
# Explanation

# N=5,K=2N=5,K=2 S={1,2,3,4,5}S={1,2,3,4,5}
# All possible values of AA and BB are:

# A = 1, B = 2; A & B = 0A = 1, B = 2; A & B = 0
# A = 1, B = 3; A & B = 1A = 1, B = 3; A & B = 1
# A = 1, B = 4; A & B = 0A = 1, B = 4; A & B = 0
# A = 1, B = 5; A & B = 1A = 1, B = 5; A & B = 1
# A = 2, B = 3; A & B = 2A = 2, B = 3; A & B = 2
# A = 2, B = 4; A & B = 0A = 2, B = 4; A & B = 0
# A = 2, B = 5; A & B = 0A = 2, B = 5; A & B = 0
# A = 3, B = 4; A & B = 0A = 3, B = 4; A & B = 0
# A = 3, B = 5; A & B = 1A = 3, B = 5; A & B = 1
# A = 4, B = 5; A & B = 4A = 4, B = 5; A & B = 4
# The maximum possible value of A&BA&B that is also <(K=2)<(K=2) is 11, so we print 11 on a new line.

#!/bin/python3

import sys
for _ in range(int(input())):
    n, k = map(int, input().split())
    a = k - 1
    b = ~a & -~a
    if a | b > n:
        print(a - 1)
    else:
        print(a)