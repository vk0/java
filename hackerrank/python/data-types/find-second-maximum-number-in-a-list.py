# -*- coding: utf-8 -*-
# Let's delve into one of the most basic data types in Python, the list. You are given NN numbers. Store them in a list and find the second largest number.

# NOTE: Do not use the insertion sort method.

# Input Format

# The first line contains NN. The second line contains an array AA[] of NN integers each separated by a space.

# Output Format

# Output the value of the second largest number.

# Sample Input

# 5
# 2 3 6 6 5
# Sample Output

# 5
# Constraints
# 2≤N≤102≤N≤10
# −100≤A[i]≤100−100≤A[i]≤100
# Concept

# A list in Python is similar to an array. A list can contain any data type as well as mixed data types. A list can contain a number, a string and even another list.
# Lists are mutable. They can be changed by adding or removing values from the list.

# For Example:

# >> a = [] # Define an empty
# >> a.append(5) # Adds a new element to a list.
# >> a.append(3)
# >> a.append(7)
# >> len(a) # Find length of the list.
# 3
# >> a[0]*a[2] # Indexing of list starts from 0.
# 35
# >> a.pop() # Removes the last element of the list and returns its value.
# 7
# >> a.remove(5) # Removes the first occurrence of the element from the list.
# >> a
# [3]
# >> a.extend([3,2]) # Appends a list at the end of another list.
# >> a
# [3, 3, 2]

nc = int(input())
nums = list(map(int,input().strip().split()))[:nc]
# print(nums)
z = max(nums)
# print(z)
while max(nums) == z:
    nums.remove(max(nums))

print(max(nums))