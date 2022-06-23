#include<stdio.h>
#include<stdlib.h>

#define SIZE 5

typedef struct double_ll
{
    int data;
    struct double_ll *prev;
    struct double_ll *next;
}dll;

void insert(dll **head);
void display(dll **head);
void delete(dll **head);

int main()
{
    dll *head = NULL;
    int i = 0;
    while(i++ < SIZE)
    {
        insert(&head);
    }
    display(&head);
    delete(&head);
    display(&head);
}

void insert(dll **head)
{
    int data;
    printf("Enter the data to be inserted: ");
    scanf("%d", &data);
    dll *newnode = (dll *)malloc(sizeof(dll));
    if(newnode == NULL)
    {
        printf("Memory not allocated\n");
    }
    else
    {
        newnode->data = data;
        newnode->prev = NULL;
        newnode->next = NULL;
        if(*head == NULL)
        {
            *head = newnode;
        }
        else
        {
            dll *temp = *head;
            while(temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newnode;
            newnode->prev = temp;
        }
    }
}

void display(dll **head)
{
    if(*head == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        dll *temp = *head;
        printf("List elements are: ");
        while(temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

void delete(dll **head)
{
    if(*head == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        dll *temp = *head;
        dll *temp1 = NULL;
        while(temp->next != NULL)
        {
            temp1 = temp;
            temp = temp->next;
        }
        temp1->next = NULL;
        printf("Deleted element is %d\n", temp->data);
        free(temp);
    }
}

