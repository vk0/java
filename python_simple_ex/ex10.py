# function overlapping()

# takes two lists

# returns True if they have at least one member in common,
# False otherwise.

# You may use your is_member() function, or the in operator, but for the sake 
# of the exercise, you should (also) write it using two nested for-loops.

def overlapping(list1, list2):
    for item1 in list1:
        for item2 in list2:
            if item1 == item2:
                return True
                break
    return False

# test
print(overlapping([1,2,3], [1,4,6]))
print(overlapping([1,2,3], [5,4,6]))
