# Write a function max_in_list() that takes a list of numbers and 
# returns the largest one.

from ex01 import max

def max_in_list(numbers):
    largest = 0
    for number in numbers:
        largest = max(number, largest)
    return largest

# test
print(max_in_list([1,2,3]))
print(max_in_list([1,2,3,6,5,3,2,1,45]))
