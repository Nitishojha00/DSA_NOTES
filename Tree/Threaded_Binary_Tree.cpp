Threaded Binary Tree (TBT) – Notes

1. Introduction:
A Threaded Binary Tree is a type of binary tree in which the NULL pointers are replaced by special pointers called "threads". These threads point to the in-order predecessor or successor of the node, which helps in faster traversal without using stack or recursion.

2. Motivation:

In a binary tree, many pointers are NULL.

In-order traversal typically uses recursion or stack.

Threaded Binary Tree utilizes NULL pointers to store additional information (in-order successor or predecessor) and reduces traversal overhead.

3. Types of Threaded Binary Trees:

Single Threaded: Only left or right NULL pointers are replaced with threads.

Left Threaded: left NULL points to in-order predecessor.

Right Threaded: right NULL points to in-order successor.

Double Threaded: Both left and right NULL pointers are replaced with threads.

4. Node Structure:
Each node has additional boolean flags to indicate whether the left/right pointer is a child link or a thread.

Example (C++ style):

struct Node {
    int data;
    Node* left;
    Node* right;
    bool leftThread;
    bool rightThread;
};
5. In-order Traversal (Threaded Binary Tree):

Start from the leftmost node.

While current node is not NULL:

Print current node’s data.

If rightThread is true, go to current->right.

Else go to the leftmost node in the right subtree.

6. Advantages:

No recursion or stack needed for in-order traversal.

Efficient memory usage (utilizes NULL pointers).

Faster in-order traversal in many cases.

7. Disadvantages:

Insertion and deletion are more complex than in a normal binary tree.

Thread management adds extra logic.

8. Applications:

Situations requiring fast and memory-efficient in-order traversal.

Syntax trees in compilers.

Memory-constrained environments like embedded systems.