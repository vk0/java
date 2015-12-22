# Дана последовательность целых чисел a[0..n-1] и натуральное число k, такое что для любых i, j: если j >= i + k, то a[i] <= a[j]. Требуется отсортировать последовательность. Последовательность может быть очень длинной. Время работы O(n * log(k)). Доп. память O(k).

# Использовать слияние.

# Sample Input:

# 20
# 3 4 1 2 0 9 7 8 6 5 11 12 13 10 14 18 19 16 17 15
# 10

# Sample Output:

# 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19

import sys

def mergeSort(alist):
    # print("Splitting ",alist)
    if len(alist)>1:
        mid = len(alist)//2
        lefthalf = alist[:mid]
        righthalf = alist[mid:]

        mergeSort(lefthalf)
        mergeSort(righthalf)

        i=0
        j=0
        k=0
        while i<len(lefthalf) and j<len(righthalf):
            if lefthalf[i]<righthalf[j]:
                alist[k]=lefthalf[i]
                i=i+1
            else:
                alist[k]=righthalf[j]
                j=j+1
            k=k+1

        while i<len(lefthalf):
            alist[k]=lefthalf[i]
            i=i+1
            k=k+1

        while j<len(righthalf):
            alist[k]=righthalf[j]
            j=j+1
            k=k+1
    # print("Merging ",alist)

input = sys.stdin
n = int(input.readline())
arr = list(map(int, input.readline().split()))
m = int(input.readline())
mergeSort(arr)
for i in range(len(arr)):
    print(arr[i], end=" ")
