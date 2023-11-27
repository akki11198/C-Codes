#include <stdio.h>
#include <stdlib.h>

struct bstnode
{
    int data;
    struct bstnode *left;
    struct bstnode *right;
} *root = NULL;

struct bstnode *new ()
{
    int key;
    struct bstnode *temp = (struct bstnode *)malloc(sizeof(struct bstnode));
    printf("Enter the Value You want to insert (-1 for no data) : ");
    scanf("%d", &key);
    if (key == -1)
        return NULL;

    temp->data = key;
    printf("Enter the Left Child of %d : \n", key);
    temp->left = new ();

    printf("Enter the Right Child of %d : \n", key);
    temp->right = new ();

    return temp;
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
int CheckBST(struct bstnode *root)
{
    if (root == NULL)
    {
        return -1;
    }
    if (root->left != NULL)
    {
        if (root->left->data < root->data)
            CheckBST(root->left);
        else
        {
            return 0;
        }
    }
    if (root->right != NULL)
    {
        if (root->right->data > root->data)
            CheckBST(root->right);
        else
        {
            return 0;
        }
    }
    return 1;
}
void main()
{
    int ch, c;
    struct bstnode *root = NULL;
    while (1)
    {
        printf("Select the Operation \n");
        printf("1. Insertion\n2. Display\n3. Check BST\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            root = new ();
            break;

        case 2:
            display(root);
            printf("\n");
            break;

        case 3:
            c = CheckBST(root);
            if (c == 0)
            {
                printf("The Tree is Not a BST!!\n");
            }
            else if (c == 1)
            {
                printf("The Tree is a BST!!\n");
            }
            else if (c == -1)
            {
                printf("The TREE is EMPTY!!\n");
            }
            break;
        }
    }
}