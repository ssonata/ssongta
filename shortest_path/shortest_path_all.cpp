#include <iostream>
#include <limits>
#define MAX 5
#define INT_MAX	numeric_limits<int>::max()
using namespace std;

int graph[MAX][MAX] = 
{
  { 0, 8, 4, 5, 5 },
  { 7, 0, 6, 2, 2 },
  { 3, 2, 0, 3, 7 },
  { 7, 3, 7, 0, 1 },
  { 3, 7, 4, 2, 0 },
};

int short_distance[MAX][MAX] = {0}; //all to all이고, 시작점-끝점이 없기에 2차원배열로 해야한다.
int short_path[MAX] = {0}; //single-source이고, 시작점이 주어졌기에 1차원배열로 충분하다.
int visit[MAX];//dijkstra알고리즘에선 효율적으로 하기위해 방문했던 것을 표시하여 재방문시 skip하게 한다.

void print(int (*short_distance)[MAX])
{
	for(int i = 0; i < MAX; i++)
	{
		for(int j = 0; j < MAX; j++)
		{
			cout<<short_distance[i][j]<< " ";
		}
		cout<<endl;
	}
}
void print(int *short_path)
{
	for(int i = 0; i < MAX; i++)
	{
		short_path[i] == INT_MAX? cout<<"INT_MAX"<<endl : cout << short_path[i] << " ";
	}
	cout<<endl;
}
void floyd_warshall()
{
	for(int i = 0; i < MAX; i++)
	{
		for(int j = 0; j < MAX; j++)
		{
			short_distance[i][j] = graph[i][j];
		}
	}

	for(int k = 0; k < MAX; k++)
	{
		for(int i = 0; i < MAX; i++)
		{
			for(int j = 0; j < MAX; j++)
			{
				if(short_distance[i][j] > short_distance[i][k] + short_distance[k][j])
				{
					short_distance[i][j] = short_distance[i][k] + short_distance[k][j];
				}
			}
		}
	}
	print(short_distance);
}

int mindistance()
{
	int min_index = INT_MAX, min = INT_MAX;
	for(int i = 0; i < MAX; i++)
	{
		if(!visit[i] && min > short_path[i])
		{
			min_index = i;
			min = short_path[i];
		}
	}
	return min_index;
}
void dijkstra(int start)
{
	for(int i = 0; i < MAX; i++)
		short_path[i] = INT_MAX, visit[i] = false;

	short_path[start] = 0;
	for(int count = 0; count < MAX - 1; count++)
	{
		int u = mindistance();
		for(int v = 0; v < MAX ; v++)
		{
			if(!visit[v] && short_path[u] != INT_MAX && short_path[v] > short_path[u] + graph[u][v])
			{
				short_path[v] =  short_path[u] + graph[u][v];
			}
		}
		visit[u] = true;
		print(short_path);
	}
}
void bellman_ford(int start)
{
	for(int i = 0; i < MAX; i++)
		short_path[i] = INT_MAX;
	short_path[start] = 0;

	for(int u = 0; u < MAX - 1; u++)
	{
		for(int v = 0; v < MAX; v++)
		{
			if(short_path[u] != INT_MAX && short_path[v] > short_path[u] + graph[u][v])
			{
				short_path[v] =  short_path[u] + graph[u][v];
			}
		}
		print(short_path);
	}

	for(int u = 0; u < MAX - 1; u++) //음수사이클 존재여부 확인하기 위해 필요!! bellman-ford알고리즘은 음수가중치를 허용한다.
	{
		for(int v = 0; v < MAX; v++)
		{
			if(short_path[u] != INT_MAX && short_path[v] > short_path[u] + graph[u][v])
			{
				cout<<"음수 가중치 존재!!!"<<endl;
			}
		}
	}
}
int main()
{
	printf("\n##########floyd_warshall##############\n");
	floyd_warshall();//말그대로 all to all 경로의 최저 경로를 찾는 알고리즘.
	
	printf("\n##########dijkstra##############\n");
	dijkstra(0); // single source로 0번째를 시작점으로 해서 최적 경로를 찾는 알고리즘.
	
	printf("\n##########Bellman-Ford##############\n");
	bellman_ford(0);// single source로 0번째를 시작점으로 해서 최적 경로를 찾는 알고리즘. 효율적으로 visit여부를 확인하여 min_distance를 찾지 않고 다 돈다.
	return 0;
}
