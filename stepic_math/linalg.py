#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""
URL: https://stepic.org/lesson/Решение-систем-линейных-алгебраических-уравнений-9582
Sample Input 1:
3 3
4 2 1 1
7 8 9 1
9 1 3 2

Sample Output 1:
YES
0.2608695652173913 0.04347826086956526 -0.1304347826086957

Sample Input 2:
2 3
1 3 4 4
2 1 4 5

Sample Output 2:
INF

Sample Input 3:
3 3
1 3 2 7
2 6 4 8
1 4 3 1

Sample Output 3:
NO
"""

import numpy

matrix_base = []
matrix_ext = []
b = []

m, n  = map(int, input().split())
# print(m,n)
for i in range(0, m):
    matrix_ext.append([x for x in map(int, input().split())])

for i in range(0, len(matrix_ext)):
    b.append(matrix_ext[i][-1])
    matrix_base.append(matrix_ext[i][:-1])

rank_extend = numpy.linalg.matrix_rank(matrix_ext)
rank_base = numpy.linalg.matrix_rank(matrix_base)

if (rank_extend == rank_base):
    if m < n:
        print("INF")
    else:
        print("YES")
        print(' '.join(map(str, numpy.linalg.solve(matrix_base, b))))
else:
    print("NO")
