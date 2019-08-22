#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

char abc[8][5] = {"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
int abcnum[8] = {3,3,3,3,3,4,3,4};

void returnarray(char * digits, int* returnSize,char ** returndigits,char *result,int i)
{
	
	if (i == strlen(digits))
	{
		returndigits[*returnSize] = malloc(sizeof(char )*(strlen(digits)+1));
		memset(returndigits[*returnSize],0,strlen(digits)+1);
		strcpy(returndigits[*returnSize],result);
		returndigits[*returnSize][strlen(digits)] = '\0';
		(*returnSize)++;
		return; 
	}
	else
	{
		int j = 0;
		if ((digits[i]-50)>=0&&(digits[i]-50<=7))
		{
			printf("-----%d\n",(digits[i]-50));
			for (j = 0; j < abcnum[digits[i]-50]; ++j)
			{
				result[i] = abc[digits[i]-50][j];
				returnarray(digits,returnSize,returndigits,result,i+1);
			}
		}
	}
}

char ** letterCombinations(char * digits, int* returnSize){
	int i = 0;int puts = 0;int count = 1;

	if (strlen(digits) == 0 )
	{
		return NULL;
	}
	for (i = 0; i < strlen(digits); ++i)
	{
		puts = digits[i]-50;
		count *= abcnum[puts];
	}
	*returnSize = 0;

	char ** returndigits = (char **)malloc(sizeof(char *)*(count+1));
	memset(returndigits,0,count+1);

	char *result = (char*)malloc((strlen(digits) + 1)*sizeof(char));
	memset(result,0,(strlen(digits) + 1));
	i = 0;
	returnarray(digits,returnSize,returndigits,result,i);

	return returndigits;
}


int main(int argc, char const *argv[])
{
	char *digits = "";
	int size = 0;int i = 0;
	char ** returnchar = letterCombinations(digits,&size);
	for (i = 0; i < size; ++i)
	{
		printf("%d %s\n", __LINE__,returnchar[i]);
	}
	return 0;
}