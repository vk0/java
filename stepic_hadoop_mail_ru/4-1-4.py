# Напишите программу, которая реализует In-mapper combining v.1 для задачи WordCount в Hadoop Streaming.

# Sample Input:

# aut Caesar aut nihil
# aut aut
# de mortuis aut bene aut nihil

# Sample Output:

# Caesar  1
# nihil   1
# aut 2
# aut 2
# nihil   1
# de  1
# mortuis 1
# aut 2
# bene    1

import sys

for line in sys.stdin:
    same_words ={}
    each_word = []
    for word in line.strip().split(" "):
        # print word
        each_word.append(word)
    for words in each_word:
        if words not in same_words.keys():
            same_words[words]=1
        else:
            same_words[words]=same_words[words]+1
    for each in same_words.keys():
        print(each,same_words[each], sep='\t')