# Introduction to Recursion
# In this lecture we will go over the basics of Recursion.
# What is Recursion?
# There are two main instances of recursion. The first is when recursion is used as a technique in which a function makes one or more calls to itself. The second is when a data structure uses smaller instances of the exact same type of data structure when it represents itself. Both of these instances are use cases of recursion.
# Recursion actually occurs in the real world, such as fractal patterns seen in plants!
# Why use Recursion?
# Recursion provides a powerful alternative for performing repetitions of tasks in which a loop is not ideal. Most modern programming languages support recursion and recursion serves as a great tool for building out particular data structures.
# We'll start this introduction with an example of recursion- a factorial function.

def fact(n):
    '''
    Returns factorial of n (n!).
    Note use of recursion
    '''
    # BASE CASE!
    if n == 0:
        return 1

    # Recursion!
    else:
        return n * fact(n-1)

print(fact(5))

# Note how we had an if statement to check if a base case occured. Without it this function would not have successfully completed running. We can visualize the recursion with the following figure:

# from IPython.display import Image
# from IPython.core.display import HTML
# Image(url= 'http://faculty.cs.niu.edu/~freedman/241/241notes/recur.gif')