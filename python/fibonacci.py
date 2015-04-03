#!/usr/bin/env python
def fibonacci(n):
    terms = [0,1]
    i = 2
    while i <=n:
        terms.append(terms[i-1]+terms[i-2])
        i += 1
    return terms[n]
