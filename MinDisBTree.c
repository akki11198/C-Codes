#include<stdio.h> 
#include<stdlib.h> 
struct node  
{ 
    int data; 
    struct node *left; 
    struct node *right; 
    struct node *root;
}; 
struct node* new(int key)
{
    struct node* node = (struct node*)malloc(sizeof(struct node)); 
    node->data = key; 
    node->left = NULL; 
    node->right = NULL; 
    return(node);
}
struct node* LCA(struct node * root, int n1,int n2)
{
    if (root == NULL)
       return root;
    if (root->data == n1 || root->data == n2)
       return root;
 
    struct node* left = LCA(root->left, n1, n2);
    struct node* right = LCA(root->right, n1, n2);
 
    if (left != NULL && right != NULL)
         return root;
    if (left == NULL && right == NULL)
           return NULL;
    if (left != NULL)
        return LCA(root->left, n1, n2);
 
    return LCA(root->right, n1, n2);
}
int Level(struct node *root, int k, int level)
{
    if(root == NULL) return -1;
    if(root->data == k) return level;
 
    int left = Level(root->left, k, level+1);
   if (left == -1)
       return Level(root->right, k, level+1);
    return left;
}
 
int Dist(struct node* root, int x, int y)
{
    struct node* lca = LCA(root, x , y);
 
    int l1 = Level(lca, x, 0);
    int l2 = Level(lca, y, 0);
 
    return l1 + l2;
}

void main()
{
    int val,i,j,dist;
    printf("Enter the value of Root Node(R) : ");
    scanf("%d,",&val);
    struct node *root = new(val);
    printf("Enter the value of left child of root(L1) : ");
    scanf("%d,",&val);
    root -> left = new(val);
    printf("Enter the value of right child of root(R1) : ");
    scanf("%d,",&val);
    root -> right = new(val);
    printf("Enter the value of left child of L1(LL1)  : ");
    scanf("%d,",&val);
    root -> left -> left = new(val);
    printf("Enter the value of right child of L1(LR1)  : ");
    scanf("%d,",&val);
    root -> left ->right = new(val);
    printf("Enter the value of left child of R1(RL1)  : ");
    scanf("%d,",&val);
    root -> right -> left = new(val);
    printf("Enter the value of Right child of R1(RR1)  : ");
    scanf("%d,",&val);
    root -> right -> right = new(val);
    printf("Enter the value of Left child of LL1(LLL1)  : ");
    scanf("%d,",&val);
    root -> left -> left -> left = new(val);
    printf("Enter the value of Right child of LL1(LLR1)  : ");
    scanf("%d,",&val);
    root -> left -> left -> right = new(val);
    printf("Enter the value of left child of LR1(LRL1)  : ");
    scanf("%d,",&val);
    root -> left -> right -> left = new(val);
    printf("Enter the value of Right child of LR1(LRR1)  : ");
    scanf("%d,",&val);
    root -> left -> right -> right = new(val);
    printf("Enter the value of left child of RL1(RLL1)  : ");
    scanf("%d,",&val);
    root -> right -> left -> left = new(val);
    printf("Enter the value of Right child of RL1(RLR1)  : ");
    scanf("%d,",&val);
    root -> right -> left -> right = new(val);
    printf("Enter the value of left child of RR1(RRL1)  : ");
    scanf("%d,",&val);
    root -> right -> right -> left = new(val);
    printf("Enter the value of Right child of RR1(RRR1)  : ");
    scanf("%d,",&val);
    root -> right -> right -> right = new(val);
    

    printf("Enter the Nodes You want to find distence between :\n ");
    scanf("%d %d",&i,&j);
    dist = Dist(root,i,j);
    printf("The Distence Between %d and %d Is : %d ",i,j,dist);


}
