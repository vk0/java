# Задача на программирование: непрерывный рюкзак


# Первая строка содержит количество предметов 1≤n≤103 и вместимость рюкзака 0≤W≤2⋅106. Каждая из следующих n строк задаёт стоимость 0≤ci≤2⋅106 и объём 0<wi≤2⋅106 предмета (n, W, ci, wi — целые числа). Выведите максимальную стоимость частей предметов (от каждого предмета можно отделить любую часть, стоимость и объём при этом пропорционально уменьшатся), помещающихся в данный рюкзак, с точностью не менее трёх знаков после запятой.

# Sample Input:

# 3 50
# 60 20
# 100 50
# 120 30

# Sample Output:

# 180.000

import sys
def knapsack(items, maxweight):
    bestvalues = [[0] * (maxweight + 1)
                  for i in range(len(items) + 1)]
    for i, (value, weight) in enumerate(items):
        i += 1
        for capacity in range(maxweight + 1):
            if weight > capacity:
                bestvalues[i][capacity] = bestvalues[i - 1][capacity]
            else:
                candidate1 = bestvalues[i - 1][capacity]
                candidate2 = bestvalues[i - 1][capacity - weight] + value
                bestvalues[i][capacity] = max(candidate1, candidate2)
    reconstruction = []
    i = len(items)
    j = maxweight
    while i > 0:
        if bestvalues[i][j] != bestvalues[i - 1][j]:
            reconstruction.append(items[i - 1])
            j -= items[i - 1][1]
        i -= 1
    reconstruction.reverse()
    return bestvalues[len(items)][maxweight], reconstruction

if __name__ == '__main__':
    lines = sys.stdin.readlines()
    c, w = lines[0].split()
    maxweight = int(w)
    items = []
    for line in lines[1:]:
        item = line.split()
        items.append(item)
    items = [[int(j) for j in i] for i in items]
    bestvalue, reconstruction = knapsack(items, maxweight)
    print(format(bestvalue, '.3f'))