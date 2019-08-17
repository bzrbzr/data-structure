#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int romanToInt(char * s){
    int numb[] =           {1000,900,500,400, 100, 90, 50,  40, 10,  9,   5,  4,   1 };
    char *romanarray[13] = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
    int number = 0;
    int i = 0;
    int j = 0;
    int lenth = strlen(s);
    //printf("%d\n",lenth );
    for (i = 0; i < lenth; )
    {
        for (j = 0; j < 13; ++j)
        {
            
            if (strncmp(s + i,romanarray[j],(j%2+1)) == 0)
            {
                //printf("%d j2+1=%d\n", __LINE__,(j%2+1));
               number = number + numb[j];
               //printf("numb[%d] = %d\n",j,numb[j]);
               break;
            }
        }
        //printf("j = %d\n", j);
        i = i + (j%2+1);
        //printf("i = %d\n", i);
    }
    //printf("numb = %d\n",number );
    return number;
}


int main(int argc, char const *argv[])
{
	char *roman = "MCMXCIV";
	int num = romanToInt(roman);
	printf("num = %d\n",num);
	return 0;
}