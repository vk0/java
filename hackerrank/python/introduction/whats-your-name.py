# -*- coding: utf-8 -*-
# Let's learn the basics of Python! You are given the first and last name of a person. Your task is to read them and print the following:

# Hello firstname lastname! You just delved into python.
# It's that simple!

# In Python, you can read a line as a string using:

# s = raw_input()
# #here s reads the whole line.
# Input Format
# The first line contains the first name, and the second line contains the last name.

# Constraints
# The length of the first and last name ≤ 1010.

# Output Format
# Print the output as mentioned above.

# Sample Input

# Guido
# Rossum
# Sample Output

# Hello Guido Rossum! You just delved into python.
# Concept
# The input read by the program is stored as a string data type. A string is a collection of characters.

firstname = raw_input()
lastname = raw_input()
print("Hello " + firstname + " " + lastname + "!" + " You just delved into python.")

# print "Hello {0} {1}! You just delved into python.".format(raw_input(), raw_input())
