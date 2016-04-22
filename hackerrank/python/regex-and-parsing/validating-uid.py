# -*- coding: utf-8 -*-
# ABCXYZ company has up to 100100 employees.
# The company decides to create a unique identification number (UID) for each of its employees.
# The company has assigned you the task of validating all the randomly generated UIDs.

# A valid UID must follow the rules below:

# It must contain at least 22 uppercase English alphabet characters.
# It must contain at least 33 digits (00 - 99).
# It should only contain alphanumeric characters (aa - zz, AA - ZZ & 00 - 99).
# No character should repeat.
# There must be exactly 1010 characters in a valid UID.
# Input Format

# The first line contains an integer TT, the number of test cases.
# The next TT lines contains an employee's UID.

# Output Format

# For each test case, print 'Valid' if the UID is valid. Otherwise, print 'Invalid', on separate lines. Do not print the quotation marks.

# Sample Input

# 2
# B1CD102354
# B1CDEF2354
# Sample Output

# Invalid
# Valid
# Explanation

# B1CD102354: 11 is repeating → Invalid
# B1CDEF2354: Valid

import re
caps = re.compile('(?=[A-Z]).')
digs = re.compile('(?=[0-9]).')
chr = re.compile('^(?=[A-Za-z0-9]).{10}$')
for _ in range(int(input())):
    s = input()
    if len(set(s)) == 10 and chr.match(s) and len(digs.findall(s)) >= 3 and len(caps.findall(s)) >= 2:
        print("Valid")
    else:
        print("Invalid")