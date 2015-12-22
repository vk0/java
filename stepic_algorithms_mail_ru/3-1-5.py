# Реализуйте сортировку вставками массива целых чисел.

# Количество чисел в массиве определяется окончанием стандартного потока ввода и заранее не известно.

# Sample Input:

# 3 1 2

# Sample Output:

# 1 2 3

import sys

def insertion_sort(arrayToSort):
    a = arrayToSort
    for i in range(len(a)):
        v = a[i]
        j = i;
        while (a[j-1] > v) and (j > 0):
            a[j] = a[j-1]
            j = j - 1
        a[j] = v
        # print(a)
    return a

input = sys.stdin
arr = list(map(int, input.readline().split()))
for i in range(len(insertion_sort(arr))):
    print(arr[i], end=" ")
