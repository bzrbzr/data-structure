#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

char * longestCommonPrefix(char ** strs, int strsSize){
	int i = 0;
	int j = 0;
	char *returnstr = "";
	if (strsSize > 0)
	{
		int minsize = 0;
		minsize = strlen(strs[0]);
		printf(" minsize = %d\n",minsize);
		char *returnstr = (char *)malloc(sizeof(char *)*minsize);
		memset(returnstr,0,minsize+1);


	 	for (i = 0; i < strsSize -1; ++i)
	 	{
	 		j = 0;
	 		while (strs[i][j] && strs[i+1][j] && (strs[i][j] == strs[i+1][j]))
	 		{
	 			j++;
	 		}
	 		if (j < minsize)
	 		{
	 			minsize = j;
	 			printf("%d  minsize = %d\n",__LINE__,minsize);
	 		}
		 }

		strncpy(returnstr,strs[0],minsize);
		//printf("returnstr = %s\n",returnstr);
		return returnstr;
	}
	else
	{
		char *returnstr = (char *)malloc(sizeof(char *));
		memset(returnstr,0,1);
		return returnstr;
	}

	
}

int main(int argc, char const *argv[])
{
	char *str[] = { };
	char *retstr = longestCommonPrefix(str,0);
	printf("retstr = %s\n",retstr);
	return 0;
}