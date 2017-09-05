#include <iostream>
using namespace std;
#define MAX 6
int graph[MAX][MAX] =
{
	1, 1, 1, 1, 1, 1,
	0, 0, 1, 0, 0, 1,
	1, 1, 1, 0, 1, 1,
	1, 0, 0, 0, 1, 0,
	1, 1, 1, 0, 1, 0,
	0, 0, 1, 1, 1, 1
};
int x[30],y[30], path[30];
int cnt;
void enqueue(int _x, int _y, int _path)
{
	x[cnt] = _x; //x축표시
	y[cnt] = _y; //y축표시
	path[cnt] = _path; //실제 노드 거리
	cnt++;
	return;
}
void bfs(int _x, int _y)
{
	int pos = 0;
	enqueue(_x, _y, 1);
	while(pos < cnt && (x[pos] != MAX - 1 || y[pos] != MAX - 1)) //끝지점이 나올때 까지 loop돌기
	{
		graph[y[pos]][x[pos]] = 0;//두 번 방문하면 안되므로, 이미 지나갔다는 표시

		if(y[pos] > 0 && graph[y[pos] - 1][x[pos]] == 1)// 위로 갈 수 있다면(전제: y[pos]는 > 0 까지 밖에 못간다.)
		{
			enqueue(x[pos], y[pos] - 1, path[pos] + 1);
		}
		if(x[pos] > 0 && graph[y[pos]][x[pos] - 1] == 1) //왼쪽으로 갈 수 있다면(전제:x[pos]-1이 배열안에 있으므로 x[pos] > 0)
		{
			enqueue(x[pos] - 1, y[pos], path[pos] + 1);
		}
		if(y[pos] < MAX - 1 && graph[y[pos] + 1][x[pos]] == 1)//밑으로 갈 수 있다면(전제: y는 MAX -1까지 밖에 못간다.)
		{
			enqueue(x[pos], y[pos] + 1, path[pos] + 1);
		}
		if(x[pos] < MAX - 1 && graph[y[pos]][x[pos] + 1] == 1) // 오른쪽으로 갈 수 있다면(전제: x는 MAX-1까지밖에 못간다.)
		{
			enqueue(x[pos] + 1, y[pos], path[pos] + 1);
		}
		pos++;
	}

	if(x[pos] == MAX - 1 && y[pos] == MAX - 1)
		cout<<"최단경로길이 : "<<path[pos]<<endl;

	return;
}
int main()
{
	bfs(0,0);	//bfs시작!
	return 0;
}
