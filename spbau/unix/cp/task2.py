#!/usr/bin/python

import copy

A = int(raw_input("enter A:"))
B = int(raw_input("enter B:"))
C = int(raw_input("enter C:"))

AS = "A"
BS = "B"

if A > B:
	temp = B
	B = A
	A = temp
	temp = BS
	BS = AS
	AS = temp

def nextstep(AC, BC, path):
	if (AC == 0):
		AC = A
		path.append(">"+AS)
		return AC, BC
	if (BC == 0):
		BC = AC
		AC = 0
		path.append(AS + ">" + BS)
		return AC, BC
	if (AC == A):
		temp = AC + BC
		if temp > B:
			BC = B
			AC = temp - BC
		else:
			BC = temp
			AC = 0;
		path.append(AS + ">" + BS)
		return AC, BC
	if (BC == B):
		BC = 0
		path.append(BS + ">")
		return AC, BC

vals = {}
vals[A] = [">" + AS, AS + ">C"]
vals[B] = [">" + BS, BS + ">C"]
AC = 0; BC = 0
path = []

while ((AC != A) or (BC != B)):
	AC, BC = nextstep(AC, BC, path)
	if not (AC == 0) and (AC not in vals):
		vals[AC] = copy.deepcopy(path)
		vals[AC].append(AS + ">C")
		if not BC == 0:
			vals[AC].append(BS + ">")
	if not (BC == 0) and (BC not in vals):
		vals[BC] = copy.deepcopy(path)
		vals[BC].append(BS + ">C")
		if not AC == 0:
			vals[BC].append(AS + ">")

def printlist(lst):
	for item in lst:
		print item

summands = vals.keys()
weights = [len(vals[key]) for key in summands]
maxweight = sum(weights) + 1
dynamic = [maxweight for i in xrange(C + 1)]
dynamic[0] = 0
path = [[] for i in xrange(C + 1)]
for w in xrange(1, C+1):
	for i in xrange(len(summands)):
		if (summands[i] <= w):
			if dynamic[w] > (dynamic[w - summands[i]] + weights[i]):
				dynamic[w] = dynamic[w - summands[i]] + weights[i]
				path[w] = copy.deepcopy(path[w - summands[i]])
				path[w].append(summands[i])

for key in path[C]:
	printlist(vals[key])
