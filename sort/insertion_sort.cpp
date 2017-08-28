#include <iostream>
#include <vector>
using namespace std;
vector<int> arr;
void insertion_sort(vector<int> &arr)
{
	vector<int>::iterator iter = arr.begin();
	for(; iter != arr.end(); ++iter)
	{
		vector<int>::iterator iter2 = arr.begin();
		for(; iter2 != arr.end(); ++iter2)
		{
			if(*iter < *iter2)
			{
				swap(*iter, *iter2);
			}
		}
	}
	return;
}
int main()
{
	arr.push_back(33);	arr.push_back(44);	arr.push_back(77);	arr.push_back(66);	arr.push_back(11);	arr.push_back(99);	arr.push_back(22);	arr.push_back(88);	arr.push_back(55);
	insertion_sort(arr);

	for(int k = 0;k < 9; k++)
		cout<<arr[k]<<" " ;
	cout<<endl;
	return 0;
}
