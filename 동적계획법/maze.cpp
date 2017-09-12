#include <iostream>
using namespace std;

int arr[4][4] = {
	{6,7,12,5},
	{5,3,11,18},
	{7,17,3,3},
	{8,10,14,9}
};
int memoization[4][4];		//memoization값 넣을 곳 선언
int maze(int x, int y)
{
	if(memoization[x][y] > -1)	return memoization[x][y];			//초기값을 무조건 -1로 해두고 그값 이상이라면 캐슁해둔 값 return
	if(x == 0 && y == 0)	memoization[x][y] = arr[x][y];
	else if(y == 0)			memoization[x][y] = maze(x-1,y) + arr[x][y];
	else if(x == 0)			memoization[x][y] =  maze(x,y-1) + arr[x][y];
	else
	{
		if(maze(x-1,y) > maze(x,y-1))
		{
			memoization[x][y] = maze(x,y-1) + arr[x][y];
		}
		else
		{
			memoization[x][y] = maze(x-1,y) + arr[x][y];
		}
	}
	return memoization[x][y];
}
int main()
{
	for(int i = 0; i < 4; i++)
		for(int j = 0; j < 4; j++)
			memoization[i][j] = -1;
	cout<< maze(3,3) << endl;		//끝값에서 부터 추적해 나간다.
	return 0;
}

