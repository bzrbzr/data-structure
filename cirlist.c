#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node{
	int value;
	struct Node *next;
}Node;

Node *creatlist(int nums)
{
	Node *head = (Node *)malloc(sizeof(Node));
	head->value = rand()%100;
	head->next = NULL;

	Node *list = head;

	while(nums--)
	{
		Node *tmp = (Node *)malloc(sizeof(Node));
		tmp->value = rand()%100;
		list->next = tmp;
		list = list->next;		
	}

	list->next = head;
	return head;
}

void printlist(Node *head)
{
	Node *list = head;

	while(list ->next != head)
	{
		printf("%d\n",list->value);
		list = list->next;
	}
	printf("%d\n",list->value);
}

Node *insert(Node *head,int pos,int val)
{
	Node *list = head;
	int j = 1;

	while(j < pos && (list->next != head))
	{
		list = list->next;
		j++;
	}
	if (j > pos ||(list->next == head))
	{
		printf(" ERROR : pos is two long\n");
		return head;
	}

	Node *tmp = (Node *)malloc(sizeof(Node));
	tmp->value = val;

	tmp->next = list->next;
	list->next = tmp;

	return head;
}

Node *delete(Node *head,int pos)
{
	Node *list = head;
	int j = 1;

	while(j < pos && (list->next != head))
	{
		list = list->next;
		j++;		
	}

	if (j > pos ||(list->next == head))
	{
		printf(" ERROR : pos is two long\n");
		return head;
	}

	list->next = list->next->next;
	free(list->next);

	return head;

}

int findnode(Node *head,int pos)
{
	Node *list = head;
	int j = 1;

	while(j < pos && (list->next != head))
	{
		list = list->next;
		j++;		
	}

	if (j > pos ||(list->next == head))
	{
		printf(" ERROR : pos is two long\n");
		return -1;
	}

	return list->next->value;
}

int main(int argc, char const *argv[])
{
	Node *p = creatlist(6);
	int findval = 0;
	printlist(p);
	printf("-----------\n");
	p = insert(p,6,100);
	//p = delete(p,7);
	//findval = findnode(p,3);
	//printf("findval = %d\n", findval);
	printlist(p);
	return 0;
}