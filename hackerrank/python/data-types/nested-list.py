# -*- coding: utf-8 -*-
# Let's implement a nested list! A nested list is a list that contains another list (i.e.: a list of lists). For example:

# >> a = [['blue', 'green'], ['red', 'black'], ['blue', 'white']]
# >> len(a)
# 3
# >> a[1]
# ['red', 'black']
# >> a[1][0]
# red
# To go through every element in a list, use a nested for loop.

# Given the names and grades for each student in a Physics class of NN students, store them in a nested list and print the name(s) of any student(s) having the second lowest grade.

# Note: If there are multiple students with the same grade, order their names alphabetically and print each name on a new line.

# Input Format

# The first line contains an integer, NN, the number of students.
# The 2N2N subsequent lines describe each student over 22 lines; the first line contains a student's name, and the second line contains their grade.

# Constraints

# 2≤N≤52≤N≤5
# There will always be one or more students having the second lowest grade.
# Output Format

# Print the name(s) of any student(s) having the second lowest grade in Physics; if there are multiple students, order their names alphabetically and print each one on a new line.

# Sample Input

# 5
# Harry
# 37.21
# Berry
# 37.21
# Tina
# 37.2
# Akriti
# 41
# Harsh
# 39
# Sample Output

# Berry
# Harry
# Explanation

# There are 55 students in this class whose names and grades are assembled to build the following list:

# students = [['Harry', 37.21], ['Berry', 37.21], ['Tina', 37.2], ['Akriti', 41], ['Harsh', 39]]
# The lowest grade of 37.237.2 belongs to Tina. The second lowest grade of 37.2137.21 belongs to both Harry and Berry, so we order their names alphabetically and print each name on a new line.

n = int(input())
marks = [[input(), float(input())] for _ in range(n)]
scores = sorted({s[1] for s in marks})
result = sorted(s[0] for s in marks if s[1] == scores[1])
print('\n'.join(result))