# // Задача на программирование: сортировка подсчётом


# // Первая строка содержит число 1≤n≤104, вторая — n натуральных чисел, не превышающих 10. Выведите упорядоченную по неубыванию последовательность этих чисел.

# // Sample Input:

# // 5
# // 2 3 9 2 9

# // Sample Output:

# // 2 2 3 9 9

import sys

input = sys.stdin
n = int(input.readline())
arr = list(map(int, input.readline().split()))
arr.sort()
for i in range(len(arr)):
    print(arr[i], end=" ")
