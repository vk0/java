# The expression \d matches any digit [ - ].

# ach04_01.png



# The expression \D matches any character that is not a digit.

# ach04_02.png


# Task

# You have a test string . Your task is to match the pattern
# Here  denotes a digit character, and  denotes a non-digit character.

# Note

# This is a regex only challenge. You are not required to write any code.
# You only have to fill the regex pattern in the blank (_________).

Regex_Pattern = r"(\d{2}\D){2}\d{4}"    # Do not delete 'r'.

import re
print(str(bool(re.search(Regex_Pattern, input()))).lower())