
Terms you'll find helpful in completing today's challenge are outlined below, along with sample Java code (where appropriate).

Tree Traversal
A traversal of some binary tree, t, is an algorithm that iterates through each node in t exactly 1 time.

InOrder Traversal
An inorder traversal of tree t is a recursive algorithm that follows the the left subtree; once there are no more left subtrees to process, we process the right subtree. The elements are processed in left-root-right order. The basic algorithm is as follows:
inOrder(t){
    if(t is not empty){
        inOrder( left subtree of t)
        process t's root element
        inOrder( right subtree of t )
    }
}
An inorder traversal of a binary search tree will process the tree's elements in ascending order.

PostOrder Traversal
A postorder traversal of tree t is a recursive algorithm that follows the the left and right subtrees before processing the root element. The elements are processed left-right-root order. The basic algorithm is as follows:
postOrder(t){
    if(t is not empty){
        postOrder( left subtree of t)
        postOrder( right subtree of t )
        process t's root element
    }
}

PreOrder Traversal
A preorder traversal of tree t is a recursive algorithm that processes the root and then performs preorder traversals of the left and right subtrees. The elements are processed root-left-right order. The basic algorithm is as follows:
preOrder(t){
    if(t is not empty){
        process t's root element
        preOrder( left subtree of t)
        preOrder( right subtree of t )
    }
}
Because a preorder traversal goes as deeply to the left as possible, it's also known as a depth-first-search.

Level-Order Traversal
A level-order traversal of tree t is a recursive algorithm that processes the root, followed by the children of the root (from left to right), followed by the grandchildren of the root (from left to right), etc. The basic algorithm shown below uses a queue of references to binary trees to keep track of the subtrees at each level:
levelOrder(BinaryTree t){
    if(t is not empty)
        queue.enqueue(t)
        while( queue is not empty ){
            BinaryTree tree = queue.dequeue();
            process tree's root;
            if( tree has non-empty left subtree ){
                queue.enqueue( left subtree of t)
            }
            if( tree has non-empty right subtree ){
                queue.enqueue( right subtree of t )
            }
        }
    }
}
Because a preorder traversal goes level-by-level, it's also known as a breadth-first-search.

Example
BinaryTree.png

The binary tree above has the following traversals:
InOrder: 1 2 3 4 5 6 7
PostOrder: 1 3 2 5 7 6 4
PreOrder: 4 2 1 3 6 5 7
Level-Order: 4 2 6 1 3 5 7