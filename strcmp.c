#include <stdio.h>
#include <string.h>

int strcmp_(const char *str1, const char *str2)
{
	int ret = 1;
	int str1_size = strlen(str1);
	int str2_size = strlen(str2);
	if(str1_size == str2_size)
	{
		if(*str1 != '\0' && *str2 != '\0')
		{
			while(*str1 == *str2)
			{
				str1++;
				str2++;
				if(*str1 == '\0' && *str2 == '\0')
				{
					ret = 0;
					break;
				}

			}
		}
		else if (*str1 == '\0' && *str2 == '\0')
		{
			ret = 0;
		}
	}
	return ret;
}
int main()
{
	if(strcmp_("songjong","songjong") == 0)
	{
		printf("same\n");
	}
	else
		printf("not same\n");
}
