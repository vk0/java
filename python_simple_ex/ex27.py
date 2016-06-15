# Write a program that maps a list of words into a list of integers 
# representing the lengths of the correponding words. 

# Write it in three different ways: 
# 1) using a for-loop, 
# 2) using the higher order function map(), and 
# 3) using list comprehensions.

# 1) using a for-loop
def word_to_lengths_for(words):
    '''
    words: list of words,
    returns a list of integers - the lengths of the corresponding words
    '''
    lengths = []
    for w in words:
        lengths.append(len(w))
    return lengths


# 2) using the higher order function map()
def word_to_lengths_map(words):
    '''
    words: list of words,
    returns a list of integers - the lengths of the corresponding words
    '''
    return list(map(len, words))


# 3) using list comprehensions.
def word_to_lengths_compr(words):
    '''
    words: list of words,
    returns a list of integers - the lengths of the corresponding words
    '''
    return [len(w) for w in words]


# Test
words = ["A", "list", "of", "words"]
print(word_to_lengths_for(words))
print(word_to_lengths_map(words))
print(word_to_lengths_compr(words))
