public static  Node insert(Node head,int data) {
    // This is a "method-only" submission.
    // You only need to complete this method.
    Node current = head;
    // Setting up our new node to add
    Node newTail = new Node(data);
    newTail.next = null;
    // if the list isn't empty
    if (current != null) {
        // get to the end of the list and set the current
        // to the last element
       while (current.next != null) {
           // iterating through
            current = current.next;
        }
    } else {
        // otherwise the list is empty and we should just return our new node with the data
        return newTail;
    }
    // then add our new tail onto the end of the list
    current.next = newTail;
    return head;
}


// public static  Node insert(Node head,int data){
//     // if list has no elements, return a new node
//     if(head == null){
//         return new Node(data);
//     }

//     // else iterate through list, add node to tail, and return head
//     Node tmp = head;
//     while(tmp.next != null){
//         tmp = tmp.next;
//     }
//     tmp.next = new Node(data);

//     return head;
// }