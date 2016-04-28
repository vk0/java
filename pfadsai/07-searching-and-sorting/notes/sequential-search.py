# Sequential Search
# Check out the video lecture for a full breakdown, in this Notebook all we do is implement Sequential Search for an Unordered List and an Ordered List.

def seq_search(arr,ele):
    """
    General Sequential Search. Works on Unordered lists.
    """
    # Start at position 0
    pos = 0
    # Target becomes true if ele is in the list
    found = False

    # go until end of list
    while pos < len(arr) and not found:

        # If match
        if arr[pos] == ele:
            found = True

        # Else move one down
        else:
            pos  = pos+1

    return found

arr = [1,9,2,8,3,4,7,5,6]
print seq_search(arr,1) #True
print seq_search(arr,10) #False

# Ordered List
# If we know the list is ordered than, we only have to check until we have found the element or an element greater than it.

def ordered_seq_search(arr,ele):
    """
    Sequential search for an Ordered list
    """
    # Start at position 0
    pos = 0

    # Target becomes true if ele is in the list
    found = False

    # Stop marker
    stopped = False

    # go until end of list
    while pos < len(arr) and not found and not stopped:

        # If match
        if arr[pos] == ele:
            found = True

        else:

            # Check if element is greater
            if arr[pos] > ele:
                stopped = True

            # Otherwise move on
            else:
                pos  = pos+1

    return found

arr.sort()
ordered_seq_search(arr,3) #True
ordered_seq_search(arr,1.5) #False