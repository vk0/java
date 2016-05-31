# The ^ symbol matches the position at the start of a string.

# ach06_01.png


# The $ symbol matches the position at the end of a string.

# ach06_02.png

# Task

# You have a test string . Your task is to match the pattern
# Here,  denotes a word character, and  denotes a digit.
#  must start with a digit  and end with . symbol.
#  should be  characters long only.

# Note

# This is a regex only challenge. You are not required to write code.
# You have to fill the regex pattern in the blank (_________).

Regex_Pattern = r"^\d.....$"    # Do not delete 'r'.

import re
print(str(bool(re.search(Regex_Pattern, input()))).lower())