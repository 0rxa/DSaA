#include <stdio.h>
#include "qt.h"

int main(int argc, char* argv[])
{
	node* rl2 = makeQT(
			baseQT(110),
			baseQT(100),
			baseQT(120),
			baseQT(90)
			);

	node* ru1 = makeQT(
			baseQT(60),
			rl2,
			baseQT(70),
			baseQT(80)
			);

	node* ll0 = makeQT(
			baseQT(50),
			baseQT(40),
			ru1,
			baseQT(30)
			);

	node* root = makeQT(
			baseQT(0),
			ll0,
			baseQT(10),
			baseQT(20)
			);

	//print(root);
	//printf("%d\n", average(&root));
	average(&root);
	print(root);
	//print_nodes(root);
}
