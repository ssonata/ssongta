#include <iostream>
using namespace std;
int list[8] = {39,78,99,85,14,56,35,66};
int msort[8] = {0};
void merge(int *list, int left, int mid, int right)
{
	int i = left;					// i는 왼쪽 정렬 포인터
	int j = mid+1;					// j는 오른쪽 정렬 포인터
	int k = left;					// 임시 배열 msort의 index값
	while(i <= mid && j <= right)  // 왼쪽 정렬 포인터가 mid보다 작고, 오른쪽 정렬 포인터가 right보다 작을 시
	{
		if(list[i] < list[j])	msort[k++] = list[i++];
		else					msort[k++] = list[j++];
	}

	//윗 반복문을 돌다보면 i가 mid보다 커지는 경우가 발생한다. 아래는 예외상황 처리구문이다.
	if(i > mid)
		for(int m = j ; m <= right; m++) // 위 반복문에서 선택한 구간 [j~right]까지의 값을 msort에 삽입한다.
			msort[k++] = list[m];
	else
		for(int n = i; n <= mid; n++)   // 위 반복문에서 선택한 구간 [i~mid]까지의 값을 msort에 삽입한다.
			msort[k++] = list[n];

	for(int o = left; o <= right; o++)  // msort에는 정렬된 값이 들어있다. 이것을 list에 복사한다.(Merge 시작시 우선 조건은 이전merge때 무조건 정렬이 되어있어야 한다.)
		list[o] = msort[o];

	return;
}
void mergesort(int *list, int left, int right)
{
	if(left < right)
	{
		int mid = (left+right) / 2;
		mergesort(list, left, mid);
		mergesort(list, mid+1, right);
		merge(list,left,mid,right);
	}
	return;
}
int main()
{
	int left = 0;
	int right = sizeof(list)/sizeof(int);
	mergesort(list,left,right-1);

	for(int i = 0; i < 8; i++)  //최종적으로 정렬되면 msort와 list 모두 같은 결과이다.
		cout<<list[i]<<" ";
	cout<<endl;

	return 0;
}
