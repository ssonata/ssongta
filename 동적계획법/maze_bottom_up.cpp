#include <iostream>
#define MAX 4
using namespace std;

int arr[MAX][MAX] = {
	{6,7,12,5},
	{5,3,11,18},
	{7,17,3,3},
	{8,10,14,9}
};
int bottom_up[MAX][MAX];		//bottom_up값 넣을 곳 선언
int maze()
{
	for(int x = 0; x < MAX; x++)
	{
		for(int y = 0; y < MAX; y++)
		{
			if(x == 0 && y == 0)	bottom_up[x][y] = arr[x][y];
			else if(y == 0)			bottom_up[x][y] = bottom_up[x-1][y] + arr[x][y];
			else if(x == 0)			bottom_up[x][y] = bottom_up[x][y-1] + arr[x][y];
			else
			{
				if(bottom_up[x-1][y] > bottom_up[x][y-1])
				{
					bottom_up[x][y] = bottom_up[x][y-1]+ arr[x][y];
				}
				else
				{
					bottom_up[x][y] = bottom_up[x-1][y] + arr[x][y];
				}
			}
		}
	}
	return bottom_up[MAX-1][MAX-1];
}
int main()
{
	cout<< maze() << endl;		//끝값에서 부터 추적해 나간다.
	return 0;
}

