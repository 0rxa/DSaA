#include <stdlib.h>
#include "select.h"

void
replaceFirst(struct numlist** head, struct numlist* new)
{
	new->next = (*head)->next;
	*head = new;
}

void
replaceRest(struct numlist** head, struct numlist* new)
{
	(*head)->next = new;
}

struct numlist*
last(struct numlist* head)
{
	if( isEmpty(head) )
	{
		fprintf(stderr, "List is empty\n");
	}
	else if ( isEmpty(rest(head)) )
	{
		return head;
	}
	else
	{
		last(rest(head));
	}
}

struct numlist*
append(struct numlist* l1, struct numlist* l2)
{
	if(isEmpty(l1))
	{
		return l2;
	}
	else
	{
		return MakeList(first(l1), append(rest(l1), l2));
	}
}
