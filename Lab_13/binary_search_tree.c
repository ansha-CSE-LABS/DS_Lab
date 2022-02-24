#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    int count;
    struct node *left;
    struct node *right;
};

typedef struct node *NODE;
NODE root = NULL;

NODE getnode(int item)
{
    NODE p;
    p = (NODE)malloc(sizeof(struct node));
    p->count = 1;
    p->data = item;
    p->left = NULL;
    p->right = NULL;
    return p;
}
NODE insert(NODE root, int data)
{
    if (root == NULL)
        return getnode(data);
    if (data == root->data)
        (root->count)++;
    else
    {
        if (data < root->data)
            root->left = insert(root->left, data);
        else
            root->right = insert(root->right, data);
    }
    return root;
}
void inorder(NODE root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    printf("\n%d(%d)", root->data, root->count);
    inorder(root->right);
}
void preorder(NODE root)
{
    if (root == NULL)
        return;
    printf("\n%d", root->data);
    preorder(root->left);
    preorder(root->right);
}
void postorder(NODE root)
{
    if (root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    printf("\n%d", root->data);
}
int main(void)
{
    int item, choice;
    while (choice != 5)
    {
        printf("\n\n1.Insert"
               "\n2.Inorder"
               "\n3.Preorder"
               "\n4.Postorder"
               "\n5.Exit\n");
        printf("Enter your choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\nEnter data:");
            scanf("%d", &item);
            root = insert(root, item);
            break;
        case 2:
            inorder(root);
            break;
        case 3:
            preorder(root);
            break;
        case 4:
            postorder(root);
            break;
        case 5:
            break;
        default:
            printf("Invalid input\n");
        }
    }
}
