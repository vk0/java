# -*- coding: utf-8 -*-
# Objective
# Today we're expanding our knowledge of Strings and combining it with what we've already learned about operators and loops. Check out the Tutorial tab for learning materials and an instructional video!

# Task
# Suppose you have a String, SS, of length NN that is indexed from 00 to N−1N−1. You also have some String, RR, that is the reverse of String SS. SS is funny if the condition |S[i]−S[i−1]|=|R[i]−R[i−1]||S[i]−S[i−1]|=|R[i]−R[i−1]| is true for every character ii from 11 to N−1N−1.

# Note: For some String SS, S[i]S[i] denotes the ASCII value of the ithith 00-indexed character in SS. The absolute value of an integer, xx, is written as |x||x|.

# Input Format

# The first line contains an integer, TT (the number of test cases).
# Each line ii of the TT subsequent lines contain a String, SS.

# Constraints

# 1≤T≤101≤T≤10
# 2≤length of S≤100002≤length of S≤10000
# Output Format

# For each String SjSj (where 0≤j≤T−10≤j≤T−1), print whether it is FunnyFunny or Not FunnyNot Funny on a new line.

# Sample Input

# 2
# acxz
# bcxz
# Sample Output

# Funny
# Not Funny
# Explanation

# Test Case 0: S="acxz"S="acxz"
# |c−a|=2=|x−z||c−a|=2=|x−z|
# |x−c|=21=|c−x||x−c|=21=|c−x|
# |z−x|=2=|a−c||z−x|=2=|a−c|
# As each comparison is equal, we print FunnyFunny.

# Test Case 1: S="bcxz"S="bcxz"
# |c−b|=1|c−b|=1, but |x−z|=2|x−z|=2
# At this point, we stop evaluating SS (as |c−b|≠|x−z||c−b|≠|x−z|) and print Not FunnyNot Funny.

n = int(input())
for i in range(0,n):
    string = input()
    s_diff = [abs(ord(string[index+1]) - ord(string[index])) for index in range(0,len(string)-1)]
    if s_diff == s_diff[::-1]:
        print('Funny')
    else:
        print('Not Funny')