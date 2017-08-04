#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int findMax(vector<int>& factory, int begin, int end)
{
	if(begin == end) return factory[begin];
	else
	{
		int middle = (begin + end) / 2;
		int max1 = findMax(factory, begin, middle);
		int max2 = findMax(factory, middle+1 , end);
		return max(max1, max2);
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
