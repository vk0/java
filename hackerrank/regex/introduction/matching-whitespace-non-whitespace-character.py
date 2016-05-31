# \s matches any whitespace character [ \r\n\t\f ].

# ach05_01.png


# \S matches any non-white space character.

# ach05_02.png

# Task

# You have a test string . Your task is to match the pattern
# Here,  denotes whitespace characters, and  denotes non-white space characters.

# Note

# This is a regex only challenge. You are not required to write code.
# You have to fill the regex pattern in the blank (_________).

Regex_Pattern = r"\S{2}(\s\S{2}){2}"    # Do not delete 'r'.

import re
print(str(bool(re.search(Regex_Pattern, input()))).lower())