#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> v;
void check_median(int num)
{
	v.push_back(num);
	sort(v.begin(),v.end());

	int size = v.size();
	if(size % 2 == 0)
	{
		if(v[size/2] % 2 == 0 && v[size/2 - 1]% 2 == 0 ||
				v[size/2] % 2 != 0 && v[size/2 - 1]% 2 != 0)
		{
			cout<<(v[size/2] + v[size/2 - 1])/2<<endl;
		}
		else
		{
			double d = (double)(v[size/2] + v[size/2 - 1])/2;
			
			cout<<fixed;
			cout.precision(1);
			cout<<d<<endl;
		}
	}
	else
	{
		cout<<v[size/2]<<endl;
	}
}

int main()
{
	int num;
	while(num != 10000)
	{
		cout<< "IN:";
		cin >> num;
		check_median(num);
	}
	return 0;
}
