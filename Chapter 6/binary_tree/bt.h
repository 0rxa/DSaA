#include <stdlib.h>
#include <math.h>

struct node
{
	int val;
	struct node* left;
	struct node* right;
};
typedef struct node node;

node*
EmptyTree()
{	
	return NULL;
}

int
isEmpty(node* t)
{
	return (t == NULL);
}

int
isLeaf(node* t)
{
	return (t->left == NULL || t->right == NULL);
}

node*
MakeTree(int v, node* l, node* r)
{
	node* tmp = (node*)malloc(sizeof(node));
	tmp->left = l;
	tmp->right = r;
	tmp->val = v;
	return tmp;
}

node*
Leaf(int v)
{
	node* tmp = (node*)malloc(sizeof(node));
	tmp->val = v;
	tmp->left = NULL;
	tmp->right = NULL;
	return tmp;
}

node*
left(node* t)
{
	return t->left;
}

node*
right(node* t)
{
	return t->right;
}

int
height(node* t )
{
	int h = 0;
	if( isEmpty(t) || isLeaf(t) )
	{
		return h;
	}
	else
	{
		h++;
		int lh = height(t->left);
		int rh = height(t->right);
		h += ((lh > rh) ? lh : rh);
		return h;
	}
}

int
real_size(node* t)
{
	if( isEmpty(t) )
	{
		return 0;
	}
	else
	{
		return (1 + real_size(t->left) + real_size(t->right));
	}
}

int
max_size(int h)
{
	return (int)(pow(2, (h+1)) - 1);
	
}

int
root(node* t)
{
	return t->val;
}
