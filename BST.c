#include <stdio.h>
#include <stdlib.h>
 
struct bstnode
{
    int data;
    struct bstnode *left;
    struct bstnode *right;
}*root = NULL;
struct bstnode* new(int item) 
{ 
    struct bstnode *temp =  (struct bstnode *)malloc(sizeof(struct bstnode)); 
    temp->data = item; 
    temp->left = temp->right = NULL; 
    return temp; 
} 
struct bstnode* insert(struct bstnode *root, int x)
{
    if(root==NULL)
        return new(x);
    else if(x>root->data)
        root->right = insert(root->right, x);
    else 
        root->left = insert(root->left,x);
    return root;
}
struct bstnode* min(struct bstnode* data)
{
    struct bstnode* temp = data;
    while (temp->left != NULL)
    temp = temp->left;
    return temp;
}
int maxNode(struct bstnode* node)
{
    struct bstnode* temp = node;
    while (temp->right != NULL)
    temp = temp->right;
    return temp->data;
}
int minNode(struct bstnode* node)
{
    struct bstnode* temp = node;
    while (temp->left != NULL)
    temp = temp->left;
    return temp->data;
}
struct bstnode* delete(struct bstnode* root, int data)
{
    if (root == NULL)
        return root;
    else if (data < root->data)
        root->left = delete(root->left, data);
    else if (data > root->data)
        root->right = delete(root->right, data);
    else
    {
        if (root->left == NULL)
        {
            struct bstnode *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct bstnode *temp = root->left;
            free(root);
            return temp;
        }       
            struct bstnode* temp = min(root->right);
            root->data = temp->data;
            root->right = delete(root->right, temp->data);
        
    }      
    return root;
}
void displayASC(struct bstnode* root)
{
    if (root == NULL)
    {
        printf("No elements in the tree to display\n");
        return;
    }
    if (root->left != NULL)    
        displayASC(root->left);
    printf("%d -> ", root->data);
    if (root->right != NULL)    
        displayASC(root->right);
}
void displayDSC(struct bstnode* root)
{
    if (root == NULL)
    {
        printf("No elements in the tree to display\n");
        return;
    }
    if (root->right != NULL)    
        displayDSC(root->right);
        printf("%d -> ", root->data);
    if (root->left != NULL)    
        displayDSC(root->left);
}
struct bstnode* kMin(struct bstnode* root,int item)
{
    if (root == NULL)
    return NULL;
    struct bstnode* lft = kMin(root->left , item);
    if(lft != NULL)
    printf("kth Smallest elemnt is : %d",root->data);
    item--;
    if(item == 0)
    {
    printf("The Kth Smallest Element is : %d",root->data);
    }
    return kMin(root->right,item);
}
void kthMax(struct bstnode* temp,int key, int *x)
{  
    if(*x>=key)
    return;
    if(temp->right)
    kthMax(temp->right,key,x);  
    (*x)++;
    if(*x==key)
    {
    printf("The kth maximum element is : %d\n",temp->data);
    return;
    }
    if(temp->left)
    kthMax(temp->left,key,x);
}
void kMax(struct bstnode* temp,int key)
{
    int count=0;
    kthMax(temp,key,&count);
}
void main()
{
    int n,i,key,ch,x;
    while(1)
    {
    printf("\nSelect the Operation : \n");
    printf("1. Insertion\n2. Deletion\n3. Display in Ascending Order\n4. Display in Descending Order\n5. Display Min Element\n");
    printf("6. Display Max Element\n7. Kth Samllest Element\n8. Kth Largest Element\n9. EXIT\n");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:
        if (root == NULL)
        {
            printf("Enter the Root Value : \n");
            scanf("%d",&key);
            root = insert(root,key);
        }
        else
        {
        printf("Enter the Node Value you want to Insert : \n");
        scanf("%d",&key);
        insert(root,key);   
        }
        break;

        case 2:
        printf("Enter the Value You Want to delete : \n");
        scanf("%d",&key);
        delete(root, key);
        printf("%d is deleted \n",key);
        break;
        
        case 3:
        displayASC(root);
        break;

        case 4:
        displayDSC(root);
        break;

        case 5:
        key = minNode(root);
        printf("The Minimum Element is : %d\n",key);
        break;

        case 6:
        key = maxNode(root);
        printf("The Maximum Element is : %d\n",key);
        break;

        case 7:
        printf("Enter the Value of 'K' : ");
        scanf("%d",&key);
        kMin(root,key);
        break;

        case 8:
        printf("Enter the Value of 'K' : ");
        scanf("%d",&key);
        kMax(root,key);
        break;

        case 9:
        exit(0);

    }
    }
}


