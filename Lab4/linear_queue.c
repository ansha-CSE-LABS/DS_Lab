#include <stdio.h>

#define SIZE 5
int q[SIZE];
int front = -1, rear = -1, num;

int isempty()
{
    if (rear == -1 && front == -1)
        return 1;
    else
        return 0;
}
int isfull()
{
    if (rear == SIZE - 1)
        return 1;
    else
        return 0;
}
void enqueue()
{
    if (isfull())
        printf("\nQueue is full\n");
    else
    {
        printf("Enter number to be pushed to queue:");
        scanf("%d", &num);
        if (isempty())
        {
            front = 0;
            q[++rear] = num;
        }
        else
        {
            q[++rear] = num;
        }
    }
}
void dequeue()
{
    if (isempty())
        printf("\nQueue is empty");
    else if (rear == front)
        rear = front = -1;
    else
        front++;
}
void display()
{
    if (isempty())
        printf("\nQueue is empty");
    else
    {
        printf("\nQueue:\n");
        for (int i = front; i <= rear; i++)
        {
            printf("%d\n", q[i]);
        }
    }
}
int main(void)
{
    int option = 0;
    do
    {
        printf("\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
        printf("Enter your option:");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            break;
        default:
            printf("Invalid option\n");
        }
    } while (option != 4);
}
