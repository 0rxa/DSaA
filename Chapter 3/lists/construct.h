#include <stdlib.h>

struct numlist
{
	int num;
	struct numlist* next;
} *head;

struct numlist*
EmptyList()
{
	return NULL;
}

struct numlist*
MakeList( int num, struct numlist* next )
{
	struct numlist* tmp = (struct numlist*)malloc(sizeof(struct numlist));
	tmp->num = num;
	tmp->next = next;
	return tmp;
}

void
print( struct numlist* tmp )
{
	printf("%d\n", tmp->num);
	if( tmp->next != NULL )
	{
		print(tmp->next);
	}
}
