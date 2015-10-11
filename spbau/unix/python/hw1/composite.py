#!/usr/bin/python

def fact(num):
	result = 1
	for i in range(2, num+1):
		result = result * i
	return result

def primetest(num):
	numfact = fact(num-1)
	if (numfact+1)%num == 0:
		return True
	else:
		return False

number = int(raw_input("enter number:"))
for i in range(4, number):
	if not primetest(i):
		print i
