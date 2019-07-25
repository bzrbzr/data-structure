#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char * convert(char * s, int numRows){
	if (numRows == 1)
	{
		return s;
	}
	int i,j,k;
	k = 0;
	int lenth = strlen(s);
	int cyclenth = 2*numRows - 2;
	int cyctime = lenth/cyclenth;
	if(lenth%cyclenth) cyctime += 1;

	char *retsrc = (char *)malloc(sizeof(char)*(lenth+1));
	memset(retsrc,0,lenth+1);
	for (i = 0; i < numRows; ++i)
	{
		for (j = 0; j + i < lenth; j += cyclenth)
		{
			 retsrc[k++] = s[i+j];
			 if (i!=0&&i!=(numRows-1)&&(j+cyclenth-i<lenth))
			 {
			 	retsrc[k++] = s[cyclenth+j-i];
			 }
		}
	}
	return retsrc;
}

int main(int argc, char const *argv[])
{
	char *src = "LEETCODEISHIRING";
	int lenth = strlen(src);
	char *retunsrc = (char *)malloc(sizeof(char)*lenth);
	int num = 3;
	retunsrc = convert(src,num);
	printf("%s\n", retunsrc);
	return 0;
}