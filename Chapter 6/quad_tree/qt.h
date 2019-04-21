#include <stdlib.h>

struct node
{
	int val;
	struct node* lu;
	struct node* ll;
	struct node* ru;
	struct node* rl;
};

typedef struct node node;

node*
baseQT(int v)
{
	node* tmp = (node*)malloc(sizeof(node));
	tmp->val = v;
	tmp->lu  = NULL;
	tmp->ll  = NULL;
	tmp->ru  = NULL;
	tmp->rl  = NULL;

	return tmp;
}

node*
makeQT(node* lu, node* ll, node* ru, node* rl)
{
	node* tmp = (node*)malloc(sizeof(node));
	tmp->lu  = lu;
	tmp->ll  = ll;
	tmp->ru  = ru;
	tmp->rl  = rl;

	return tmp;
}

node*
lu(node* qt)
{
	return qt->lu;
}

node*
ll(node* qt)
{
	return qt->ll;
}

node*
ru(node* qt)
{
	return qt->ru;
}

node*
rl(node* qt)
{
	return qt->rl;
}

node*
rotate(node* qt)
{
	node* tmp = NULL;
	node* ret = qt;
	tmp = ret->lu;
	ret->lu = ret->ll;
	ret->ll = ret->rl;
	ret->rl = ret->ru;
	ret->ru = tmp;

	return ret;
}

int
val(node* qt)
{
	return qt->val;
}

int
isVal(node* qt)
{
	if(qt->lu == NULL || qt->ll == NULL ||
		qt->rl == NULL || qt->ru == NULL )
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int
average(node** n)
{
	if( isVal(*n) )
	{
		return val(*n);
	}
	else
	{
		int sum = 0;
		sum += average(&((*n)->lu));
		sum += average(&((*n)->ru));
		sum += average(&((*n)->rl));
		sum += average(&((*n)->ll));
		(*n)->val = sum/4;
		return sum/4;
	}
}

void
print_node(node* qt)
{
	printf("lu: %d\n", val(lu(qt)));
	printf("ru: %d\n", val(ru(qt)));
	printf("rl: %d\n", val(rl(qt)));
	printf("ll: %d\n", val(ll(qt)));
}

void
print(node* n)
{
	if( isVal(n) )
	{
		printf("%d\n", val(n));
	}
	else
	{
		print(n->lu);
		print(n->ru);
		print(n->rl);
		print(n->ll);
	}
}

void
print_nodes(node* n)
{
	if( !isVal(n) )
	{
		printf("%d\n", n->val);
		print_nodes(n->lu);
		print_nodes(n->ru);
		print_nodes(n->rl);
		print_nodes(n->ll);
	}
}
