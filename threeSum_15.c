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
	*returnColumnSizes = (int *)malloc(sizeof(int)*17000);
	//memset(triarray , 0 ,17000);
	int ptr_ra = -1;

	for (i = 0; i < numsSize - 2; ++i)
	{
		while (i>0 && i<numsSize - 2 && numbs[i] == numbs[i-1])
		{
			i++;
		}
		j = i + 1;
		k = numsSize - 1;
		target = 0 - numbs[i];
		//printf("%d %d %d\n",i,j,k);
		while(j<k)
		{
			if (numbs[j] + numbs[k] == target)
			{
				triarray[++ptr_ra] = (int *)malloc(sizeof(int) * 3);
				triarray[ptr_ra][0] = numbs[i];
				triarray[ptr_ra][1] = numbs[j];
				triarray[ptr_ra][2] = numbs[k];
				(*returnColumnSizes)[ptr_ra] = 3;
				while(j<k && numbs[k] == numbs[k-1]) k--;
				while(j<k && numbs[j] == numbs[j+1]) j++;
				j++;
				k--;
				printf("k = %d  j = %d\n",k,j );
			}
			else if(numbs[j] + numbs[k] > target)
			{
				while(j<k && numbs[k] == numbs[k-1]) k--; 
				k--;
			}
			else
			{
				while(j<k && numbs[j] == numbs[j+1]) j++; 
				j++;
			}
		}

	}

	*returnSize = ptr_ra +1;

	return triarray;
}


int main(int argc, char const *argv[])
{
	int count;int i = 0;
	int** returnColumnSizes = (int **)malloc(sizeof(int*)*17000);
	int nums[] = {0,0,0,0,0};
	int **triplets = threeSum(nums,sizeof(nums)/sizeof(int),&count,returnColumnSizes);

	for (i = 0; i < count; ++i)
	{
		printf("%d %d %d\n", triplets[i][0],triplets[i][1],triplets[i][2]);
	}
	return 0;
}