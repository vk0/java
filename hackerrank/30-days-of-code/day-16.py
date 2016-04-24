# -*- coding: utf-8 -*-
# Objective
# Today, we're getting started with Exceptions by learning how to parse an integer from a string and print a custom error message. Check out the Tutorial tab for learning materials and an instructional video!

# Task
# Read a string, SS, and print its integer value; if SS cannot be converted to an integer, print Bad StringBad String.

# Note: You must use the String-to-Integer and exception handling constructs built into your submission language. If you attempt to use loops/conditional statements, you will get a 00 score.

# Input Format

# A single string, SS.

# Constraints

# 1≤|S|≤61≤|S|≤6, where |S||S| is the length of string SS.
# SS is composed of either lowercase letters (a−za−z) or decimal digits (0−90−9).
# Output Format

# Print the parsed integer value of SS, or Bad StringBad String if SS cannot be converted to an integer.

# Sample Input 0

# 3
# Sample Output 0

# 3
# Sample Input 1

# za
# Sample Output 1

# Bad String
# Explanation

# Sample Case 00 contains an integer, so it should not raise an exception when we attempt to convert it to an integer. Thus, we print the 33
# Sample Case 11 does not contain any integers, so an attempt ot convert it to an integer will raise an exception. Thus, our exception handler prints Bad StringBad String.

#!/bin/python3

s = input().strip()
try:
    print(int(s))
except ValueError:
    print("Bad String")