#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int findMax(vector<int>& factory, int begin, int end)
{
	int maximum;
	if(begin > end) return -1;
	else
	{
		return max(factory[begin], findMax(factory, begin+1, end));
	}
}

int main()
{
	vector<int> factory;
	for(int i = 0; i < 100; i ++)
	{
		factory.push_back(i);
	}
	int begin = 10;
	int end = 99;
	cout<<findMax(factory, begin, end) << endl;
	return 0;
}
