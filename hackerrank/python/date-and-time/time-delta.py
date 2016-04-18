# -*- coding: utf-8 -*-
# Timestamps are given in the format:

# Day dd Mon yyyy hh:mm:ss +xxxx

# Here +xxxx represents the time zone. See the sample below for details.

# Task
# Given 22 timestamps, print the absolute difference (in seconds) between them.

# Input Format
# The first line contains TT, the number of testcases.
# Each testcase contains 22 lines, representing time t1t1 and time t2t2.

# Output Format
# Print the absolute difference (t1−t2)(t1−t2) in seconds.

# Constraints
# It is guaranteed that the input contains only valid timestamps, and the year can reach up to 30003000.

# Sample Input

# 2
# Sun 10 May 2015 13:54:36 -0700
# Sun 10 May 2015 13:54:36 +0000
# Sat 02 May 2015 19:54:36 +0530
# Fri 01 May 2015 13:54:36 +0000
# Sample Output

# 25200
# 88200

from datetime import datetime

FMT = "%a %d %b %Y %H:%M:%S %z"
for _ in range(int(input())):
    t1 = datetime.strptime(input(), FMT)
    t2 = datetime.strptime(input(), FMT)
    print(abs(int((t1-t2).total_seconds())))