# On-Site Question 3 - SOLUTION

# Question
# Given a string, write a function that uses recursion to reverse it.

# Requirements
# You MUST use pen and paper or a whiteboard to answer this, no coding allowed!

# SOLUTION
# Hopefully you remember this problem, you've already seen it! The solution is:

def reverse(s):

    # Base Case
    if len(s) <= 1:
        return s

    # Recursion
    return reverse(s[1:]) + s[0]

# Notes
# Remember when recursion questions arise, think about the base case and the recursive case. Review the recusion section of the course for review for this problem.