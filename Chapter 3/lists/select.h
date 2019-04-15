#include <stdio.h>
#include <stdbool.h>
#include "construct.h"

int
isEmpty(struct numlist* ptr)
{
	if( ptr == NULL )
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int
first(struct numlist* ptr)
{
	if(!isEmpty(ptr))
	{
		return ptr->num;
	}
	else
	{
		return 0;
	}

}

struct numlist*
rest(struct numlist* ptr)
{
	if(!isEmpty(ptr))
	{
		return ptr->next;
	}
	else
	{
		return NULL;
	}
}
