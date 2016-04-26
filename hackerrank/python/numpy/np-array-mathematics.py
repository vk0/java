# -*- coding: utf-8 -*-
# Basic mathematical functions operate element-wise on arrays. They are available both as operator overloads and as functions in the NumPy module.

# import numpy

# a = numpy.array([1,2,3,4], float)
# b = numpy.array([5,6,7,8], float)

# print a + b                     #[  6.   8.  10.  12.]
# print numpy.add(a, b)           #[  6.   8.  10.  12.]

# print a - b                     #[-4. -4. -4. -4.]
# print numpy.subtract(a, b)      #[-4. -4. -4. -4.]

# print a * b                     #[  5.  12.  21.  32.]
# print numpy.multiply(a, b)      #[  5.  12.  21.  32.]

# print a / b                     #[ 0.2         0.33333333  0.42857143  0.5       ]
# print numpy.divide(a, b)        #[ 0.2         0.33333333  0.42857143  0.5       ]

# print a % b                     #[ 1.  2.  3.  4.]
# print numpy.mod(a, b)           #[ 1.  2.  3.  4.]

# print a**b                      #[  1.00000000e+00   6.40000000e+01   2.18700000e+03   6.55360000e+04]
# print numpy.power(a, b)         #[  1.00000000e+00   6.40000000e+01   2.18700000e+03   6.55360000e+04]
# Task

# You are given two arrays (AA & BB) of dimensions NNXMM.
# Your task is to perform the following operations:

# Add (AA + BB)
# Subtract (AA - BB)
# Multiply (AA * BB)
# Divide (AA / BB)
# Mod (AA % BB)
# Power (AA ** BB)
# Input Format

# The first line contains two space separated integers, NN and MM.
# The next NN lines contains MM space separated integers of array AA.
# The following NN lines contains MM space separated integers of array BB.

# Output Format

# Print the result of each operation in the given order under Task.

# Sample Input

# 1 4
# 1 2 3 4
# 5 6 7 8
# Sample Output

# [[ 6  8 10 12]]
# [[-4 -4 -4 -4]]
# [[ 5 12 21 32]]
# [[0 0 0 0]]
# [[1 2 3 4]]
# [[    1    64  2187 65536]]
# Use // for division in Python 3.

import numpy
n, m = map(int, input().split())
A = numpy.array([input().split() for _ in range(n)], int)
B = numpy.array([input().split() for _ in range(n)], int)
for i in (A+B, A-B, A*B, A//B, A%B, A**B):
    print(i)