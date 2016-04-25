# # -*- coding: utf-8 -*-
# Objective
# Yesterday's challenge taught you to manage exceptional situations by using try and catch blocks. In today's challenge, you're going to practice throwing and propagating an exception. Check out the Tutorial tab for learning materials and an instructional video!

# Task
# Write a Calculator class with a single method: int power(int,int). The power method takes two integers, nn and pp, as parameters and returns the integer result of npnp. If either nn or pp is negative, then the method must throw an exception with the message: n and p should be non-negative.

# Note: Do not use an access modifier (e.g.: public) in the declaration for your Calculator class.

# Input Format

# Input from stdin is handled for you by the locked stub code in your editor. The first line contains an integer, TT, the number of test cases. Each of the TT subsequent lines describes a test case in 22 space-separated integers denoting nn and pp, respectively.

# Constraints

# No Test Case will result in overflow for correctly written code.
# Output Format

# Output to stdout is handled for you by the locked stub code in your editor. There are TT lines of output, where each line contains the result of npnp as calculated by your Calculator class' power method.

# Sample Input

# 4
# 3 5
# 2 4
# -1 -2
# -1 3
# Sample Output

# 243
# 16
# n and p should be non-negative
# n and p should be non-negative
# Explanation

# T=4T=4
# T0T0: 33 and 55 are positive, so power returns the result of 3535, which is 243243.
# T1T1: 22 and 44 are positive, so power returns the result of 2424=, which is 1616.
# T2T2: Both inputs (−1−1 and −2−2) are negative, so power throws an exception and n and p should be non-negativen and p should be non-negative is printed.
# T3T3: One of the inputs (−1−1) is negative, so power throws an exception and n and p should be non-negativen and p should be non-negative is printed.

class Calculator:
    def power(self, n, p):
        if (n < 0 or p < 0):
            raise Exception("n and p should be non-negative")
        else:
            return n**p

myCalculator=Calculator()
T=int(input())
for i in range(T):
    n,p = map(int, input().split())
    try:
        ans=myCalculator.power(n,p)
        print(ans)
    except Exception as e:
        print(e)