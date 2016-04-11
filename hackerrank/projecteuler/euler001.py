# -*- coding: utf-8 -*-
# This problem is a programming version of Problem 1 from projecteuler.net

# If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.

# Find the sum of all the multiples of 3 or 5 below NN.

# Input Format
# First line contains TT that denotes the number of test cases. This is followed by TT lines, each containing an integer, NN.

# Output Format
# For each test case, print an integer that denotes the sum of all the multiples of 3 or 5 below NN.

# Constraints
# 1≤T≤1051≤T≤105
# 1≤N≤1091≤N≤109

# Sample Input

# 2
# 10
# 100
# Sample Output

# 23
# 2318


def sum_multiples(n):
    sum = 0
    for x in range(0, n):
        if x % 3 == 0 or x % 5 == 0:
            sum += x
    return sum

n = int(input())
for i in range(n):
    a = int(input())
    print(sum_multiples(a))