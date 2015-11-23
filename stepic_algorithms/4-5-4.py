# https://github.com/superbobry/rcviz

def memo(f):
    cache = {}

def memo(f):
    cache = {}
    def inner(n):
        if n not in cache:
            cache[n] = f(n)
        return cache[n]
    return inner

def fib1_old(n):
    assert n >= 0
    return n if n <= 1 else fib1_old(n - 1) + fib1_old(n - 2)

fib1 = memo(fib1_old)

print(fib1(80))