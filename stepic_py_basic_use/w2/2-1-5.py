# -*- coding: utf-8 -*-
# Вашей программе будет доступна функция foo, которая может бросать исключения.

# Вам необходимо написать код, который запускает эту функцию, затем ловит исключения ArithmeticError, AssertionError, ZeroDivisionError и выводит имя пойманного исключения.

# Пример решения, которое вы должны отправить на проверку.

# try:
#     foo()
# except Exception:
#     print("Exception")
# except BaseException:
#     print("BaseException")

# Подсказка: https://docs.python.org/3/library/exceptions.html#exception-hierarchy

try:
    foo()
except ArithmeticError as e:
    if e.__class__.__name__ in ("ZeroDivisionError"):
        print(e.__class__.__name__)
    else:
        print("ArithmeticError")
except AssertionError as e:
    print(e.__class__.__name__)