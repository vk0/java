# The expression \w will match any word character.
# Word characters include alphanumeric characters (-, - and -) and underscores (_).

# ach03_01.png



# \W matches any non-word character.
# Non-word characters include characters other than alphanumeric characters (-, - and -) and underscore (_).

# ach03_02.png

# Task

# You have a test string . Your task is to match the pattern
# Here  denotes any word character and  denotes any non-word character.

# Note

# This is a regex only challenge. You are not required to write any code.
# You only have to fill the regex pattern in the blank (_________).

Regex_Pattern = r"\w{3}\W\w{10}\W\w{3}"    # Do not delete 'r'.

import re
print(str(bool(re.search(Regex_Pattern, input()))).lower())