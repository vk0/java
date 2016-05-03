# -*- coding: utf-8 -*-
# Objective
# Today we're learning about running time! Check out the Tutorial tab for learning materials and an instructional video!

# Task
# A prime is a natural number greater than 11 that has no positive divisors other than 11 and itself. Given a number, nn, determine and print whether it's PrimePrime or Not primeNot prime.

# Note: If possible, try to come up with a O(n√)O(n) primality algorithm, or see what sort of optimizations you come up with for an O(n)O(n) algorithm. Be sure to check out the Editorial after submitting your code!

# Input Format

# The first line contains an integer, TT, the number of test cases.
# Each of the TT subsequent lines contains an integer, nn, to be tested for primality.

# Constraints

# 1≤T≤201≤T≤20
# 1≤n≤2×1091≤n≤2×109
# Output Format

# For each test case, print whether nn is PrimePrime or Not primeNot prime on a new line.

# Sample Input

# 3
# 12
# 5
# 7
# Sample Output

# Not prime
# Prime
# Prime
# Explanation

# Test Case 0: n=12n=12.
# 1212 is divisible by numbers other than 11 and itself (i.e.: 22, 33, 66), so we print Not primeNot prime on a new line.

# Test Case 1: n=5n=5.
# 55 is only divisible 11 and itself, so we print PrimePrime on a new line.

# Test Case 2: n=7n=7.
# 77 is only divisible 11 and itself, so we print PrimePrime on a new line.