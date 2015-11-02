# Simple recursive algorithm

n=int(input())
def fib(n):
    if (n <= 1):
        return n
    else:
        return (fib(n-1)+fib(n-2))

print(fib(n))