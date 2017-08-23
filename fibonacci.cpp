#include <iostream>
using namespace std;

int fibonacci(unsigned int n)
{
	if(n < 2) return n;
	else	  return fibonacci(n - 1) + fibonacci(n - 2);
}
int main()
{
	cout<< fibonacci(10) << endl;
	return 0;
}
