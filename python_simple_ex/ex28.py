# Write a function find_longest_word() that takes a list of words and 
# returns the length of the longest one. 
# Use only higher order functions.

def find_longest_word(words):
    '''
    words: a list of words
    returns: the length of the longest one
    '''
    return max(list(map(len, words)))

# test
print(find_longest_word(["i", "am", "pythoning"]))
print(find_longest_word(["hello", "world"]))
print(find_longest_word(["ground", "control", "to", "major", "tom"]))
