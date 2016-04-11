# Deques Overview
# A deque, also known as a double-ended queue, is an ordered collection of items similar to the queue. It has two ends, a front and a rear, and the items remain positioned in the collection. What makes a deque different is the unrestrictive nature of adding and removing items. New items can be added at either the front or the rear. Likewise, existing items can be removed from either end. In a sense, this hybrid linear structure provides all the capabilities of stacks and queues in a single data structure.
# It is important to note that even though the deque can assume many of the characteristics of stacks and queues, it does not require the LIFO and FIFO orderings that are enforced by those data structures. It is up to you to make consistent use of the addition and removal operations.
# Let's see an Image to visualize the Deque Data Structure:

from IPython.display import Image
Image('http://www.codeproject.com/KB/recipes/669131/deque.png')

# Note how we can both add and remove from the front and the back of the Deque. In the next lecture, we will implement our own Deque class!