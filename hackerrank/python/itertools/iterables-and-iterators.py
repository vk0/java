# -*- coding: utf-8 -*-
# The itertools module standardizes a core set of fast, memory efficient tools that are useful by themselves or in combination. Together, they form an iterator algebra making it possible to construct specialized tools succinctly and efficiently in pure Python.

# To read more about the functions in this module, check out their documentation here.

# You are given a list of NN lowercase English letters. For a given integer KK, you can select any KK indices (assume 11-based indexing) with a uniform probability from the list.

# Find the probability that at least one of the KK indices selected will contain the letter: 'aa'.

# Input Format

# The input consists of three lines. The first line contains the integer NN, denoting the length of the list. The next line consists of NN space-separated lowercase English letters, denoting the elements of the list.

# The third and the last line of input contains the integer KK, denoting the number of indices to be selected.

# Output Format

# Output a single line consisting of the probability that at least one of the KK indices selected contains the letter:'aa'.

# Note: The answer must be correct up to 3 decimal places.

# Constraints

# 1≤N≤101≤N≤10
# 1≤K≤N1≤K≤N
# All the letters in the list are lowercase English letters.

# Sample Input

# 4
# a a c d
# 2
# Sample Output

# 0.8333
# Explanation

# All possible unordered tuples of length 22 comprising of indices from 11 to 44 are:

# (1,2),(1,3),(1,4),(2,3),(2,4),(3,4)(1,2),(1,3),(1,4),(2,3),(2,4),(3,4)

# Out of these 66 combinations, 55 of them contain either index 11 or index 22 which are the indices that contain the letter 'aa'.

# Hence, the answer is 5656.

from itertools import combinations
n=input()
l=input().split()
r=int(input())
l=list(combinations(list(l),r))
c=0
for i in l:
    i=list(i)
    for j in i:
        if j=='a':
            c+=1
            break
print(c/len(l))