#include <stdio.h>
#include "qt.h"

int main(int argc, char* argv[])
{
	node* root = makeQT(
			baseQT(0),
			baseQT(3),
			baseQT(1),
			baseQT(2));

	printf("Root isVal: %d\n", isVal(root));
	printf("lu isVal: %d\n", isVal(lu(root)));
	printf("ru isVal: %d\n", isVal(ru(root)));
	printf("rl isVal: %d\n", isVal(rl(root)));
	printf("ll isVal: %d\n", isVal(ll(root)));
	puts("");

	puts("Tree:");
	print_node(root);
	rotate(root);
	puts("");
	puts("Rotated:");
	print_node(root);
}
