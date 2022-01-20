/*
Implement a Doubly linked list program to store Facebook friend list (name, mobile number, likes) and display friend details having the highest number of likes.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    char name[50];
    char phno[12];
    int likes;
    struct node *prev;
    struct node *next;
};

struct node *head = NULL;

void append()
{
    struct node *temp = head, *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter name:");
    scanf("%s", &newnode->name);
    printf("Enter phone number:");
    scanf("%s", &newnode->phno);
    printf("Enter number of likes:");
    scanf("%d", &newnode->likes);
    newnode->prev = NULL;
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
        newnode->prev = temp;
    }
}

void display()
{
    struct node *temp;
    temp = head;

    if (head == NULL)
    {
        printf("No element to display\n");
        return;
    }
    printf("\nPerson with highest likes;");
    printf("\nName:%s", temp->name);
    printf("\nPh.no.:%s", temp->phno);
    printf("\nNo. of likes:%d\n", temp->likes);
}

void swap(struct node *x, struct node *y)
{
    struct node temp = *x;
    x->likes = y->likes;
    strcpy(x->name, y->name);
    strcpy(x->phno, y->phno);
    y->likes = temp.likes;
    strcpy(y->name, temp.name);
    strcpy(y->phno, temp.phno);
}

void sort()
{
    struct node *i, *j;
    if (head == NULL)
        return;
    for (i = head; i->next != NULL; i = i->next)
    {
        for (j = i->next; j != NULL; j = j->next)
        {
            if (i->likes < j->likes)
                swap(i, j);
        }
    }
}

int main(void)
{
    int option = 0;
    do
    {
        printf("\n1.Add person to list"
               "\t2.Display highest"
               "\t3.exit");
        printf("\nEnter your option:");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            append();
            break;
        case 2:
            sort();
            display();
            break;
        case 3:
            break;
        default:
            printf("\nInvalid choice!");
        }
    } while (option != 3);
}
