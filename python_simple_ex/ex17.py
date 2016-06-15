# Write a version of a palindrome recognizer that also accepts phrase palindromes
# such as "Go hang a salami I'm a lasagna hog.", "Was it a rat I saw?",
# "Step on no pets", "Sit on a potato pan, Otis", "Lisa Bonet ate no basil",
# "Satan, oscillate my metallic sonatas", "I roamed under it as a tired nude
# Maori", "Rise to vote sir", or the exclamation "Dammit, I'm mad!".
# Note that punctuation, capitalization, and spacing are usually ignored.

import string

def palindrome(phrase):
    punctuation = string.punctuation + ' '

    clean_phrase = ""
    for letter in phrase:
        if letter not in punctuation:
            clean_phrase += letter.lower()

    return clean_phrase == clean_phrase[::-1]

# test
print(palindrome("Go hang a salami I'm a lasagna hog."))
print(palindrome("Was it a rat I saw?"))
print(palindrome("Step on no pets"))
print(palindrome("Sit on a potato pan, Otis!"))
print(palindrome("Lisa Bonet ate no basil"))
print(palindrome("Satan, oscillate my metallic sonatas"))
print(palindrome("I roamed under it as a tired nude Maori"))
print(palindrome("Rise to vote sir"))
print(palindrome("Dammit, I'm mad!"))
print(palindrome("Babababa"))
