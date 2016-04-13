# -*- coding: utf-8 -*-
# Напишите реализацию функции closest_mod_5, принимающую в качестве единственного аргумента целое число x и возвращающую самое маленькое целое число y, такое что:

#     y больше или равно x
#     y делится нацело на 5

# Формат того, что ожидается от вас в качестве ответа:

# def closest_mod_5(x):
#     if x % 5 == 0 and => x:
#         return x
#     return "I don't know :("

def closest_mod_5(x):
    if x % 5 == 0:
        return int(x)
    else:
        while x % 5 != 0:
            x = x + 1
        return int(x)

print(closest_mod_5(51))