# On-Site Question 1 - SOLUTION

# Problem
# Given a list of integers, find the largest product you could make from 3 integers in the list

# Requirements
# You can assume that the list will always have at least 3 integers
# Paper/pencil only, don't code this out until you've solved it as far as you can by hand.

# Solution
# We can solve this problem in O(n) time with O(1) space, we should also be able to take into account negative numbers, so that a list like: [-5,-5,1,3] returns (-5)(-5)(3) = 75 as its answer.

# Hopefully you've begun to realize the similarity between this problem and the Amazon stock problem from the E-Commerce Company mock interview questions! You could brute force this problem by just simply trying every single combination of three digits, but this would require O(n^3) time!
# How about we use a greedy approach and keep track of some numbers. In the stock problem we kept track of max profit so far, in this problem we are actually going to keep track of several numbers:
# The highest product of 3 numbers so far
# The highest product of 2 numbers so far
# The highest number so far
# Since we want to keep negative numbers in account, we will also keep track of the lowest product of two and the lowest number:
# The lowest product of 2
# The lowest number
# Once we iterate through the list and reach the end we will have the highest posiible product with 3 numbers. At each iteration we will take the current highest product of 3 and compare it to the current integer multiplied by the highest and lowest products of 2.
# Let's see this coded out:

def solution(lst):

    # Start at index 2 (3rd element) and assign highest and lowest
    # based off of first two elements

    # Highest Number so far
    high = max(lst[0],lst[1])

    # Lowest number so far
    low = min(lst[0],lst[1])

    # Initiate Highest and lowest products of two numbers
    high_prod2 = lst[0]*lst[1]
    low_prod2 = lst[0]*lst[1]

    # Initiate highest product of 3 numbers
    high_prod3 = lst[0]*lst[1]*lst[2]

    # Iterate through list
    for num in lst[2:]:

        # Compare possible highest product of 3 numbers
        high_prod3 = max(high_prod3,num*high_prod2,num*low_prod2)

        # Check for possible new highest products of 2 numbers
        high_prod2 = max(high_prod2,num*high,num*low)

        # Check for possible new lowest products of 2 numbers
        low_prod2 = min(low_prod2,num*high,num*low)

        # Check for new possible high
        high = max(high,num)

        # Check for new possible low
        low = min(low,num)

    return high_prod3

l = [99,-82,82,40,75,-24,39, -82, 5, 30, -25, -94, 93, -23, 48, 50, 49,-81,41,63]
solution(l) #763092

# Great! Through the use of a greedy approach we have been able to complete the problem in O(n) time. Keep this sort of approach in mind when you have to iterate through a list and a brute force solution is on the order of an exponential!
