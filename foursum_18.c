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

int** fourSum(int* nums, int numsSize, int target ,int* returnSize, int** returnColumnSizes){
	int i = 0;int j = 0;int k = 0;int tar_val = 0;int w = 0;
	int *numbs = sort(nums,numsSize);
	int **triarray = (int **)malloc(sizeof(int *)*17000);
	*returnColumnSizes = (int *)malloc(sizeof(int)*17000);
	memset(triarray , 0 ,17000);
	//memset(returnColumnSizes,0,17000);
	int ptr_ra = -1;
	//printf("%d\n", numsSize);

	for (i = 0; i < numsSize - 3; ++i)
	{
			while (i>0 && i<numsSize - 3 && numbs[i] == numbs[i-1])
			{
				i++;
			}
			for (w = i+1; w < numsSize - 2; ++w)
			{
			//printf("----%d---- %d\n",__LINE__,w);
#if 1
				while ( w>0 && w<numsSize - 2&&(numbs[w] == numbs[w-1]) &&(w-i>1))
				{
					w++;
				}
#endif

			j = w + 1;
			k = numsSize - 1;
			tar_val = target - numbs[i] - numbs[w];

			while(j<k)
			{
			if (numbs[j] + numbs[k] == tar_val)
			{
				printf("i = %d  w = %d\n",i ,w );
				triarray[++ptr_ra] = (int *)malloc(sizeof(int) * 4);
				triarray[ptr_ra][0] = numbs[i];
				//printf("%d triarray[ptr_ra][0] = %d %d \n",__LINE__,triarray[ptr_ra][0], numbs[i]);
				triarray[ptr_ra][1] = numbs[w];
				triarray[ptr_ra][2] = numbs[j];
				triarray[ptr_ra][3] = numbs[k];
				(*returnColumnSizes)[ptr_ra] = 4;
				while(j<k && numbs[k] == numbs[k-1]) k--;
				while(j<k && numbs[j] == numbs[j+1]) j++;
				j++;
				k--;
				//printf("k = %d  j = %d\n",k,j );
			}
			else if(numbs[j] + numbs[k] > tar_val)
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
	}

	*returnSize = ptr_ra +1;

	return triarray;
}


int main(int argc, char const *argv[])
{
	int count;int i = 0;int target = 28;
	int** returnColumnSizes = (int **)malloc(sizeof(int*)*17000);
	int nums[] = {-7,-5,0,7,1,1,-10,-2,7,7,-2,-6,0,-10,-5,7,-8,5};
	int **triplets = fourSum(nums,sizeof(nums)/sizeof(int),target,&count,returnColumnSizes);

	for (i = 0; i < count; ++i)
	{
		printf("%d %d %d %d\n", triplets[i][0],triplets[i][1],triplets[i][2],triplets[i][3]);
	}
	return 0;
}