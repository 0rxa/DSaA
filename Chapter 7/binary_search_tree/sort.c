#include <stdio.h>
#include "bst.h"
#define sz 9

int main(int argc, char* argv[])
{
	int arr[sz] = { 1, 6, 3, 8, 5, 4, 7, 0 , 9};
	order(sort(arr, (sizeof(arr)/sizeof(arr[0]))));
}
