# -*- coding: utf-8 -*-
# Реализуйте класс PositiveList, отнаследовав его от класса list, для хранения положительных целых чисел.
# Также реализуйте новое исключение NonPositiveError.

# В классе PositiveList переопределите метод append(self, x) таким образом, чтобы при попытке добавить неположительное целое число бросалось исключение NonPositiveError и число не добавлялось, а при попытке добавить положительное целое число, число добавлялось бы как в стандартный ﻿list.

# В данной задаче гарантируется, что в качестве аргумента x метода append всегда будет передаваться целое число.

class NonPositiveError(Exception):
    pass

class PositiveList(list):
    def __init__(self):
        list.__init__(self)

    def append(self, x):
        if x > 0:
            list.append(self, x)
        else:
            raise NonPositiveError