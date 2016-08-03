# Uses python3
import sys

def get_change(n):
    for i in [10,5,1]:
        if n>=i:
            return n//i + get_change(n%i)
    return n

if __name__ == '__main__':
    m = int(sys.stdin.read())
    print(get_change(m))
