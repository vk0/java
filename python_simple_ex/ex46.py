# An alternade is a word in which its letters, taken alternatively in a strict 
# sequence, and used in the same order as the original word, make up at least 
# two other words. All letters must be used, but the smaller words are not 
# necessarily of the same length. For example, a word with seven letters where 
# every second letter is used will produce a four-letter word and a three-letter 
# word. Here are two examples:
#   "board": makes "bad" and "or".
#   "waists": makes "wit" and "ass".
# Using the word list at http://www.puzzlers.org/pub/wordlists/unixdict.txt, 
# write a program that goes through each word in the list and tries to make two 
# smaller words using every second letter. The smaller words must also be 
# members of the list. Print the words to the screen in the above fashion.

words = []

file_name = "unixdict.txt"
with open(file_name, 'r') as file:
    for line in file:
        words.append(line.rstrip())

for word in words:
    odd = word[0::2]
    even = word[1::2]
    if (odd in words) and (even in words):
        print("\"%s\": makes \"%s\" and \"%s\"" % (word, odd, even))
