# -*- coding: utf-8 -*-
# Unique Characters in String¶
# Problem
# Given a string,determine if it is compreised of all unique characters. For example, the string 'abcde' has all unique characters and should return True. The string 'aabcde' contains duplicate characters and should return false.
# Solution
# We'll show two possible solutions, one using a built-in data structure and a built in function, and another using a built-in data structure but using a look-up method to check if the characters are unique.

# Solution
# We'll show two possible solutions, one using a built-in data structure and a built in function, and another using a built-in data structure but using a look-up method to check if the characters are unique.

def uni_char(s):
    return len(set(s)) == len(s)

def uni_char2(s):
    chars = set()
    for let in s:
        # Check if in set
        if let in chars:
            return False
        else:
            #Add it to the set
            chars.add(let)
    return True

print(uni_char('abcd'))
print(uni_char2('abcda'))