# Objective
# In this challenge, we practice using the head command to display the first nn characters of a text file.

# Resources
# By default, it displays the first 1010 lines when used in the form:

# head [filename]
# head -n 11 [filename]  -> First 11 lines
# head -c 20 [filename]  -> First 20 characters
# Since we will provide the text files via STDIN the filename may be ignored.

# We can also specify a certain number of lines to be displayed and list multiple filenames as well. It may also be used to display a specified number of bytes from an input file. Click here for more details about using the head command.

# Task
# Display the first 2020 characters of an input file.

# Input Format

# A text file.

# Output Format

# Output the first 2020 characters of the text file.

# Sample Input

# New York is a state in the Northeastern and Mid-Atlantic regions of the United States.
# New York is the 27th-most extensive, the third-most populous populated of the 50 United States.
# New York is bordered by New Jersey and Pennsylvania to the south.
# About one third of all the battles of the Revolutionary War took place in New York.
# Henry Hudson's 1609 voyage marked the beginning of European involvement with the area.
# Sample Output

# New York is a state

head -c 20