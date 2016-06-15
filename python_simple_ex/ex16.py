# Write a function filter_long_words() that takes a list of words and
# an integer n and returns the list of words that are longer than n.

def filter_long_words(words, n):
    long_words = [word for word in words if len(word) > n]
    return long_words

print(filter_long_words(["ground", "control", "to", "major", "tom"], 4))
