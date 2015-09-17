from sys import stdin
from math import ceil, log
from decimal import Decimal as d

class RMQ(object):
    def __init__(self, numbers):
        self.e = []
        n = len(numbers)
        
        if (n & (n-1))!=0:
            x = ceil(log(n, 2))
            self.n = 2**x;

            while n != self.n:
                numbers.append(d('Infinity'))
                n += 1
        else: self.n = n
        
        temp = numbers[::-1]

        for i in range(0, 2*(self.n-1), 2):
            temp.append(min(temp[i], temp[i+1]))

        temp.append(d('Infinity'))
        self.e = temp[::-1]
        self.size = len(temp)
      
    def recover(self, idx):
        while idx > 1:
            parent = idx//2
            self.e[parent] = min(self.e[2*parent], self.e[2*parent+1])
            idx = parent
  
    def min(self, left, right, begin = 1, end = None, idx = 1):
        if end is None: end = self.n

        if left==begin and right==end:
            return self.e[idx]

        mid = (begin + end) // 2

        if left >= begin and right <= mid:
            return self.min(left, right, begin, mid, 2*idx)
        elif left > mid and right <= end:
            return self.min(left, right, mid+1, end, 2*idx+1)
        else:
            left_child = self.min(left, mid, begin, mid, 2*idx)
            right_child = self.min(mid+1, right, mid+1, end, 2*idx+1)
            return min(left_child, right_child)
  
    def set(self, origin, value):
        idx = self.size//2+origin-1
        self.e[idx] = value
        self.recover(idx)
  
    
if __name__ == '__main__':

    f = open('source/rmq2.txt', 'r')
    n, m = map(int, f.readline().split())
    numbers = list(map(int, f.readline().split()))
    rmq = RMQ(numbers)

    for i in range(0, m):
        c, x, y = f.readline().split()

        if c == 'Min':
          print(rmq.min(int(x), int(y)))
        elif c == 'Set':
          rmq.set(int(x), int(y))
