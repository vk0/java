# Uses python3
import sys

def optimal_summands(n):
    summands = [1]
    A = 2
    B = 3
    while B<=n:
        summands.append(A)
        A+=1
        B+=A
    summands[-1] += n-(B-A)
    return summands

if __name__ == '__main__':
    input = sys.stdin.read()
    n = int(input)
    summands = optimal_summands(n)
    print(len(summands))
    for x in summands:
        print(x, end=' ')
