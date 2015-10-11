#!/usr/bin/python

class car(object):
	def who(self):
		print "i'm car"

class drift(car):
	def who(self):
		print "i'm drift"

class buld(car):
	def who(self):
		print "i'm suck"

c = car()
d = drift()
b = buld()

c.who()
d.who()
b.who()
