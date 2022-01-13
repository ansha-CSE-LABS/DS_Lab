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
void pop()
{
    struct node *temp;
    if (head == NULL)
        printf("\nList is empty");
    else
    {
        temp = head;
        head = head->next;
        free(temp);
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
int main(void)
{
    int option = 0;
    do
    {
        printf("\nStack operation:\t1.Push\t\t2.Pop\n"
               "Queue operation:\t3.Append\t4.Dequeue\n"
               "5.Display\n"
               "6.Exit\n");
        printf("\nEnter your option:");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            append();
            break;
        case 4:
            pop();
            break;
        case 5:
            display();
            break;
        case 6:
            exit(0);
        default:
            printf("Invalid choice.\n");
        }
    } while (option != 6);
}
