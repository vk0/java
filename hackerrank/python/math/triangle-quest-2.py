# # -*- coding: utf-8 -*-
# You are given a positive integer NN.
# Your task is to print a palindromic triangle of size NN.

# For example, a palindromic triangle of size 55 is:

# 1
# 121
# 12321
# 1234321
# 123454321
# You can't take more than two lines. The first line (a for-statement) is already written for you.
# You have to complete the code using exactly one print statement.

# Note:
# Using anything related to strings will give a score of 00.
# Using more than one for-statement will give a score of 00.

# Input Format

# A single line of input containing the integer NN.

# Constraints

# 0<N<100<N<10
# Output Format

# Print the palindromic triangle of size NN as explained above.

# Sample Input

# 5
# Sample Output

# 1
# 121
# 12321
# 1234321
# 123454321

for x in range(1,int(input())+1):
    print(((10**x - 1)//9)**2)