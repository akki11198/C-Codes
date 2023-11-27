#include <stdio.h>
#include <stdlib.h>
 
struct btnode
{
    int data;
    struct btnode *left;
    struct btnode *right;
    struct btnode *nxtRight
}*root = NULL;

struct btnode* new()
{
    int key;
    struct btnode *temp =  (struct btnode *)malloc(sizeof(struct btnode));
    printf("Enter the Value You want to insert (-1 for no data) : ");
    scanf("%d",&key);
    if(key == -1)
    return NULL;

    temp->data = key;
    printf("Enter the Left Child of %d : \n",key);
    temp->left = new();

    printf("Enter the Right Child of %d : \n",key);
    temp->right = new();

    return temp;
}
void display(struct btnode* root)
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

void nxtRght(struct btnode *root)
{
    if (!root) 
        return; 
  
    if (root->left) 
        root->left->nxtRight = root->right; 

    if (root->right)
    {
        if (root->nxtRight)
        {
           root->right->nxtRight = root->nxtRight->left ;
        }
        else
        root->right->nxtRight = NULL;

    } 
    nxtRght(root->left); 
    nxtRght(root->right); 
}

void nxt(struct btnode *root)
{
    root->nxtRight = NULL;
    nxtRght(root);
}

void main()
{
    int ch,c;
    struct btnode* root=NULL;
    while(1)
    {
    printf("Select the Operation \n");
    printf("1. Insertion\n2. Display\n3.Nodes on Same level : \n");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:
        root = new();
        break;

        case 2:
        display(root);
        printf("\n");
        break;

        case 3:
        nxt(root);
        printf("Following are the Nodes at same level of the tree : (-1 if no next Node)\n");
        printf("Next Right of %d is : %d\n",root->data,root->nxtRight ? root->nxtRight->data : -1); 
        printf("Next Right of %d is %d \n", root->left->data,root->left->nxtRight ? root->left->nxtRight->data : -1); 
        printf("Next Right of %d is %d \n", root->right->data,root->right->nxtRight ? root->right->nxtRight->data : -1); 
        printf("Next Right of %d is %d \n", root->left->left->data, root->left->left->nxtRight ? root->left->left->nxtRight->data : -1);
        printf("Next Right of %d is %d \n", root->left->right->data, root->left->right->nxtRight ? root->left->right->nxtRight->data : -1);
        printf("Next Right of %d is %d \n", root->right->left->data, root->right->left->nxtRight ? root->right->left->nxtRight->data : -1);
        printf("Next Right of %d is %d \n", root->right->right->data, root->right->right->nxtRight ? root->right->right->nxtRight->data : -1);
        break;
    }
    }
}

