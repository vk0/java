# Implementation of Insertion Sort
# Insertion Sort builds the final sorted array (or list) one item at a time. It is much less efficient on large lists than more advanced algorithms such as quicksort, heapsort, or merge sort.
# Resources for Review
# Check out the resources below for a review of Insertion sort!
# Wikipedia
# Visual Algo
# Animation
# Sorting Algorithms Animcation with Pseudocode

def insertion_sort(arr):

    # For every index in array
    for i in range(1,len(arr)):

        # Set current values and position
        currentvalue = arr[i]
        position = i

        # Sorted Sublist
        while position>0 and arr[position-1]>currentvalue:

            arr[position]=arr[position-1]
            position = position-1

        arr[position]=currentvalue

arr =[3,5,4,6,8,1,2,12,41,25]
insertion_sort(arr)
arr # [1, 2, 3, 4, 5, 6, 8, 12, 25, 41]