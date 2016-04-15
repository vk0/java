# -*- coding: utf-8 -*-
# You are given a function f(X)=X2f(X)=X2.

# You are also given KK lists. The ithith list consists of NiNi elements.

# You have to pick exactly one element from each list so that the equation below is maximized:

# S=(f(X1)+f(X2)+...+f(Xk))S=(f(X1)+f(X2)+...+f(Xk))%MM
# XiXi denotes the element picked from the ithith list . Find the maximized value SmaxSmax obtained.

# %% denotes the modulo operator.

# Input Format
# The first line contains 22 space separated integers KK and MM.
# The next KK lines each contains an integer NiNi followed by NiNi space separated integers denoting the elements in the list.

# Output Format
# Output a single integer denoting the value SmaxSmax.

# Constraints
# 1≤K≤71≤K≤7
# 1≤M≤10001≤M≤1000
# 1≤Ni≤71≤Ni≤7
# 1≤Magnitudeofelementsinlist≤1091≤Magnitudeofelementsinlist≤109

# Sample Input

# 3 1000
# 2 5 4
# 3 7 8 9
# 5 5 7 8 9 10
# Sample Output

# 206
# Explanation

# Picking 55 from the 11st list, 99 from the 22nd list and 1010 from the 33rd list gives the maximum SS value equal to (52+92+102)(52+92+102)%10001000 = 206206.

from itertools import product

k, m = tuple(map(int, input().strip().split()))
lists = []
for i in range(k):
    lists.append(list(map(int, input().strip().split()))[1:])
max = 0
for each in product(*lists):
    modu = sum([x**2 for x in each])% m
    if modu > max:
        max = modu
print(max)