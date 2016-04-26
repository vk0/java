# # -*- coding: utf-8 -*-
# min

# The tool min returns the minimum value along a given axis.

# import numpy

# my_array = numpy.array([[2, 5],
#                         [3, 7],
#                         [1, 3],
#                         [4, 0]])

# print numpy.min(my_array, axis = 0)         #Output : [1 0]
# print numpy.min(my_array, axis = 1)         #Output : [2 3 1 0]
# print numpy.min(my_array, axis = None)      #Output : 0
# print numpy.min(my_array)                   #Output : 0
# By default, the axis value is None. Therefore, it finds the minimum over all the dimensions of the input array.

# max

# The tool max returns the maximum value along a given axis.

# import numpy

# my_array = numpy.array([[2, 5],
#                         [3, 7],
#                         [1, 3],
#                         [4, 0]])

# print numpy.max(my_array, axis = 0)         #Output : [4 7]
# print numpy.max(my_array, axis = 1)         #Output : [5 7 3 4]
# print numpy.max(my_array, axis = None)      #Output : 7
# print numpy.max(my_array)                   #Output : 7
# By default, the axis value is None. Therefore, it finds the maximum over all the dimensions of the input array.

# Task

# You are given a 2-D array with dimensions NNXMM.
# Your task is to perform the min function over axis 11 and then find the max of that.

# Input Format

# The first line of input contains the space separated values of NN and MM.
# The next NN lines contains MM space separated integers.

# Output Format

# Compute the min along axis 11 and then print the max of that result.

# Sample Input

# 4 2
# 2 5
# 3 7
# 1 3
# 4 0
# Sample Output

# 3
# Explanation

# The min along axis 11 = [2,3,1,0][2,3,1,0]
# The max of [2,3,1,0][2,3,1,0] = 3

import numpy
N, M = map(int, input().split())
A = numpy.array([list(map(int, input().split())) for _ in range(N)])
print(numpy.max(numpy.min(A, axis = 1)))