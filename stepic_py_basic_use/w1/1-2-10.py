# -*- coding: utf-8 -*-
# Реализуйте программу, которая будет вычислять количество различных объектов в списке.
# Два объекта a и b считаются различными, если a is b равно False.

# Вашей программе доступна переменная с названием objects, которая ссылается на список, содержащий не более 100 объектов. Выведите количество различных объектов в этом списке.

# Формат ожидаемой программы:﻿


# ans = 0
# for obj in objects: # доступная переменная objects
#     ans += 1
# print(ans)

def unique(list):
    uniq=[]
    for i in list:
        k=0
        for j in uniq:
            if i is j:
                k=1
                break;
        if k==0:
            uniq.append(i)
    return len(uniq)

print(unique(objects))