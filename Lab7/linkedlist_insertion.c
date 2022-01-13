/*Singly linked list insertion*/

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;
int n;

void display()
{
    struct node *temp = head;
    if (head == NULL)
    {
        printf("\nNo element to display\n");
        return;
    }
    else
    {
        while (temp != NULL)
        {
            printf("\n%d", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}
void push()
{
    printf("\nEnter data:");
    scanf("%d", &n);

    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = n;
    newnode->next = NULL;

    if (head == NULL)
    {
        head = newnode;
        return;
    }
    else
    {
        newnode->next = head;
        head = newnode;
    }
}
void append()
{
    printf("\nEnter data:");
    scanf("%d", &n);

    struct node *temp = head, *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = n;
    newnode->next = NULL;

    if (head == NULL)
    {
        head = newnode;
        return;
    }
    else
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
    }
}
void add_at_pos(int pos)
{
    printf("\nEnter data:");
    scanf("%d", &n);
    struct node *temp = head;
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = n;
    newnode->next = NULL;
    if (head == NULL)
        head = newnode;
    else
    {
        for (int i = 1; i < pos - 1; i++)
        {
            temp = temp->next;
        }
        newnode->next = temp->next;
        temp->next = newnode;
    }
}
int main(void)
{
    int option = 0, n, pos;
    while (option != 5)
    {
        printf("\nChoose:\n1:Insert from front\n2:Insert at end\n3:Insert at specific position\n4:Display\n5:Exit\n");
        printf("\nEnter your option:");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            push();
            break;
        case 2:
            append();
            break;
        case 3:
            printf("\nEnter position:");
            scanf("%d", &pos);
            add_at_pos(pos);
            break;
        case 4:
            display();
            break;
        case 5:
            break;
        default:
            printf("\nInvalid choice");
        }
    }
}
