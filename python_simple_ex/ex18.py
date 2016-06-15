# A pangram is a sentence that contains all the letters of the English alphabet
# at least once, for example: The quick brown fox jumps over the lazy dog.

# Your task here is to write a function to check a sentence to see
# if it is a pangram or not.

import string
alphabet = string.ascii_lowercase

def pangram(sentence):
    for l in alphabet:
        if l not in sentence.lower():
            return False
    return True

# Test
p = "The quick brown fox jumps over the lazy dog."
print(pangram(p))
print(pangram("other string"))
