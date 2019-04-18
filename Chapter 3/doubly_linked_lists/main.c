#include <stdio.h>
#include "list.h"

int main(int argc, char* argv[])
{
	//list* l = MakeListLeft(3, MakeListLeft(1, MakeListRight(5, MakeListRight(2, MakeListLeft(4, EmptyList())))));

	puts("TEST MakeListLeft");
	list* l = MakeListLeft(1, MakeListLeft(2, MakeListLeft(3, EmptyList())));
	print_f(print_r(l));
	puts("");

	puts("TEST MakeListRight");
	list* j = MakeListRight(1, MakeListRight(2, MakeListRight(3, EmptyList())));
	print_r(print_f(j));
}
