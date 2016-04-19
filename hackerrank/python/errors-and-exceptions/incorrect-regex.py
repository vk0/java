# -*- coding: utf-8 -*-
# You are given a string SS.
# Your task is to find out whether SS is a valid regex or not.

# Input Format

# The first line contains integer TT, the number of test cases.
# The next TT lines contains the string SS.

# Constraints

# 0<T<1000<T<100
# Output Format

# Print "True" or "False" for each test case without quotes.

# Sample Input

# 2
# .*\+
# .*+
# Sample Output

# True
# False
# Explanation

# .*\+ : Valid regex.
# .*+: Has the error multiple repeat. Hence, it is invalid.

import re
for _ in range(int(input())):
    ans = True
    try:
        reg = re.compile(input())
    except re.error:
        ans = False
    print(ans)