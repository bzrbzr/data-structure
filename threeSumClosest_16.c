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

int threeSumClosest(int* nums, int numsSize,int target){
	int i = 0;int j = 0;int k = 0;int retval = 0;int retval_sum = 0;
	int *numbs = sort(nums,numsSize);

	retval = abs(numbs[0]+numbs[1]+numbs[2] - target);
	retval_sum = numbs[0]+numbs[1]+numbs[2];
	printf("retval = %d\n", retval);

	for (i = 0; i < numsSize - 2; ++i)
	{
		while (i>0 && i<numsSize - 2 && numbs[i] == numbs[i-1])
		{
			i++;
		}
		j = i + 1;
		k = numsSize - 1;

		printf("%d %d %d %d\n", __LINE__,numbs[i],numbs[j],numbs[k]);
		while(j<k)
		{
			if (numbs[j] + numbs[k] + numbs[i] == target)
			{
				//retval = 0;
				retval_sum = numbs[j] + numbs[k] + numbs[i];
				break;
			}
			else if(numbs[j] + numbs[k] + numbs[i] > target)
			{
				printf("%d %d %d\n", __LINE__,(numbs[i] + numbs[j] + numbs[k]-target),retval);
				if ((numbs[i] + numbs[j] + numbs[k]-target )<retval)
				{
					printf("%d %d %d %d\n", __LINE__,numbs[i],numbs[j],numbs[k]);
					retval = abs(numbs[i]+numbs[j]+numbs[k] - target);
					retval_sum = numbs[j] + numbs[k] + numbs[i];
					printf("%d %d\n",__LINE__,retval);
				}
				while(j<k && numbs[k] == numbs[k-1]) k--; 
				k--;
			}
			else
			{
				printf("%d %d %d\n", __LINE__,(target - numbs[j] - numbs[k] - numbs[i]),retval);
				if ((target - numbs[j] - numbs[k] - numbs[i]) < retval)
				{
					printf("%d %d %d %d\n", __LINE__,numbs[i],numbs[j],numbs[k]);
					retval = abs(numbs[i]+numbs[j]+numbs[k] - target);
					retval_sum = numbs[j] + numbs[k] + numbs[i];
					printf("%d %d\n",__LINE__,retval);
				}
				while(j<k && numbs[j] == numbs[j+1]) j++; 
				j++;
			}
		}
	}
	return retval_sum;
}


int main(int argc, char const *argv[])
{
	int target = 0;
	int nums[] = {0,1,2};
	int retval = threeSumClosest(nums,sizeof(nums)/sizeof(int),target);
	printf("retval = %d\n", retval);
	return 0;
}