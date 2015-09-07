# -*- coding: utf-8 -*-
A=int(input())
list=['программист','программиста', 'программистов']
iA = A % 100
if iA >=9 and iA <=20:
    print(str(A) + " " + list[2])
else:
    iA = iA % 10
    if iA == 1:
        print(str(A) + " " + list[0])
    elif iA > 1 and iA < 5:
        print(str(A) + " " + list[1])
    else:
        print(str(A) + " " + list[2])# put your python code here