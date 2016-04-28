# # -*- coding: utf-8 -*-
# Вашей программе на вход подаются три строки s, a, b, состоящие из строчных латинских букв.
# За одну операцию вы можете заменить все вхождения строки a в строку s на строку b.

# Необходимо узнать, после какого минимального количества операций в строке s не останется вхождений строки a, либо же определить, что это невозможно.

# Выведите одно число – минимальное число операций, после применения которых в строке s не останется вхождений строки a.
# Если после применения любого числа операций в строке s останутся вхождения строки a, выведите Impossible﻿.

# Sample Input 1:

# ababa
# a
# b

# Sample Output 1:

# 1


# Sample Input 2:

# ababa
# b
# a

# Sample Output 2:

# 1


# Sample Input 3:

# ababa
# c
# c

# Sample Output 3:

# 0


# Sample Input 4:

# ababac
# c
# c

# Sample Output 4:

# Impossible

s, a, b = [input() for _ in range(3)]
impossible = False
count = 0

while a in s:
    s = s.replace(a, b)
    count += 1
    if count > 50:
        impossible = True
        break
if impossible:
    print('Impossible')
else:
    print(count)