# Uses python3

def calc_fib(n):
    fb = [0,1]
    i = 2
    while i <=n:
        fb.append(fb[i-1]+fb[i-2])
        i += 1
    return fb[n]

# def calc_fib(n):
#     if (n <= 1):
#         return n
#     return calc_fib(n - 1) + calc_fib(n - 2)

n = int(input())
print(calc_fib(n))
