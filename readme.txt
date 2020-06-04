Gafei Szeto
CSE 674
Homework 3
May 23rd, 2020

------------
Description
------------

In this homework, we're asked to implment different versions of
the balanced Binary Search Trees and analyze them.

-------------------
Binary Search Trees
-------------------

Binary Search Trees are binary trees made of nodes with a left 
and right references. Each node has a root node that is larger 
then its left children, left subchildren and smaller then its 
right children and right subchildren.

In the Binary Search Tree, we have a function called "insert(int key)"
that will insert a new node into the binary search tree. 

The insert function will check to see if a root node exists. 
If a root node does not exist, it will create a new node and 
insert it into the tree. If a root node already exists, the insert 
function will insert a new node into the proper location on the 
binary search tree.

The remove function will remove a value specified by a key in the function.
It will search for the key and will then check how many children are in the
node to be removed. For nodes with two children we must figure out the 
"successor" of the node to be deleted. This node is the smallest key in the 
right subtree. The value in this successor node is saved, preserves the
order of the tree and then recursively deleted from the tree. 

To cacluate the height of the BST tree, we traverse down the left children
and the right children. The larger of the children is the height. If there
are no nodes in the tree, the tree is empty and will return -1.

Tree structures are displayed inorder and preorder. In the preorder
function both the root node is displayed first, then the left and right
child. In order will print the contents of the binary tree in order. 

The remove function was referenced from:
https://www.geeksforgeeks.org/binary-search-tree-data-structure/


-------------------
DSW Algorithm
-------------------

The DSW algorithm, called the Day, Stout, Warren algorithm, is a method to
balance binary search trees. Trees will decrease in height O(log n) nodes. 
In this algorith, the tree will compact itself into a right skewed 
binary tree using using the function createBackbone(). This function will
constantly perform a right rotate on until a right skewed linked list is 
formed. 

After that, a perfect binary tree is formed by converting this 
right skewed linked list into a peferct binary tree. The perfect binary
tree is created by obtaining the height of the right skewed, backbone, 
linked list, and performing a new height calculation to get the height
of the new balanced tree, by consistently "compressing" or rotating left
on every odd node of the right skewed linked list.

To cacluate the height of the BST tree, we traverse down the left children
and the right children. The larger of the children is the height. If there
are no nodes in the tree, the tree is empty and will return -1.

The insert and remove function are the same as in the original implementation
of the Binary Search Tree.

Tree structures are displayed inorder and preorder. In the preorder
function both the root node is displayed first, then the left and right
child. In order will print the contents of the binary tree in order. 

References for the DSW algorithm are below:
http://courses.cs.vt.edu/cs2604/spring05/mcpherson/note/BalancingTrees.pdf
http://www.geekviewpoint.com/java/bst/dsw_algorithm
https://github.com/palkakrzysiek/IT-class/blob/master/algorithms/structures/bst.cpp


-------------------
AVL Tree Algorithm
-------------------

The AVL tree is a self balancing binary search tree, where the heights of the
two child subtrees of any node differ by at most one. If the two child 
subtrees differ by more then one, then a rebalance is done to sustain this 
property. 

In the insert function, if a tree is empty, we insert a node at the root of the
tree. If the tree isn't empty, we recursively go down the tree through the 
root and search for a location to insert the node.  

As we're traversing the tree to insert, we must keep track of height of the 
ancestor node and update it. We'll also obtain the balance factor of the tree
and rotate the tree either "left left" if the balance is greater than 1,
along with the insert node's left child key,  "right right" if the balance is 
less than -1 along with the node's right child's key, "left right" if the balance
is greater than 1 along with the node's left child key, and "right left" if 
the balance is less than -1 along with the node's right child's key. 

The remove function is carried over from the Binary Search Tree.

Tree structures are displayed inorder and preorder. In the preorder
function both the root node is displayed first, then the left and right
child. In order will print the contents of the binary tree in order. 

AVL tree was referenced from:
https://www.geeksforgeeks.org/avl-tree-set-1-insertion/

--------------------
Splay Tree Algorithm
--------------------

The splay tree algorithm is a self balancing binary search tree where
recently accessed elements are quick to access again. Every operation, 
including a search, insert, or remove, will "splay" the tree and move
the node that was accessed to the root.

In the splay operation, we first check if the key is the root node.
If not, the node is checked against child of the root. It it's found
as either the left child or right child, it will rotate, right or left,
respectively. If the node has both a grandparent and parent, we will
perform a zig-zig rotation, (rotateRight twice) or a zag-zag rotation,
(rotateLeft twice). If a node is a left child of the parent, or is a 
parent of the right child of the grandparent we will perform a zag-zig 
(left then right rotate). If a node is a right child of its 
parent and left child of its grandparent, then we will perform a "zig-zag"
(right rotation and then left).

Splay Tree was referenced from:
https://www.geeksforgeeks.org/splay-tree-set-1-insert/