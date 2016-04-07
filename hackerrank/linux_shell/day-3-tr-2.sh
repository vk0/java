# # Objective
# In this challenge, we practice using the tr command because it is a useful translation tool in Linux.

# Resources
# 'e' being transformed to 'E'

# $ echo "Hello" | tr "e" "E"
# HEllo
# Spaces being transformed to hyphens

# $ echo "Hello how are you" | tr " " '-'
# Hello-how-are-you
# Digits (numerals) being deleted

# $ echo "Hello how are you 1234" | tr -d [0-9]
# Hello how are you
# Task
# In a given fragment of text, delete all the lowercase characters a−za−z.

# Input Format

# A block of ASCII text.

# Output Format

# Delete all the lowercase characters in the given block of text.

# Sample Input

# Hello
# World
# how are you
# Sample Output

# H
# W
# Recommended References

# This tutorial shows various ways that the tr command may be used for transforming or translating characters or character classes. It can also be used to delete, complement, remove or squeeze characters.

tr -d a-z