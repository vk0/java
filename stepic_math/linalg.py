#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""
URL: https://stepic.org/lesson/Решение-систем-линейных-алгебраических-уравнений-9582
"""

import numpy

matrix_base = []
matrix_ext = []
b = []

m, n  = map(int, input().split())
print(m,n)
for i in range(0, m):
    matrix_ext.append([x for x in map(int, input().split())])

for i in range(0, len(matrix_ext)):
    b.append(matrix_ext[i][-1])
    matrix_base.append(matrix_ext[i][:-1])

rank_extend = numpy.linalg.matrix_rank(matrix_ext)
rank_base = numpy.linalg.matrix_rank(matrix_base)

if (rank_extend == rank_base):
    if r_m < n:
        print("INF")
    else:
        print("YES")
        print(' '.join(map(str, numpy.linalg.solve(matrix_base, b))))
else:
    print("NO")
