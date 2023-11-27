#include <stdio.h>
#include <stdlib.h>

struct btnode
{
    int data;
    struct btnode *left;
    struct btnode *right;
} *root = NULL;
struct btnode *new (int item)
{
    struct btnode *temp = (struct btnode *)malloc(sizeof(struct btnode));
    temp->data = item;
    temp->left = temp->right = NULL;
    return temp;
}
struct btnode *insert(struct btnode *root, int x)
{
    if (root == NULL)
        return new (x);
    else if (x > root->data)
        root->right = insert(root->right, x);
    else
        root->left = insert(root->left, x);
    return root;
}
void display(struct btnode *root)
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
void fixPrevPtr(struct btnode *root)
{
    static struct node *pre = NULL;

    if (root != NULL)
    {
        fixPrevPtr(root->left);
        root->left = pre;
        pre = root;
        fixPrevPtr(root->right);
    }
}
struct node *fixNextPtr(struct btnode *root)
{
    struct node *prev = NULL;
    while (root && root->right != NULL)
        root = root->right;
    while (root && root->left != NULL)
    {
        prev = root;
        root = root->left;
        root->right = prev;
    }
    return (root);
}
struct btnode *convertDLL(struct btnode *root)
{
    fixPrevPtr(root);
    return fixNextPtr(root);
}
void printDLL(struct btnode *root)
{
    while (root != NULL)
    {
        printf("%d <=> ", root->data);
        root = root->right;
    }
}
void main()
{
    int ch, key;
    while (1)
    {
        printf("\nSelect Operation : \n1. Insertion\n2. Display\n3. Convert to Doubly Linked List\n4. EXIT\n");
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
            convertDLL(root);
            printDLL(root);
            break;

        case 4:
            exit(0);
        }
    }
}