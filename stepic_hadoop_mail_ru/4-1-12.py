# Реализуйте reducer из задачи Distinct Values v2.

# Reducer принимает на вход строки, каждая из которых состоит из разделенных табуляцией значения и названия группы.

# Sample Input:

# 1   a
# 1   b
# 1   b
# 2   a
# 2   d
# 2   e
# 3   a
# 3   b

# Sample Output:

# a   3
# d   1
# b   2
# e   1


Skip to content
This repository

    Explore
    Features
    Enterprise
    Pricing

1
0

    0

lancelote/stepic_hadoop
Code
Issues 0
Pull requests 0
Pulse
Graphs
stepic_hadoop/hw/module_4/basic_algorithms/distinct_values_4.py
9b3b5fc 11 days ago
@lancelote lancelote Reformates project structure, adds relations_functions
1 contributor
58 lines (44 sloc) 1.15 KB
# coding=utf-8

""""
Реализуйте reducer из задачи Distinct Values v2.
Reducer принимает на вход строки, каждая из которых состоит из разделенных
табуляцией значения и названия группы.
Sample Input:
    1   a
    1   b
    1   b
    2   a
    2   d
    2   e
    3   a
    3   b
Sample Output:
    a   3
    d   1
    b   2
    e   1
"""

import sys
from collections import defaultdict

categories = defaultdict(int)
categories_seen = []
previous_value = ''

for line in sys.stdin:
    value, category = line.strip().split('\t')

    # First input line
    if not previous_value:
        previous_value = value
        categories_seen.append(category)
        categories[category] += 1

    # Value did not changed
    if value == previous_value:
        if category not in categories_seen:
            categories_seen.append(category)
            categories[category] += 1

    # New value
    else:
        previous_value = value
        categories_seen = [category]
        categories[category] += 1

for category in categories.keys():
    print('%s\t%s' % (category, categories[category]))

