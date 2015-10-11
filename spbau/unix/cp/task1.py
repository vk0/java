#!/usr/bin/python

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

AC = 0; BC = 0

if C == A:
	print ">A"
elif C == B:
	print ">B"
else:
	path = []
	while (AC != C) and (BC != C) and ((AC != A) or (BC != B)):
		AC, BC = nextstep(AC, BC, path)
	if (AC == C) or (BC == C):
		for item in path:
			print item
	else:
		print "Impossible"
