# https://github.com/superbobry/rcviz

cache = {}

def fib2(n):
    assert n >= 0
    if n not in cache:
        cache[n] = n if n <= 1 else fib2(n - 1) + fib2(n - 2)
    return cache[n]

print(fib2(8))