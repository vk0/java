# -*- coding: utf-8 -*-
# Какие числа будут выведены на экран в результате выполнения данного кода?
x, y = 1, 2

def foo():
    global y
    if y == 2:
        x = 2
        y = 1

foo()
print(x)
if y == 1:
    x = 3
print(x)

# 1,3