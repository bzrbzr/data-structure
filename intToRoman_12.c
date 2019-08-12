#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

char * intToRoman(int num){
    int numb[] =           {1000,900,500,400, 100, 90, 50,  40, 10,  9,   5,  4,   1 };
    char *romanarray[13] = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
    char *retroma = (char *)malloc(sizeof(char)*11);
    memset(retroma,0,11);
    int i = 0;	

    for (i = 0; i < 13; ++i)
    {
    	while(num >= numb[i])
    	{
    		num -= numb[i];
    		printf("%s %d\n", romanarray[i],num);
    		strcat(retroma,romanarray[i]);
    	}
    }

    return retroma;
}


int main(int argc, char const *argv[])
{
	int a = 1994;
	char *roman = intToRoman(a);
	printf("roman = %s\n",roman);
	return 0;
}