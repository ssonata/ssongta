#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 7
using namespace std;
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
vector<int> v;
void dfs(int start)
{
	visit[start] = 1;
	cout<<start<<" " ;
	for(int next_node = 0; next_node < MAX; next_node++)
	{
		if(graph[start][next_node])
		{
			if(visit[next_node] == 0)
			{
				dfs(next_node);
			}
		}
	}
	v.push_back(start);
	return;
}
int main()
{
	dfs(0);
	cout<<endl;
	vector<int>::iterator iter = v.begin();
	reverse(v.begin(),v.end());

	for(;iter != v.end(); ++iter)
		cout<<*iter<<" ";
	cout<<endl;
	return 0;
}
