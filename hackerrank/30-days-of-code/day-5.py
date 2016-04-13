# Objective
# In this challenge, we're going to use loops to help us do some simple math. Check out the Tutorial tab to learn more.

# Task
# Given an integer, NN, print its first 1010 multiples. Each multiple N×iN×i (where 1≤i≤101≤i≤10) should be printed on a new line in the form: N x i=resultN x i=result.

# Input Format

# A single integer, NN.

# Constraints

# 2≤N≤202≤N≤20
# Output Format

# Print 1010 lines of output; each line ii (where 1≤i≤101≤i≤10) contains the resultresult of N×iN×i in the form: N x i=resultN x i=result.

# Sample Input

# 2
# Sample Output

# 2 x 1 = 2
# 2 x 2 = 4
# 2 x 3 = 6
# 2 x 4 = 8
# 2 x 5 = 10
# 2 x 6 = 12
# 2 x 7 = 14
# 2 x 8 = 16
# 2 x 9 = 18
# 2 x 10 = 20

#!/bin/python3

import sys

N = int(input().strip())
for i in range(1,11):
    print(str(N) + " x " + str(i) + " = " + str(N * int(i)))
