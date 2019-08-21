#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
char abc[8][4] = {"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
int abcnum[] = {3,3,3,3,3,4,3,4};

//char **returnarray(char **beginarray,char *signalarray)
//{

//}

char ** letterCombinations(char * digits, int* returnSize){
	int i = 0;int puts = 0;int count = 1;
	//printf("%d\n", i);
	for (i = 0; i < strlen(digits); ++i)
	{
		puts = digits[i]-50;
		printf("puts = %d\n", puts);
		count *= abcnum[puts];
	}
	* returnSize = count;
	printf("returnSize = %d\n", *returnSize);
	char ** returndigits = (char **)malloc(sizeof(char *)*count);
	memset(returndigits,0,count);
	for (i = 0; i < strlen(digits); ++i)
	{
		returndigits[i] = malloc(sizeof(char )*strlen(digits)+1);
		memset(returndigits[i],0,strlen(digits)+1);
	}
	
	//memset(returndigits,0,1000);
	//int i = 0;
	returndigits[0][0] = abc[0][0];

#if 0
	for (i = 0; digits[i] ; ++i)
	{
		puts = digits[i]-50;
		printf("%d\n",puts);
		if (i == 0)
		{
			printf("---\n");
			//returndigits[0][0] = abc[puts][0];
			//returndigits[0][1] = abc[puts][1];
			//returndigits[0][2] = abc[puts][2];
			//returndigits[0][3] = abc[puts][3];
		}
		//returndigits = returnarray(returndigits,abc[puts]);
	}
#endif
	//printf("%c\n", returndigits[0][0]);
	return returndigits;
}


int main(int argc, char const *argv[])
{
	char *digits = "233";
	int size = 0;
	char ** returnchar = letterCombinations(digits,&size);
	return 0;
}