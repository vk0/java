# On-Site Question 3 - SOLUTION

# Problem
# Given two rectangles, determine if they overlap. The rectangles are defined as a Dictionary, for example:

r1 = {

         # x and y coordinates of the bottom-left corner of the rectangle
         'x': 2 , 'y': 4,

         # Width and Height of rectangle
         'w':5,'h':12}

# If the rectangles do overlap, return the dictionary which describes the overlapping section

# Requirements
# Make sure the dictionary you output is in the same form as the input.
# Feel free to use an IDE for the code, but make sure you use paper/pencil or whiteboard to draw out your plan and logic

# Solution
# This is a problem where it helps a lot to draw out your thinking. There are a few things we will need to think about:
# How can we determine an intersection?
# What if a rectangle is fully inside another rectangle?
# What if there is no intersection, but the rectangles share an edge?
# The key to solving this problem is to break it up in to sub-problems. We can split up the problem into an x-axis problem and a y-axis problem.
# We will create a function that can detect overlap in 1 dimension. Then we will split the rectangles into x and width, and y and height components. We can then determine that if there is overlap on both dimensions, then the rectangles themselves intersect!
# In order to understand the calc_overlap function, draw out two flat lines and follow along with the function and notice how it detects an overlap!

# Let's begin by creating a general function to detect overlap in a single dimension:

def calc_overlap(coor1,dim1,coor2,dim2):
    """
    Takes in 2 coordinates and their length in that dimension
    """

    # Find greater of the two coordinates
    # (this is either the point to the most right
    #  or the higher point, depending on the dimension)

    # The greater point would be the start of the overlap
    greater = max(coor1,coor2)

    # The lower point is the end of the overlap
    lower = min(coor1+dim1,coor2+dim2)

    # Return a tuple of Nones if there is no overlap

    if greater >= lower:
        return (None,None)

    # Otherwise, get the overlap length
    overlap = lower-greater

    return (greater,overlap)

def calc_rect_overlap(r1,r2):


    x_overlap, w_overlap = calc_overlap(r1['x'],r1['w'],r2['x'],r2['w'])

    y_overlap, h_overlap = calc_overlap(r1['y'],r1['h'],r2['y'],r2['h'])

    # If either returned None tuples, then there is no overlap!
    if not w_overlap or not h_overlap:
        print 'There was no overlap!'
        return None

    # Otherwise return the dictionary format of the overlapping rectangle
    return { 'x':x_overlap,'y': y_overlap,'w':w_overlap,'h':h_overlap}

# Our solution is O(1) for both time and space! Let's see it in action:

r1 = {'x': 2 , 'y': 4,'w':5,'h':12}
r2 = {'x': 1 , 'y': 5,'w':7,'h':14}

calc_rect_overlap(r1,r2) # {'h': 11, 'w': 5, 'x': 2, 'y': 5}

# Make sure to review the answer and practice writing it out by hand!
