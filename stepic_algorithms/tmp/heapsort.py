class Heap(object):
    def __init__(self):
        self.size = 0
        self.e = []
        self.e.append(0)

    def insert(self, value):
        self.e.append(value)
        self.size += 1
        self.swift_up(self.size)

    def swift_up(self, idx):
        while idx > 1 and self.greater(idx//2, idx):
            self.exch(idx, idx//2)
            idx = idx//2

    def swift_down(self, idx):
        while 2*idx <= self.size:
            j = 2*idx
            
            if j < self.size and self.greater(j,j+1): j += 1

            if self.greater(j, idx): break

            self.exch(idx, j)
            idx = j

    def del_min(self):
        self.exch(1, self.size)
        item = self.e.pop()
        self.size -= 1
        self.swift_down(1)
        return item

    def greater(self, i, j):
        return self.e[i] > self.e[j]

    def exch(self, i, j):
        self.e[i], self.e[j] = self.e[j], self.e[i]

    def is_empty(self):
        return self.size == 0

def heapsort(array):
    h = Heap()
    for i in array:
        h.insert(i)

    sorted = []
    while not h.is_empty():
        sorted.append(h.del_min())

    return sorted

if __name__ == '__main__':
    n = int(input())
    numbers = map(int, input().split())
    result = heapsort(numbers)

    for i in result:
        print(i)
