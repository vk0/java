# Implement a Linked List - SOLUTION
# Problem Statement
# Implement a Linked List by using a Node class object. Show how you would implement a Singly Linked List and a Doubly Linked List!
# Solution
# Since this is asking the same thing as the implementation lectures, please refer to those video lectures and notes for a full explanation. The code from those lectures is displayed below:

class LinkedListNode(object):

    def __init__(self,value):

        self.value = value
        self.nextnode = None

a = LinkedListNode(1)
b = LinkedListNode(2)
c = LinkedListNode(3)
a.nextnode = b
b.nextnode = c

class DoublyLinkedListNode(object):

    def __init__(self,value):

        self.value = value
        self.next_node = None
        self.prev_node = None

a = DoublyLinkedListNode(1)
b = DoublyLinkedListNode(2)
c = DoublyLinkedListNode(3)

# Setting b after a
b.prev_node = a
a.next_node = b

# Setting c after a
b.next_node = c
c.prev_node = b