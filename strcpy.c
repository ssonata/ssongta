#include <stdio.h>
#include <string.h>
char * strcpy_(char *start, const char *src)
{
	int i = 0;
	while(*src != '\0')
	{
		start[i] = *src;
		i++;
		src++;
	}
	start[i] = '\0';
	return start; 
}

int main()
{
	char start[1000];
	memset(start, 0x00, 1000);
	strcpy_(start, "songjongsup");
	printf("%s\n",start);

	char start_[1000];
	memset(start_, 0x00, 1000);
	strcpy(start_, "songjongsup");
	printf("%s\n",start_);
	return 0;
}
