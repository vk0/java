# # -*- coding: utf-8 -*-
# In this task, we would like for you to appreciate the usefulness of the groupby() function of itertools . To read more about this function, Check this out .

# You are given a string SS. Suppose a character 'cc' occurs consecutively XX times in the string. Replace these consecutive occurrences of the character 'cc' with (X,c)(X,c) in the string.

# For a better understanding of the problem, check the explanation.

# Input Format

# A single line of input consisting of the string SS.

# Output Format

# A single line of output consisting of the modified string.

# Constraints

# All the characters of SS denote integers between 00 and 99.

# 1≤∣S∣≤1041≤∣S∣≤104
# Sample Input

# 1222311
# Sample Output

# (1, 1) (3, 2) (1, 3) (2, 1)
# Explanation

# First, the character 11 occurs only once. It is replaced by (1,1)(1,1). Then the character 22 occurs three times, and it is replaced by (3,2)(3,2) and so on.

# Also, note the single space within each compression and between the compressions.

from itertools import groupby
s=input()
for k, g in groupby(s):
    print(tuple((len(list(g)),int(k))),end=' '),

