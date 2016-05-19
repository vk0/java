#  -*- coding: utf-8 -*-
# Objective
# This challenge is very different from the others we've completed because it requires you to generate valid test cases for a problem instead of solving the problem. There is no input to read, you simply have to generate and print test values for the problem that satisfy both the problem's Input Format and the criteria laid out in the Task section. Check out the Tutorial tab for an instructional video on testing!

# Consider the following problem:

# Problem Statement

# A Discrete Mathematics professor has a class of NN students. Frustrated with their lack of discipline, the professor decides to cancel class if fewer than KK students are present when class starts. Given the arrival time of each student, determine if the class is canceled.

# Input Format

# The first line of input contains TT, the number of test cases.

# Each test case spans two lines. The first has two space-separated integers, NN (students in the class) and KK (the cancelation threshold). The second contains NN space-separated integers describing the students' arrival times as array aa (a0,…,aN−1a0,…,aN−1).

# Note: Non-positive arrival times (ai≤0ai≤0) indicate the student arrived early or on time; positive arrival times (ai>0ai>0) indicate the student arrived aiai minutes late. If a student arrives exactly on time (ai=0)(ai=0), the student is considered to have entered before the class started.

# Output Format

# For each test case, print the word YESYES if the class is canceled or NONO if it is not.

# Example

# When properly solved, this input:

# 2
# 4 3
# -1 -3 4 2
# 4 2
# 0 -1 2 1
# Should produce this output:

# YES
# NO
# For the first test case, K=3K=3. The professor wants at least 33 students in attendance, but only 22 arrive on time (−3−3 and −1−1). Thus, the class is canceled.

# For the second test case, K=2K=2. The professor wants at least 22 students in attendance, and 22 do arrive on time (00 and −1−1). Thus, the class is not canceled.

# Task

# Create and print one or more test cases for the problem above that meet the following criteria:

# T≤5T≤5
# 1≤N≤2001≤N≤200
# 1≤K≤N1≤K≤N
# −1000≤ai≤1000,where i∈[1,N]−1000≤ai≤1000,where i∈[1,N]
# The value of NN should be distinct across all the test cases.
# Array aa must have at least 11 zero, 11 positive integer, and 11 negative integer.
# Scoring

# If you submit xx correct test cases, your score will be 20.0×x20.0×x. If you submit more than 55 test cases, only the first 55 test cases will be evaluated.

# You must create five test cases to earn the maximum possible score.

# The output for your test case (were it to run against a correct solution to the problem above) should be:

# YES
# NO
# YES
# NO
# YES
# Print your test cases as output the same way the solution would expect to read them as input. For example:

# print('1')
# print('4 3')
# print('-1 -3 4 2')
# print('5 2')
# print('0 -1 2 1 4')

import random
# no of tests
print('5')
for i in range(5):
    students = i+5
    treshold = random.randint(3,students-1)
    print(str(students) + " " + str(treshold))
    arrivals = "0 "
    if not i%2:
        arrivals += ( "-1 " )
        for x in range(2,students):
            arrivals += ( str(random.randint(1,5)) + " " )
    else:
        arrivals += ( "1 " )
        for x in range(2,students):
            arrivals += ( str(random.randint(-5,-1)) + " " )
    print(arrivals.strip())



# print("5")
# print("3 3")
# print("-1 0 1")
# print("4 3")
# print("-2 -1 0 2")
# print("5 3")
# print("-2 0 1 2 3")
# print("6 3")
# print("-3 -2 -1 0 1 2")
# print("7 3")
# print("-1 0 1 2 3 4 5")