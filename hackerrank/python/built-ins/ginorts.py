# -*- coding: utf-8 -*-
# You are given a string SS.
# SS contains alphanumeric characters only.
# Your task is to sort the string SS in the following manner:

# All sorted lowercase letters are ahead of uppercase letters.
# All sorted uppercase letters are ahead of digits.
# All sorted odd digits are ahead of sorted even digits.
# Input Format

# A single line of input contains the string SS.

# Constraints

# 0<len(S)<10000<len(S)<1000
# Output Format

# Output the sorted string SS.

# Sample Input

# Sorting1234
# Sample Output

# ginortS1324
# Note:
# a) Using join, for or while anywhere in your code, even as substrings, will result in a score of 0.
# b) You can only use oneone sorted function in your code. A 0 score will be awarded for using sorted more than once.

# Hint: Success is not the key, but keykey is success.

s=input().strip()
def proxys(s):
    if s.islower():
        return ord(s)
    elif s.isupper():
        return ord(s)*100
    elif s in '13579':
        return ord(s) * 1000
    else:
        return ord(s) * 10000000
print(*sorted(s,key=proxys),sep='')