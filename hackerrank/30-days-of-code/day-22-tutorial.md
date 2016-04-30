Terms you'll find helpful in completing today's challenge are outlined below, along with sample Java code (where appropriate).

Binary Tree
Fundamentally, a binary tree is composed of nodes connected by edges (with further restrictions discussed below). Some binary tree, t, is either empty or consists of a single root element with two distinct binary tree child elements known as the left subtree and the right subtree of t. As the name binary suggests, a node in a binary tree has a maximum of 2 children.

The following diagrams depict 2 different binary trees:
Binary Trees.png

Here are the basic facts and terms to know about binary trees:
The convention for binary tree diagrams is that the root is at the top, and the subtrees branch down from it.
A node's left and right subtrees are referred to as children, and that node can be referred to as the parent of those subtrees.
A non-root node with no children is called a leaf.
Some node A is an ancestor of some node B if B is located in a left or right subtree whose root node is A. This means that the root node of binary tree t is the ancestor of all other nodes in the tree.
If some node A is an ancestor of some node B, then the path from A to B is the sequence of nodes starting with A, moving down the ancestral chain of children, and ending with B.
The depth (or level) of some node A is its distance (i.e.: number of edges) from the tree's root node.
Simply put, the height of a tree is the number of edges between the root node and its furthest leaf. More technically put, it's 1 + the maximum of the heights of its left and right subtrees. Any node has a height of 1, and the height of an empty subtree is -1. Because the height of each node is 1 + the height of its subtrees and an empty subtree's height is -1, the height of a single-element tree or leaf node is 0.

Let's apply some of the terms we learned above to the binary tree on the right:
The root node is A.
The respective left and right children of A are B and E. The left child of B is C. The respective left and right children of E are F and D.
Nodes C, F, and D are leaves (i.e.: each node is a leaf).
The root is the ancestor of all other nodes; B is an ancestor of D, and E is an ancestor of F and D.
The path between A and C is A → B → C. The path between A and F is A → E → F. The path between A and D is A → E → D.
The depth of root node A is 0. The depth of nodes B and E is 1. The depth of nodes C, F, and D, is 2.
The height of the tree (height(t))is 2. We calculate this recursively as height(t) = 1 + (MAX(height(rootleftChild), height(rootrightChild))). Because this is long and complicated when expanded, we'll break it down using an image of a slightly simpler version of t whose height is still 2:

BT Height.png

In the diagram above, the height of t is 2 because that is the maximum height of t's left and right subtrees.

Binary Search Tree
A Binary Search Tree, t, is a binary tree that is either empty or:
Each element in leftTree(t) is less than or equal to the root element of t.
Each element in rightTree(t) is greater than the root element of t.
Both leftTree(t) and rightTree(t) are BSTs

You can essentially think of it as a regular binary tree where for each node parent having a leftChild and rightChild, leftChild.value ≤ parent.value < rightChild.value. The binary tree of integers (on the left side) above is a binary search tree.