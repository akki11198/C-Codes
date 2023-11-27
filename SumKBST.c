#include <stdio.h>
#include <stdlib.h>
int arr[20],count=0;
 
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
void insertARR(int key)
{
    arr[count] = key;
    count++;  
}
void display(struct bstnode* root)
{
    if (root->left != NULL)    
        display(root->left);
    printf("%d -> ", root->data);
    if (root->right != NULL)    
        display(root->right);
}
void BSTArray(struct bstnode* root)
{
    if (root->left != NULL)    
        BSTArray(root->left);
    insertARR(root->data);
    if (root->right != NULL)    
        BSTArray(root->right);

}
void main()
{
    int i,j,n,key,sum,temp[20],t1=0,t2=1;
    printf("Enter the No. of nodes in the tree : \n");
    scanf("%d",&n);
    printf("Enter the Elemnets : \n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&key);
        if(root == NULL)
        root = insert(root,key);
        else
        insert(root,key);
    }
    printf("The Nodes in tree are : ");
    display(root);
    printf("\n");

    printf("Enter the Required Sum : \n");
    scanf("%d",&sum);
    BSTArray(root);
    count = 0;
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(sum == (arr[i] + arr[j]))
            {
                count++;
                temp[t1] = arr[i];
                temp[t2] = arr[j];
                t1 = t1+2;
                t2 = t2+2;
            }
        }
    }
    if(count !=0)
    {
        i=0;
        printf("Sum is found!!\nThere are %d set of Elements:\n",count);
        while(i<(count*2))
        {
            printf("%d and %d\n",temp[i],temp[i+1]);
            i=i+2;
        }
    }
    else
    printf("No Pair of Elements with Given SUM\n");

}