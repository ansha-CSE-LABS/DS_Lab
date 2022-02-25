#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
typedef struct node *NODE;
NODE tail = NULL;

NODE getnode(int item)
{
    NODE p = (NODE)malloc(sizeof(struct node));
    p->data = item;
    p->next = p;
    return p;
}
void display()
{
    NODE temp = tail->next;
    if (tail == NULL)
    {
        printf("\nNo items to display!");
        return;
    }
    while (temp->next != tail->next)
    {
        printf("\n%d", temp->data);
        temp = temp->next;
    }
    printf("\n%d", temp->data);
    printf("\n");
}
void append(int item)
{
    NODE temp = tail->next;
    NODE newnode = getnode(item);
    if (tail == NULL)
    {
        tail = newnode;
        tail->next=newnode;
    }
    else
    {
        newnode->next = tail->next;
        tail->next = newnode;
        tail = newnode;
    }
}
void push(int item)
{
    NODE newnode = getnode(item);
    if (tail == NULL)
    {
        tail = newnode;
        tail->next=newnode;
    }
    else
    {
        newnode->next = tail->next;
        tail->next = newnode;
    }
}
void add_at_pos(int item, int pos)
{
    NODE temp = tail->next;
    NODE newnode = getnode(item);
    if (tail->next == NULL)
        tail->next = newnode;
    else if (pos == 1)
    {
        push(item);
    }
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
void pop()
{
    NODE temp = tail->next;
    if (tail == NULL)
    {
        printf("\nList is empty");
        return;
    }
    else if (temp->next == temp)
    {
        tail = NULL;
        free(temp);
    }
    else
    {
        tail->next = temp->next;
        free(temp);
    }
}
void delete_from_end()
{
    NODE temp = tail->next, prev;
    if (tail == NULL)
    {
        printf("\nList is empty");
        return;
    }
    else if (temp->next->next == temp)
    {
        tail = NULL;
        free(temp);
    }
    else
    {
        while (temp->next != tail->next)
        {
            prev = temp;
            temp = temp->next;
        }
        prev->next = tail->next;
        free(temp);
    }
}
void delete_at_pos(int pos)
{
    NODE temp = tail->next, ptr;
    if (tail->next == NULL)
    {
        printf("\nList is empty");
        return;
    }
    else if (pos == 1)
    {
        pop();
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
    int choice, item, pos, val;
    while (choice != 8)
    {
        printf("\n1.Push"
               "\n2.Append"
               "\n3.Add at specific position"
               "\n4.Pop"
               "\n5.Dequeue"
               "\n6.Delete from specific position"
               "\n7.Display"
               "\n8.Exit\n");
        printf("Enter your choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\nEnter data:");
            scanf("%d", &item);
            push(item);
            break;
        case 2:
            printf("\nEnter data:");
            scanf("%d", &item);
            append(item);
            break;
        case 3:
            printf("\nEnter data:");
            scanf("%d", &item);
            printf("\nEnter position:");
            scanf("%d", &pos);
            add_at_pos(item, pos);
            break;
        case 4:
            pop();
            break;
        case 5:
            delete_from_end();
            break;
        case 6:
            printf("\nEnter position:");
            scanf("%d", &pos);
            delete_at_pos(pos);
            break;
        case 7:
            display();
            break;
        case 8:
            break;
        default:
            printf("\nInvalid input");
        }
    }
}
