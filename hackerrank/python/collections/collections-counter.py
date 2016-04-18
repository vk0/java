# # -*- coding: utf-8 -*-
# collections.Counter()
# A counter is a container that stores elements as dictionary keys, and their counts are stored as dictionary values.

# Sample Code

# >>> from collections import Counter
# >>>
# >>> myList = [1,1,2,3,4,5,3,2,3,4,2,1,2,3]
# >>> print Counter(myList)
# Counter({2: 4, 3: 4, 1: 3, 4: 2, 5: 1})
# >>>
# >>> print Counter(myList).items()
# [(1, 3), (2, 4), (3, 4), (4, 2), (5, 1)]
# >>>
# >>> print Counter(myList).keys()
# [1, 2, 3, 4, 5]
# >>>
# >>> print Counter(myList).values()
# [3, 4, 4, 2, 1]
# Task

# RaghuRaghu is a shoe shop owner. His shop has XX number of shoes.
# He has a list containing the size of each shoe he has in his shop.
# There are NN number of customers who are willing to pay xixi amount of money only if they get the shoe of their desired size.

# Your task is to compute how much money RaghuRaghu earned.

# Input Format

# The first line contains XX, the number of shoes.
# The second line contains the space separated list of all the shoe sizes in the shop.
# The third line contains NN, the number of customers.
# The next NN lines contain the space separated values of the shoe sizeshoe size desired by the customer and xixi, the price of the shoe.

# Constraints

# 0<X<1030<X<103
# 0<N≤1030<N≤103
# 20<xi<10020<xi<100
# 2<shoe size<202<shoe size<20
# Output Format

# Print the amount of money earned by RaghuRaghu.

# Sample Input

# 10
# 2 3 4 5 6 8 7 6 5 18
# 6
# 6 55
# 6 45
# 6 55
# 4 40
# 18 60
# 10 50
# Sample Output

# 200
# Explanation

# Customer 1: Purchased size 6 shoe for $55.
# Customer 2: Purchased size 6 shoe for $45.
# Customer 3: Size 6 no longer available, so no purchase.
# Customer 4: Purchased size 4 shoe for $40.
# Customer 5: Purchased size 18 shoe for $60.
# Customer 6: Size 10 not available, so no purchase.

# Total money earned = 55+45+40+60=55+45+40+60=  $200
from collections import Counter

numShoes = int(input())
shoes = Counter(map(int, input().split()))
numCust = int(input())

income = 0

for i in range(numCust):
    size, price = map(int, input().split())
    if shoes[size]:
        income += price
        shoes[size] -= 1

print(income)