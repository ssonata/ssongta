#include <iostream>
#include <vector>
using namespace std;

vector<int> arr;
void sorting(vector<int> &arr)
{
	for(int i = arr.size() - 1; i >= 0; i --)
	{
		for(int j = 0; j < i; j++)
		{
			if(arr[j] > arr[j+1])	swap(arr[j], arr[j+1]);
		}
	}
	return;
}
int main()
{
	arr.push_back(33);	arr.push_back(99);	arr.push_back(11);	arr.push_back(44);	arr.push_back(55);	arr.push_back(88);	arr.push_back(77);	arr.push_back(66);	arr.push_back(22);
	sorting(arr);

	vector<int>::iterator iter = arr.begin();
	for(;iter != arr.end(); ++iter)
		cout<<*iter<<" ";
	cout<<endl;
	return 0;
}
