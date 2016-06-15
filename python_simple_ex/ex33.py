# According to Wikipedia, a semordnilap is a word or phrase that spells 
# a different word or phrase backwards. ("Semordnilap" is itself "palindromes" 
# spelled backwards.) 
# Write a semordnilap recogniser that accepts a file name (pointing to 
# a list of words) from the user and finds and prints all pairs of words 
# that are semordnilaps to the screen. 
# For example, if "stressed" and "desserts" is part of the word list, 
# the the output should include the pair "stressed desserts". 
# Note, by the way, that each pair by itself forms a palindrome!

words = []

file_name = input("Please enter the file name: ")
if len(file_name) < 1:
    file_name = 'unixdict.txt'

with open(file_name, 'r') as file:
    for line in file:
        words.append(line.rstrip())

for word in words:
    if word[::-1] in words:
        print(word, word[::-1])
