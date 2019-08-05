#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

bool isPalindrome(int x){
	int *array = (int *)malloc(sizeof(int)*100);
	int i = 0;
	int j = 0;
	long palnum = 0;
	if (x<0)
	{
		return 0;
	}
	else if (x>=0&&x<10)
	{
		return 1;
	}
	else
	{
		int numb = x;
		while(numb)
		{
			array[i] = numb%10;
			numb /=10;
			//printf("%d\n", numb);
			//printf("array[%d] = %d\n",i,array[i]);
			i++;
		}
		while(j < i)
		{
			palnum = palnum*10 + array[j];
			//printf("palnum = %ld\n", palnum);
			j++;
		}
		printf("palnum = %ld  x =%d\n",palnum,x );
		if (palnum == x)
		{
			return 1;
		}
		else
			return 0;
	}
}

int main(int argc, char const *argv[])
{

	int a = 12333421;
	if (isPalindrome(a) == 1)
	{
		printf("a is Palindrome\n");
	}
	else
		printf("a is not Palindrome\n");
	
	return 0;
}