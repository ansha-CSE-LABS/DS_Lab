#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
typedef struct node *NODE;
NODE head = NULL;

NODE getnode(int item)
{
    NODE p = (NODE)malloc(sizeof(struct node));
    p->data = item;
    p->next = NULL;
    return p;
}
void display()
{
    NODE temp = head;
    if (head == NULL)
    {
        printf("\nNo items to display!");
        return;
    }
    while (temp != NULL)
    {
        printf("\n%d", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
void append(int item)
{
    NODE temp = head;
    NODE newnode = getnode(item);
    if (head == NULL)
        head = newnode;
    else
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
    }
}
void push(int item)
{
    NODE newnode = getnode(item);
    if (head == NULL)
        head = newnode;
    else
    {
        newnode->next = head;
        head = newnode;
    }
}
void add_at_pos(int item, int pos)
{
    NODE temp = head;
    NODE newnode = getnode(item);
    if (head == NULL)
        head = newnode;
    else if (pos == 1)
    {
        newnode->next = head;
        head = newnode;
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
    NODE temp;
    if (head == NULL)
    {
        printf("\nList is empty");
        return;
    }
    else
    {
        temp = head;
        head = head->next;
        free(temp);
    }
}
void delete_from_end()
{
    NODE temp = head,prev;
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
            prev = temp;
            temp = temp->next;
        }
        prev->next = NULL;
        free(temp);
    }
}
void delete_at_pos(int pos)
{
    NODE temp = head, ptr;
    if (head == NULL)
    {
        printf("\nList is empty");
        return;
    }
    else if (pos == 1)
    {
        head = head->next;
        free(temp);
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
void delete_by_val(int val)
{
    NODE temp = head,prev;
    if (head == NULL)
    {
        printf("\nList is empty");
        return;
    }
    else
    {
        if(temp!=NULL && temp->data==val){
            head = head->next;
            free(temp);
            return;
        }
        while (temp != NULL &&temp->data != val)
        {
            prev=temp;
            temp = temp->next;
        }
        prev->next=temp->next;
        free(temp);
    }
}
int main(void)
{
    int choice, item, pos,val;
    while (choice != 9)
    {
        printf("\n1.Push"
               "\n2.Append"
               "\n3.Add at specific position"
               "\n4.Pop"
               "\n5.Dequeue"
               "\n6.Delete from specific position"
               "\n7.Delete a specific value"
               "\n8.Display"
               "\n9.Exit\n");
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
            printf("\nEnter value:");
            scanf("%d",&val);
            delete_by_val(val);
            break;
        case 8:
            display();
            break;
        case 9:
            break;
        default:
            printf("\nInvalid input");
        }
    }
}
