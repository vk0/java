# Define a function is_palindrome() that recognizes palindromes
# (i.e. words that look the same written backwards).
# For example, is_palindrome("radar") should return True.

def is_palindrome(word):
    backwards = word[::-1]
    return backwards == word

# test
print("Is \"radar\" a palindrome?")
print(is_palindrome("radar"))
print("Is \"woof\" a palindrome?")
print(is_palindrome("woof"))
