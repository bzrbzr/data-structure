#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct node
{
	int value;
	struct node *next;
}node;

typedef struct stack
{
	node *top;
	int count;
}stack;

stack *creatstack(int nums)
{
	stack *s = (stack *)malloc(sizeof(stack));
	node *tmp = (node *)malloc(sizeof(node));

	tmp->value = rand()%100;
	//printf("head value = %d\n",tmp->value);
	tmp->next = NULL;

	s->count = 1;

	s->top = tmp;
#if 1
	while(--nums)
	{
		node *tmp = (node *)malloc(sizeof(node));
		tmp->value = rand()%100;
		tmp->next = s->top;

		s->top = tmp;
		s->count++;
	}

#endif
	return s;
}
#if 0
void printlinklist(stack *s)
{
	node *j = s->top;
	while(j->next != NULL)
	{
		printf("%d\n",j->value);
		j = j->next;
	}
	printf("%d\n",j->value);
}
#else
void printlinklist(stack *s)
{
	stack *j = (stack *)malloc(sizeof(stack));
	j->count = s->count;
	j->top = (node *)malloc(sizeof(node)*(j->count));
	memcpy(j->top,s->top,sizeof(node)*(j->count));
	while(j->top->next != NULL)
	{
		printf("%d\n",j->top->value);
		j->top = j->top->next;
	}
	printf("%d\n",j->top->value);
}
#endif

stack *insetstack(stack *s,int data)
{
	node *tmp = (node *)malloc(sizeof(node));
	tmp->value = data;
	tmp->next = s->top;

	s->top = tmp;

	s->count++;

	return s;

}

int main(int argc, char const *argv[])
{
	stack *s = creatstack(3);
	printlinklist(s);
	printf("--------insetstack----\n");
	s = insetstack(s,100);
	printlinklist(s);
	return 0;
}