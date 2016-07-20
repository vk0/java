# On-Site Question 1 - SOLUTION

# Question
# Given a dice which rolls 1 to 7 (with uniform probability), simulate a 5 sided dice. Preferably, write your solution as a function.

# Requirements
# You MUST do this on pen and paper or on a whiteboard. No actual coding is allowed until you've solved it on pen and paper!

# SOLUTION
# This is a new problem we haven't seen directly before! Many times this question is asked in the form of functions e.g. your given a function random_7() and you have to take it as an input and create random_5()
# The key to solving this problem is to make sure you focus on the requirement that the final distribution of the rolls be uniform, also you were not given any requirements on Time and Space, so the solution is actually very simple, just keep re-rolling if you get a number greater than 5!

# We can code this out:


from random import randint

def dice7():
    return randint(1, 7)

# Our Solution
def convert7to5():
    # Starting roll (just needs to be larger than 5)
    roll = 7
    while roll > 5:
        roll = dice7()
        print 'dice7() produced a roll of ', roll
        print ' Your final returned roll is below:'
    return roll

convert7to5()
# dice7() produced a roll of  7
# dice7() produced a roll of  5
# Your final returned roll is below: 5