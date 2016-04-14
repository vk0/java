# # -*- coding: utf-8 -*-
# .intersection()
# The .intersection() operator returns the intersection of a set and the set of elements in an iterable.
# Sometimes, the & operator is used in place of the .intersection() operator, but it only operates on the set of elements in set.
# The set is immutable to the .intersection() operation (or & operation).

# >>> s = set("Hacker")
# >>> print s.intersection("Rank")
# set(['a', 'k'])

# >>> print s.intersection(set(['R', 'a', 'n', 'k']))
# set(['a', 'k'])

# >>> print s.intersection(['R', 'a', 'n', 'k'])
# set(['a', 'k'])

# >>> print s.intersection(enumerate(['R', 'a', 'n', 'k']))
# set([])

# >>> print s.intersection({"Rank":1})
# set([])

# >>> s & set("Rank")
# set(['a', 'k'])
# Task
# The students of District College have subscriptions to English and French newspapers. Some students have subscribed only to English, some have subscribed only to French, and some have subscribed to both newspapers.

# You are given two sets of student roll numbers. One set has subscribed to the English newspaper, one set has subscribed to the French newspaper. Your task is to find the total number of students who have subscribed to both newspapers.

# Input Format

# The first line contains nn, the number of students who have subscribed to the English newspaper.
# The second line contains nn space separated roll numbers of those students.
# The third line contains bb, the number of students who have subscribed to the French newspaper.
# The fourth line contains bb space separated roll numbers of those students.

# Constraints

# 0<Total number of students in college<10000<Total number of students in college<1000
# Output Format

# Output the total number of students who have subscriptions to both English and French newspapers.

# Sample Input

# 9
# 1 2 3 4 5 6 7 8 9
# 9
# 10 1 2 3 11 21 55 6 8
# Sample Output

# 5
# Explanation

# The roll numbers of students who have both subscriptions:
# 1,2,3,61,2,3,6 and 88.
# Hence, the total is 55 students.

en = input()
es = set(map(int,input().split()))
fn = input()
fs = set(map(int,input().split()))
print(len(es.intersection(fs)))
