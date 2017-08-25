#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> arr;
void selection_sort(vector<int>& arr)
{
	int index = 0;
	vector<int>::iterator iter = arr.end();
	for(;iter != arr.begin(); iter--)
	{
		int maximum = *max_element(arr.begin(),iter);
		for(int j = 0; j < arr.size(); j++)
		{
			if(arr[j] == maximum)
			{
				swap(arr[j], arr[(arr.size() - 1) - index]);
				index++;
				break;
			}
		}
	}
	return;
}


int main()
{
	arr.push_back(29);	arr.push_back(10);	arr.push_back(41);	arr.push_back(87);	arr.push_back(50); arr.push_back(99); arr.push_back(13); arr.push_back(56);
	selection_sort(arr);

	vector<int>::iterator iter = arr.begin();
	for(; iter != arr.end(); ++iter)
	{
		cout<< *iter<<" ";
	}
	cout<<endl;
	return 0;
}
