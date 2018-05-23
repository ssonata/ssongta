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
