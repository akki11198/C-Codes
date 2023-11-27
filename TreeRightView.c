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
void RView(struct bstnode *root, int level, int *max_level)
{
    if (root == NULL)
        return;
    if (*max_level < level)
    {
        printf("%d-> ", root->data);
        *max_level = level;
    }
    RView(root->right, level + 1, max_level);
    RView(root->left, level + 1, max_level);
}
void RSView(struct bstnode *root)
{
    int max_level = 0;
    RView(root, 1, &max_level);
}
void main()
{
    int ch, key;
    while (1)
    {
        printf("\nSelect Operation : \n1. Insertion\n2. Display\n3. Display RIGHT Side View\n4. EXIT\n");
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
                printf("Enter the bstnode Value you want to Insert : \n");
                scanf("%d", &key);
                insert(root, key);
            }
            break;

        case 2:
            display(root);
            break;

        case 3:
            printf("The Right Side View Is : \n");
            RSView(root);
            break;

        case 4:
            exit(0);
        }
    }
}