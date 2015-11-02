# -*- coding: utf-8 -*-
# Задача на программирование: наибольший общий делитель
# По данным двум числам 1≤a,b≤2⋅109 найдите их наибольший общий делитель.
# Sample Input 1:

# 18 35

# Sample Output 1:

# 1

# Sample Input 2:

# 14159572 63967072

# Sample Output 2:

# 4

import sys
a,b = sys.stdin.readline().split(' ')
a,b = int(a), int(b)
while a!=0 and b!=0:
    if a > b:
        a = a % b
    else:
        b = b % a

print (a+b)