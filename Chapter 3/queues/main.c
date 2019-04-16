#include <stdio.h>
#include "queues.h"

int main(int argc, char* argv[])
{
	queue* q;
	q = push(push(push(push(push(EmptyQueue(), 1), 2), 3), 4), 5);

	do
	{
		printf("%d\n", top(q));
	} while( pop(&q) );
}
