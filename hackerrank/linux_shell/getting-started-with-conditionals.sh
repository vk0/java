# if statements in Bash are often used in four important ways:

# 1. if...then...fi statements
# 2. if...then...else...fi statements
# 3. if..elif..else..fi
# 4. if..then..else..if..then..fi..fi.. (Nested Conditionals)
# The Recommended Resources section may give you a clearer idea of conditionals in Bash.

# Your task

# Read in one character from the user (this may be 'Y', 'y', 'N', 'n'). If the character is 'Y' or 'y' display "YES". If the character is 'N' or 'n' display "NO". No other character will be provided as input.

# Input Format
# One character (this may be 'Y', 'y', 'N', 'n').

# Output Format
# One word: either "YES" or "NO" (quotation marks excluded).

# Sample Input 1

# y
# Sample Output 1

# YES
# Recommended Resources

# A quick but useful tutorial for bash newcomers is here.
# Handling input is documented and explained quite well on this page.
# Different ways in which 'if' statements may be used in Bash are demonstrated here.

read char
if [ "$char" == "Y" -o "$char" == "y" ]; then
    echo "YES";
elif [ "$char" == "N" -o "$char" == "n" ]; then
    echo "NO"
fi