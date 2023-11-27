#include <stdio.h>
#include <stdlib.h>
int arr[10];
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
struct bstnode *kMin(struct bstnode *root, int item)
{
    if (root == NULL)
        return NULL;
    struct bstnode *lft = kMin(root->left, item);
    if (lft != NULL)
        printf("kth Smallest elemnt is : %d", root->data);
    item--;
    if (item == 0)
    {
        printf("The Kth Smallest Element is : %d", root->data);
    }
    return kMin(root->right, item);
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
void main()
{
    int ch, key, k;
    while (1)
    {
        printf("\nSelect the Operation : \n");
        printf("1. Insertion\n2. Display\n3. Kth Min Node\n4. Exit\n");
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
            printf("Enter the Value of 'K' : ");
            scanf("%d", &key);
            printf("%d", arr[key]);
            break;

        case 4:
            exit(0);
        }
    }
}