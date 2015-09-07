# -*- coding: utf-8 -*-
A=input()
D =[int(i) for i in str(A)]
if sum(D[0:3]) == sum(D[3:6]):
    print("Счастливый")
else:
    print("Обычный")