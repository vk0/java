# -*- coding: utf-8 -*-
# The defaultdict tool is a container in the collections class of Python. It's similar to the usual dictionary (dict) container, but it has one difference: The value fields' data type is specified upon initialization.
# For example:

# from collections import defaultdict
# d = defaultdict(list)
# d['python'].append("awesome")
# d['something-else'].append("not relevant")
# d['python'].append("language")
# for i in d.items():
#     print i
# This prints:

# ('python', ['awesome', 'language'])
# ('something-else', ['not relevant'])
# In this challenge, you will be given 22 integers, nn and mm. There are nn words, which might repeat, in word group AA. There are mm words belonging to word group BB. For each mm words, check whether the word has appeared in group AA or not. Print the indices of each occurrence of mm in group AA. If it does not appear, print −1−1.

# Constraints
# 1≤n≤100001≤n≤10000
# 1≤m≤1001≤m≤100
# 1≤ length of each word in the input≤1001≤ length of each word in the input≤100
# Input Format

# The first line contains integers, nn and mm separated by a space.
# The next nn lines contains the words belonging to group AA.
# The next mm lines contains the words belonging to group BB.

# Output Format

# Output mm lines.
# The ithith line should contain the 11-indexed positions of the occurrences of the ithith word separated by spaces.

# Sample Input

# 5 2
# a
# a
# b
# a
# b
# a
# b
# Sample Output

# 1 2 4
# 3 5
# Explanation

# 'a' appeared 33 times in positions 11, 22 and 44.
# 'b' appeared 22 times in positions 33 and 55.
# In the sample problem, if 'c' also appeared in word group BB, you would print −1−1.

from collections import defaultdict

n, m = [int(x) for x in input().split()]
d = defaultdict(list)

for i in range(n+m):
    if i < n:
        d[input().strip()].append(i + 1)
    else:
        w = input().strip()
        print(" ".join([str(x) for x in d[w]]) if w in d else -1)