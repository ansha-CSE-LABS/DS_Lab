//Singly Linked list deletion

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
void delete_front()
{
    struct node *temp;
    if (head == NULL)
        printf("\nList is empty\n");
    else
    {
        temp = head;
        head = head->next;
        free(temp);
    }
}
void delete_end()
{
    struct node *temp = head, *prev;
    if (head == NULL)
        printf("\nList is empty\n");
    else
    {
        while (temp->next != NULL)
        {
            prev = temp;
            temp = temp->next;
        }
        prev->next = NULL;
        free(temp);
    }
}
void delete_pos(int pos)
{
    struct node *temp, *ptr;
    temp = head;
    if (head == NULL)
        printf("\nList is empty");
    else if (temp == NULL)
    {
        printf("\nLess than %d elements in list", pos);
    }
    else
    {
        for (int i = 1; i < pos; i++)
        {
            ptr = temp;
            temp = temp->next;
        }
        ptr->next = temp->next;
        free(temp);
    }
}
int main(void)
{
    int option = 0, pos;
    while (option != 6)
    {
        printf("\nChoose:\n1:Insert\n2:Delete from front\n3.Delete at the end\n4:Insert at specific position\n5:Display\n6:Exit\n");
        printf("\nEnter your option:");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            append();
            break;
        case 2:
            delete_front();
            break;
        case 3:
            delete_end();
            break;
        case 4:
            printf("\nEnter position:");
            scanf("%d", &pos);
            delete_pos(pos);
            break;
        case 5:
            display();
            break;
        case 6:
            break;
        default:
            printf("\nInvalid choice");
        }
    }
}
