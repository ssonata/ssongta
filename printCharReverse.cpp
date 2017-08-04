#include <iostream>
using namespace std;

int  printCharReverse(string str)
{
	if(str.size() == 0) return 0;
	else
	{
		printCharReverse(str.substr(1));
		cout<< str.at(0);
	}
	return 0;
}
int main()
{
	printCharReverse("songjongsup");
	cout<<endl;
	return 0;
}
