# In a game of Lingo, there is a hidden word, five characters long. 
# The object of the game is to find this word by guessing, and in return 
# receive two kinds of clues: 
# 1) the characters that are fully correct, with respect to identity as well as 
# to position, 
# 2) the characters that are indeed present in the word, but which are placed 
# in the wrong position. 
# Write a program with which one can play Lingo. Use square brackets to mark 
# characters correct in the sense of 1), and ordinary parentheses to mark 
# characters correct in the sense of 2). 
# Assuming, for example, that the program conceals the word "tiger", you should 
# be able to interact with it in the following way:
# >>> import lingo
# snake
# Clue: snak(e)
# fiest
# Clue: f[i](e)s(t)
# times
# Clue: [t][i]m[e]s
# tiger
# Clue: [t][i][g][e][r]

from random import randrange

words = ["tiger", "snake", "fiest", "times"]
hidden_word = words[randrange(0, len(words))]

while True:
    guess = input()[:5]

    clue = ""
    for i in range(5):
        if guess[i] == hidden_word[i]:
            clue += "[" + guess[i] + "]"
        elif guess[i] in hidden_word:
            clue += "(" + guess[i] + ")"
        else:
            clue += guess[i]

    print("Clue: " + clue)

    if guess == hidden_word:
        break
