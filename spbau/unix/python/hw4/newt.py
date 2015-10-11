#!/usr/bin/python

import cmath
from numpy import *
from numpy.linalg import *
from pylab import *

theta1 = float(raw_input('enter first angle: '))
theta2 = float(raw_input('enter second angle: '))
endtime = float(raw_input('enter end time: '))
n = int(raw_input('enter count of points: '))
l = float(raw_input('enter thread length: '))
steps = int(raw_input('enter steps count: '))

g = 9.8
k = g/l
t = endtime/(n-1)

def diff(alpha0, alpha1, alpha2):
	return (alpha0-2*alpha1+alpha2)/(t**2) + k*cmath.sin(alpha1);

def getnthrow(index, alpha):
	res = []
	if index==0:
		res.append(1)
		res.extend([0 for i in xrange(1,n)])
	elif index==(n-1):
		res.extend([0 for i in xrange(0,n-1)])
		res.append(1)
	else:
		res.extend([0 for i in xrange(0,index-1)])
		res.extend([1/(t**2), -2/(t**2)+k*cmath.cos(alpha), 1/(t**2)])
		res.extend([0 for i in xrange(index+2, n)])
	return res

def genmatrix(func):
	res = []
	for i in xrange(n):
		res.append(getnthrow(i, func[i][0]))
	return res

def gendiffv(func):
	res = [[func[0][0]-theta1]]
	for i in xrange(1, n-1):
		res.append([(func[i+1][0]+func[i-1][0]-2*func[i][0])/(t**2) + k*cmath.sin(func[i][0])])
	res.append([func[n-1][0]-theta2])
	return res

alpha = array([[1] for i in xrange(n)])

for step in xrange(steps):
	idf = inv(array(genmatrix(alpha)))
	dv = array(gendiffv(alpha))
	alpha = alpha - idf.dot(dv)

drawvec = [alpha[i][0] for i in xrange(n)]
xs = [i for i in xrange(n)]
plot(xs, drawvec)
show()
