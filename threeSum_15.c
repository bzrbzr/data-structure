#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int *sort(int *nums,int count)
{
	int i,j,value;
	i = j = value = 0;
	for (i = 0; i < count -1; ++i)
	{
		for (j = i; j < count; ++j)
		{
			if (nums[j] < nums[i])
			{
				value = nums[j];
				nums[j] = nums[i];
				nums[i] = value;
			}
		}
	}
	return nums;
}

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
	int i = 0;int j = 0;int k = 0;int target = 0;
	int *numbs = sort(nums,numsSize);
	int **triarray = (int **)malloc(sizeof(int *)*17000);
	//returnColumnSizes = (int **)malloc(sizeof(int)*17000);
	//memset(triarray , 0 ,17000);
	int ptr_ra = -1;

	for (i = 0; i < numsSize - 2; ++i)
	{
		j = i + 1;
		k = numsSize - 1;
		target = 0 - numbs[i];
		//printf("%d %d %d\n",i,j,k);
#if 1
		while(j<k)
		{
			if (numbs[j] + numbs[k] == target)
			{
				triarray[++ptr_ra] = (int *)malloc(sizeof(int) * 3);
				triarray[ptr_ra][0] = numbs[i];
				triarray[ptr_ra][1] = numbs[j];
				triarray[ptr_ra][2] = numbs[k];
				//(returnColumnSizes)[ptr_ra] = 3;
				j++;
				k--;
			}
			else if(numbs[j] + numbs[k] > target)
			{
				while(numbs[k] == numbs[k-1]) k--; 
				k--;
			}
			else
			{
				while(numbs[j] == numbs[j+1]) j++; 
				j++;
			}
		}
#endif
	}

	for (i = 0; i < ptr_ra+1; ++i)
	{
		printf("%d %d %d\n", triarray[i][0],triarray[i][1],triarray[i][2]);
	}
}


int main(int argc, char const *argv[])
{
	int count;int i = 0;
	int** returnColumnSizes;
	int nums[] = {-1, 0, 1, 2, -1, -4};
	int **triplets = threeSum(nums,sizeof(nums)/sizeof(int),&count,returnColumnSizes);
	return 0;
}