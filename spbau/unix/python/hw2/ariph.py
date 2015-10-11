#!/usr/bin/python

base = 1000

def maxlenandone(num1, num2):
	result = len(num1)
	if len(num2) > result:
		result = len(num2)
	return result + 1

def longsum (num1, num2):
	result = []; take = 0
	maxlen = maxlenandone(num1, num2)
	for i in range(maxlen):
		val1 = 0; val2 = 0
		if i < len(num1):
			val1 = num1[i]
		if i < len(num2):
			val2 = num2[i]
		val = val1 + val2 + take
		if val != 0:
			result.append(val % base)
			if val < base:
				take = 0
			else:
				take = 1
	return result

def longsub (num1, num2):
	result = []; take = 0
	maxlen = maxlenandone(num1, num2)
	for i in range(maxlen):
		val1 = 0; val2 = 0
		if i < len(num1):
			val1 = num1[i]
		if i < len(num2):
			val2 = num2[i]
		val = val1 - val2 - take
		if val < 0:
			val = val + base
			take = 1
		else:
			take = 0
		result.append(val)
	if take != 0:
		result.append(-take)
	
	return result

def normnum (num):
	if num > 0:
		return str(num).rjust(3, '0')
	else:
		if num == 0:
			return "000"
		else:
			return num

def trimlong (num):
	count = 0
	while num[-count-1] == 0:
		count = count + 1
	return num[0:len(num)-count]

def printlong (num):
	trimmed = trimlong(num)
	if len(trimmed) > 0:
		print trimmed[-1],
	for i in range(len(trimmed) - 1):
			print normnum(trimmed[-i-2]),
	if len(trimmed) == 0:
		print "0",
	print ""

v1 = [999, 999]
v2 = [999, 999, 1]
v5 = [1]
v6 = [0, 0, 1]
v3 = longsum(v1,v2)
v4 = longsub(v1,v2)
v7 = longsub(v6, v5)
printlong(v3)
printlong(v4)
printlong(v7)
