# # -*- coding: utf-8 -*-
# sum

# The sum tool returns the sum of array elements over a given axis.

# import numpy

# my_array = numpy.array([ [1, 2], [3, 4] ])

# print numpy.sum(my_array, axis = 0)         #Output : [4 6]
# print numpy.sum(my_array, axis = 1)         #Output : [3 7]
# print numpy.sum(my_array, axis = None)      #Output : 10
# print numpy.sum(my_array)                   #Output : 10
# By default, the axis value is None. Therefore, it performs a sum over all the dimensions of the input array.

# prod

# The prod tool returns the product of array elements over a given axis.

# import numpy

# my_array = numpy.array([ [1, 2], [3, 4] ])

# print numpy.prod(my_array, axis = 0)            #Output : [3 8]
# print numpy.prod(my_array, axis = 1)            #Output : [ 2 12]
# print numpy.prod(my_array, axis = None)         #Output : 24
# print numpy.prod(my_array)                      #Output : 24
# By default, the axis value is None. Therefore, it performs the product over all the dimensions of the input array.

# Task

# You are given a 2-D array with dimensions NNXMM.
# Your task is to perform the sumsum tool over axis 00 and then find the productproduct of that result.

# Input Format

# The first line of input contains space separated values of NN and MM.
# The next NN lines contains MM space separated integers.

# Output Format

# Compute the sum along axis 00. Then, print the product of that sum.

# Sample Input

# 2 2
# 1 2
# 3 4
# Sample Output

# 24
# Explanation

# The sum along axis 00 = [44 66]
# The product of this sum = 24

import numpy
N, M = map(int, input().split())
A = numpy.array([list(map(int, input().split())) for _ in range(N)])
print(numpy.prod(numpy.sum(A, axis = 0), axis = 0))