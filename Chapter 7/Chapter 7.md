# Binary Search Trees
Binary search trees are a type of
binary tree that provide an efficient
way of storing data and allows for
quick searching.

At each tree node should be information
that can tell the algorithm either that
the seeked data is found or in which
subtree to look for it.

A **Binary Search Tree** is a binary tree
that is either empty or satisfies these
conditions:
* All values occurring in the left subtree are
	smaller than that of the root.
* All values occurring in the right subtree are
	larger than that of the root.
* The left and right subtrees are themselves
	binary search trees.

The constructors and selectors of general
binary trees are still useful for binary search
trees at the promise of maintaining the
node value ordering.

## Building Binary Search Trees
Binary search trees are built from the root
down. So in order to insert a new value v
the following cases arise:

* The given tree is empty.
	* Assign the value to root
	* Assign NULL to left and right
		subtrees.

* The given tree is non-empty.
	* If *v* is smaller than value of root
		assign it to the left subtree.
	* If *v* is larger than value of root
		assign it to the right subtree.
	* If *v* is equal to the value of root
		exit.

### Deleting nodes from binary search trees
Suppose for some reason an item needs to be
removed or deleted from a binary search tree.
It would not be efficient to rebuild the
binary tree with the new element added or the
old one removed, so we use better algorithms
for updating the existing binary tree.

* If the node in question is a leaf, remove it.
* If only one of the nodes subtrees is non-empty
	move it one level up.
* If the node has two subtrees find the 
	leftmost node of the right node
	and use it to replace the node
	in question.

### Balancing binary search trees
BSTs built by inserting elements randomly
are generally balanced and their height is
about log<sub>2</sub>n.
