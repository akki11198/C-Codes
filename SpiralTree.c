#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct btnode
{
    int data;
    struct btnode *left;
    struct btnode *right;
    struct btnode *nxtRight
} *root = NULL;

struct btnode *new ()
{
    int key;
    struct btnode *temp = (struct btnode *)malloc(sizeof(struct btnode));
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

void displayIn(struct btnode *root)
{
    if (root == NULL)
    {
        printf("No elements in the tree to display\n");
        return;
    }
    if (root->left != NULL)
        displayIn(root->left);
    printf("%d -> ", root->data);
    if (root->right != NULL)
        displayIn(root->right);
}
void printLevel(struct btnode *root, int level, int l)
{
    if (root == NULL)
        return;
    if (level == 1)
        printf("%d -> ", root->data);
    else if (level > 1)
    {
        if (l)
        {
            printLevel(root->left, level - 1, l);
            printLevel(root->right, level - 1, l);
        }
        else
        {
            printLevel(root->right, level - 1, l);
            printLevel(root->left, level - 1, l);
        }
    }
}

int height(struct btnode *node)
{
    if (node == NULL)
        return 0;
    else
    {
        int lheight = height(node->left);
        int rheight = height(node->right);

        if (lheight > rheight)
            return (lheight + 1);
        else
            return (rheight + 1);
    }
}
void displaySpiral(struct btnode *root)
{
    int h = height(root);
    int i;

    bool l = false;
    for (i = 1; i <= h; i++)
    {
        printLevel(root, i, l);

        l = !l;
    }
}
void main()
{
    int ch, c;
    struct btnode *root = NULL;
    while (1)
    {
        printf("Select the Operation \n");
        printf("1. Insertion\n2. Display InOrder\n3. Display Spiral Traversal\n4. EXIT\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            root = new ();
            break;

        case 2:
            displayIn(root);
            printf("\n");
            break;

        case 3:
            displaySpiral(root);
            printf("\n");
            break;

        case 4:
            exit(0);
        }
    }
}