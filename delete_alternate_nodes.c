#include <stdio.h>
#include<stdlib.h>

#define NODE_SIZE 5

typedef struct node
{
    int data;
    struct node *link;
}sll;

void insert(int data, sll **head);
void print(sll **head);
void delete_alternate(sll **head);

int main()
{
    sll *head = NULL;
    int data, i = 0;
    while(i++ < NODE_SIZE)
    {
        printf("Enter data: ");
        scanf("%d", &data);
        insert(data, &head);
    }
    print(&head);
    delete_alternate(&head);
    print(&head);
    
    return 0;
}

void insert(int data, sll **head)
{
    sll *new = (sll *)malloc(sizeof(sll));
    if(new == NULL)
    {
        printf("Memory not allocated\n");
    }
    else
    {
        new->data = data;
        new->link = NULL;
        if(*head == NULL)
        {
            *head = new;
        }
        else
        {
            sll *temp = *head;
            while(temp->link != NULL)
            {
                temp = temp->link;
            }
            temp->link = new;
        }
    }
}

void print(sll **head)
{
    if(*head == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        sll *temp = *head;
        while(temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->link;
        }
        printf("\n");
    }
}

void delete_alternate(sll **head)
{
    if(*head == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        sll *temp = *head;
        sll *temp1;
        while(temp->link != NULL)
        {
            temp1 = temp->link;
            temp->link = temp1->link;
            printf("The deleted item is %d\n", temp1->data);
            free(temp1);
            temp = temp->link;
        }
    }
}

