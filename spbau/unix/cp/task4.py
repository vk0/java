#/usr/bin/python

num = int(input())
cont = True
while (num != 1) and cont:
	if num%2 == 0:
		num = num/2
	else:
		print "NO"
		cont = False;

if cont:
	print "YES"
