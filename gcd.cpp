#include <iostream>
using namespace std;

int gcd(int p, int q)
{
	if(q == 0) return p;
	else	   return gcd(q, p%q);
}
int main()
{
	cout << gcd(12, 5) << endl;
	return 0;
}
