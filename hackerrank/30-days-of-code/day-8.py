# # -*- coding: utf-8 -*-
# Objective
# Today, we're learning about Key-Value pair mappings using a Map or Dictionary data structure. Check out the Tutorial tab for learning materials and an instructional video!

# Task
# Given NN names and phone numbers, assemble a phone book that maps friends' names to their respective phone numbers. You will then be given an unknown number of names to query your phone book for; for each namename queried, print the associated entry from your phone book (in the form name=phoneNumbername=phoneNumber) or Not foundNot found if there is no entry for namename.

# Note: Your phone book should be a Dictionary/Map/HashMap data structure.

# Input Format

# The first line contains an integer, NN, denoting the number of entries in the phone book.
# Each of the NN subsequent lines describes an entry in the form of 22 space-separated values on a single line. The first value is a friend's namename, and the second value is an 88-digit phone numberphone number.

# After the NN lines of phone book entries, there are an unknown number of lines of queries. Each line (query) contains a namename to look up, and you must continue reading lines until there is no more input.

# Note: Names consist of lowercase English letters and are first names only.

# Constraints

# 1≤N≤1051≤N≤105
# 1≤queries≤1051≤queries≤105
# Output Format

# On a new line for each query, print Not foundNot found if the name has no corresponding entry in the phone book; otherwise, print the full namename and phoneNumberphoneNumber in the format name=phoneNumbername=phoneNumber.

# Sample Input

# 3
# sam 99912222
# tom 11122222
# harry 12299933
# sam
# edward
# harry
# Sample Output

# sam=99912222
# Not found
# harry=12299933
# Explanation

# N=3N=3
# We add the NN subsequent (Key,Value) pairs to our map so it looks like this:

# phoneBook={(sam,99912222),(tom,11122222),(harry,12299933)}phoneBook={(sam,99912222),(tom,11122222),(harry,12299933)}
# We then process each query and print Key=ValueKey=Value if the queried Key is found in the map, or Not foundNot found otherwise.

# Query 0: samsam
# Sam is one of the keys in our dictionary, so we print sam=99912222sam=99912222.

# Query 1: edwardedward
# Edward is not one of the keys in our dictionary, so we print Not foundNot found.

# Query 2: harryharry
# Harry is one of the keys in our dictionary, so we print harry=12299933harry=12299933.

n=int(input())

phonebook = dict(input().split() for _ in range(n))

for j in range(n):
    name = input().strip()
    if name in phonebook:
        print(name + "=" + phonebook[name])
    else:
        print("Not found")