#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

int maxArea(int* height, int heightSize){
	int i = 0;
	int j = 0;
	int areamax = 0;
	int numb = 0;
	int area = 0;
	for (i = 0; i < heightSize; ++i)
	{
		for (j = i+1 ; j < heightSize; ++j)
		{
			if (height[i] >= height[j])
			{
				numb = height[j];
			}
			else
				numb = height[i];
			area = numb*(j-i);
			printf("i = %d j = %d area = %d\n",i,j,area);
			if (area > areamax)
			{
				areamax = area;
				printf("areamax = %d\n",area);
			}
		}
	}
	return areamax;
}

int main(int argc, char const *argv[])
{
	int array[] = {1,8};
	int *p = array;
	int size = 2;
	int maxsize = maxArea(p,size);
	printf("maxsize = %d\n", maxsize);
	return 0;
}
