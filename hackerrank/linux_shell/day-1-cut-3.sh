# Objective
# In this challenge, we practice using the cut command to get and print characters from a file.

# Resources
# This is a very well written tutorial demonstrating different ways in which cut may be used to either print characters at a particular position, or to print columns of a text file based on delimiters. The latter is particularly useful while dealing with tabulated data in *.tsv or *.csv format.

# Task
# Display a range of characters starting at the 22ndnd position of a string and ending at the 77thth position (both positions included).

# Input Format

# A text file containing NN lines of ASCII text only.

# Constraints

# 1≤N≤1001≤N≤100
# Note: These values don't really impact your command.

# Output Format

# The output should contain NN lines.
# Each line should contain the range of characters starting at the 22ndnd position of a string and ending at the 77thth position (both positions included).

# Sample Input

# Hello
# World
# how are you
# Sample Output

# ello
# orld
# ow are

cut -c 2-7