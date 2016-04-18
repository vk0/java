# -*- coding: utf-8 -*-
# This challenge is only forPython 2.

# input()

# In Python 2, the expression input() is equivalent to eval(raw _input(prompt)).

# Code

# >>> input()
# 1+2
# 3
# >>> company = 'HackerRank'
# >>> website = 'www.hackerrank.com'
# >>> input()
# 'The company name: '+company+' and website: '+website
# 'The company name: HackerRank and website: www.hackerrank.com'
# Task

# You are given a polynomial PP of a single indeterminate (or variable), xx.
# You are also given the values of xx and kk. Your task is to verify if P(x)=kP(x)=k.

# Constraints
# All coefficients of polynomial PP are integers.
# xx and yy are also integers.

# Input Format

# The first line contains the space separated values of xx and kk.
# The second line contains the polynomial PP.

# Output Format

# Print True if P(x)=kP(x)=k. Otherwise, print False.

# Sample Input

# 1 4
# x**3 + x**2 + x + 1
# Sample Output

# True
# Explanation

# P(1)=13+12+1+1=4=kP(1)=13+12+1+1=4=k
# Hence, the output is True.

x, y = map(int, raw_input().split())
print input() == y