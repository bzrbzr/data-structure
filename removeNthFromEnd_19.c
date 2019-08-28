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
	int j = 0;
	struct ListNode *last = head;

	int len = nodelen(last);

	int pos = 0;
	pos = len - n;
	printf("%d len = %d n = %d pos = %d \n", __LINE__,len,n,pos);

	if (len == 1)
	{
		printf("-----\n");
		free(last);
		head = NULL;
		return head;
	}
	else
	{
		while((j<(pos-1)) && last->next)
		{
			last = last->next;
			j++;
			printf("%d j = %d\n",__LINE__,j);
		}

		if (j == 0 && n == len)
		{
			printf("----\n");
			head = last->next;
		}
		else
			last->next = last->next->next;

		return head;
	}
}


int main(int argc, char const *argv[])
{
	int lenth = 0;
	int findval = 0;
	struct ListNode *p = NULL;
	p = creatnext(4);
	//p = creathead(6);
	printnode(p);
	lenth = nodelen(p);
	printf("lenth = %d\n",lenth);
	p = removeNthFromEnd(p,1);
	//p = clearlist(p);
	//lenth = nodelen(p);
	//printf("lenth = %d\n",lenth);
	//findval = findnode(p,7);
	//printf("findval = %d\n",findval);

	printnode(p);

	return 0;
}