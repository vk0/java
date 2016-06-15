# Define a procedure histogram() that takes a list of integers and
# prints a histogram to the screen.
# For example, histogram([4, 9, 7]) should print the following:
# ****
# *********
# *******

def histogram(integers):
    for integer in integers:
        print(integer * '*')

# test
histogram([4, 9, 7])
