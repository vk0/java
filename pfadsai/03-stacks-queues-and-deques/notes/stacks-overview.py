# Stacks Overview
# Please see the lecture video for the full Overview on Stacks!
# A stack is an ordered collection of items where the addition of new items and the removal of existing items always takes place at the same end. This end is commonly referred to as the “top.” The end opposite the top is known as the “base.”
# The base of the stack is significant since items stored in the stack that are closer to the base represent those that have been in the stack the longest. The most recently added item is the one that is in position to be removed first.
# This ordering principle is sometimes called LIFO, last-in first-out. It provides an ordering based on length of time in the collection. Newer items are near the top, while older items are near the base.
# For example, consider the figure below:

from IPython.display import Image
url ='https://upload.wikimedia.org/wikipedia/commons/b/b4/Lifo_stack.png'
Image(url)

# Note how the first items "pushed" to the stack begin at the base, and as items are "popped" out. Stacks are fundamentally important, as they can be used to reverse the order of items. The order of insertion is the reverse of the order of removal.
# Considering this reversal property, you can perhaps think of examples of stacks that occur as you use your computer. For example, every web browser has a Back button. As you navigate from web page to web page, those pages are placed on a stack (actually it is the URLs that are going on the stack). The current page that you are viewing is on the top and the first page you looked at is at the base. If you click on the Back button, you begin to move in reverse order through the pages.
# In the next lecture we will implement our own Stack class!