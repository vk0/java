def quicksort(a, l, r):
    if l >= r: return

    mid = partition(a, l, r)
    quicksort(a, l, mid - 1)
    quicksort(a, m + 1, r)

def partition(a, l, r):
    x = a[l]
    j = i
    

if __name__ == '__main__':
    
    numbers = map(int, input().split())
    quicksort(numbers, 0, len(numbers))
    print(numbers)
