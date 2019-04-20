#include <stdio.h>

#define S(x) (sizeof(x)/sizeof(int))

void
sort(int* a, int s)
{
	for( int c = 0; c < s; c++ )
	{
		for( int g = c+1; g < s; g++ )
		{
			if( a[c] > a[g] )
			{
				int tmp = a[c];
				a[c] = a[g];
				a[g] = tmp;
			}
		}
	}
}


int
bsearch(int* a, int s, int x)
{
	int left = 0;
	int right = s-1;
	int mid;
	while( left < right )
	{
		mid = (int)((left+right)/2);
		if( x > a[mid] )
		{
			left = mid+1;
		}
		else
		{
			right = mid;
		}
	}

	if( a[left] == x )
	{
		return left;
	}

	return -1;
}

int main(int argc, char* argv[])
{
	int a[] = {1, 4, 17, 3, 90, 79, 4, 6, 81};
	sort(a, S(a));
	int f = bsearch(a, S(a), 81);
	printf("Index: %d\nValue: %d\n", f, a[f]);
}
