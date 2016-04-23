#!/bin/python3

# Maria loves playing soccer. Because she wants to play professionally when she grows up, she tracks her training by marking her calendar with a 11 on the days that she trained, and a 00 on the days she did not. She also loves math, and wants your help connecting her soccer training with what she's learning about even and odd numbers in school.

# Given nn days of Maria's calendar history, print whether or not she trained for an even number of days (either YesYes or NoNo), followed by the total number of days she trained.

# Note: Code demonstrating how to read input from stdin is provided in your editor.

# Input Format

# The first line contains an integer, nn, denoting the number of days Maria tracked in her calendar.
# The next line contains nn space-separated integers describing whether or not Maria trained each day. Recall that the number 11 indicates that she did train, and 00 indicates she did not.

# Constraints

# 1≤n≤1051≤n≤105
# Output Format

# Your output should consist of 22 space-separated values on a single line. For the first value, you should print YesYes if Maria trained for an even number of days or NoNo if she did not. For the second value, you should print a single integer denoting the total number of days Maria trained.

# Sample Input 0

# 4
# 1 1 0 0
# Sample Output 0

# Yes 2
# Sample Input 1

# 4
# 1 0 1 1
# Sample Output 1

# No 3
# Explanation

# Sample 0:
# n=4,calendar="1 1 0 0"n=4,calendar="1 1 0 0"
# Maria trained on 22 days; because this is an even number, we print Yes 2Yes 2.

# Sample 1:
# n=4,calendar="1 0 1 1"n=4,calendar="1 0 1 1"
# Maria trained on 33 days; because this is an odd number, we print No 3No 3.

import sys

n = int(input().strip())
a = [int(a_temp) for a_temp in input().strip().split(' ')]

dc = a.count(1)
if dc % 2 == 0:
    print("Yes " + str(dc))
else:
    print("No " + str(dc))