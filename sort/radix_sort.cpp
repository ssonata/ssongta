#include <iostream>
#include <string.h>
using namespace std;
int arr[7] = {329,457,657,839,436,720,355};

void sorting(int (*queue)[10])//2차원 배열 parameter는 괄홍+배열 형식으로 보내주면 된다.
{
	int idx = 0;
	for(int i = 0; i < 10; i++)
	{
		for(int j = 0; j < 10; j++)
		{
			if(queue[i][j] != 0)
			{
				arr[idx++] = queue[i][j];    //queue에서 자리수 별로 정리된 것을 arr에 sorting한다.
			}
		}
	}
	return;
}

void radix_sort(int *arr, int digit)
{
	int incoming[10] = {0};
	int queue[10][10] = {0};     //queue 2차원 배열 생성
	int num,i;
	for(i = 0; i < 7; i++)
	{
		if(digit == 0)		num = (arr[i] % 10);         //맨 마지막 자리수 값
		else if(digit == 1)	num = (arr[i] % 100) / 10;   // 가운데 자리수 값
		else				num = (arr[i] / 100);        // 첫번째 자리수 값
		queue[num][incoming[num]] = arr[i];             // 현재 배열의 값을 queue(0~9)의 자리수에 넣는다.
		incoming[num]++;              // 같은 자리가 중복으로 들어올 수 있으니 이미 들어온 것은 +1 해준다.
	}

	sorting(queue);              // queue에서 자리수별로 정리 된 것을 다시 arr에 sorting한다.
	return;
}

void print()
{
	for(int i = 0; i < 7; i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	return;
}
int main()
{
	radix_sort(arr, 0);  //radix sort 함수 실행! 3자리이니 3번 호출함.
	radix_sort(arr, 1);
	radix_sort(arr, 2);
	print();
	return 0;
}
