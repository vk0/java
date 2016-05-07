# -*- coding: utf-8 -*-
# Objective
# Today, we're working with regular expressions. Check out the Tutorial tab for learning materials and an instructional video!

# Task
# Consider a database table, Emails, which has the attributes First Name and Email ID. Given NN rows of data simulating the Emails table, print an alphabetically-ordered list of people whose email address ends in @gmail.com@gmail.com.

# Input Format

# The first line contains an integer, NN, total number of rows in the table.
# Each of the NN subsequent lines contains 22 space-separated strings denoting a person's first name and email ID, respectively.

# Constraints

# 2≤N≤302≤N≤30
# Each of the first names consists of lower case letters [a−z][a−z] only.
# Each of the email IDs consists of lower case letters [a−z][a−z], @@ and .. only.
# The length of the first name is no longer than 20.
# The length of the email ID is no longer than 50.
# Output Format

# Print an alphabetically-ordered list of first names for every user with a gmail account. Each name must be printed on a new line.

# Sample Input

# 6
# riya riya@gmail.com
# julia julia@julia.me
# julia sjulia@gmail.com
# julia julia@gmail.com
# samantha samantha@gmail.com
# tanya tanya@gmail.com
# Sample Output

# julia
# julia
# riya
# samantha
# tanya

#!/bin/python3

import sys


N = int(input().strip())
for a0 in range(N):
    firstName,emailID = input().strip().split(' ')
    firstName,emailID = [str(firstName),str(emailID)]