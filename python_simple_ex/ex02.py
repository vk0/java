# Define a function max_of_three() that takes three numbers as arguments and
# returns the largest of them.

from ex01 import max

def max_of_three(x,y,z):
    return max(x, max(y, z))

# test
print(max_of_three(1,2,3))
print(max_of_three(4,2,0))
print(max_of_three(2,2,0))
