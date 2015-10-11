#!/usr/bin/python

import string
import sys

def multiply(m1, m2):
	matrix = []
	for row in range(len(m1)):
		line = []
		for col in range(len(m2[0])):
			sum = 0;
			for i in range(len(m2)):
				sum = sum + m1[row][i]*m2[i][col]
			line.append(sum)
		matrix.append(line)
	return matrix

def printmatrix(m):
	maxlen = 0
	for row in range(len(m)):
		for col in range(len(m[row])):
			if maxlen<len(str(m[row][col])):
				maxlen = len(str(m[row][col]))
	maxlen = maxlen + 1
	for row in range(len(m)):
		for col in range(len(m[row])):
			sys.stdout.write("%s" % string.ljust(str(m[row][col]), maxlen))
		sys.stdout.write("\n");
	sys.stdout.write("\n");

gen = [[1, 1],
       [1, 0]]
matrix = gen

print "Fibonachi numbers:\n"

printmatrix(matrix)
sys.stdout.write("\n")

for i in range(3):
	matrix = multiply(matrix, gen)
	printmatrix(matrix)
	sys.stdout.write("\n")
