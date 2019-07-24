#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/*!!!!!!!!!!!!!!!!!!!leetcode  over time !!!!!!!!!!!!!!!!!*/

int judgepalind(char *src,int len)
{
	int i = 0;
		for (i = 0; i < len/2; ++i)
		{
			if (src[i] != src[len - i -1])
			{
				return 0;
			}
		}
		if(i >= len/2) return 1;
		else 		   return 0;
}

char * longestPalindrome(char * s)
{
	int i ,j , max,size;
	max = 0;
	char *retsrc = (char *)malloc(1000);
	size = strlen(s);

	for(i = 0;i<size;i++)
	{
		j = i;
		for(j = 0;j<size;j++)
		{
			if (judgepalind(&s[i],j-i+1) == 1)
			{
				if ((j-i+1) > max)
				{
					max = j-i+1;
					//printf("max = %d i = %d j = %d\n",max,i,j);
					strncpy(retsrc,&s[i],(j-i+1));
				}
			}
		}
	}
	return retsrc;
}

int main(int argc, char const *argv[])
{
	char *src = "babad";
	char *retsrc = malloc(1000);
	retsrc = longestPalindrome(src);
	printf("retsrc = %s\n",retsrc);
	return 0;
}