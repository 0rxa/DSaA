#include <stdio.h>
#include "bt.h"

int main(int argc, char* argv[])
{
	node* root = MakeTree(
			8,
			MakeTree(
				3,
				Leaf(1),
				MakeTree(
					6,
					EmptyTree(),
					Leaf(7))),
			MakeTree(
				11,
				MakeTree(
					9,
					EmptyTree(),
					Leaf(10)),
				MakeTree(
					14,
					Leaf(12),
					Leaf(15)))
			);

	printf("Height: %d\n", height(root));
	printf("max_size: %d\n", max_size(height(root)));
	printf("real_size: %d\n", real_size(root));
}
