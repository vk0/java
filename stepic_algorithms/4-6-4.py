import random

def test(gcd, n_iter=100):
    for i in range(n_iter):
        c = random.randint(0, 1024)
        a = c * random.randint(0, 128)
        b = c * random.randint(0, 128)
        assert gcd(a, a) == gcd(a, 0) == a
        assert gcd(b, b) == gcd(b, 0) == b
        assert gcd(a, 1) == gcd(b, 1) == 1
        d = gcd(a,b)
        assert a % d == b % d == 0

def gcd2(a,b):
    while a and b:
        if a >= b:
            a %= b
        else:
            b %= a
    return max(a,b)

print(gcd2(8,3))
print(gcd2(8,0))
print(test(gcd2))