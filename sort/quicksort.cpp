#include <iostream>
using namespace std;

int x = 0, j = 0, i = 0, q = 0;
int partition(int *A, int p, int r)
{
	x = A[r]; // x is pivot
	i = p - 1;
	for(int j = p; j < r; j++) // j is more bigger than i. so j start p and i start p -1
	{
		if(A[j] <= x) // pivot is bigger than current value ?
		{
			i++; //(left size check value) 'i' plus 1.
			swap(A[i], A[j]); // j move to the pivot left.
		}
	}
	swap(A[i+1], A[r]); // last pivot move to i+1.
	return i + 1;
}
void quicksort(int *A, int p, int r)
{
	if(p < r)
	{
		q = partition(A, p, r);
		quicksort(A, p, q-1);
		quicksort(A, q+1, r);
	}
}
int main()
{
	int A[8] = {35, 42, 10, 55, 8, 37, 15, 41};

	quicksort(A,0,7);
	for(int k = 0; k < 8; k++)
		cout<<A[k]<<" ";
	cout<<endl;
	return 0;
}
