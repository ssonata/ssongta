#include <iostream>
#include <vector>
using namespace std;

static int count = 0;

int search(vector<int>& factory, int begin, int end, int target)
{
	if(begin > end) return -1;
	else
	{
		int middle = (begin + end) / 2;
		if(factory[middle] == target) return count;
		else
		{
			count++;
			int index = search(factory, begin, middle -1, target);
			if(index != -1) return index;
			else			return search(factory, middle+1, end, target);
		}
	}
}

int main()
{
	vector<int> factory;
	for(int i = 0 ;  i < 1000; i ++)
	{
		factory.push_back(i);
	}
	int begin = 150;
	int end = 950;
	int target = 500;
	cout << search(factory, begin, end, target) << endl;
	return 0;
}
