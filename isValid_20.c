#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

bool isValid(char * s){
	int lenth = strlen(s);
	int i = 0;int a = 0;
	char *tmp = (char *)malloc(sizeof(char)*(lenth+1));
	memset(tmp,0,lenth+1);
	for (i = 0; i < lenth; ++i)
	{
		if ((*(s+i) == '(')||(*(s+i) == '{')||(*(s+i) == '['))
		{
			a++;
			*(tmp+a) = *(s+i);
			printf("%c a = %d\n",*(tmp+a),a);
		}
		else if((*(s+i) == (*(tmp+a)+1))||(*(s+i) == (*(tmp+a)+2)))
		{
			a--;
		}
		else
		{
			return 0;
			//printf("---\n");
		}
	}
	if (a)
	{
		//printf("--%d\n",a );
		return 0;
	}
	return 1;
}

int main(int argc, char const *argv[])
{
	char *s = "()[]";
	int value = isValid(s);
	printf("value = %d\n", value);
	return 0;
}