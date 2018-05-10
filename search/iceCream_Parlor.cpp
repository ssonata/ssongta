/*
 * 아이스크림 가게 문제
 * m이라는 돈을 가지고 있고, n개의 맛을 고를 수 있다.
 * oost비용을 n개만큼 내고,
 * cost가격이 m과 딱 맞는 것을 고르는 문제
 * 문제조건 중 오름차순정렬도 있다.
 * 출력은 cost가 저장된 index를 표현.
*/

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class IceCream
{
public: 
    int flavor; 
    int index;

	IceCream(int flavor, int index)
	{
	   this->flavor = flavor;
	   this->index = index;
	}																		        }
};
    
int binarySearch(int first, int last, vector<IceCream> arr, int search)
{
    for(int i = first ; i <= last; i++)
    {
        if(arr[i].flavor == search)
        {
            return arr[i].index;
        }
    }
    return -1;
}

int compare(IceCream a1, IceCream a2)
{
	    return a1.flavor < a2.flavor;
}

int main()
{
   int t;
   int n, m;
   cin >> t;

   for(int test = 0; test < t; test++)
   {       
		cin >> m >> n;
		vector<IceCream> arr;
		arr.reserve(n); 

		for (int i = 0; i < n; i++)
		{
			int cost;
			cin >> cost;
			arr.push_back(IceCream(cost, i + 1));	
		}
 
		sort(arr.begin(), arr.end(), compare);
		int firstIndex = 100000, secondIndex = 100000;
		for(int i = 0; i < n - 1 ; i++)
		{
			int search = m - arr[i].flavor;
			if(search >= arr[i].flavor)
			{
				int index = binarySearch( i + 1, n - 1, arr, search);
				if( index != -1 )						
				{
					cout << min(arr[i].index, index) << " " << max(arr[i].index, index) << endl;
					break;
				}
			}
	     }
   }
}
