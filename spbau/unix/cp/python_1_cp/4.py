import sys

__author__ = 'luckyman'

number = sys.stdin.readline()
if number.strip():
    num = int(number.strip())
    yes = 1
    while num > 2:
        ost = num%2
        if not ost:
            num /= 2
        else:
            yes = 0
            break
    if yes:
        print "YES"
    else:
        print "NO"