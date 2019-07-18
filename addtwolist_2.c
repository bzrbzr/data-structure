#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct ListNode 
{
	int val;
    struct ListNode *next;
};

struct ListNode *creatnext(int n)
{
	struct ListNode *head = (struct ListNode *)malloc(sizeof(struct ListNode));
	head->val = rand()%10;
	head->next = NULL;

	struct ListNode *last = head;

	while(--n)
	{
		struct ListNode *tmp = (struct ListNode *)malloc(sizeof(struct ListNode));
		tmp->val = rand()%10;
		tmp->next = NULL;
		last->next = tmp;
		last = tmp;
	}
	return head;
}

void printnode(struct ListNode *head)
{
	struct ListNode *p = head;
	while(p->next != NULL)
	{
		printf("%d\n",p->val);
		p = p->next;
	}
	printf("%d\n",p->val);
}


struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
	int flag = 0;
	int x=0;int y=0;
	struct ListNode *head = (struct ListNode *)malloc(sizeof(struct ListNode));
	if ((l1->val)+(l2->val)+flag>=10)
	{
		head->val = ((l1->val)+(l2->val)+flag)%10;
		flag = 1;
	}
	else
	{
		head->val = (l1->val)+(l2->val)+flag;
		flag = 0;
	}
	head->next = NULL;
	struct ListNode *last = head;

	l1 = l1->next;
	l2 = l2->next;	

	while((l1||l2)||flag)
	{

		x= (l1 == NULL)?0:l1->val;
		y= (l2 == NULL)?0:l2->val;


		struct ListNode *tmp = (struct ListNode *)malloc(sizeof(struct ListNode));
		if ((x+y+flag)>=10)
		{
			tmp->val = (x+y+flag)%10;
			flag = 1;
		}
		else
		{
			tmp->val = (x+y+flag);
			flag = 0;
		}
		tmp->next = NULL;
		last->next = tmp;
		last = tmp;

		if (l1) l1 = l1->next;
		if (l2) l2 = l2->next;
	}
	return head;
}

int main(int argc, char const *argdv[])
{
	int lenthl1 = 0;int lenthl2 = 0;

	struct ListNode *l1 = NULL;
	struct ListNode *l2 = NULL;
	struct ListNode *l3 = NULL;
	l1 = creatnext(3);
	l2 = creatnext(4);
	printnode(l1);
	printf("------\n");
	printnode(l2);
	l3 = addTwoNumbers(l1,l2);
	printf("---------\n");
	printnode(l3);
	return 0;
}