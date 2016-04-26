# -*- coding: utf-8 -*-
# dot

# The dot tool returns the dot product of two arrays.

# import numpy

# A = numpy.array([ 1, 2 ])
# B = numpy.array([ 3, 4 ])

# print numpy.dot(A, B)       #Output : 11
# cross

# The cross tool returns the cross product of two arrays.

# import numpy

# A = numpy.array([ 1, 2 ])
# B = numpy.array([ 3, 4 ])

# print numpy.cross(A, B)     #Output : -2
# Task

# You are given two arrays AA and BB. Both have dimensions of NNXNN.
# Your task is to compute their matrix product.

# Input Format

# The first line contains the integer NN.
# The next NN lines contains NN space separated integers of array AA.
# The following NN lines contains NN space separated integers of array BB.

# Output Format

# Print the matrix multiplication of AA and BB.

# Sample Input

# 2
# 1 2
# 3 4
# 1 2
# 3 4
# Sample Output

# [[ 7 10]
#  [15 22]]

import numpy
N = int(input())
A = numpy.array([list(map(int, input().split())) for _ in range(N)])
B = numpy.transpose(numpy.array([list(map(int, input().split())) for _ in range(N)]))
AB = numpy.array([[numpy.dot(A[i], B[j]) for j in range(N)] for i in range(N)])
print(AB)