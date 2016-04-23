Terms you'll find helpful in completing today's challenge are outlined below, along with sample Java code (where appropriate).

Linked List
A singly linked list is a data structure having a list of elements where each element has a reference pointing to the next element in the list. Its elements are generally referred to as nodes; each node has a data field containing a data value and a next field pointing to the next element in the list (or null if it is the last element in the list). The diagram below depicts a linked list of length 3:
myLinkedList.png

The sample code below demonstrates how to create a LinkedList of Strings, and some of the operations that can be performed on it.
LinkedList<String> myLinkedList = new LinkedList<String>();

myLinkedList.add("First"); // adds a node with data="First" to back of the (empty) list
myLinkedList.add("Second"); // adds a node with data="Second" to the back of the list
myLinkedList.addFirst("Third"); // inserts a node with data="Third" at front of the list
myLinkedList.addLast("Fourth"); // inserts a node with data="Fourth" at back of the list
myLinkedList.add(2, "Fifth"); // inserts a node with data="Fifth" at index 2
System.out.println(myLinkedList); // print the list: [Third, First, Fifth, Second, Fourth]

// Print the value at list index 2:
System.out.println(myLinkedList.get(2));

// Empty the list
myLinkedList.clear();
System.out.println(myLinkedList); // print the newly emptied list: []

myLinkedList.add("Sixth"); // adds a node with data="Sixth" to back of the (empty) list
System.out.println(myLinkedList); // print the list: [Sixth]

The above code produces the following output:
[Third, First, Fifth, Second, Fourth]
Fifth
[]
[Sixth]