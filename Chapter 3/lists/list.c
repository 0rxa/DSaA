#include <stdio.h>
#include "mutate.h"

int main(int argc, char* argv[])
{
	head = MakeList(3, MakeList(1, MakeList(4, MakeList(2, MakeList(5, EmptyList())))));
	struct numlist* newel = MakeList(99, EmptyList());
	struct numlist* newlist = MakeList(6, MakeList(7, MakeList(8, MakeList(9, MakeList(10, EmptyList())))));

	printf("Test EmptyList function: %d\n", isEmpty(EmptyList()));
	printf("Test MakeList function: %d\n", isEmpty(head));

	print(head);
	puts("################################################");
	puts("");

	replaceFirst(&head, newel);
	print(head);
	puts("################################################");
	puts("");

	replaceRest(&head, newlist);
	print(head);
	printf("last: %d\n", (last(head))->num);
	puts("################################################");
	puts("");

	head = MakeList(3, MakeList(1, MakeList(4, MakeList(2, MakeList(5, EmptyList())))));
	newlist = MakeList(6, MakeList(7, MakeList(8, MakeList(9, MakeList(10, EmptyList())))));
	puts("RESET");
	printf("Test head: %d\n", !isEmpty(head));
	printf("Test newlist: %d\n", !isEmpty(newlist));
	print(head);
	puts("################################################");
	puts("");

	struct numlist* test = append(head, newlist);
	print(test);
	puts("################################################");
	puts("");
}
