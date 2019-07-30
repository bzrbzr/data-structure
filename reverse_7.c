#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int convert(int x)
{
	int array[32] = {0};
	int i = 0;
	int j = 0;
	long value = 0;
	while(x)
	{
		array[i++] = x%10;
		x = x/10;
		//printf("i = %d\n", i);
	}
	for (j; j < i; j++)
	{
	 	
	 	value = value*10 + array[j];
	 	//printf("value = %ld\n", value);
	 	
	}
	if ((value < -pow(2,31)||(value > (pow(2,31)-1)))||(value==0))
	{
		printf("------\n");
		return 0;
	} 
	else 
	 return (int)value;
}

int reverse(int x)
{
	int value = 0;
	int rev_num = 0;
	if (x == 0|| x == -2147483648)
	{
		return 0;
	}
	if (x > 0)
	{
		value = (int )convert(x);
	}
	if (x < 0)
	{
		value = (int )convert(-x) *(-1);
	}
 
	return value;
}

int main(int argc, char const *argv[])
{
	int i = -2147483648;
	int number = 0;
	number = reverse(i);
	printf("number = %d\n", number);
	return 0;
}
