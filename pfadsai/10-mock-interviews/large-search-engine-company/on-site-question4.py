# On-Site Question 4 - SOLUTION

# Question
# Find the squareroot of a given number rounded down to the nearest integer, without using the sqrt function. For example, squareroot of a number between [9, 15] should return 3, and [16, 24] should be 4.

# Requirements
# Feel free to code this out (but its recommended that you use paper/pencil or whiteboard)

# Solution
# The squareroot of a (non-negative) number N always lies between 0 and N/2. The straightforward way to solve this problem would be to check every number k between 0 and N/2, until the square of k becomes greater than or equal to N. If k^2 becomes equal to N, then we return k. Otherwise, we return k-1 because we're rounding down. Here's the code:

def solution(num):
    if num<0:
        raise ValueError
    if num==1:
        return 1
    for k in range(1+(num/2)):
        if k**2==num:
            return k
        elif k**2>num:
            return k-1
    return k

solution(14) #3
solution(15) #3
solution(16) #4


# The complexity of this approach is O(N), because we have to check N/2 numbers in the worst case. This linear algorithm is pretty inefficient, we can use some sort of binary search to speed it up. We know that the result is between 0 and N/2, so we can first try N/4 to see whether its square is less than, greater than, or equal to N. If it’s equal then we simply return that value. If it’s less, then we continue our search between N/4 and N/2. Otherwise if it’s greater, then we search between 0 and N/4. In both cases we reduce the potential range by half and continue, this is the logic of binary search. We’re not performing regular binary search though, it’s modified. We want to ensure that we stop at a number k, where k^2<=N but (k+1)^2>N. For example:

def better_solution(num):
    if num<0:
        raise ValueError
    if num==1:
        return 1
    low=0
    high=1+(num/2)

    while low+1<high:
        mid=low+(high-low)/2
        square=mid**2
        if square==num:
            return mid
        elif square<num:
            low=mid
        else: high=mid

    return low

better_solution(14) #3
better_solution(15) #3
better_solution(16) #4


# One difference from regular binary search is the condition of the while loop, it’s low+1<high instead of low<high. Also we have low=mid instead of low=mid+1, and high=mid instead of high=mid-1. These are the modifications we make to standard binary search. The complexity is still the same though, it’s logarithmic O(logN). Which is much better than the naive linear solution.
# There’s also a constant time O(1) solution which involves a clever math trick. Here it is:

#
# =N0.5
# =2^log2N0.5
# =2^0.5log2N

# This solution exploits the property that if we take the exponent of the log of a number, the result doesn’t change, it’s still the number itself. So we can first calculate the log of a number, multiply with 0.5, take the exponent, and finally take the floor of that value to round it down. This way we can avoid using the sqrt function by using the log function. Logarithm of a number rounded down to the nearest integer can be calculated in constant time, by looking at the position of the leftmost 1 in the binary representation of the number. For example, the number 6 in binary is 110, and the leftmost 1 is at position 2 (starting from right counting from 0). So the logarithm of 6 rounded down is 2. This solution doesn’t always give the same result as above algorithms though, because of the rounding effects. And depending on the interviewer’s perspective this approach can be regarded as either very elegant and clever, or tricky and invalid. Either way, you should let your interviewer know that you are capable of the shortcut!