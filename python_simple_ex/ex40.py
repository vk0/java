# An anagram is a type of word play, the result of rearranging the letters
# of a word or phrase to produce a new word or phrase, using all the original
# letters exactly once; e.g., orchestra = carthorse, A decimal point = I'm
# a dot in place.
#
# Write a Python program that, when started
# 1) randomly picks a word w from given list of words,
# 2) randomly permutes w (thus creating an anagram of w),
# 3) presents the anagram to the user, and
# 4) enters an interactive loop in which the user is invited to guess the
# original word.
# It may be a good idea to work with (say) colour words only.
#
# The interaction with the program may look like so:
# >>> import anagram
# Colour word anagram: onwbr
# Guess the colour word!
# black
# Guess the colour word!
# brown
# Correct!

import random


def make_anagram(word):
    letters = [ltr for ltr in word]
    random.shuffle(letters)
    return ''.join(letters)


def anagram(words, topic):
    word = words[random.randrange(0, len(words))]
    a = make_anagram(word)

    print("%s word anagram: %s" % (topic.capitalize(), a))
    while True:
        print("Guess the %s word!" % topic)
        guess = input()
        if guess == word:
            print("Correct!")
            break

# test
anagram(["tiger", "elephant", "monkey", "kitten", "doge"], "animals")
