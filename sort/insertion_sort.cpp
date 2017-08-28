#include <iostream>
#include <vector>
using namespace std;
vector<int> arr;
void insertion_sort(vector<int> &arr)
{
	for(int i = 1; i < arr.size(); i++)
	{
		int temp = i;
		for(int j = i - 1; j >= 0 ; j--)
		{
			if(arr[temp] < arr[j])
			{
				swap(arr[temp],arr[j]);
				temp = j;
			}
		}
	}
	return;
}
int main()
{
	arr.push_back(33);
	arr.push_back(44);
	arr.push_back(77);
	arr.push_back(66);
	arr.push_back(11);
	arr.push_back(99);
	arr.push_back(22);
	arr.push_back(88);
	arr.push_back(55);

	insertion_sort(arr);

	for(int k = 0;k < 9; k++)
		cout<<arr[k]<<" " ;
	cout<<endl;
	return 0;
}
