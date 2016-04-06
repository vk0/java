# Objective
# In this challenge, we practice using the cut command to get and print characters from a file.

# Resources
# Here's a useful video on the topic:


# Click here for a tutorial discussing the ways that cut may be used to print characters at a particular position in a file or print columns from a file of delimiter separated values. The latter is particularly useful when dealing with tabulated data (e.g.: *.tsv, *.csv, etc).

# Task
# Given NN lines of input, print the 3rd3rd character from each line as a new line of output. It is guaranteed that each of the nn lines of input will have a 3rd3rd character.

# Input Format

# A text file containing NN lines of ASCII characters.

# Constraints

# 1≤N≤1001≤N≤100
# Output Format

# For each line of input, print its 3rd3rd character on a new line for a total of NN lines of output.

# Sample Input

# Hello
# World
# how are you
# Sample Output

# l
# r
# w

cut -c 3