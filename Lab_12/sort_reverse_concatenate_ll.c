#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
int n;
struct node *append(struct node *head)
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
        return head;
    }
    else
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
    }
    return head;
}

void display(struct node *head)
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

struct node *reverse(struct node *head)
{
    struct node *current = head, *prev=NULL, *next=NULL;
    if (head == NULL)
    {
        printf("list is empty\n");
        return head;
    }
    if (head->next == NULL)
        return head;
    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
    return head;
}

void swap(struct node *x, struct node *y)
{
    struct node temp = *x;
    x->data = y->data;
    y->data = temp.data;
}

struct node *sort(struct node *head)
{
    struct node *i, *j;
    if (head == NULL)
    {
        printf("List is empty!");
        return head;
    }
    else
    {
        for (i = head; i->next != NULL; i = i->next)
        {
            for (j = i->next; j != NULL; j = j->next)
            {
                if (i->data > j->data)
                    swap(i, j);
            }
        }
    }
    return head;
}
struct node *concatenate(struct node *head1, struct node *head2)
{
    struct node *temp = head1;
    if (head1 == NULL)
        return head2;
    if (head2 == NULL)
        return head1;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = head2;
    return head1;
}
int main(void)
{
    struct node *head1 = NULL;
    struct node *head2 = NULL;
    int option = 0;
    while (option != 10)
    {
        printf("\nChoose\n1.Insert to list1"
               "\n2.Insert to list 2"
               "\n3.Sort list 1"
               "\n4.Sort list 2"
               "\n5.Reverse list 1"
               "\n6.Reverse list 2"
               "\n7.concatenate lists"
               "\n8.Display list 1 or concatenated list"
               "\n9.Display list 2"
               "\n10.Exit\n");
        printf("\nEnter your option:");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            head1 = append(head1);
            break;
        case 2:
            head2 = append(head2);
            break;
        case 3:
            head1 = sort(head1);
            break;
        case 4:
            head2 = sort(head2);
            break;
        case 5:
            head1 = reverse(head1);
            break;
        case 6:
            head2 = reverse(head2);
            break;
        case 7:
            head1 = concatenate(head1, head2);
            break;
        case 8:
            display(head1);
            break;
        case 9:
            display(head2);
            break;
        case 10:
            break;
        default:
            printf("Incorrect choice");
        }
    }
}
