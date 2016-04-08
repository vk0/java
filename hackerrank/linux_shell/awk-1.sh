# Objective
# In this challenge, we practice using the awk command for text-munging and data processing tasks.

# Resources
# Here's a useful video on the topic:


# The awk interpreter may be used for a lot of text-munging and data-processing tasks that require some quick scripting work.

# The following links show examples with awk:
# Print Examples
# Conditionals with Awk

# Task
# You are given a file with four space separated columns containing the scores of students in three subjects. The first column contains a single character (A−ZA−Z), the student identifier. The next three columns have three numbers each. The numbers are between 00 and 100100, both inclusive. These numbers denote the scores of the students in English, Mathematics, and Science, respectively.

# Your task is to identify those lines that do not contain all three scores for students.

# Input Format

# There will be no more than 1010 rows of data.
# Each line will be in the following format:
# [Identifier][English Score][Math Score][Science Score]

# Output Format

# For each student, if one or more of the three scores is missing, display:

# Not all scores are available for [Identifier]
# Sample Input

# A 25 27 50
# B 35 75
# C 75 78
# D 99 88 76
# Sample Output

# Not all scores are available for B
# Not all scores are available for C
# Explanation

# Only 22 scores have been provided for student B and student C.

awk '{if ($4 == "") print "Not all scores are available for", $1}'