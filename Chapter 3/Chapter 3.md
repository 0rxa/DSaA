## Linked lists
A list can invlolve any data type.

Non-empty lists are represented by two cells, one
containing the data and the other pointing to another two-cell
or an empty list.

#### Constructors
To construct a list on the abstract level two constructors are needed:
* EmptyList - Returns the empty list.
* MakeList  - Puts an element on top of an existing list.

Using this approach (called inductive), we can construct any list as such:
	
	MakeList(3, MakeList(1, MakeList(4, MakeList(2, MakeList(5, EmptyList())))));

The inductive approach must always start with a base case, in this case the EmptyList,
and then builds up increasingly complex lists by repeatedly applying induction, in
this case the MakeList operator.

#### Selectors
Since list elements can not be accessed by indices, it is always necessary to have 
a reference to the first element and to the rest of the list.

Selectors can only work with populated lists, so a condition to 
differentiate empty and non-empty lists is needed.

The selector *first(list)* will return the element of the first
element of the list:

	first(MakeList(x,l)) = x

The selector *rest(list)* will return the pointer to the next element of
the list:
	
	rest(MakeList(x,l)) = l


#### Mutators
Lists can also be changed destructively using mutator functions
which change either the first element or the rest of a non-empty list:
* replaceFirst(x,l)
* replaceRest(r,l)

*replaceFirst* mutator function will remove the head of a list
and replace it with a new one.

*replaceRest* mutator function will change the next pointer of the 
given element to the new element pointer given as function argument.

## Recursion

Recursion is the natural way to process data stored in 
linked lists. Procedures must provide at least one step that
invokes the procedure itself.

For example to find the last element of a linked list
we can remove the first remaining element until we
have an empty list. This procedure calls itself for every element
in the list, so if there are more elements, the procedure will take
more time to complete. Here is my implementation in C:

	if( isEmpty(head) )
	{
		fprintf(stderr, "List is empty\n");
	}
	else if ( isEmpty(rest(head)) )
	{
		return head->next;
	}
	else
	{
		last(rest(head));
	}


In order to append a new list to an existing, we also need to use recursion.
This is done by repeatedly taking the first remaining item of l1 and ading it to the front 
of the remainder appended to l2. My implementation in C:

	if(isEmpty(l1))
	{
		return l2;
	}
	else
	{
		return MakeList(first(l1), append(rest(l1), l2));
	}

The time complexity of this procedure is proportional to the length of first list
since we invoke the procedure as long as there are elements in it.

## Stacks
Stacks are equivalent to linked lists in an abstract level. They are
the ideal data structure to implement LIFO buffers. The graphical
representation of stacks and linked lists is the same but special care is
needed on the order of items. For example a LIFO buffer inserted as
"0, 1, 2, 3" is represented as 

	3 -> 2 -> 1 -> 0 -> NULL

Although very similar, stacks primitive operators are named
differently from linked lists.

#### Constructors

* EmptyStack - returns an empty stack.
* push(element, stack) - puts *element* at the top of *stack*

#### Selectors

* top(stack) - returns the element at the top of *stack*
* pop(stack) - returns *stack* removing the element at the top of it

As it concerns implementation it is better to not create new stacks when
using constructors or selectors but to destructively change the existing stack.

## Queues
Queues are the ideal data structure to model a FIFO buffer. Theoretically we
add to the end of a queue and take away elements from its front.

Queues are represented like lists but with an extra cell to keep track
of the first and last elements. This allows changes to both ends of the queue
with constant effort. A queue inserted as "0, 1, 2, 3" is accessed as:

	0 -> 1 -> 2 -> 3 -> NULL

#### Constructors
* EmptyQueue - returns an empty queue
* push(element, queue) - returns a queue identical to *queue* but with *element* at the beginning

#### Selectors
* top(queue) - returns the first element of *queue*
* pop(queue) - reutrns *queue* removing the first element

My implementation consisted of two data structures one for a linked list
and one for the queue structure.

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
