# An anagram is a type of word play, the result of rearranging the letters of 
# a word or phrase to produce a new word or phrase, using all the original 
# letters exactly once; e.g., orchestra = carthorse. 
# Using the word list at http://www.puzzlers.org/pub/wordlists/unixdict.txt, 
# write a program that finds the sets of words that share the same characters 
# that contain the most words in them.

words = []
anagrams = {}

file_name = "unixdict.txt"
with open(file_name, 'r') as file:
    for line in file:
        words.append(line.rstrip())

for word in words:
    anagram = "".join(sorted(word)) # 'hello' -> 'ehllo'
    if anagram in anagrams:
        anagrams[anagram].append(word)
    else:
        anagrams[anagram] = [word]

anagr_lengths = {}
for a in anagrams:
    l = len(anagrams[a])
    if l in anagr_lengths:
        anagr_lengths[l].append(a)
    else:
        anagr_lengths[l] = [a]

lengths = list(anagr_lengths)
max_length = max(lengths)
longest_anagrams = anagr_lengths[max_length]

for a in longest_anagrams:
    print(a + ": " + str(anagrams[a]))
