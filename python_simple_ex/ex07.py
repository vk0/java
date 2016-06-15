# Define a function reverse() that computes the reversal of a string. 
# For example, reverse("I am testing") should return the string "gnitset ma I".

# this is pythonic
def reverse1(string):
    return string[::-1]

# test
reverse1("I am testing")

# another solution (the first one is better)
def reverse2(string):
    rev_string = ""
    for letter in string:
        rev_string = letter + rev_string
    return rev_string

# test
reverse2("I am testing")
