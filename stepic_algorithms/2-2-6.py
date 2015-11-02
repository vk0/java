# -*- coding: utf-8 -*-
# Задача на программирование: небольшое число Фибоначчи
# Дано целое число 1≤n≤40, необходимо вычислить n-е число Фибоначчи (напомним, что F0=0, F1=1 и Fn=Fn−1+Fn−2 при n≥2).

# Sample Input:

# 3

# Sample Output:

# 2

n=int(input())
def fib(n):
    fb = [0,1]
    i = 2
    while i <=n:
        fb.append(fb[i-1]+fb[i-2])
        i += 1
    return fb[n]

print(fib(n))