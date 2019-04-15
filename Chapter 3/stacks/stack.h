#include <stdlib.h>

struct stack{
	int num;
	struct stack* next;
} *head;

struct stack*
EmptyStack()
{
	return NULL;
}

struct stack*
push(struct stack* s, int num)
{
	struct stack* tmp = malloc(sizeof(struct stack));
	tmp->num  = num;
	tmp->next = s;

	return tmp;
}

int
isEmpty(struct stack* s)
{
	if(s->next == NULL)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int
top(struct stack* s)
{
	if( s != NULL )
	{
		return s->num;
	}
	else
	{
		return 0;
	}
}

void
pop(struct stack** s)
{
	*s = (*s)->next;
}
