#include <iostream>
using namespace std;

void print(int n)
{
	cout<<n;
}

void binary(int n)
{
	if( n < 2 ) print(n);
	else
	{
		binary(n / 2);
		print(n % 2);
	}
	return;
}

int main()
{
	binary(10);
	cout<<endl;
	return 0;
}
