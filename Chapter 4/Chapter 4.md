# Searching

## Requirements
Locating data is a mainstream problem in computing. This
problem is generally called searching.

In order to find information, the computer first need
computer-readable information. The process of *encoding*
turns human-readable data into computer-readable data
through the mployment of data structures.

Assuming we want to search through a list of integers
we have two requirements:

1. The simplest, most obvious representation.
1. Two potential algorithms for processing that representation.

The most obvious way to store a collection of integers is
an integer array. Suppose we have an integer array as:

``a = {1,4,17,3,90,79,4,6,81}``

Since the array is unsorted the only thing we can do
is compare every element of the array to the given number
and if it matches return the index, otherwise return a negative
number since array indices cannot be negative.

## Linear Search
### Specification
Given an integer x, find an integer i such that

1. if there is no j such that a[j] is x, then i is -1
1. otherwise, i is any j for which a[j] is x.

The second specification is ambiguous. So if x occurrs more
than once in the array different algorithms would return
different values, this is not a disadvantage and occurrs quite
often in practice.

### Implementation
Linear search goes through each element of the array starting
from one end and if the required value is found, it returns
the index otherwise it returns -1 (by convention). My implementation:

	int
	find(int* arr, int s, int x)
	{
		for( int c = 0; c < s; c++ )
			if( x == arr[c] ) return c;
		return -1;
	}

## Binary Search
An improvement over linear search is binary search. The data can 
still be represented in an array but for binary search it has to be sorted.

### Specification
Given a sorted array of size *n* and a key *x*.
Use integers left(set to 0), right(set to *n*-1) and mid.
Mid is set to the arithmetic average of left and right.

1. Split the array in two and search it until an integer equal to x is found.
1. Return index of element if it's found or -1 if it's not.

