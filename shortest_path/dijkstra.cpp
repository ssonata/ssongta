#include <stdio.h>
#include <limits.h> // INT_MAX�� �̿�
 
// ������ ������ ����
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
// ���������� �� ���������� �ִ� �Ÿ��� ������ش�.
void printSolution(int short_distance[], int n)
{
    printf("Vertex   Distance from Source\n");
    for (int i = 0; i < V; i++)
        printf("%d \t\t %d\n", i, short_distance[i]);
}
 
void dijkstra(int (*graph)[V], int src) //int graph[V][V]�� �Ѱܵ� ��.
{
    int short_distance[V]; // �ִ� �Ÿ��� �ľ��ϴ� �迭
    bool visited[V]; // �湮 �ߴ��� üũ �ϴ� bool�� �迭
 
    for (int i = 0; i<V; i++)
        short_distance[i] = INT_MAX, visited[i] = false;

 
    // �ʱ� ���� ����.
    short_distance[src] = 0;
 
    // V-1�� ������ �����Ѵٴ� ���� ù src��带 ������ ��� ���鿡 ������ �� ����� �Ѵٴ� �ǹ�.
    for (int count = 0; count < V - 1; count++)
    {
        // �ִܰŸ� ������ �˰� �ִ� ���� �� ���� �Ÿ��� ª�� ����� �ε����� �����´�.
        int u = minDistance(short_distance, visited);
 
        // �׷��� ���� ��� ������ Ž���ϸ� u ����� �ֺ� ������ �����Ѵ�.
        for (int v = 0; v < V; v++)
        {
            // 1. ���� ó���� ���� ���� ����̾�� �ϸ� (���ѷ��� ����)
            // 2. u-v ���� edge�� �����ϰ�
            // 3. src���� u������ ��ΰ� �����ϰ�
            // 4. ������ v�������� �ִܰŸ� ������ ���� ���Ǵ� �ִܰŸ��� �� ª�� ���
            if (!visited[v] && graph[u][v] && short_distance[u] != INT_MAX && short_distance[v] > short_distance[u] + graph[u][v])
            {
                // �ִܰŸ��� �������ش�.
                short_distance[v] = short_distance[u] + graph[u][v];
            }
        }
 
        // ���� �� ���(u)�� ������ ���� ����. �÷��׸� true�� ����.
        visited[u] = true;
 
        // ��������� �ִ� �Ÿ��� ������ش�.
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
 
    dijkstra(graph, 0);// dijkstra(�ִ� �Ÿ��� ���ϰ��� �ϴ� �׷���, ���� �ϰ��� �ϴ� ����);
    return 0;
}
