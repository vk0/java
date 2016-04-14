# -*- coding: utf-8 -*-
# You are given two sets, AA and BB.
# Your job is to find whether set AA is a subset of set BB.

# If set AA is subset of set BB, print True.
# If set AA is not a subset of set BB, print False.

# Input Format

# The first line will contain the number of test cases, TT.
# The first line of each test case contains the number of elements in set AA.
# The second line of each test case contains the space separated elements of set AA.
# The third line of each test case contains the number of elements in set BB.
# The fourth line of each test case contains the space separated elements of set BB.

# Constraints

# 0<T<210<T<21
# 0<Number of elements in each set<10010<Number of elements in each set<1001
# Output Format

# Output True or False for each test case on separate lines.

# Sample Input

# 3
# 5
# 1 2 3 5 6
# 9
# 9 8 5 6 3 2 1 4 7
# 1
# 2
# 5
# 3 6 5 4 1
# 7
# 1 2 3 5 6 8 9
# 3
# 9 8 2
# Sample Output

# True
# False
# False
# Explanation

# Test Case 01 Explanation

# Set AA = {1 2 3 5 6}
# Set BB = {9 8 5 6 3 2 1 4 7}
# All the elements of set AA are elements of set BB.
# Hence, set AA is a subset of set BB.


# Note: More than 4 lines will result in a score of zero. Blank lines won't be counted.

for i in range(int(input())): #More than 4 lines will result in 0 score. Blank lines won't be counted.
    a = int(input()); A = set(input().split())
    b = int(input()); B = set(input().split())
    print(not bool(A.difference(B)))
