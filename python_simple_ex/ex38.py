# Write a program that will calculate the average word length of a text 
# stored in a file (i.e the sum of all the lengths of the word tokens in 
# the text, divided by the number of word tokens).

from string import punctuation

def clear(line):
    clean_line = ""
    for letter in line:
        if letter not in punctuation:
            clean_line += letter
    return clean_line

def average_word(file_name):
    words = []

    file = open(file_name, 'r')
    for line in file:
        words += clear(line).split()
    file.close()

    words_lengths = list(map(len, words))
    return sum(words_lengths) / len(words_lengths)

# test
print(average_word("sample.txt"))
