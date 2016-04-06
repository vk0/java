# O(1) Constant

# Note how this function is constant because regardless of the list size, the function will only ever take a constant step size, in this case 1, printing the first value from a list. so we can see here that an input list of 100 values will print just 1 item, a list of 10,000 values will print just 1 item, and a list of n values will print just 1 item!

def func_constant(values):
    '''
    Prints first item in a list of values.
    '''
    print values[0]

func_constant([1,2,3])

# O(n) Linear
# This function runs in O(n) (linear time). This means that the number of operations taking place scales linearly with n, so we can see here that an input list of 100 values will print 100 times, a list of 10,000 values will print 10,000 times, and a list of n values will print n times.


def func_lin(lst):
    '''
    Takes in list and prints out all values
    '''
    for val in lst:
        print val

func_lin([1,2,3])

# O(n^2) Quadratic
# Note how we now have two loops, one nested inside another. This means that for a list of n items, we will have to perform n operations for every item in the list! This means in total, we will perform n times n assignments, or n^2. So a list of 10 items will have 10^2, or 100 operations. You can see how dangerous this can get for very large inputs! This is why Big-O is so important to be aware of!

def func_quad(lst):
    '''
    Prints pairs for every item in list.
    '''
    for item_1 in lst:
        for item_2 in lst:
            print item_1,item_2

lst = [0, 1, 2, 3]

func_quad(lst)

# Calculating Scale of Big-O
# When it comes to Big O notation we only care about the most significant terms, remember as the input grows larger only the fastest growing terms will matter. If you've taken a calculus class before, this will reminf you of taking limits towards infinity. Let's see an example of how to drop constants:

# The print_once() function is O(n) since it will scale linearly with the input. What about the next example?

def print_once(lst):
    '''
    Prints all items once
    '''
    for val in lst:
        print val

# We can see that the first function will print O(n) items and the second will print O(3n) items. However for n going to inifinity the constant can be dropped, since it will not have a large effect, so both functions are O(n).

def print_3(lst):
    '''
    Prints all items three times
    '''
    for val in lst:
        print val

    for val in lst:
        print val

    for val in lst:
        print val

# So let's break down the operations here. We can combine each operation to get the total Big-O of the function:
# O(1+n/2+10)
# We can see that as n grows larger the 1 and 10 terms become insignificant and the 1/2 term multiplied against n will also not have much of an effect as n goes towards infinity. This means the function is simply O(n)!

def comp(lst):
    '''
    This function prints the first item O(1)
    Then is prints the first 1/2 of the list O(n/2)
    Then prints a string 10 times O(10)
    '''
    print lst[0]

    midpoint = len(lst)/2

    for val in lst[:midpoint]:
        print val

    for x in range(10):
        print 'number'