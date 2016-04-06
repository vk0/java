# for loops in Bash can be used in several ways:
# - iterating between two integers, aa and bb
# - iterating between two integers, aa and bb, and incrementing by cc each time
# - iterating through the elements of an array, etc.

# Your task is to use for loops to display only odd natural numbers from 11 to 9999.

# Input
# There is no input.

# Output

# 1
# 3
# 5
# .
# .
# .
# .
# .
# 99
# Recommended Resources

# A quick but useful tutorial for bash newcomers is here.
# Handling input is documented and explained quite well on this page.
# Different ways in which for loops may be used are explained with examples here.

for i in {1..99}
do
if [ $(($i%2)) -ne 0 ];
then
    echo $i;
else
    continue;
fi
done