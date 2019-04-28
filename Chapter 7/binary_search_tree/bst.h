#include <stdlib.h>
#include <math.h>
#define true 1
#define false 0

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
	return (t->left == NULL && t->right == NULL);
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
		int lh = height(left(t));
		int rh = height(right(t));
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

// int
// max_size(int h)
// {
// 	return (int)(pow(2, (h+1)) - 1);
// 	
// }

int
root(node* t)
{
	return t->val;
}

node*
insert(node* n, int val)
{
	if(isEmpty(n))
	{
		return MakeTree(val, NULL, NULL);
	}
	else if(val > root(n))
	{
		return MakeTree(root(n), left(n), insert(right(n), val));
	}
	else if(val < root(n))
	{
		return MakeTree(root(n), insert(left(n), val), right(n));
	}
	else
	{
		printf("Error");
		exit(1);
	}
}

node*
find(node* n, int val)
{
	if(isEmpty(n))
	{
		printf("Error, not a valid tree\n");
		exit(1);
	}

	if(val > root(n))
	{
		return find(right(n), val);
	}
	else if(val < root(n))
	{
		return find(left(n), val);
	}
	else
	{
		return n;
	}
}

int
smallestNode(node* t)
{
	if(isEmpty(left(t)))
	{
		return root(t);
	}
	else
	{
		return smallestNode(left(t));
	}

}

node*
removeSmallestNode(node* t)
{
	if(isEmpty(left(t)))
	{
		return right(t);
	}
	else
	{
		return MakeTree(root(t), removeSmallestNode(left(t)), right(t));
	}

}

node*
delNode(node* t, int val)
{
	if(isEmpty(t))
	{
		printf("Not a valid tree\n");
		exit(1);
	}

	if(val < root(t))
	{
		return MakeTree(root(t), left(t), delNode(right(t), val));
	}
	else if(val > root(t))
	{
		return MakeTree(root(t), left(t), delNode(right(t), val));
	}
	else
	{
		if(isEmpty(left(t)))
		{
			return right(t);
		}
		else if(isEmpty(right(t)))
		{
			return left(t);
		}
		else
		{
			return MakeTree(smallestNode(right(t)), left(t), removeSmallestNode(right(t)));
		}
	}
}

int
all_smaller(node* t, int val)
{
	if( isEmpty(t) )
	{
		return true;
	}
	else
	{
		return ( (root(t) < val) &&
				all_smaller(left(t), val) &&
				all_smaller(right(t), val) );
	}
}

int
all_bigger(node* t, int val)
{
	if( isEmpty(t) )
	{
		return true;
	}
	else
	{
		return ( (root(t) > val) &&
				all_bigger(left(t), val) &&
				all_bigger(right(t), val) );
	}
}

int
isBST(node* t)
{
	if( isEmpty(t) )
	{
		return 1;
	}
	else
	{
		return ( all_smaller(left(t), root(t)) &&
				isBST(left(t)) &&
				all_bigger(right(t), root(t)) &&
				isBST(right(t)) );
	}
}

void
order(node* t)
{
	if( !isEmpty(t) )
	{
		order(left(t));
		printf("%d\n", root(t));
		order(right(t));
	}
}

node*
sort(int* arr, int sz)
{
	node* t = EmptyTree();
	for( int c = 0; c < sz; c++ )
	{
		t = insert(t, arr[c]);
	}

	return t;
}
