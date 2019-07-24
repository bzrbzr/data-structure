#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

char * longestPalindrome(char * s)
{
	int i ,j , max,size;
	max = 0;
	char *retsrc = (char *)malloc(1001);
	size = strlen(s);
	bool dp[1001][1001];
    memset(dp, 0, sizeof(dp));
    int start = 0;

	for (i = 0; i < size; ++i)
	{
		for (j = 0; j <= i; ++j)
		{
			if ((i-j)<2)
			{
				dp[j][i] = (s[i] == s[j]);
				printf("%d  dp[%d][%d]\n",__LINE__,i,j);
			}
			else
			{
				printf("%d  %d  %d\n",__LINE__,i,j);
				dp[j][i] = (s[i] == s[j]&&dp[j+1][i-1]);

			}

			if (dp[j][i]&&(max < i-j+1))
			{
				max = i-j+1;
				start = j;
				printf("start=%d\n",start);
			}
		}
	}
	for (i = 0; i < max; ++i)
	{
		retsrc[i] = s[start+i];
	}
	
	return retsrc;
}

int main(int argc, char const *argv[])
{
	char *src = "babaabab";
	char *retsrc = malloc(1000);
	retsrc = longestPalindrome(src);
	printf("retsrc = %s\n",retsrc);
	return 0;
}