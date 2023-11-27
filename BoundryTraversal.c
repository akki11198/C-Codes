#include <stdio.h>
#include <stdlib.h>

struct bstnode
{
    int data;
    struct bstnode *left;
    struct bstnode *right;
} *root = NULL;
struct bstnode *new (int item)
{
    struct bstnode *temp = (struct bstnode *)malloc(sizeof(struct bstnode));
    temp->data = item;
    temp->left = temp->right = NULL;
    return temp;
}
struct bstnode *insert(struct bstnode *root, int x)
{
    if (root == NULL)
        return new (x);
    else if (x > root->data)
        root->right = insert(root->right, x);
    else
        root->left = insert(root->left, x);
    return root;
}
void display(struct bstnode *root)
{
    if (root == NULL)
    {
        printf("No elements in the tree to display\n");
        return;
    }
    if (root->left != NULL)
        display(root->left);
    printf("%d -> ", root->data);
    if (root->right != NULL)
        display(root->right);
}
void printLeaves(struct bstnode *root)
{
    if (root == NULL)
        return;
    printLeaves(root->left);
    if (!(root->left) && !(root->right))
        printf("%d-> ", root->data);
    printLeaves(root->right);
}
void printBoundaryLeft(struct bstnode *root)
{
    if (root == NULL)
        return;
    if (root->left)
    {
        printf("%d-> ", root->data);
        printBoundaryLeft(root->left);
    }
    else if (root->right)
    {
        printf("%d-> ", root->data);
        printBoundaryLeft(root->right);
    }
}
void printBoundaryRight(struct bstnode *root)
{
    if (root == NULL)
        return;

    if (root->right)
    {
        printBoundaryRight(root->right);
        printf("%d-> ", root->data);
    }
    else if (root->left)
    {
        printBoundaryRight(root->left);
        printf("%d-> ", root->data);
    }
}
void printBoundary(struct bstnode *root)
{
    if (root == NULL)
        return;
    printf("%d-> ", root->data);
    printBoundaryLeft(root->left);
    printLeaves(root->left);
    printLeaves(root->right);
    printBoundaryRight(root->right);
}
void main()
{
    int ch, key, k;
    while (1)
    {
        printf("\nSelect the Operation : \n");
        printf("1. Insertion\n2. Display\n3. Boundry Traversal\n4. Exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            if (root == NULL)
            {
                printf("Enter the Root Value : \n");
                scanf("%d", &key);
                root = insert(root, key);
            }
            else
            {
                printf("Enter the Node Value you want to Insert : \n");
                scanf("%d", &key);
                insert(root, key);
            }
            break;

        case 2:
            display(root);
            break;

        case 3:
            printf("The Boundry Traversal is :\n");
            printBoundary(root);
            break;

        case 4:
            exit(0);
        }
    }
}
