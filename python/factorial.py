#!/usr/bin/env python
#recursive function
def factorial(number):
    if number <=1:
        return 1
    else:
        print number
        return number*factorial(number-1)

#number_input = input("Number: ")
number_input = 1
fac = factorial(number_input)
print ("Factorial for", number_input , fac)
