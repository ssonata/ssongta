#include <iostream>
#include <vector>
using namespace std;

int sum_of_sum(vector<int>& factory, int n)
{
	if(n == 100) return 100;
	else
	{
		factory.push_back(n);
		return n + sum_of_sum(factory, n +1);
	}
}

int binarySearch(vector<int>& factory, int begin, int end, int target)
{
	if(begin > end) return -1;
	else
	{
		int middle = (begin + end) / 2;
		int result = (target == factory[middle])? 1: 0;
		if(result)	return factory[middle];
		else
		{
			if(target > factory[middle]) return binarySearch(factory, middle+1, end, target);
			else						 return binarySearch(factory, begin, middle-1, target);

		}
	}
}

int main()
{
	vector<int> factory;
	sum_of_sum(factory, 0);
	int begin = 2;
	int end = 100;
	int target = 79;
	cout << binarySearch(factory, begin, end, target) << endl;
	return 0;
}
