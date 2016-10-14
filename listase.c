#include <stdio.h>

struct node
{
	int val;
	struct node *next;
};

void makelist(struct node *cabeza,int n)
{
	struct node *prev, *cur;
	int i;
	prev = cabeza;
	for (i=2;i<=n;i++)
	{
		cur = malloc(sizeof(struct node));
		cur -> val = i;
		prev -> next = cur;
		prev = cur;
	}
	prev -> next = NULL;
}

int lenl(struct node *cabeza)
{
	int n=0;
	struct node *temp;
	temp = cabeza;
	while(temp != NULL)
	{
		temp = temp->next;
		n++;
	}
	return n;
}

void printl(struct node *cabeza)
{
	struct node *t;
	t = cabeza;
	printf("[");
	while(t!=NULL)
	{
		printf("%d",t->val);
		if(t->next != NULL)
			printf(",");
		t = t->next;
	}
	printf("]\n");
}

void deletel(struct node *cabeza, int n)
{
	struct node *prev, *cur, *temp;
	prev = cabeza;
	cur = cabeza->next;
	if(cabeza->val == n)
	{
		temp = cabeza;
		cabeza = cabeza->next;
		free(temp);
	}
	else 
	{
		while(cur != NULL)
		{
			if (cur->val == n)
			{
				prev->next = cur->next;
				free(cur);
				break;
			}
			prev = cur;
			cur = cur->next;
	}
	}
}

void insertl(struct node *cabeza, int i, int n)
{
	struct node *temp, *prev, *cur;
	int i2;
	temp = malloc(sizeof(struct node));
	if(i == 1){
		temp ->val = cabeza-> val;
		temp ->next = cabeza->next;
		cabeza -> val = n;
		cabeza -> next = temp;
	}
	else
	{
		prev = cabeza;
		cur = cabeza->next;
		for(i2=2; i2<i && cur->next != NULL; i2++)
		{
			prev = prev->next;
			cur = cur->next;
		}
		temp->val = n;
		if(i < lenl(cabeza)){
			prev->next = temp;
			temp->next = cur;
		}
		else
		{
			cur->next = temp;
			temp -> next = NULL;
		}
	}
	
}

void insertsort(struct node *cabeza, int n)
{
	int i=1;
	struct node *cur;
	cur = cabeza;
	while(cur != NULL && n > cur->val){
		i++;
		cur = cur->next;
	}
	insertl(cabeza,i,n);
}

void concatenar(struct node *lista1, struct node *lista2)
{
	struct node *temp;
	temp = lista2;
	while(temp != NULL)
	{
		insertl(lista1,lenl(lista1)+lenl(lista2)+1,temp->val);
		temp = temp->next;
	}
}

main()
{
	struct node *head, *head2;
	head = malloc(sizeof(struct node));
	head2 = malloc(sizeof(struct node));
	head ->val = 1;
	head2 ->val = 1;
	makelist(head2,9);
	makelist(head,7);
	printl(head);
	deletel(head,4);
	printl(head);
	insertl(head,10,3);
	printl(head);
	insertsort(head,4);
	printl(head);
	printl(head2);
	concatenar(head,head2);
	printl(head);
}
