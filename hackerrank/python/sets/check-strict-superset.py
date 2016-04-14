# -*- coding: utf-8 -*-
# You are given one set AA and a number of other sets, NN.
# Your job is to find whether set AA is a strict superset of all the NN sets.
# Print True, if AA is a strict superset of all of the NN sets. Otherwise, print False.

# A strict superset has at least one element that does not exist in its subset.

# Example:
# Set([1,3,4])([1,3,4]) is a strict superset of set([1,3])([1,3]).
# Set([1,3,4])([1,3,4]) is not a strict superset of set([1,3,4])([1,3,4]).
# Set([1,3,4])([1,3,4]) is not a strict superset of set([1,3,5])([1,3,5]).

# Input Format

# The first line contains the space separated elements of set AA.
# The second line contains integer NN, the number of other sets.
# The next NN lines contains the space separated elements of the other sets.

# Constraints

# 0<len(set(A))<5010<len(set(A))<501
# 0<N<210<N<21
# 0<len(otherSets)<1010<len(otherSets)<101

# Output Format

# Print True if set AA is a strict superset of all other NN sets. Otherwise, print False.

# Sample Input

# 1 2 3 4 5 6 7 8 9 10 11 12 23 45 84 78
# 2
# 1 2 3 4 5
# 100 11 12
# Sample Output

# False
# Explanation

# Set AA is the strict superset of the set([1,2,3,4,5])([1,2,3,4,5]) but not of the set([100,11,12])([100,11,12]) because 100100 is not in set AA.
# Hence, the output is False.

A, n = set(input().split()), int(input())
flag = True
for i in range(n):
    newSet = set(input().split())
    if not (A > newSet):
        flag = False
        break
print(flag)