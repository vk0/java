# https://github.com/superbobry/rcviz

def fib1(n):
    assert n >= 0
    return n if n <= 1 else fib1(n - 1) + fib1(n - 2)

print(fib1(8))