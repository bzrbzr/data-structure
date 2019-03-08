#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct node
{
	int value;
	struct node *prior;
	struct node *next;
}node;

node *creatlist(int nums)
{
	node *head = (node *)malloc(sizeof(node));
	head->value = rand()%100;
	head->next = NULL;
	head->prior = NULL;

	node *list = head;

	while(nums--)
	{
		node *tmp = (node *)malloc(sizeof(node));
		tmp->value = rand()%100;
		list->next = tmp;
		tmp->prior = list;
		tmp->next = NULL;

		list = tmp;
	}
	return head;
}

void printlist(node *head)
{
	node *list = head;

	while(list->next)
	{
		printf("%d\n",list->value);
		list = list->next;
	}

	printf("%d\n",list->value);
}

node *insert(node *head,int pos,int value)
{
	node *list = head;
	int j = 1;

	while(j < pos && list->next)
	{
		list = list->next;
		j++;
	}

	if(j > pos ||(list->next == NULL))
	{
		printf(" ERROR : pos is two long\n");
		return head;
	}

	node *tmp = (node *)malloc(sizeof(node));
	tmp->value = value;

	tmp->prior = list;
	tmp->next = list->next;
	list->next->prior = tmp;
	list->next = tmp;

	return head;
}

node *delete(node *head,int pos)
{
	node *list = head;
	int j = 0;

	while(j < pos && list)
	{
		list = list->next;
		j++;
		printf("j = %d list = %d\n",j,list->value);
	}

	if(j > pos ||(list == NULL))
	{
		printf(" ERROR : pos is two long\n");
		return head;
	}


	list->prior->next = list->next;
	if (list->next)
	{
		list->next->prior = list->prior;
	}
			

	free(list);

	return head;
}

int main(int argc, char const *argv[])
{
	node *p = creatlist(6);
	printlist(p);
	printf("--------------\n");
	//p = insert(p,6,100);
	p = delete(p,6);
	printlist(p);
	return 0;
}