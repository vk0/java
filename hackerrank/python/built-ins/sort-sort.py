# -*- coding: utf-8 -*-
# You are given data in a tabular format. The data contains NN rows, and each row contains MM space separated elements.

# You can imagine the MM items to be different attributes, (like height, weight, energy, etc.) and each of the NN rows as an instance or a sample.

# Your task is to sort the table on the KKth attribute and print the final resulting table.

# Note: If two attributes are the same for different rows, print the row that appeared first in the input.

# Input Format

# The first line contains NN and MM separated by a space.
# The next NN lines each contain MM elements.
# The last line contains KK.

# Constraints

# 1≤N,M≤10001≤N,M≤1000
# 0≤K<M0≤K<M
# Each element ≤1000≤1000
# Output Format

# Print the NN lines of the sorted table. Each line should contain the space separated elements. Check the sample below for clarity.

# Sample Input

# 5 3
# 10 2 5
# 7 1 0
# 9 9 9
# 1 23 12
# 6 5 9
# 1
# Sample Output

# 7 1 0
# 10 2 5
# 6 5 9
# 9 9 9
# 1 23 12
# Explanation

# The table is sorted on the second attribute shown as K=1K=1 because it's 00-indexed.

n, m = map(int, input().split())
l = [list(map(int, input().split())) for _ in range(n)]
k = int(input())
l.sort(key = lambda x: x[k])
for i in l:
    print(" ".join(map(str, i)))