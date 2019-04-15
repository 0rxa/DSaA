#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct nl
{
	int num;
	struct nl *next;
} head;

struct nl* empty_list()
{
	struct nl* tmp = NULL;
	return tmp;
}

struct nl* make_list(struct nl* list, int num)
{
	struct nl* tmp = malloc(sizeof(struct nl));
	tmp->next = list;
	tmp->num = num;
	return tmp;
}

int is_empty(struct nl* list)
{
	if(list->next == NULL || list == NULL)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void replace_first(struct nl* old, struct nl* new)
{
	old->num = new->num;
}

struct nl* rest(struct nl* head)
{
	return head->next;
}

void replace_rest(struct nl* head, struct nl* chain)
{
	head->next = chain;
}

void print(struct nl* head)
{
	printf("%d\n", head->num);
	if(!is_empty(head))
	{
		print(head->next);
	}
}

struct nl* last(struct nl* head)
{
	if(!is_empty(head))
	{
		return last(head->next);
	}
	else
	{
		return head;
	}
}

struct nl* append(struct nl* l1, struct nl* l2)
{
	if( is_empty(l1) )
	{
		return l2;
	}
	else
	{
		return make_list(append(rest(l1), l2), l1->num);
	}
}

int main(int argc, char* argv[])
{
	struct nl* head;
	struct nl* chain;
	head = make_list(make_list(make_list(make_list(make_list(empty_list(), 5), 2), 4), 1), 3);
	chain = make_list(make_list(make_list(make_list(make_list(empty_list(), 55), 44), 33), 22), 11);

	head = append(head, chain);
	print(head);
}
