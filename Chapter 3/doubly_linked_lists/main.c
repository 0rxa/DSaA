#include <stdio.h>
#include "list.h"

int main(int argc, char* argv[])
{
	list* l = MakeListLeft(3, EmptyList());

	l = MakeListLeft(2, l);
	l = MakeListLeft(1, l);
	l = MakeListLeft(0, l);

	l=print_r(l);
	l=MakeListRight(90, l);
	l=MakeListRight(91, l);
	l=MakeListRight(92, l);
	l=MakeListRight(93, l);
	//system("clear");
	print_r(print_f(l));
}
