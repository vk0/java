#!/usr/bin/python

import time
import os
import re
from pylab import *

timestep = 1.0
fulload = 0
steps = 0

regexp = 'cpu\\s+(\\d+)\\s+(\\d+)\\s+(\\d+)\\s+(\\d+)'
statfile = open('/proc/stat')
line = statfile.readline()
m = re.search(regexp, line)
start1 = m.group(1)
start2 = m.group(2)
start3 = m.group(3)
start4 = m.group(4)
statfile.close()
time.sleep(timestep);

o1 = start1
o2 = start2
o3 = start3
o4 = start4

ys = [0 for i in xrange(60)]
avgs = [0 for i in xrange(60)]
xs = range(60)

ion()

l1, = plot(xs, ys)
l2, = plot(xs, avgs)
axis([0, 60, 0, 100])

while (True):
	statfile = open('/proc/stat')
	line = statfile.readline()
	m = re.search(regexp, line)
	n1 = m.group(1)
	n2 = m.group(2)
	n3 = m.group(3)
	n4 = m.group(4)
	
	d1 = int(n1) - int(o1)
	d2 = int(n2) - int(o2)
	d3 = int(n3) - int(o3)
	d4 = int(n4) - int(o4)

	fulltimediff = d1 + d2 + d3 + d4

	o1 = n1
	o2 = n2
	o3 = n3
	o4 = n4

	val = (100 * (d1 + d2 + d3)) / fulltimediff
	fulload += val
	steps += 1

	ys.append(val)
	avgs.append(fulload/steps)
	ys.pop(0)
	avgs.pop(0)

	print str(val), 'avg = ', fulload/steps
	statfile.close();
	l1.set_ydata(ys)
	l2.set_ydata(avgs)
	draw()
	time.sleep(timestep)
