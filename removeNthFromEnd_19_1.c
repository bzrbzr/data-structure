#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct ListNode
{
	struct ListNode *next;
	int value;
};

struct ListNode *creatnext(int n)
{
	struct ListNode *head = (struct ListNode *)malloc(sizeof(struct ListNode));
	head->value = rand()%100;
	head->next = NULL;

	struct ListNode *last = head;

	while(--n)
	{
		struct ListNode *tmp = (struct ListNode *)malloc(sizeof(struct ListNode));
		tmp->value = rand()%100;
		tmp->next = NULL;
		last->next = tmp;
		last = tmp;
	}
	return head;
}


void printnode(struct ListNode *head)
{
	struct ListNode *p = head;
	if (p == NULL)
	{
		printf(" 123\n");
	}
	else
	{
		while(p->next != NULL)
		{
			printf("%d\n",p->value);
			p = p->next;
		}
		printf("%d\n",p->value);
	}

}


int nodelen(struct ListNode *head)
{
	struct ListNode *p = head;
	int len = 0;
	while(p->next != NULL)
	{
		p = p->next;
		len++;
	}
	return ++len;
}


struct ListNode * removeNthFromEnd(struct ListNode *head,int n)
{
	struct ListNode *p,*prev,*q;
	//struct ListNode prev;
	//struct ListNode *q;
	prev = (struct ListNode *)malloc(sizeof(struct ListNode));
	//prev = (struct ListNode *)malloc(sizeof(struct ListNode));
	prev->next = head;
	//prev = p;
	q = head;
	while(--n)
	{
		q = q->next;
	}
	printf("q = %d\n",q->value);

	while(q->next)
	{
		q = q->next;
		prev = prev->next;
	}

	struct ListNode *tmp = prev->next;
	prev->next = tmp->next;

	if (tmp == head)
	{
		head = tmp->next;
	}


	return head;
}


int main(int argc, char const *argv[])
{
	int lenth = 0;
	int findval = 0;
	struct ListNode *p = NULL;
	p = creatnext(2);
	//p = creathead(6);
	printnode(p);
	lenth = nodelen(p);
	printf("lenth = %d\n",lenth);
	p = removeNthFromEnd(p,2);
	//p = clearlist(p);
	//lenth = nodelen(p);
	//printf("lenth = %d\n",lenth);
	//findval = findnode(p,7);
	//printf("findval = %d\n",findval);

	printnode(p);

	return 0;
}