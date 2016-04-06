# for loops in Bash can be used in several ways: - iterating between two integers, aa and bb - iterating between two integers, aa and bb, and incrementing by cc each time - iterating through the elements of an array, etc.

# Use for loops to display the natural numbers from 11 to 5050.

# Input
# There is no input

# Output

# 1
# 2
# 3
# 4
# 5
# .
# .
# .
# .
# .
# 50
# Recommended Resources

# A quick but useful tutorial for Bash newcomers is here.
# Handling input is documented and explained quite well on this page.
# Different ways in which for loops may be used are explained with examples here.

for i in {1..50}
do
echo $i;
done