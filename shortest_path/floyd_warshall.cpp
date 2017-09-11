#include <iostream>
#define MAX 5
using namespace std;


int graph[MAX][MAX] = 
{
  { 0, 8, 4, 5, 5 },
  { 7, 0, 6, 2, 2 },
  { 3, 2, 0, 3, 7 },
  { 7, 3, 7, 0, 1 },
  { 3, 7, 4, 2, 0 },
};

void printSolution(int (*d)[MAX])
{
	for(int i = 0; i < MAX; i++)
	{
		for(int j = 0; j < MAX; j++)
		{
			cout<<d[i][j]<<" ";
		}
		cout<<endl;
	}
	return;
}
void floyd_warshall()
{
	int d[MAX][MAX] = {0};
	int pie[MAX][MAX] = {0};

	for(int i = 0; i < MAX; i++)
	{
		for(int j = 0; j < MAX; j++)
		{
			d[i][j] = graph[i][j];			//거리를 의미하는 d값을 graph값으로 초기화 해준다.
		}
	}
	for(int k = 0; k < MAX; k++)
	{
		for(int i = 0; i < MAX; i++)
		{
			for(int j = 0; j < MAX; j++)
			{
				if(d[i][j] > (d[i][k] + d[k][j]))			//현재 d[i][j]값이 최소가 아닌경우에는 무조건 최소로 맞춰준다.
				{
					d[i][j] = d[i][k] + d[k][j];
					pie[i][j] = k;							//직전노드 값
				}
			}
		}
	}
	printSolution(d);
	return;
}
int main()
{
	floyd_warshall();			//floyd_warshall 알고리즘을 구하라.
	return 0;
}
