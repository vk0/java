# -*- coding: utf-8 -*-
import math
x=input()
if x == "треугольник":
    a=int(input())
    b=int(input())
    c=int(input())
    p=(a+b+c)/2
    S=math.sqrt(p*(p-a)*(p-b)*(p-c))
    print(S)
elif x == "прямоугольник":
    a=int(input())
    b=int(input())
    print(float((a*b)))
elif x == "круг":
    a=int(input())
    print((3.14*a**2))
else:
    exit(0)