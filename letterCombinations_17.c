#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
char abc[8][4] = {"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
int abcnum[] = {3,3,3,3,3,4,3,4};

char **returnarray(char **beginarray,char *signalarray,int puts)
{
	int i = 0;int j = 1;
	for (i = 0; i < abcnum[puts]; ++i)
	{
		printf("%d %s\n", __LINE__,beginarray[i]);
		returndigits[i][j] = abc[puts][0];
		
	}
	j++;
}

char ** letterCombinations(char * digits, int* returnSize){
	int i = 0;int puts = 0;int count = 1;
	//printf("%d\n", i);
	for (i = 0; i < strlen(digits); ++i)
	{
		puts = digits[i]-50;
		//printf("puts = %d\n", puts);
		count *= abcnum[puts];
	}
	* returnSize = count;
	printf("returnSize = %d\n", *returnSize);
	char ** returndigits = (char **)malloc(sizeof(char *)*count);
	memset(returndigits,0,count);
	for (i = 0; i <= count; ++i)
	{
		returndigits[i] = malloc(sizeof(char )*(strlen(digits)+1));
		memset(returndigits[i],0,strlen(digits)+1);
	}

#if 1
	for (i = 0; digits[i] ; ++i)
	{
		puts = digits[i]-50;
		printf("%d\n",puts);
		if (i == 0)
		{
			printf("---\n");
			returndigits[0][0] = abc[puts][0];
			returndigits[1][0] = abc[puts][1];
			returndigits[2][0] = abc[puts][2];
			returndigits[3][0] = abc[puts][3];
		}
		returndigits = returnarray(returndigits,abc[puts],puts);
	}
#endif
	//printf("%c\n", returndigits[0][0]);
	return returndigits;
}


int main(int argc, char const *argv[])
{
	char *digits = "2";
	int size = 0;int i = 0;
	char ** returnchar = letterCombinations(digits,&size);
	for (i = 0; i < size; ++i)
	{
		printf("%d %s\n", __LINE__,returnchar[i]);
	}
	return 0;
}