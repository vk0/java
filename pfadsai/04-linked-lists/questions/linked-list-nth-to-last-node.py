# Linked List Nth to Last Node - SOLUTION
# Problem Statement
# Write a function that takes a head node and an integer value n and then returns the nth to last node in the linked list. For example, given:


class Node:
    def __init__(self, value):
        self.value = value
        self.nextnode  = None

a = Node(1)
b = Node(2)
c = Node(3)
d = Node(4)
e = Node(5)

a.nextnode = b
b.nextnode = c
c.nextnode = d
d.nextnode = e

# Solution
# One approach to this problem is this:
# Imagine you have a bunch of nodes and a "block" which is n-nodes wide. We could walk this "block" all the way down the list, and once the front of the block reached the end, then the other end of the block would be a the Nth node!
# So to implement this "block" we would just have two pointers a left and right pair of pointers. Let's mark out the steps we will need to take:
# Walk one pointer n nodes from the head, this will be the right_point
# Put the other pointer at the head, this will be the left_point
# Walk/traverse the block (both pointers) towards the tail, one node at a time, keeping a distance n between them.
# Once the right_point has hit the tail, we know that the left point is at the target.
# Let's see the code for this!

def nth_to_last_node(n, head):

    left_pointer  = head
    right_pointer = head

    # Set right pointer at n nodes away from head
    for i in range(n-1):

        # Check for edge case of not having enough nodes!
        if not right_pointer.nextnode:
            raise LookupError('Error: n is larger than the linked list.')

        # Otherwise, we can set the block
        right_pointer = right_pointer.nextnode

    # Move the block down the linked list
    while right_pointer.nextnode:
        left_pointer  = left_pointer.nextnode
        right_pointer = right_pointer.nextnode

    # Now return left pointer, its at the nth to last element!
    return left_pointer


# This would return the node d with a value of 4, because its the 2nd to last node.
target_node = nth_to_last_node(2, a)
print(target_node.value)