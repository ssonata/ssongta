#include <iostream>
#include <queue>
using namespace std;
#define MAX 7
int graph[MAX][MAX] =
{
   0, 1, 1, 0, 0, 0, 0,
   1, 0, 0, 1, 1, 0, 0,
   1, 0, 0, 0, 0, 0, 1,
   0, 1, 0, 0, 0, 1, 0,
   0, 1, 0, 0, 0, 1, 0,
   0, 0, 0, 1, 1, 0, 1,
   0, 0, 1, 0, 0, 1, 0
};
int visit[MAX] = {0};
void bfs(int start)
{
	queue<int>q;
	visit[start] = 1;
	q.push(start);
	while(!q.empty())
	{
		int node = q.front();
		for(int next = 0; next < MAX; next++)
		{
			if(graph[node][next] == 1 && !visit[next])
			{
				visit[next] = 1;
				q.push(next);
			}
		}
		cout<<node<<"->";
		q.pop();
	}
	cout<<endl;
}
int main()
{
	bfs(0);
}
