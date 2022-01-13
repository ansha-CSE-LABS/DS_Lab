#include <stdio.h>

#define SIZE 5
int q[SIZE], front = -1, rear = -1, num;

int isempty()
{
    if (rear == -1 && front == -1)
        return 1;
    else
        return 0;
}
int isfull()
{
    if ((rear + 1) % SIZE == front)
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
        printf("\nEnter number to be enqueued:");
        scanf("%d", &num);
        if (isempty())
        {
            rear = front = 0;
            q[rear] = num;
        }
        else
        {
            rear = (rear + 1) % SIZE;
            q[rear] = num;
        }
    }
}
int dequeue()
{
    int n;
    if (isempty())
    {
        printf("\nQueue is empty\n");
        return 1;
    }
    else
    {
        n = q[front];
        if (front == rear)
            front = rear = -1;
        else
            front = (front + 1) % SIZE;
    }
    return n;
}
void display()
{
    if (isempty())
        printf("\nQueue is empty\n");
    else
    {
        int i;
        printf("\nQueue elements:\n");
        for (i = front; i != rear; i = (i + 1) % SIZE)
        {
            printf("%d\n", q[i]);
        }
        printf("%d\n", q[i]);
    }
}
int main(void)
{
    int num, option = 0;
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
            num = dequeue();
            if (num != 1)
                printf("\n%d was dequeued\n", num);
            break;
        case 3:
            display();
            break;
        case 4:
            break;
        default:
            printf("\nInvalid option");
        }
    } while (option != 4);
}
