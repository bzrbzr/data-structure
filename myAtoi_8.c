#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int myAtoi(char * str){
	long retvalue = 0;
	int i = 0;
	int flag = 0;
	int number = strlen(str);
	while(str[i])
	{
		if (str[i] == ' ')	i++;
		else break;
	}

	if (str[i]<48||str[i]>57)
	{
		if (str[i] == '-')
		{
			flag = 1;
			i++;
		}
		else if(str[i] == '+')
		{
			i++;
		}
		else return 0;
	}
	while(str[i])
	{
		if (str[i]>=48&&str[i]<=57)
		{

			retvalue = retvalue*10 + (str[i]-48);
			if (retvalue > pow(2,31))
			{
				retvalue = pow(2,31);
				break;
			}

		}
		else break;
		i++;
	}

	if (flag)
	{
		if (retvalue >= pow(2,31))
		{
			return -pow(2,31);
		}
		else
			return (int)(retvalue*-1);
	}
	else
	{
		if(retvalue >= pow(2,31) -1)
		{
			return pow(2,31) - 1;
		}
		else
			return (int)retvalue;
	}
}

int main(int argc, char const *argv[])
{
	char *src = "+4";
	int value = myAtoi(src);

	printf("%d value = %d\n", __LINE__,value);
	return 0;
}