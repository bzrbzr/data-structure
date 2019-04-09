#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/**/

typedef struct Node
{
	struct Node *next;
	int value;
}node;

node *creatnext(int n)
{
	node *head = (node *)malloc(sizeof(node));
	head->value = rand()%100;
	head->next = NULL;

	node *last = head;

	while(--n)
	{
		node *tmp = (node *)malloc(sizeof(node));
		tmp->value = rand()%100;
		tmp->next = NULL;
		last->next = tmp;
		last = tmp;
	}
	return head;
}

node *creathead(int n)
{
	node *head = (node *)malloc(sizeof(node));
	head->value = rand()%100;
	head->next = NULL;

	node *last = head;

	while(--n)
	{
		node *tmp = (node *)malloc(sizeof(node));
		tmp->value = rand()%100;
		tmp->next = NULL;
		tmp->next = last->next;
		last->next = tmp;
	}
	return head;
}


void printnode(node *head)
{
	node *p = head;
	while(p->next != NULL)
	{
		printf("%d\n",p->value);
		p = p->next;
	}
	printf("%d\n",p->value);
}

int nodelen(node *head)
{
	node *p = head;
	int len = 0;
	while(p->next != NULL)
	{
		//printf("%d\n",p->value);
		p = p->next;
		len++;
	}
	return ++len;
}

#if 0
node *insert(node *head,int pos,int val)
{
	int len = 0;
	int i = 0;

	node *testlen = head;
	node *last = head;
	node *fm = last;

	node *tmp = (node *)malloc(sizeof(node));
	tmp->value = val;
	tmp->next = NULL;

	i = nodelen(testlen);
	printf("i = %d\n",i);
	if ( pos > i)
	{
		printf(" ERROR : pos is two long\n");
		return head;
	}

	if (i == pos)
	{
		while (len < (pos-1))
		{
			fm = last;
			last = last->next;
			len++;
		}

		last->next = tmp;
		tmp->next = NULL;
	}
	else
	{
		while (len < pos)
		{
			fm = last;
			last = last->next;
			len++;
		}
		tmp->next = last;
		fm->next = tmp;
	}

	return head;
}

#else
node *insert(node *head,int pos,int val)
{
	int j = 1;
	node *last = head;

	while(last && (j<pos))
	{
		last = last->next;
		j++;
	}

	if (!last||(j>pos))
	{
		printf(" ERROR : pos is two long\n");
		return head;	
	}

	node *tmp = (node *)malloc(sizeof(node));
	tmp->value = val;

	tmp->next = last->next;
	last->next = tmp;

	return head;
}

#endif



#if 0

node *delete(node *head,int pos)
{
	int len = 1;
	int i = 0;
	node *testlen = head;
	node *last = head;
	node *fm = last;

	i = nodelen(testlen);

	if (pos > i)
	{
		printf(" ERROR : pos is two long\n");
		return head;
	}

	while (len < pos)
	{
		fm = last;
		last = last->next;
		len++;
	}	

	fm->next = last->next;

	free(last);

	return head;
}
#else
node *delete(node *head,int pos)
{
	int j = 1;
	node *last = head;

	while((j<pos) && last->next)
	{
		last = last->next;
		j++;
	}

	while(!last->next || (j>pos))
	{
		printf(" ERROR : pos is two long\n");
		return head;
	}

	last->next = last->next->next;

	return head;
}

#endif

node *clearlist(node *head)
{
	node *last = head->next;
	node *q = NULL;

	while(last)
	{
		q = last->next;
		free(last);
		last = q;
	}
	head->next = NULL;

	return head;
}

int findnode(node *head,int pos)
{
	int len = 1;
	int i = 0;
	node *testlen = head;
	node *last = head;
	node *fm = last;

	i = nodelen(testlen);

	if (pos > i)
	{
		printf(" ERROR : pos is two long\n");
		return -1;
	}

	while (len < pos)
	{
		fm = last;
		last = last->next;
		len++;
	}

	return (last->value);	

}

int main(int argc, char const *argv[])
{
	int lenth = 0;
	int findval = 0;
	node *p = NULL;
	p = creatnext(6);
	//p = creathead(6);
	printnode(p);
	lenth = nodelen(p);
	printf("lenth = %d\n",lenth);
	//p = insert(p,3,400);
	//p = delete(p,2);
	p = clearlist(p);
	lenth = nodelen(p);
	printf("lenth = %d\n",lenth);
	//findval = findnode(p,7);
	//printf("findval = %d\n",findval);

	printnode(p);

	return 0;
}