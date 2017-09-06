#include <iostream>
using namespace std;
#define MAX 7
int graph[MAX][MAX] = 	{
	0, 1, 1, 0, 0, 0, 0,
	1, 0, 0, 1, 1, 0, 0,
	1, 0, 0, 0, 0, 0, 1,
	0, 1, 0, 0, 0, 1, 0,
	0, 1, 0, 0, 0, 1, 0,
	0, 0, 0, 1, 1, 0, 1,
	0, 0, 1, 0, 0, 1, 0
};
int visit[MAX] = {0};
void dfs(int start)
{
	visit[start] = 1;
	cout<<start<<"->";								//dfs를 통해 방문했던 노드들 출력!
	for(int next_node = 0; next_node < MAX; next_node++)
	{
		int adj_node = graph[start][next_node];		//인접노드가 있는지 여부 판단
		if(adj_node)
		{
			if(visit[next_node] == 0)				//인접노드가 있으면 그 노드가 방문했던 노드인지 판단
			{
				dfs(next_node);						//방문안한 노드라면 dfs()호출
			}
		}
	}
	return;
}
int main()
{
	for(int i = 0; i < MAX; i++)
	{
		if(visit[i] == 0)
		{
			dfs(0);									//dfs 시작!!!
		}
	}
	cout<<endl;
	return 0;
}
