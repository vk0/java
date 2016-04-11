# -*- coding: utf-8 -*-
# Given a time in AM/PM format, convert it to military (2424-hour) time.

# Note: Midnight is 12:00:00AM12:00:00AM on a 1212-hour clock, and 00:00:0000:00:00 on a 2424-hour clock. Noon is 12:00:00PM12:00:00PM on a 1212-hour clock, and 12:00:0012:00:00 on a 2424-hour clock.

# Input Format

# A single string containing a time in 1212-hour clock format (i.e.: hh:mm:ssAMhh:mm:ssAM or hh:mm:ssPMhh:mm:ssPM), where 01≤hh≤1201≤hh≤12.

# Output Format

# Convert and print the given time in 2424-hour format, where 00≤hh≤2300≤hh≤23.

# Sample Input

# 07:05:45PM
# Sample Output

# 19:05:45

import sys

def format_input():
    return sys.stdin.read()

def convert_time(t):
    converted_time = ''
    if t[8] == 'P' and int(t[:2]) <= 12:
        if t[:2] == '12':
            converted_time += t[:8]
        else:
            converted_time += (str(12 + int(t[:2])) + t[2:8])
    else:
        if t[:2] == '12':
            converted_time += ('00' + t[2:8])
        else:
            converted_time += t[:8]
    return converted_time

print(convert_time(format_input()))