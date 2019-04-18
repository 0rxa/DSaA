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
init(int num, list** l)
{
	(*l)->num = num;
}

list*
MakeListRight(int num, list* l)
{
	list* tmp = malloc(sizeof(list));
	tmp->num = num;
	tmp->next = l;
	if( l != NULL && l->previous == NULL )
	{
		l->previous = tmp;
	}
	return tmp;
}

list*
MakeListLeft(int num, list* l)
{
	list* tmp = malloc(sizeof(list));
	tmp->num = num;
	tmp->previous = l;
	if( l != NULL && l->next == NULL )
	{
		l->next = tmp;
	}
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

list*
print_f( list* l )
{
	printf("%d\n", l->num);
	if( l->next != NULL )
	{
		print_f(l->next);
	}
	else
	{
		return l;
	}
}

list*
print_r( list* l )
{
	printf("%d\n", l->num);
	if( l->previous != NULL )
	{
		print_r(l->previous);
	}
	else
	{
		return l;
	}
}

void
test( list* l )
{
	printf("num: %d\n", l->num);
	printf("next: %d\n", l->next == NULL);
	printf("previous: %d\n", l->previous == NULL);
}
