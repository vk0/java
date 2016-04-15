# -*- coding: utf-8 -*-
# itertools.combinations(iterable, r)
# This tool returns the rr length subsequences of elements from the input iterable.

# Combinations are emitted in lexicographic sorted order. So, if the input iterable is sorted, the combination tuples will be produced in sorted order.

# Sample Code

# >>> from itertools import combinations
# >>>
# >>> print list(combinations('12345',2))
# [('1', '2'), ('1', '3'), ('1', '4'), ('1', '5'), ('2', '3'), ('2', '4'), ('2', '5'), ('3', '4'), ('3', '5'), ('4', '5')]
# >>>
# >>> A = [1,1,3,3,3]
# >>> print list(combinations(A,4))
# [(1, 1, 3, 3), (1, 1, 3, 3), (1, 1, 3, 3), (1, 3, 3, 3), (1, 3, 3, 3)]
# Task

# You are given a string SS.
# Your task is to print all possible combinations, up to size kk, of the string in lexicographic sorted order.

# Input Format

# A single line containing the string SS and integer value kk separated by a space.

# Constraints

# 0<k≤len(S)0<k≤len(S)
# The string contains only UPPERCASE characters.

# Output Format

# Print the different combinations of string SS on separate lines.

# Sample Input

# HACK 2
# Sample Output

# A
# C
# H
# K
# AC
# AH
# AK
# CH
# CK
# HK

from itertools import combinations
inpt = input().split()
for i in range(1, int(inpt[1]) + 1):
    l = sorted(list(combinations(sorted(inpt[0]), i)))
    print('\n'.join(''.join(elems) for elems in l))