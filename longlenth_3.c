#include <stdio.h>
#include <string.h>

int contain(char *src,char c,int lenth)
{
	int i = 0;
	for (i = 0; i < lenth; ++i)
	{
		if (src[i] == c)
		{
			return 1;
		}
	}

	return 0;
}
int lengthOfLongestSubstring(char * s){
	int i = 0;
	int j = 1;
	int lenth = strlen(s);
	int max = 0;
	while(s[i])
	{
		printf("---24--\n");
		while(s[j]&&contain(&s[i],s[j],j-i)==0)
		{
			printf("--27-\n");
			if ((j-i+1)>max)
			{
				max = j-i+1;
			}
			j++;
		}
		i++;
		if (max == 0)
		{
			max = 1;
		}
	}
	return max;
}

int main(int argc, char const *argv[])
{
	char *src = "abcabc";
	int max = 0;
	max = lengthOfLongestSubstring(src);
	printf("max = %d\n", max);
	return 0;
}