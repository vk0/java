# Write a function find_longest_word() that takes a list of words and
# returns the length of the longest one.


def find_longest_word(words):
    longest = ""

    for word in words:
        if len(word) >= len(longest):
            longest = word

    return longest

# test
print(find_longest_word(["i", "am", "pythoning"]))
print(find_longest_word(["hello", "world"]))
print(find_longest_word(["ground", "control", "to", "major", "tom"]))
