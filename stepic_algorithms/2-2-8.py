# -*- coding: utf-8 -*-
# Задача на программирование повышенной сложности: огромное число Фибоначчи по модулю

# Даны целые числа 1≤n≤1018 и 2≤m≤105, необходимо найти остаток от деления n-го числа Фибоначчи на m.

# Sample Input:

# 47905881698199969 76940

# Sample Output:

# 13794

import sys
from functools import lru_cache

@lru_cache(maxsize=1024)
def fbmodl(n, m):
    n, m = int(n), int(m)
    if n <= 3:
        return (0, 1, 1, 2)[n] % m
    elif n % 2 == 0:
        a = fbmodl(n // 2 - 1, m)
        b = fbmodl(n // 2, m)
        return ((2 * a + b) * b) % m
    else:
        a = fbmodl(n // 2, m)
        b = fbmodl(n // 2 + 1, m)
        return (a * a + b * b) % m

n,m = sys.stdin.readline().split(' ')
print(fbmodl(n,m))