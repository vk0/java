# -*- coding: utf-8 -*-
# A postal code PP must be a number in the range of (100000−999999100000−999999).
# A postal code PP must not contain more than one alternating repetitive digit pair.

# Alternating repetitive digits are digits which repeat immediately after the next digit. In other words, an alternating repetitive digit pair is formed by two equal digits that have just a single digit between them.

# For example:

# 121426 # Here, 1 is an alternating repetitive digit.
# 523563 # Here, NO digit is an alternating repetitive digit.
# 552523 # Here, both 2 and 5 are alternating repetitive digits.
# Your task is to validate whether PP is a valid postal code or not.

# Input Format

# One single line of input containing the string PP.

# Output Format

# Print "True" if PP is valid. Otherwise, print "False". Do not print the quotation marks.

# Sample Input

# 110000
# Sample Output

# False
# Explanation

# 1 1 0000 : (0, 0) and (0, 0) are two alternating digit pairs. Hence, it is an invalid postal code.

# Note:
# A score of 00 will be awarded for using 'if' conditions in your code.
# You have to pass all the testcases to get a positive score.

import re
s=input().strip()
print(bool(re.search(r'^[1-9]\d{5}$', s) and len(re.findall(r'(?=(\d)\d\1)', s)) <2))
