#include <stdio.h>
#include <stdlib.h>

struct btnode 
{
    int data;
    struct btnode* left;
    struct btnode* right;
};
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
    if(root == NULL)
    printf("Tree is Empty\n");

    if (root->left != NULL)    
        display(root->left);
    printf("%d -> ", root->data);
    if (root->right != NULL)    
        display(root->right);
}
int count(struct btnode* root)
{
    int c = 1;
    if (root == NULL)
        return 0;
    
    else
    {
        c += count(root->left);
        c += count(root->right);
        return c;
    }
}
int BTtoARR(struct btnode* root,int arr[],int* ptr)
{
    int *x=0;
    if (root != NULL)
    {
    BTtoARR(root->left,arr,ptr);
    arr[*x] = root->data;
    printf("%d ",arr[*x]);
    (*x)++;
    BTtoARR(root->right,arr,ptr);
    }
    printf("Hii BTarr");

}
int sort(int* arr,int n)
{
    int i,j,temp;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            temp = arr[j];
            arr[j] = arr[j+1];
            arr[j+1] = temp;
        }
    }
    
}
int ARRtoBST(struct btnode* root,int arr[],int* ptr)
{
    int *x=0;
    if(root != NULL)
    {
    ARRtoBST(root->left,arr,ptr);
    root->data = arr[*x];
    (*x)++;
    ARRtoBST(root->right,arr,ptr);
    }

}
void BTtoBST(struct btnode* root)
{
    int *i;
    i=0;
    int arr[50],n;    
    if(root == NULL)
    {
    printf("No nodes in the tree \n");
    return NULL;
    }
    n = count(root);
    printf("%d\n",n);
    BTtoARR(root,arr,&i);
    sort(arr,n);
    i=0;
    ARRtoBST(arr,root,&i);
    printf("The BST traversal of the given tree is : \n");
    display(root);
}
void main()
{
    int ch;
    struct btnode* root=NULL;
    while(1)
    {
    printf("Select the Operation \n");
    printf("1. Insertion\n2. Display\n3. Convert to BST\n");
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
        BTtoBST(root);
        break;
    }
    }
}


