#include <iostream>
#include <stack>
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
void dfs(int start)
{
	stack<int>s;
	cout<<start<<"->";
	visit[start] = 1;
	s.push(start);
	for(int next = 0; next<MAX; next++)
	{
		if(graph[start][next] == 1 && !visit[next])
		{
			dfs(next);
		}
	}
	if(s.empty())	return;
	s.pop();
}
int main()
{
	dfs(0);
	cout<<endl;
}
