#!/usr/bin/python

from sympy import *

x = Symbol('x')

f1=1+x+x**2+x**3+x**4+x**5
f2=1+x**4
f3=1+x**5
f4=1+x**3
res=(f1*f2*f3*f4).expand()
print "task1:"
print res
print ""

f1=1+x**5+x**10+x**15+x**20
f2=1+x**3+x**6+x**9+x**12+x**15+x**18
f3=1+x+x**2+x**3+x**4
f4=x**3+x**4+x**5+x**6+x**7+x**8+x**9+x**10+x**11+x**12+x**13+x**14+x**15+x**16+x**17+x**18+x**19+x**20
f5=1+x+x**2
res=(f1*f2*f3*f4*f5).expand()
print "task2:"
print res
print ""

res=1+x
res=(res*(1+x**2+x**4)).expand()
res=(res*(1+x**5)).expand()
res=(res*(1+x**10)).expand()
res=(res*(1+x**20+x**40)).expand()
res=(res*(1+x**50)).expand()
res=(res*(1+x**100)).expand()
res=(res*(1+x**200+x**400)).expand()
#res=(res*(1+x**500)).expand()
print "task3:"
print res
print ""
