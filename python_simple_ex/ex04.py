# Write a function that takes a character (i.e. a string of length 1) and
# returns True if it is a vowel, False otherwise.

vowels = "aeiou"

def vornot(character):
    return character in vowels
  # if character in vowels:
  #   return True
  # else:
  #   return False

# test
print(vornot("a"))
print(vornot("w"))