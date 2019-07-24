#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char * convert(char * s, int numRows){
	int i,j;
	i = numRows;
	j = strlen(s)/(2*i-2);
	if (strlen(s)%(2*i-2))
	{
		j = j+1;
	}
	char *retsrc = malloc(j);
	int array[] = {};
	for (i = 0; i < j; ++i)
	{
		array[i] = 6*i;
	}
	for (i = 0; i < ; ++i)
	{
		/* code */
	}
	printf("i = %d j = %d\n",i,j);
}

int main(int argc, char const *argv[])
{
	char *src = "LEETCODEISHIRING";
	int num = 4;
	convert(src,num);
	printf("%s\n", src);
	return 0;
}