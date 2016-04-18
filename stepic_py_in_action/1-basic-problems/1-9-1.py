# Не используя интерпретатор, попробуйте определить, что будет выведено на экран после выполнения следующего кода:

def t():
    print('true')
    return True

def f():
    print('false')
    return False

if t() and f():
    print('t and f')

if f() and t():
    print('f and t')

if t() or f():
    print('t or f')

if f() or t():
    print('f or t')


# Заполняйте поля ввода слева-направо, в каждое поле ввода вводите только одну строку реального вывода.
# true
# false
# false
# true
# t or f
# false
# true
# f or t