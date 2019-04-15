#include <iostream>
using namespace std;

int
minimum(int arr[], int s)
{
	int min = arr[0];

	// min will always be equal to or smaller than any
	// number in the array, min is an invariant
	for( int c = 0; c != s; c++ )
	{
		if( arr[c] < min ) min = arr[c];
	}

	return min;
}

int main(int argc, char* argv[])
{
	int arr[] = { 9, 99, 8, 99, 5, 4, 7 };
	cout<<minimum(arr, sizeof(arr)/sizeof(int))<<endl;
}
