# -*- coding: utf-8 -*-
# An array is a type of data structure that stores elements of the same type in a contiguous block of memory. In an array, AA, of size NN, each memory location has some unique index, ii (where 0≤i<N0≤i<N), that can be referenced as A[i]A[i] (in documentation, you may also see it written as AiAi).

# Given an array, AA, of NN integers, print each element in reverse order as a single line of space-separated integers.

# Note: If you've already solved our C++ domain's Arrays Introduction challenge, you may want to skip this.

# Input Format

# The first line contains an integer, NN (the number of integers in AA).
# The second line contains NN space-separated integers describing AA.

# Constraints

# 1≤N≤1031≤N≤103
# 1≤Ai≤104, where Ai is the ith integer in A1≤Ai≤104, where Ai is the ith integer in A
# Output Format

# Print all NN integers in AA in reverse order as a single line of space-separated integers.

# Sample Input

# 4
# 1 4 3 2
# Sample Output

# 2 3 4 1

#!/bin/python3

import sys


n = int(input().strip())
arr = [int(arr_temp) for arr_temp in input().strip().split(' ')]
for a in arr[::-1]:
    print(a, end=" ")