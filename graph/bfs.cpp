#include <iostream>
#include <queue>
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

void bfs(int (*graph)[MAX], int start)
{
	queue<int>q;		//Queue를 하나 생성
	visit[start] = 1;   //넣은 start값을 visit로 변경
	q.push(start);		//queue에 넣는다.
	while(!q.empty())
	{
		int current = q.front();		//queue에서 하나 뺀다. 유일하게 int형으로 lvalue를 받을 수 있음.
		cout<<current<<" "; 
		q.pop();						//pop의 return value는 void형이라 front로 받자.
		for(int i = 0; i < MAX; i++)
		{
			if(graph[current][i])		//같은 행에 있으면 인접한 노드라고 말할 수 있다.
			{
				if(!visit[i])			//방문 안했으면
				{
					visit[i] = 1;		//방문 한 것으로 표시하고
					q.push(i);			//queue에 넣는다.
				}
			}
		}
	}
	cout<<endl;
	return;
}
int main()
{
	bfs(graph,0);						//bfs시작!
	return 0;
}
