#include<stdio.h>
#include<stdlib.h>

#define NODE_SIZE 5

typedef struct node
{
	int data;
	struct node *link;
}slist;

slist *head = NULL;

void insert(int data)
{
	slist *new = malloc(sizeof(slist));
	if(new == NULL)
	{
		printf("Memory is not allocated\n");
	}
	else
	{		
		new->data = data;
		if(head == NULL)
		{
			head = new;
			new->link = head;
		}
		else
		{
			slist *temp = head;
			while(temp->link != head)
			{
				temp = temp->link;
			}
			temp->link = new;
			new->link = head;
		}
	}
}

void display()
{
	slist *temp = head;
	if(head == NULL)
	{
		printf("List is empty\n");
	}
	else
	{
		printf("The circular list is : ");
		do
		{
			printf("%d ", temp->data);
			temp = temp->link;
		}while(temp != head);
		printf("\n");
	}
}

int looping()
{
	slist *prev = head;
	slist *curr = head;
	while(prev != NULL && curr != NULL && curr->link != NULL)
	{
		prev = prev->link;
		curr = curr->link->link;
		if(prev == curr)
		{
			return 1;
		}
	}
	return 0;
}

int main()
{
	int i=0,data;
	while(i++<NODE_SIZE)
	{
		printf("Enter data : ");
		scanf("%d", &data);
		insert(data);
	}
	display();
	int ret = looping();
	if(ret)
	printf("Loop is present\n");
	else
	printf("Loop is not present\n");
}

