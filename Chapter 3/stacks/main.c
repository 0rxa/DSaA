#include <stdio.h>
#include "stack.h"

int main(int argc, char* argv[])
{
	//head = push(head, 6);	
	//head = push(head, 7);
	//head = push(head, 8);
	head = push(push(push(EmptyStack(), 6), 7), 8);

	printf("%d\n", top(head));
	pop(&head);
	printf("%d\n", top(head));
	pop(&head);
	printf("%d\n", top(head));
	pop(&head);
	printf("%d\n", top(head));
}
