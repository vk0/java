# A hapax legomenon (often abbreviated to hapax) is a word which occurs 
# only once in either the written record of a language, the works of an 
# author, or in a single text. Define a function that given the file name 
# of a text will return all its hapaxes. Make sure your program ignores 
# capitalization.

def hapax(file_name):
    file = open(file_name, 'r')
    text = file.read()
    file.close()

    words = text.lower().split()

    return list(filter(lambda word: words.count(word) == 1, words))

# test
print(hapax("sample.txt"))
