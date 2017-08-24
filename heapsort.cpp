#include <iostream>
using namespace std;
int A[8] = {99,91,63,41,55,79,74,14};
int	heap_size = (sizeof(A)/ sizeof(int));
void max_heapify(int *A, int parent) //max값만 빼고 나머지는 heapsorting 되게 하는 함수
{
	int left = 2*parent;
	int right = 2*parent+1;
	int largest = parent;
	if((left < heap_size) && (A[left] > A[largest])) largest = left;
	if((right < heap_size) && (A[right] > A[largest])) largest = right;

	if(largest != parent)
	{
		swap(A[parent], A[largest]);
		max_heapify(A,largest);
	}
	return;
}
void build_max_heap(int *A) //정렬 안된 A를 max heap이 되게 만드는 함수
{
	for(int j = heap_size/2; j >= 0; j--) // <-방향으로 가는 것이기에 -1씩 해준다. 시작은 부모노드부터(build를 하는 것이니 root노드까지 모두 거친다.)
	{
		max_heapify(A, j);
	}
	return;
}
void heapsort(int *A) //heapsort하기 위한 함수
{
	build_max_heap(A);                   // max_heap tree로 빌드를 우선 한다.
	for(int i = heap_size-1; i >= 0; i--) // max_heap tree에서 root노드와 맨 마지막 노드를 swap하여 max_heapify를 만든다.
	{
		heap_size -= 1;
		swap(A[0], A[i]);
		max_heapify(A,0);
	}
}
int main()
{
	heapsort(A);
	for(int i = 0; i < 8; i++)
		cout<<A[i]<<" ";
	cout<<endl;
	return 0;
}
