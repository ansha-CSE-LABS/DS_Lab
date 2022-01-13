#include <stdio.h>
#include <stdlib.h>

#define SIZE 5
int stack[SIZE], top = -1;

int isfull()
{
    if (top == SIZE - 1)
        return 1;
    else
        return 0;
}
int isempty()
{
    if (top == -1)
        return 1;
    else
        return 0;
}
void push(int num)
{
    if (isfull())
        printf("\nStack Overflow!\n");
    else
    {
        top++;
        stack[top] = num;
    }
}
int pop()
{
    int n;
    if (isempty())
    {
        printf("\nStack Underflow!\n");
        return -1;
    }
    else
    {
        n = stack[top];
        top--;
    }
    return n;
}
void display()
{
    if (isempty())
        printf("\nStack is empty\n");
    else
    {
        for (int i = top; i >= 0; i--)
            printf("\n%d", stack[i]);
        printf("\n");
    }
}
int main(void)
{
    int num, option;
    while (option != 4)
    {
        printf("\n1.Push\n2.Pop\n3.Display\n4.Exit");
        printf("\nEnter your option:");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            printf("\nEnter number to be pushed:");
            scanf("%d", &num);
            push(num);
            break;
        case 2:
            num = pop();
            if (num != -1)
                printf("\n%d was popped out of stack\n", num);
            break;
        case 3:
            display();
            break;
        }
    }
}
