#!/usr/bin/python
import cmath

def complex_roots(num, index):
	result = []
	step = 2*cmath.pi/index
	for i in xrange(index):
		result.append(cmath.rect(num**(1/index), i*step))
	return result

print complex_roots(1, int(raw_input("enter index of root: ")))
