#include <stdio.h>
#include "bst.h"

int main(int argc, char* argv[])
{
	node* nonbst = MakeTree(
			8,
			MakeTree(
				3,
				Leaf(1),
				MakeTree(
					6,
					Leaf(0),
					Leaf(12)
					)
				),
			MakeTree(
				11,
				MakeTree(
					9,
					EmptyTree(),
					EmptyTree()
					),
				MakeTree(
					14,
					Leaf(13),
					Leaf(15)
					)
				)
			);

	node* root = NULL;
	root = insert(root, 0);
	root = insert(root, -5);
	root = insert(root, -3);
	root = insert(root, -7);
	root = insert(root, -1);
	root = insert(root, 5);
	root = insert(root, 6);
	root = insert(root, 4);
	root = insert(root, 3);
	root = insert(root, 7);
	root = insert(root, -4);

	printf("isBST(root): %d\n", isBST(root));
	printf("isBST(nonbst): %d\n", isBST(nonbst));

	getchar();
	system("clear");

	printf("root->right\n");
	printf("%d\n", root->right->val);
	printf("%d\n", root->right->right->val);
	printf("%d\n", root->right->left->val);

	printf("Removed\n");
	root = delNode(root,  root->right->val);
	printf("%d\n", root->right->val);
	printf("%d\n", root->right->right->val);
	printf("%d\n", root->right->left->val);

	printf("isBST(root): %d\n", isBST(root));
	printf("isBST(nonbst): %d\n", isBST(nonbst));

	getchar();
	system("clear");

	order(nonbst);
}
