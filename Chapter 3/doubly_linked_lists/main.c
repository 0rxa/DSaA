#include <stdio.h>
#include "list.h"

int main(int argc, char* argv[])
{
	list* l = MakeListLeft(3, MakeListLeft(1, MakeListRight(5, MakeListRight(2, MakeListLeft(4, EmptyList())))));
}
