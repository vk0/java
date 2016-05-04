# -*- coding: utf-8 -*-
# Objective
# Today's challenge puts your understanding of nested conditional statements to the test. You already have the knowledge to complete this challenge, but check out the Tutorial tab for a video on testing!

# Task
# Your local library needs your help! Given the expected and actual return dates for a library book, create a program that calculates the fine (if any). The fee structure is as follows:

# If the book is returned on or before the expected return date, no fine will be charged (i.e.: fine=0)fine=0).
# If the book is returned after the expected return day but still within the same calendar month and year as the expected return date, fine=15 Hackos × (the number of days late)fine=15 Hackos × (the number of days late).
# If the book is returned after the expected return month but still within the same calendar year as the expected return date, the fine=500 Hackos × (the number of months late)fine=500 Hackos × (the number of months late).
# If the book is returned after the calendar year in which it was expected, there is a fixed fine of 10000 Hackos10000 Hackos.
# Input Format

# The first line contains 33 space-separated integers denoting the respective dayday, monthmonth, and yearyear on which the book was actually returned.
# The second line contains 33 space-separated integers denoting the respective dayday, monthmonth, and yearyear on which the book was expected to be returned (due date).

# Constraints

# 1≤D≤311≤D≤31
# 1≤M≤121≤M≤12
# 1≤Y≤30001≤Y≤3000
# It is guaranteed that the dates will be valid Gregorian calendar dates.It is guaranteed that the dates will be valid Gregorian calendar dates.
# Output Format

# Print a single integer denoting the library fine for the book received as input.

# Sample Input

# 9 6 2015
# 6 6 2015
# Sample Output

# 45
# Explanation

# Given the following return dates:
# Actual: Da=9,Ma=6,Ya=2015Da=9,Ma=6,Ya=2015
# Expected: De=6,Me=6,Ye=2015De=6,Me=6,Ye=2015
# Because Ye≡YaYe≡Ya, we know it is less than a year late.
# Because Me≡MaMe≡Ma, we know it's less than a month late.
# Because De<DaDe<Da, we know that it was returned late (but still within the same month and year).

# Per the library's fee structure, we know that our fine will be 15 Hackos × (# days late)15 Hackos × (# days late). We then print the result of 15×(Da−De)=15×(9−6)=4515×(Da−De)=15×(9−6)=45 as our output.