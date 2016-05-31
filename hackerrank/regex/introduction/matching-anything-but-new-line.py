# dot

# The dot (.) matches anything (except for a newline).

# ach02.png


# Note: If you want to match (.) in the test string, you need to escape the dot by using a slash \..
# In Java, use \\. instead of \..

# Task

# You have a test string .
# Your task is to match the pattern  where  denotes any character (other than the newline).

# Note

# This is a regex only challenge. You are not required to write any code.
# You only have to fill in the regex pattern in the blank (_________).

Regex_Pattern = r".{3}\..{3}\..{3}\..{3}"   # Do not delete 'r'.


import re
Test_String = input()
match = re.findall(Regex_Pattern, Test_String)
print("Number of matches :", len(match))