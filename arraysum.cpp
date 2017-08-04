#include <iostream>
using namespace std;
int arraysum(int n, int *data)
{
	if(n <= 0) return 0;
	else		return arraysum(n-1 , data) + data[n];
}

int main()
{
	int arr[10];
	for(int i = 1; i < 11; i ++)
	{
		arr[i] = i;
	}
	cout << arraysum(10, arr)<< endl;
	return 0;
}
