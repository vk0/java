# Objective
# Today, we're discussing data types. Check out the Tutorial tab for learning materials and an instructional video!

# Task
# Complete the code in the editor below. The variables ii, dd, and ss are already declared and initialized for you. You must declare 33 variables: one of type int, one of type double, and one of type String. Then you must read 33 lines of input from stdin and initialize your 33 variables. Finally, you must use the ++ operator to perform the following operations:

# Print the sum of ii plus your int variable on a new line.
# Print the sum of dd plus your double variable to a scale of one decimal place on a new line.
# Concatenate ss with the string you read as input and print the result on a new line.
# Note: If you are using a language that doesn't support using ++ for string concatenation (e.g.: CC), you can just print one variable immediately following the other on the same line. The string provided in your editor must be printed first, immediately followed by the string you read as input.

# Input Format

# The first line contains an integer, ii.
# The second line contains a double, dd.
# The third line contains a string, ss.

# Output Format

# Print the sum of both integers on the first line, the sum of both doubles on the second line, and then the two concatenated strings on the third line.

# Sample Input

# 12
# 4.0
# is the best place to learn and practice coding!
# Sample Output

# 16
# 8.0
# HackerRank is the best place to learn and practice coding!

# Sample Input

# i = 3
# d = 2.8
# s = 'is my favorite platform!'

# Sample Output

# 7
# 6.8
# HackerRank is my favorite platform!

# Declare second integer, double, and String variables.
i = 4
d = 4.0
s = 'HackerRank '

# Read and save an integer, double, and String to your variables.
i2 = input()
d2 = input()
s2 = input()

# Print the sum of both integer variables on a new line.
print(int(i) + int(i2))
# Print the sum of the double variables on a new line.
print(float(d) + float(d2))
# Concatenate and print the String variables on a new line
# The 's' variable above should be printed first.
print('HackerRank ' + s2)