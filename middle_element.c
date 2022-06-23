#include <stdio.h>
#include<stdlib.h>

#define NODE_SIZE 3

typedef struct node
{
    int data;
    struct node *link;
}sll;

void insert(sll **head_arg, int data);
void print(sll **head_arg);
void middle_element(sll **head_arg);

int main()
{
    sll *head = NULL;
    int data, i = 0;
    while(i++ < NODE_SIZE)
    {
        printf("Enter data: ");
        scanf("%d", &data);
        insert(&head, data);
    }
    print(&head);
    middle_element(&head);
    
    return 0;
}

void insert(sll **head_arg, int data)
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
        if(*head_arg == NULL)
        {
            *head_arg = new;
        }
        else
        {
            sll *temp = *head_arg;
            while(temp->link != NULL)
            {
                temp = temp->link;
            }
            temp->link = new;
        }
    }
}

void print(sll **head_arg)
{
    if(*head_arg == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        sll *temp = *head_arg;
        printf("Elements are: ");
        while(temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->link;
        }
        printf("\n");
    }
}

void middle_element(sll **head_arg)
{
    if(*head_arg == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        sll *slow_ptr = *head_arg;
        sll *fast_ptr = *head_arg;
        while(fast_ptr->link != NULL)
        {
            slow_ptr = slow_ptr->link;
            fast_ptr = fast_ptr->link->link;
        }
        printf("Middle element is %d\n", slow_ptr->data);
    }
}

