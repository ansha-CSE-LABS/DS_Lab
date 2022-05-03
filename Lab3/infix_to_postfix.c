#include <stdio.h>
#include <ctype.h>

#define SIZE 10
char stack[SIZE];
int top = -1;

void push(char n)
{
    if (top == SIZE - 1)
        printf("\nStack Overflow");
    else
        stack[++top] = n;
}
char pop()
{
    if (top == -1)
        printf("\nStack Underflow");
    else
        return (stack[top--]);
}
int priority(char opr)
{
    if (opr == '^')
        return 3;
    else if (opr == '*' || opr == '/' || opr == '%')
        return 2;
    else if (opr == '+' || opr == '-')
        return 1;
    else
        return 0;
}
void infixtopostfix(char inf[], char post[])
{
    int i = 0, j = 0, n, ch;
    push('#');
    while ((ch = inf[i++]) != '\0')
    {
        if (ch == '(')
            push(ch);
        else
        {
            if (isalnum(ch))
                post[j++] = ch;
            else
            {
                if (ch == ')')
                {
                    while (stack[top] != '(')
                    {
                        post[j++] = pop();
                    }
                    n = pop();
                }
                else
                {
                    while (priority(stack[top]) >= priority(ch))
                    {
                        post[j++] = pop();
                    }
                    push(ch);
                }
            }
        }
    }
    while (stack[top] != '#')
    {
        post[j++] = pop();
    }
    post[j] = '\0';
}
int main(void)
{
    char inf[10], post[10];
    printf("\nEnter infix expression:");
    scanf("%s", inf);
    infixtopostfix(inf, post);
    printf("\nPostfix expression = %s\n", post);
}
