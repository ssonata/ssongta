#include <iostream>
#include <vector>
using namespace std;

static int count = 0;

int search(vector<int>& factory, int begin, int end, int target)
{
	if(begin > end) return -1;
	else if(factory[end] == target) return count;
	else
	{
		count++;
		return search(factory, begin, end-1, target);
	}
}

int main()
{
	vector<int> factory;
	for(int i = 0 ;  i < 1000; i ++)
	{
		factory.push_back(i);
	}
	int begin = 100;
	int end = 900;
	int target = 500;
	cout << search(factory, begin, end, target) << endl;
	return 0;
}
