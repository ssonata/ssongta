#include <stdio.h>
#include <string.h>
char *strcat_(char *a, const char *b)
{
	int i = 0;
	while(*a != '\0')
	{
		a++;
	}
	while(*b != '\0')
	{
		*a = *b;
		a++;
		b++;
	}
	a = '\0';
	return a;
}
int main()
{
	char start[100] = "song";
	strcat_(start,"jongsup");
	printf("%s\n",start);
	
	char start1[100] = "song";
	printf("%s\n",strcat(start1,"jongsup"));
    return 0;
}
