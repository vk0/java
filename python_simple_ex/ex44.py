# Your task in this exercise is as follows:
# Generate a string with N opening brackets ("[") and N closing brackets ("]"), 
# in some arbitrary order.
# Determine whether the generated string is balanced; that is, whether it 
# consists entirely of pairs of opening/closing brackets (in that order), 
# none of which mis-nest.
# Examples:
#    []        OK   ][        NOT OK
#    [][]      OK   ][][      NOT OK
#    [[][]]    OK   []][[]    NOT OK

import random

def generate_string(n):
    '''returns a string with n opening ("[") and n closing brackets ("]")'''
    string = ["[", "]"] * n
    random.shuffle(string)
    print("".join(string))
    return "".join(string) 

def is_balanced(string):
    balance = 0
    for c in string:
        if c == "[":
            balance += 1
        elif c == "]":
            balance -= 1
            if balance < 0: return False
    return balance == 0

# test
print(is_balanced(generate_string(1)))
print(is_balanced(generate_string(2)))
print(is_balanced(generate_string(3)))
print(is_balanced(generate_string(6)))
