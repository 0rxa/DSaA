#include <stdlib.h>

struct list
{
	int num;
	struct list* previous;
	struct list* next;
};
typedef struct list list;

int
isEmpty(list* l)
{
	return (l == NULL);
}

list*
EmptyList()
{
	return NULL;
}

list*
MakeListLeft(int num, list* l)
{
	list* tmp = malloc(sizeof(list));
	if( !isEmpty(l) )
	{
		l->next = tmp;
	}
	tmp->num = num;
	tmp->previous = l;
	return tmp;
}

list*
MakeListRight(int num, list* l)
{
	list* tmp = malloc(sizeof(list));
	if( !isEmpty(l) )
	{
		l->previous = tmp;
	}
	tmp->next = l;
	tmp->num = num;
	tmp->previous = NULL;
	return tmp;
}

int
first(list* l)
{
	return l->num;
}

list*
restLeft(list* l)
{
	return l->previous;
}

list*
restRight(list* l)
{
	return l->next;
}
