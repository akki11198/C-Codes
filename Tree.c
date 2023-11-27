#include <stdio.h>
#include <stdlib.h>
struct btnode
{
    int data;
    struct btnode *left;
    struct btnode *right;
} *root = NULL;
struct btnode *new ()
{
    int key;
    struct btnode *temp = (struct btnode *)malloc(sizeof(struct btnode));
    printf("Enter The Key Value(-1 for NULL)  :");
    scanf("%d", &key);
    if (key == -1)
        return NULL;
    temp->data = key;
    printf("Enter the Value of Left Child of %d : \n", key);
    temp->left = new ();
    printf("Enter the Value of Right Child of %d : \n", key);
    temp->right = new ();
    return temp;
}
void display(struct btnode *root)
{
    if (root == NULL)
    {
        printf("Tree is Empty\n");
        return;
    }
    if (root->left != NULL)
        display(root->left);
    printf("%d -> ", root->data);
    if (root->right != NULL)
        display(root->right);
}

void main()
{
    int ch;
    while (1)
    {
        printf("Select Operation : \n1. Insertion\n2. Display\n3. EXIT\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            new ();
            break;

        case 2:
            display(root);
            break;

        case 3:
            exit(0);
        }
    }
}