//입력 : 3 3 
//       1 2 1
//       2 3 2
//       1 3 3
//출력   3
//결과는 Kruscal 알고리즘과 같게 나온다. 노트를 펴고 위의 입력값을 토대로 해당
//알고리즘을 분석해보면 출력이 3이 나오는 것을 확인할 수 있을 것이다.


#include <iostream>
#include <vector>
#include <queue>
#define MAX_NODE 10000
using namespace std;

typedef pair<int,int> next_node;
bool visit[MAX_NODE];
vector<next_node> node[MAX_NODE];
void prim(int start)
{
	visit[start] = true;				//일단 prim알고리즘을 시작했으니 해당 노드는 true이다.

	priority_queue<next_node,vector<next_node>,greater<next_node>> pq;		//우선순위 Queue(STL)함수 이용!!! 오름차순이면서 vector연산을 쓰자(deque도 쓸 수 있다.)

	for(int i = 0; i < node[start].size(); i++)
	{
		int nextcost = node[start][i].first;				//해당 노드안에 저장되어있는 first와 second값을 가져와서 그걸 priority_queue에 넣는다.
		int next = node[start][i].second;

		pq.push(next_node(nextcost,next));
	}

	int ans = 0;

	while(!pq.empty())										//STL함수답게 안에서 오름차순으로 정렬을 해준다.(가장 낮은 Cost의 값이 맨 앞에 온다.)
	{
		int herecost = pq.top().first;						//Lowest Cost값을 뽑는다.
		int here = pq.top().second;							//Lowest Cost값의 노드를 뽑는다.
		cout<<"here"<<here<<"herecost:"<<herecost<<endl;
		pq.pop();											//사용된 Node는 Priority Queue에서 삭제!

		if(visit[here]) continue;							//이미 방문된 Node라면 패스!
		visit[here] = true;									//방문 안된 노드라면 true로 설정
		ans += herecost;									//MST를 구하는것이 목적이기에 cost값을 더해준다.

		for(int i = 0; i < node[here].size(); i ++)
		{
			int therecost = node[here][i].first;			//이미 다른 노드들은 priority queue에 있기에 새롭게 추가된 노드의 인접노드만 pq에 추가한다.
			int there = node[here][i].second;

			pq.push(next_node(therecost,there));
		}
	}
	cout<<ans<<endl;
	return;
}
int main()
{
	int V; //vertex(node)
	int E; //edge

	cin >> V >> E;
	for(int i = 0; i < E; i++)
	{
		int from,to,val;
		cin >> from >> to >> val;
		node[from].push_back(next_node(val,to));		//각 노드마다 cost값이랑 목적노드값을 넣는다.
		node[to].push_back(next_node(val,from));		//각 노드마다 cost값이랑 목적노드값을 넣는다.
	}
	prim(1);
	return 0;
}
