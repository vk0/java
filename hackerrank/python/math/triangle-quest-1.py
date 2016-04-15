# -*- coding: utf-8 -*-
# You are given a positive integer NN. Print a numerical triangle of height N−1N−1 like the one below:

# 1
# 22
# 333
# 4444
# 55555
# ......
# Can you do it using only arithmetic operations, a single for loop and print statement?

# Use no more than two lines. The first line (the for statement) is already written for you. You have to complete the print statement.

# Note: Using anything related to strings will give a score of 00.

# Input Format
# A single line containing integer, NN.

# Constraints
# 1≤N≤91≤N≤9

# Output Format
# Print N−1N−1 lines as explained above.

# Sample Input

# 5
# Sample Output

# 1
# 22
# 333
# 4444
for i in range(1,int(input())): #More than 2 lines will result in 0 score. Do not leave a blank line also
    # print((pow(10,i)/9)*i)
    print(sum(map(lambda x: i * 10**x, range(i))))


