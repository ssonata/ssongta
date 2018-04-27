//예제입력
//3 3
//1 2 1
//2 3 2
//1 3 3

//출력 
//3
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef struct kruscal
{
	int from;
	int to;
	int weight;
}KrusCal;
vector<KrusCal> edge;

int parent[10002];
int res;
int chk;

int comp(KrusCal v1, KrusCal v2)
{
	return v1.weight < v2.weight;
}
int find_rootnode(int u)							//union find에서 이용할 함수
{
	if(u != parent[u])
	{
		return find_rootnode(parent[u]);//내가 root노드가 아니라면 root노드로 올라가는 recursive!
	}
	return parent[u];				 //찾고자 하는것과 parent가 같다면 그것이 root노드이다.
}
void weight_union(int u, int v)		//하나의 Tree로 Merge하는 과정
{
	if(u > v) parent[v] = u;		//level depth가 깊어지는 걸 막고자 큰 Tree가 무조건 부모가 된다.
	else	  parent[u] = v;
	return;
}
void union_(int u, int v)
{
	chk = false;
	u = find_rootnode(u);
	v = find_rootnode(v);	//find_rootnode()를 통해 u와v의 root node를 알아낸다.

	if(u == v)	return; //사이클 되어있는지 여부 확인

	weight_union(u,v);
	chk = true;
	return;
}
int main()
{
	int V; //node(vertex)
	int E; //edge

	cin >> V >> E;
	for(int i = 1; i<= V; i++)			//초기에는 자기자신이 자기부모다.
		parent[i] = i;

	for(int i = 0; i < E; i++)			//간선에 해당하는 값을 vector에 넣는다.
	{
		KrusCal kc;
		cin >> kc.from >> kc.to >> kc.weight;
		edge.push_back(kc);
	}

	sort(edge.begin(),edge.end(),comp); //가중치로 오름차순 정렬하기

	for(int i = 0; i < E; i++)
	{
		union_(edge[i].from, edge[i].to);
		if(chk)
		{
			res += edge[i].weight;			//가중치들의 합을 res에 저장한다.
		}
	}
	cout<<res<<endl;
	return 0;
}
