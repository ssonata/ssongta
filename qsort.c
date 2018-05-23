//*c언어에 qsort() API Call이 있다는 사실을 처음 알았다. 사실... STL에
//존재하는 줄 알았는데..ㅠ STL에는 sort()함수만 존재한다....
//
//사용방법은 다음과 같다.
// qsort(배열, 내가 입력한 string 길이, 배열의 type size,비교함수(함수포인터))
// compare함수에서는 strcmp로 같을 시엔 위치이동 하지 않는 0 같지 않을시엔 위치이동하는 0아닌 값이 나오게 해준다.


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char buffer[128];
int compare(const void *a, const void *b)
{
	return strcmp((char*)a,(char*)b);
}

int main()
{
	int count,count2;
	scanf("%d",&count);
	char line[count][128];
	int i,j;
	int index = 0;
	while(index != count)
	{
		scanf("%s",line[index]);
		int size1 = strlen(line[index]);
		qsort(line,size1, sizeof(char), compare);
		index++;
	}
	for( i = 0; i < count; i++)
	{
		printf("output:%s\n",line[i]);
	}
	return 0;
}
