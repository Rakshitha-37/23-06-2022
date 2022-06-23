#include <stdio.h>
#include<stdlib.h>

#define NODE_SIZE 5

typedef struct circular
{
    char data;
    struct circular *link;
}cll;

void insert(cll **head_arg, char data);
void print(cll **head_arg);

int main()
{
    char data;
    int i = 0;
    cll *head = NULL;
    while(i++ < NODE_SIZE)
    {
        printf("Enter the data: ");
        scanf(" %c", &data);
        insert(&head, data);
    }
    print(&head);
    return 0;
}

void insert(cll **head_arg, char data)
{
    cll *new = (cll *)malloc(sizeof(cll));
    if(new == NULL)
    {
        printf("Memory not allocated\n");
    }
    else
    {
        new->data = data;
        new->link = NULL;
        if(*head_arg == NULL)
        {
            *head_arg = new;
            new->link = *head_arg;
        }
        else
        {
            cll *temp = *head_arg;
            while(temp->link != *head_arg)
            {
                temp = temp->link;
            }
            temp->link = new;
            new->link = *head_arg;
        }
    }
}

void print(cll **head_arg)
{
    cll *temp;
    if(*head_arg == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        temp = *head_arg;
        printf("Elements are: ");
        do
        {
            printf("%c ", temp->data);
            temp = temp->link;
        }while(temp != *head_arg);
        printf("\n");
    }
}