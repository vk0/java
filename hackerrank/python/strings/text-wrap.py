# -*- coding: utf-8 -*-
# Textwrap

# The textwrap module provides two convenient functions: wrap() and fill().

# textwrap.wrap()
# The wrap() function wraps a single paragraph in text (a string) so that every line is width characters long at most.
# It returns a list of output lines.

# >>> import textwrap
# >>> string = "This is a very very very very very long string."
# >>> print textwrap.wrap(string,8)
# ['This is', 'a very', 'very', 'very', 'very', 'very', 'long', 'string.']
# textwrap.fill()
# The fill() function wraps a single paragraph in text and returns a single string containing the wrapped paragraph.

# >>> import textwrap
# >>> string = "This is a very very very very very long string."
# >>> print textwrap.fill(string,8)
# This is
# a very
# very
# very
# very
# very
# long
# string.
# Task

# You are given a string SS and width ww.
# Your task is to wrap the string into a paragraph of width ww.

# Input Format

# The first line contains a string, SS.
# The second line contains the width, ww.

# Constraints

# 0<len(S)<10000<len(S)<1000
# 0<w<len(S)0<w<len(S)
# Output Format

# Print the text wrapped paragraph.

# Sample Input

# ABCDEFGHIJKLIMNOQRSTUVWXYZ
# 4
# Sample Output

# ABCD
# EFGH
# IJKL
# IMNO
# QRST
# UVWX
# YZ

import textwrap
string = input()
k = int(input())
print(textwrap.fill(string,k))

# without using textwrap
# string = input().strip()
# k = int(input())
# for i in range(0,len(string)+1,k):
#     print(string[i:k+i])