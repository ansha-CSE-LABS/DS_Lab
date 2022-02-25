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
    if (data < root->data)
        root->left = insert(root->left, data);
    else
        root->right = insert(root->right, data);
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
int search(NODE root, int item)
{
    if (root == NULL)
        return 0;
    if (item == root->data)
        return 1;
    else if (item > root->data)
        search(root->right, item);
    else if (item < root->data)
        search(root->left, item);
    else
        printf("\nNot found");
}
NODE find_min(NODE root)
{
    while (root->left != NULL)
    {
        root = root->left;
    }
    return root;
}
NODE find_max(NODE root)
{
    while (root->right != NULL)
    {
        root = root->right;
    }
    return root;
}
NODE delete (NODE root, int item)
{
    if (root == NULL)
        return root;
    else if (item < root->data)
        root->left = delete (root->left, item);
    else if (item > root->data)
        root->right = delete (root->right, item);
    else
    {
        if (root->left == NULL && root->right == NULL)
        {
            free(root);
            root = NULL;
        }
        else if (root->left == NULL)
        {
            NODE temp = root;
            root = root->right;
            free(temp);
        }
        else if (root->right == NULL)
        {
            NODE temp = root;
            root = root->left;
            free(temp);
        }
        else
        {
            NODE temp = find_min(root->right);
            root->data = temp->data;
            root->right = delete (root->right, temp->data);
        }
    }
    return root;
}
int main(void)
{
    int item, choice, n;
    NODE ptr;
    while (choice != 9)
    {
        printf("\n\n1.Insert"
               "\n2.Inorder"
               "\n3.Preorder"
               "\n4.Postorder"
               "\n5.Search"
               "\n6.Find minimum"
               "\n7.Find maximum"
               "\n8.Delete"
               "\n9.Exit\n");
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
            printf("\nEnter item:");
            scanf("%d", &item);
            n = search(root, item);
            if (n == 1)
                printf("\nElement found");
            else
                printf("\nElement not found");
            break;
        case 6:
            ptr = find_min(root);
            printf("\nSmallest element is %d", ptr->data);
            break;
        case 7:
            ptr = find_max(root);
            printf("\nLargest element is %d", ptr->data);
            break;
        case 8:
            printf("\nEnter data:");
            scanf("%d", &item);
            delete (root, item);
            break;
        default:
            printf("Invalid input\n");
        }
    }
}
