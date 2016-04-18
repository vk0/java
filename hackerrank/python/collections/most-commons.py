# -*- coding: utf-8 -*-
# You are given a string SS.
# The string contains only lowercase English alphabet characters.

# Your task is to find the top three most common characters in the string SS.

# Input Format

# A single line of input containing the string SS.

# Constraints

# 3<len(S)<1043<len(S)<104
# Output Format

# Print the three most common characters along with their occurrence count each on a separate line.
# Sort output in descending order of occurrence count.
# If the occurrence count is the same, sort the characters in ascending order.

# Sample Input

# aabbbccde
# Sample Output

# b 3
# a 2
# c 2
# Explanation

# Here, b occurs 33 times. It is printed first.
# Both a and c occur 22 times. So, a is printed in the second line and c in the third line because a comes before c.

# Note: The string SS has at least 33 distinct characters.

from collections import Counter

c = Counter(input()).most_common(3)
b = sorted(c, key=lambda x: (-x[1], x[0]))
for x in range(3):
    print(b[x][0], b[x][1])