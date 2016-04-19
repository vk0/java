# -*- coding: utf-8 -*-
# You are given an integer NN followed by NN email addresses. Your task is to print a list containing only valid email addresses in lexicographical order.


# Valid email addresses must follow these rules:

# It must have the username@websitename.extension format type.
# The username can only contain letters, digits, dashes and underscores.
# The website name can only have letters and digits.
# The maximum length of the extension is 33.

# Concept

# A filter takes a function returning True or False and applies it to a sequence, returning a list of only those members of the sequence where the function returned True. A Lambda function can be used with filters.

# Let's say you have to make a list of the squares of integers from 00 to 99 (both included).

# >> l = list(range(10))
# >> l = list(map(lambda x:x*x, l))
# Now, you only require those elements that are greater than 1010 but less than 8080.

# >> l = list(filter(lambda x: x > 10 and x < 80, l))
# Easy, isn't it?

# Input Format

# The first line of input is the integer NN, the number of email addresses.
# NN lines follow, each containing a string.

# Constraints

# Each line is a non-empty string.

# Output Format

# Output a list containing the valid email addresses in lexicographical order. If the list is empty, just output an empty list, [].

# Sample Input

# 3
# lara@hackerrank.com
# brian-23@hackerrank.com
# britts_54@hackerrank.com
# Sample Output

# ['brian-23@hackerrank.com', 'britts_54@hackerrank.com', 'lara@hackerrank.com']

import re
lst = []
for i in range(int(input())):
    lst.append(input())
print(sorted(list(filter(lambda x: re.search(r'^[\w\d-]+@[A-Za-z0-9]+\.[a-zA-Z]{1,3}$',x),lst))))