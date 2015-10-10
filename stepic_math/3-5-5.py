# -*- coding: utf-8 -*-
# Нужно сгенерировать все возможные k-сочетания из n элементов.

# Формат входных данных:
# Два числа k и n через пробел. Для них гарантированно выполняется условие: 0≤k≤n.

# Формат выходных данных:
# Необходимое число строк, в каждой из которых содержится k чисел из диапазона от 0 до n-1 включительно, разделенных пробелом.

# Sample Input 1:
# 2 3
# Sample Output 1:
# 0 1
# 0 2
# 1 2

# Sample Input 2:
# 1 1
# Sample Output 2:
# 0

import itertools
import sys
k,n = map(int,sys.stdin.readline().split())
# k = 2
# n = 3
if k == 0:
    exit()
elif k == n:
    print("0")
    exit()
range_n=range(n)
# print range_n
# print list(itertools.permutations([0,3]))
for n in itertools.product(range_n, repeat=k):
    print(str(n[0]),end=' ')
    print(str(n[1]))
# def perm(a,k=0):
#    if(k==len(a)):
#       print a
#    else:
#       for i in xrange(k,len(a)):
#          a[k],a[i] = a[i],a[k]
#          perm(a, k+1)
#          a[k],a[i] = a[i],a[k]

# perm([0,1,2])