# -*- coding: utf-8 -*-
# Objective
# Today, we're building on our knowledge of Arrays by adding another dimension. Check out the Tutorial tab for learning materials and an instructional video!

# Context
# Given a 6×66×6 2D Array, AA:

# 1 1 1 0 0 0
# 0 1 0 0 0 0
# 1 1 1 0 0 0
# 0 0 0 0 0 0
# 0 0 0 0 0 0
# 0 0 0 0 0 0
# We define an hourglass in AA to be a subset of values with indices falling in this pattern in AA's graphical representation:

# a b c
#   d
# e f g
# There are 1616 hourglasses in AA, and an hourglass sum is the sum of an hourglass' values.

# Task
# Calculate the hourglass sum for every hourglass in AA, then print the maximum hourglass sum.

# Input Format

# There are 66 lines of input, where each line contains 66 space-separated integers describing 2D Array AA; every value in AA will be in the inclusive range of −9−9 to 99.

# Constraints

# −9≤A[i][j]≤9−9≤A[i][j]≤9
# 0≤i,j≤50≤i,j≤5
# Output Format

# Print the largest (maximum) hourglass sum found in AA.

# Sample Input

# 1 1 1 0 0 0
# 0 1 0 0 0 0
# 1 1 1 0 0 0
# 0 0 2 4 4 0
# 0 0 0 2 0 0
# 0 0 1 2 4 0
# Sample Output

# 19
# Explanation

# AA contains the following hourglasses:

# 1 1 1   1 1 0   1 0 0   0 0 0
#   1       0       0       0
# 1 1 1   1 1 0   1 0 0   0 0 0

# 0 1 0   1 0 0   0 0 0   0 0 0
#   1       1       0       0
# 0 0 2   0 2 4   2 4 4   4 4 0

# 1 1 1   1 1 0   1 0 0   0 0 0
#   0       2       4       4
# 0 0 0   0 0 2   0 2 0   2 0 0

# 0 0 2   0 2 4   2 4 4   4 4 0
#   0       0       2       0
# 0 0 1   0 1 2   1 2 4   2 4 0
# The hourglass with the maximum sum (1919) is:

# 2 4 4
#   2
# 1 2 4

#!/bin/python3

import sys

arr = []
for arr_i in range(6):
   arr_t = [int(arr_temp) for arr_temp in input().strip().split(' ')]
   arr.append(arr_t)
maxi = None
for i in range(4):
    for j in range(4):
        current = arr[i][j] + arr[i][j+1] + arr[i][j+2] + \
                  arr[i+1][j+1] + \
                  arr[i+2][j] + arr[i+2][j+1] + arr[i+2][j+2]
        if maxi == None or current > maxi:
            maxi = current
print(maxi)