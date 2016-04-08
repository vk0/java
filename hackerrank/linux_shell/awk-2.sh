# Objective
# In this challenge, we practice using the awk command for text-munging and data processing tasks.

# Resources
# The awk interpreter may be used for a lot of text-munging and data-processing tasks that require some quick scripting work.

# The following links show examples with awk:
# Print Examples
# Conditionals with Awk

# Task
# You are given a file with four space separated columns containing the scores of students in three subjects. The first column contains a single character (A−ZA−Z), the student identifier. The next three columns have three numbers each. The numbers are between 00 and 100100, both inclusive. These numbers denote the scores of the students in English, Mathematics, and Science, respectively.

# Your task is to identify whether each of the students has passed or failed.
# A student is considered to have passed if (s)he has a score 5050 or more in each of the three subjects.

# Input Format

# There will be no more than 1010 rows of data.
# Each line will be in the following format:
# [Identifier][English Score][Math Score][Science Score]

# Output Format

# Depending on the scores, display the following for each student:

# [Identifier]:[Pass]
# or

# [Identifier]:[Fail]
# Sample Input

# A 25 27 50
# B 35 37 75
# C 75 78 80
# D 99 88 76
# Sample Output

# A : Fail
# B : Fail
# C : Pass
# D : Pass
# Explanation

# Only student C and student D have scored ≥≥ 5050 in all three subjects.

awk '{print $1,":", $2<50 || $3<50 || $3<50 ? "Fail":"Pass"}'
