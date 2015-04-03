#!/usr/bin/env python

def fibonacci(n):
    print ("Fibonacci: "+str(n))
    if n < 2:
        return n
    else:
        return (fibonacci(n-1)+fibonacci(n-2))
"""
    if n == 0:
        return 0
    elif n == 1:
        return 1
    else:
"""

"""
0 1 1 2 3 5 8
"""
