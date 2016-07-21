# On-Site Question 2 - SOLUTION

# Problem
# Write a function that given a target amount of money and a list of possible coin denominations, returns the number of ways to make change for the target amount using the coin denominations

# Requirements
# Write out your work on paper/pencil, then see if you can code up your solution

# Solution
# This is a classic interview problem, so classic that you've already seen a very similar problem in the recursion section! Make sure to review that problem first before reading our solution here!
# In this solution we will use a bottom-up algorithm.
# As we iterate through each coin, we are adding the ways of making arr[i - coin] to arr[i]
# If we have 2 ways of making 4, and are now iterating on a coin of value 3, there should be 2 ways of making 7.
# We are essentially adding the coin we are iterating on to the number of ways of making arr[i].

def solution(n, coins):
    # Set up our array for trakcing results
    arr = [1] + [0] * n

    for coin in coins:
        for i in range(coin, n + 1):
            arr[i] += arr[i - coin]

    if n == 0:
        return 0
    else:
        return arr[n]

solution(100, [1, 2, 3]) #884

# This solution results in O((m)(n)) with m being the number of coins, where we iterate about n operations. This is O(n) space.