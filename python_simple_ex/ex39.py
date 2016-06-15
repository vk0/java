# Write a program able to play the "Guess the number"-game, where the number 
# to be guessed is randomly chosen between 1 and 20. 
# (Source: http://inventwithpython.com) 
# This is how it should work when run in a terminal:
# >>> import guess_number
# Hello! What is your name?
# Torbjörn
# Well, Torbjörn, I am thinking of a number between 1 and 20.
# Take a guess.
# 10
# Your guess is too low.
# Take a guess.
# 15
# Your guess is too low.
# Take a guess.
# 18
# Good job, Torbjörn! You guessed my number in 3 guesses!

from random import randrange

print("Hello! What is your name?")
name = input()
print("Well, %s, I am thinking of a number between 1 and 20." % name)

guesses = 0
number = randrange(1, 21)

while True:
    print("Take a guess.")
    guess = int(input())
    guesses += 1

    if guess < number:
        print("Your guess is too low.")
    elif guess > number:
        print("Your guess is too high.")
    else:
        break
        
print("Good job, %s! You guessed my number in %s guesses!" % (name, guesses))
