# On-Site Question 2 - SOLUTION

# Problem
# Given a list of account ID numbers (integers) which contains duplicates , find the one unique integer. (the list is guaranteed to only have one unique (non-duplicated) integer

# Requirements
# Do not use built-in Python functions or methods

# Solution
# This should feel very familiar to one of the problems we did in the array section of the course! We can use an XOR operation. The exclusive or operations will take two sets of bits and for each pair it will return a 1 value if one but not both of the bits is 1.
# In Python we can use the ^ symbol to perform an XOR.
# Now for our solution we can simply XOR all the integers in the list. We start with a unique id set to 0, then every time we XOR a new id from the list, it will change the bits. When we XOR with the same ID again, it will cancel out the earlier change.
# By the end, we wil be left with the ID that was unique and only appeared once!


def solution(id_list):
    # Initiate unique Id
    unique_id = 0
    # XOR fo revery id in id list
    for i in id_list:
        # XOR operation
        unique_id ^= i
    return unique_id