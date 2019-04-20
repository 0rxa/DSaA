#include <stdio.h>

int
find(int* arr, int s, int x)
{
	for( int c = 0; c < s; c++ )
		if( x == arr[c] ) return c;
	return -1;
}

int main(int argc, char* argv[])
{
	 int arr[] = {1, 4, 17, 3, 90, 79, 4, 6, 81};
	 int x = 90;
	 int f = find(arr, (sizeof(arr)/sizeof(int)), x);
	 printf("Index: %d\nValue: %d\n", f, arr[f]);
}
