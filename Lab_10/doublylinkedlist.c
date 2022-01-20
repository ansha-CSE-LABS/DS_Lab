/* Doubly Linked List */

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *prev;
    struct node *next;
};

struct node *head = NULL;
int n;

void push()
{
    printf("\nEnter data:");
    scanf("%d", &n);

    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = n;
    newnode->prev = NULL;
    newnode->next = NULL;

    if (head == NULL)
    {
        head = newnode;
        return;
    }
    else
    {
        newnode->next = head;
        head->prev = newnode;
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

void addatpos(int pos)
{
    struct node *temp = head, *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->prev = NULL;
    newnode->next = NULL;

    if (head == NULL)
    {
        head = newnode;
        return;
    }
    else
    {
        for (int i = 1; i < pos - 1; i++)
        {
            temp = temp->next;
        }
        if (temp->next == NULL)
        {
            printf("\nGiven position not found.Insertion not possible\n");
            return;
        }
        printf("\nEnter data:");
        scanf("%d", &n);
        newnode->data = n;

        newnode->next = temp->next;
        newnode->prev = temp;
        temp->next = newnode;
        newnode->next->prev = newnode;
    }
}

void delete_front()
{
    struct node *temp;
    if (head == NULL)
    {
        printf("\nList is empty");
        return;
    }
    else if (head->next == NULL)
    {
        free(head);
        head = NULL;
    }
    else
    {
        temp = head;
        head = head->next;
        free(temp);
        head->prev = NULL;
    }
}

void delete_end()
{
    struct node *temp = head;
    if (head == NULL)
    {
        printf("\nList is empty");
        return;
    }
    else if (head->next == NULL)
    {
        free(head);
        head = NULL;
    }
    else
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->prev->next = NULL;
        free(temp);
    }
}

void delete_pos(int pos)
{
    struct node *temp = head;

    if (head == NULL)
    {
        printf("\nList is empty");
        return;
    }
    else
    {
        if (pos == 1)
        {
            head = head->next;
            free(temp);
        }
        else
        {
            for (int i = 1; i < pos; i++)
            {
                temp = temp->next;
            }
            if (temp->next == NULL)
            {
                temp->prev->next = NULL;
                free(temp);
                return;
            }
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            free(temp);
        }
    }
}

void delete_by_val(int val)
{
    struct node *temp = head;

    if (head == NULL)
    {
        printf("\nList is empty");
        return;
    }
    else
    {
        if (temp != NULL && temp->data == val)
        {
            head = head->next;
            free(temp);
            return;
        }
        while (temp != NULL && temp->data != val)
        {
            temp = temp->next;
        }
        if (temp->next == NULL)
        {
            temp->prev->next = NULL;
            free(temp);
            return;
        }
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        free(temp);
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

void display_reverse()
{
    struct node *temp;
    temp = head;

    if (head == NULL)
    {
        printf("No element to display\n");
        return;
    }
    else
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        while (temp != head->prev)
        {
            printf("\n%d", temp->data);
            temp = temp->prev;
        }
        printf("\n");
    }
}

int main(void)
{
    int option = 0, pos, val;
    do
    {
        printf("\n1.Insert from front\n"
               "2.insert at end\n"
               "3.insert at position\n"
               "4.delete from front\n"
               "5.delete at end\n"
               "6.delete at position\n"
               "7.delete by value\n"
               "8.display start to end\n"
               "9.display reverse\n"
               "10.exit\n");
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
            addatpos(pos);
            break;
        case 4:
            delete_front();
            break;
        case 5:
            delete_end();
            break;
        case 6:
            printf("\nEnter position:");
            scanf("%d", &pos);
            delete_pos(pos);
            break;
        case 7:
            printf("\nEnter value:");
            scanf("%d", &val);
            delete_by_val(val);
            break;
        case 8:
            display();
            break;
        case 9:
            display_reverse();
            break;
        case 10:
            exit(0);
        default:
            printf("\nInvalid option\n");
        }
    } while (option != 10);
}
