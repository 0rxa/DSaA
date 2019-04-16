#include <stdlib.h>

struct node{
	int num;
	struct node *next;
};
typedef struct node node;

struct queue{
	struct node* first;
	struct node* last;
};
typedef struct queue queue;

queue*
EmptyQueue()
{
	queue* q = malloc(sizeof(queue));
	q->first = NULL;
	q->last = NULL;
	return q;
}

int
isEmpty(queue* q)
{
	return (q->first == NULL);
}

queue*
push(queue* q, int num)
{
	node* n = malloc(sizeof(node));
	n->num = num;
	n->next = NULL;
	if(isEmpty(q))
	{
		q->first = n;
	}
	else
	{
		q->last->next = n;
	}
	q->last = n;
	return q;
}

int
top(queue* q)
{
	return q->first->num;
}

int
pop(queue** q)
{
	if( (*q)->first->next != NULL )
	{
		(*q)->first = (*q)->first->next;
		return 1;
	}
	else
	{
		return 0;
	}
}
