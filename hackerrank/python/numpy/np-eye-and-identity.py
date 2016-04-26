# -*- coding: utf-8 -*-
# identity

# The identity tool returns an identity array. An identity array is a square matrix with all the main diagonal elements as 11 and the rest as 00. The default type of elements is float.

# import numpy
# print numpy.identity(3) #3 is for  dimension 3 X 3

# #Output
# [[ 1.  0.  0.]
#  [ 0.  1.  0.]
#  [ 0.  0.  1.]]
# eye

# The eye tool returns a 2-D array with 11's as the diagonal and 00's elsewhere. The diagonal can be main, upper or lower depending on the optional parameter kk. A positive kk is for the upper diagonal, a negative kk is for the lower, and a 00 kk (default) is for the main diagonal.

# import numpy
# print numpy.eye(8, 7, k = 1)    # 8 X 7 Dimensional array with first upper diagonal 1.

# #Output
# [[ 0.  1.  0.  0.  0.  0.  0.]
#  [ 0.  0.  1.  0.  0.  0.  0.]
#  [ 0.  0.  0.  1.  0.  0.  0.]
#  [ 0.  0.  0.  0.  1.  0.  0.]
#  [ 0.  0.  0.  0.  0.  1.  0.]
#  [ 0.  0.  0.  0.  0.  0.  1.]
#  [ 0.  0.  0.  0.  0.  0.  0.]
#  [ 0.  0.  0.  0.  0.  0.  0.]]

# print numpy.eye(8, 7, k = -2)   # 8 X 7 Dimensional array with second lower diagonal 1.
# Task

# Your task is to print an array of size NNXMM with its main diagonal elements as 11's and 00's everywhere else.

# Input Format

# A single line containing the space separated values of NN and MM.
# NN denotes the rows.
# MM denotes the columns.

# Output Format

# Print the desired NNXMM array.

# Sample Input

# 3 3
# Sample Output

# [[ 1.  0.  0.]
#  [ 0.  1.  0.]
#  [ 0.  0.  1.]]

import numpy
columns, rows = map(int, input().split())
print(numpy.eye(columns, rows))