#include <iostream>
#define INT_MAX 99999999
using namespace std;

typedef struct edges
{
	int start;	//시작노드
	int end;	//끝 노드
	int weight; //가중치
}EDGE;

typedef struct graph_
{
	int V;	//vertex(node)
	int E;	//edge
	EDGE * edge;
}GRAPH;

GRAPH *createGraph(int v, int e)
{
	GRAPH * graphs = new GRAPH();
	graphs->V = v;
	graphs->E = e;
	graphs->edge = new EDGE();
	return graphs;
}

void bellman_ford(GRAPH *graph, int start)
{
	int single_source[graph->V];
	for(int i = 0; i < graph->V; i++)
		single_source[i] = INT_MAX;			//모든 output노드는 무한대로 초기화
	single_source[start] = 0;				//시작 노드는 0으로 setting

	for(int i = 1; i < (graph->V) - 1; i++)	//bellman-ford 알고리즘.	무조건 Node - 1 만큼 돈다.
	{
		for(int j = 0; j < graph->E; j++)
		{
			int u = graph->edge[j].start;
			int v = graph->edge[j].end;
			int wei = graph->edge[j].weight;

			if(single_source[u] != INT_MAX && single_source[u] + wei < single_source[v])
			{
				single_source[v] = single_source[u] + wei;
			}
		}
	}

	//위에서 분명 single_source[v] <= single_source[u] + wei가 될 수 밖에
	//없는데 또 아래에서 같은 check 루틴을 넣는다. 이유는? 음수사이클이
	//존재하는지 확인하기 위해!!
	for(int i =  0; i <  graph->E; i++)
	{
		int u = graph->edge[i].start;
		int v = graph->edge[i].end;
		int wei = graph->edge[i].weight;

		if(single_source[u] != INT_MAX && single_source[u] + wei < single_source[v])
		{
			cout<<"음수 가중치!!!!"<<endl;
		}
	}

	for(int i = 0; i  < graph->V; i++)
	{
		single_source[i] == INT_MAX ? cout<<"INT_MAX"<<endl : cout<<single_source[i]<<endl;
	}
	return;
}
int main()
{
	int s = 5 , e = 9;
	GRAPH * graph = createGraph(s, e);	//graph 생성
	
	if(graph == NULL) return 0;
	graph->edge[0].start = 0;				// 0에서 
	graph->edge[0].end = 2;			// 2로 가는 간선의
	graph->edge[0].weight = 1;			// 가중치는 1로 정한다.
	 
	graph->edge[1].start = 0;
	graph->edge[1].end = 3;
	graph->edge[1].weight = 5;
					 
	graph->edge[2].start = 1;
	graph->edge[2].end = 2;
	graph->edge[2].weight = -2;
								 
	graph->edge[3].start = 2;
	graph->edge[3].end = 1;
	graph->edge[3].weight = 4;
											 
	graph->edge[4].start = 2;
	graph->edge[4].end = 3;
	graph->edge[4].weight = 4;
													 
	graph->edge[5].start = 3;
	graph->edge[5].end = 0;
	graph->edge[5].weight = -1;
																	 
	graph->edge[6].start = 3;
	graph->edge[6].end = 1;
	graph->edge[6].weight = 3;
																				 
	graph->edge[7].start = 4;
	graph->edge[7].end = 0;
	graph->edge[7].weight = 1;
																							 
	graph->edge[8].start = 4;
	graph->edge[8].end = 2;
	graph->edge[8].weight = -1;

	bellman_ford(graph, 0);
	return 0;
}
