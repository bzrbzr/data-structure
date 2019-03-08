#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAXSIZE 7

typedef struct stack
{
	int data[MAXSIZE];
	int top;
}stack;

stack *creatstack(int nums)
{
	stack *s = (stack *)malloc(sizeof(stack));
	s->top = -1;
	if (nums > MAXSIZE)
	{
		printf(" ERROR :  create nums is two large\n");
		exit(-1);
	}
	while(s->top < nums-1)
	{
		s->data[++(s->top)] = rand()%100;
	}

	return s;
}

void printstack(stack *s)
{
	int j = s->top;
	while (j != -1)
	{
		//printf("%d\n",s->top);
		printf("%d\n",s->data[j]);
		j--;
	}
}

stack *push(stack *s,int value)
{
	if (s->top == MAXSIZE-1)
	{
		printf(" ERROR : full stack\n");
		exit(-1);
	}
	s->data[++(s->top)] = value;

	return s;
}
int pop(stack *s,int *value)
{
	if (s->top == -1)
	{
		printf("ERROR : empty stack\n");
		exit(-1);
	}
	value = &(s->data[s->top]);
	printf("value = %d\n",*value);
	s->top--;

	return *value;
}

int main(int argc, char const *argv[])
{
	stack *s = creatstack(6);
	int add = 0;
	printstack(s);
	printf("---------\n");
	s = push(s,6);
	add = pop(s,&add);
	//printf("add value = %p\n",&add);
	printf("pop value = %d\n",add);
	printstack(s);
	return 0;
}