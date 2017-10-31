#include <stdio.h>
#include <limits.h> // INT_MAX에 이용
 
// 정점의 개수를 정의
#define V 5

int minDistance(int *short_distance, bool *visited)
{
    int min = INT_MAX, min_index;
 
    for (int v = 0; v < V; v++)
    {
        if (!visited[v] && min > short_distance[v])
        {
            min_index = v;
            min = short_distance[v];
        }
    }
 
    return min_index;
}
// 시작점에서 그 정점까지의 최단 거리를 출력해준다.
void printSolution(int short_distance[], int n)
{
    printf("Vertex   Distance from Source\n");
    for (int i = 0; i < V; i++)
        printf("%d \t\t %d\n", i, short_distance[i]);
}
 
void dijkstra(int (*graph)[V], int src) //int graph[V][V]로 넘겨도 됨.
{
    int short_distance[V]; // 최단 거리를 파악하는 배열
    bool visited[V]; // 방문 했는지 체크 하는 bool형 배열
 
    for (int i = 0; i<V; i++)
        short_distance[i] = INT_MAX, visited[i] = false;

 
    // 초기 조건 설정.
    short_distance[src] = 0;
 
    // V-1번 루프를 수행한다는 것은 첫 src노드를 제외한 모든 노드들에 접근을 해 계산을 한다는 의미.
    for (int count = 0; count < V - 1; count++)
    {
        // 최단거리 정보를 알고 있는 노드들 중 가장 거리가 짧은 노드의 인덱스를 가져온다.
        int u = minDistance(short_distance, visited);
 
        // 그래프 상의 모든 노드들을 탐색하며 u 노드의 주변 정보를 갱신한다.
        for (int v = 0; v < V; v++)
        {
            // 1. 아직 처리가 되지 않은 노드이어야 하며 (무한루프 방지)
            // 2. u-v 간에 edge가 존재하고
            // 3. src부터 u까지의 경로가 존재하고
            // 4. 기존의 v노드까지의 최단거리 값보다 새로 계산되는 최단거리가 더 짧을 경우
            if (!visited[v] && graph[u][v] && short_distance[u] != INT_MAX && short_distance[v] > short_distance[u] + graph[u][v])
            {
                // 최단거리를 갱신해준다.
                short_distance[v] = short_distance[u] + graph[u][v];
            }
        }
 
        // 이제 이 노드(u)는 접근할 일이 없다. 플래그를 true로 설정.
        visited[u] = true;
 
        // 현재까지의 최단 거리를 출력해준다.
        printSolution(short_distance, V);
    }
}
 
int main()
{
    int graph[V][V] = 
    { 
        { 0, 3, 6, 8, 7 },
        { 3, 0, 2, 4, 8 },
        { 6, 2, 0, 5, 5 },
        { 8, 4, 5, 0, 2 },
        { 7, 8, 5, 2, 0 },
    };
 
    dijkstra(graph, 0);// dijkstra(최단 거리를 구하고자 하는 그래프, 시작 하고자 하는 정점);
    return 0;
}
