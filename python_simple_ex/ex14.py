# Write a program that maps a list of words into a list of integers
# representing the lengths of the correponding words.

# much better
def words_lengths(words):
    lengths = [len(word) for word in words]
    return lengths

# not cool
# def words_lengths(words):
#     lengths = []
#     for word in words:
#         lengths.append(len(word))
#     return lengths

# test
w = ["i", "am", "pythoning"]
print(words_lengths(w))
