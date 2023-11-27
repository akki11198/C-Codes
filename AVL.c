#include <stdio.h>
#include <stdlib.h>
 
typedef struct avlNode
{
	int data;
	struct avlNode *left;
	struct avlNode *right;
	int ht;
}avlNode;

int height(avlNode *temp)
{
	int leftH,rightH;
	if(temp==NULL)
		return(0);
	
	if(temp->left==NULL)
		leftH=0;
	else
		leftH=1+temp->left->ht;
		
	if(temp->right==NULL)
		rightH=0;
	else
		rightH=1+temp->right->ht;
	
	if(leftH>rightH)
		return(leftH);
	
	return(rightH);
}

int BF(avlNode *temp)
{
	int leftH,rightH;
	if(temp==NULL)
		return(0);
 
	if(temp->left==NULL)
		leftH=0;
	else
		leftH=1+temp->left->ht;
 
	if(temp->right==NULL)
		rightH=0;
	else
		rightH=1+temp->right->ht;
 
	return(leftH-rightH);
}
avlNode * RRight(avlNode *key)
{
	avlNode *temp1;
	temp1=key->left;
	key->left=temp1->right;
	temp1->right=key;
	key->ht=height(key);
	temp1->ht=height(temp1);
	return(temp1);
} 
avlNode * RLeft(avlNode *key)
{
	avlNode *temp1;
	temp1=key->right;
	key->right=temp1->left;
	temp1->left=key;
	key->ht=height(key);
	temp1->ht=height(temp1);
	
	return(temp1);
} 
avlNode * RR(avlNode *temp)
{
	temp=RLeft(temp);
	return(temp);
} 
avlNode * LL(avlNode *temp)
{
	temp=RRight(temp);
	return(temp);
} 
avlNode * LR(avlNode *temp)
{
	temp->left=RLeft(temp->left);
	temp=RRight(temp);
	
	return(temp);
} 
avlNode * RL(avlNode *temp)
{
	temp->right=RRight(temp->right);
	temp=RLeft(temp);
	return(temp);
}  
void preorder(avlNode *temp)
{
	if(temp!=NULL)
	{
		printf("%d -> ",temp->data);
		preorder(temp->left);
		preorder(temp->right);
	}
}   
avlNode * insert(avlNode *temp,int key)
{
	if(temp==NULL)
	{
		temp=(avlNode*)malloc(sizeof(avlNode));
		temp->data=key;
		temp->left=NULL;
		temp->right=NULL;
	}
	else
		if(key > temp->data)	
		{
			temp->right=insert(temp->right,key);
			if(BF(temp)==-2)
				if(key>temp->right->data)
					temp=RR(temp);
				else
					temp=RL(temp);
		}
		else
			if(key<temp->data)
			{
				temp->left=insert(temp->left,key);
				if(BF(temp)==2)
					if(key < temp->left->data)
						temp=LL(temp);
					else
						temp=LR(temp);
			}
		
		temp->ht=height(temp);
		
		return(temp);
} 
avlNode * delete(avlNode *temp,int key)
{
	avlNode *temp1;
	
	if(temp==NULL)
	{
		return NULL;
	}
	else
		if(key > temp->data)		
		{
			temp->right=delete(temp->right,key);
			if(BF(temp)==2)
				if(BF(temp->left)>=0)
					temp=LL(temp);
				else
					temp=LR(temp);
		}
		else
			if(key<temp->data)
			{
				temp->left=delete(temp->left,key);
				if(BF(temp)==-2)	
					if(BF(temp->right)<=0)
						temp=RR(temp);
					else
						temp=RL(temp);
			}
			else
			{
				if(temp->right!=NULL)
				{	
					temp1=temp->right;
					
					while(temp1->left!= NULL)
						temp1=temp1->left;
					
					temp->data=temp1->data;
					temp->right=delete(temp->right,temp1->data);
					
					if(BF(temp)==2)
						if(BF(temp->left)>=0)
							temp=LL(temp);
						else
							temp=LR(temp);\
				}
				else
					return(temp->left);
			}
	temp->ht=height(temp);
	return(temp);
}
   
void inorder(avlNode *temp)
{
	if(temp!=NULL)
	{
		inorder(temp->left);
		printf("%d -> ",temp->data);
		inorder(temp->right);
	}
}

void main()
{
	avlNode *root=NULL;
	int key,n,i,op;
	
	while(1)
	{
        printf("Select the operation you want to perform : \n");
		printf("1. Insertion\n2. Deletion\n3. Traversal\n4. Exit\n");
		scanf("%d",&op);
		
		switch(op)
		{				
			case 1:
            if (root == NULL)
            {
                printf("\nEnter the ROOT data : \n");
				scanf("%d",&key);
				root=insert(root,key);  
            }
            else
            {
                printf("\nEnter the NODE data : \n");
				scanf("%d",&key);
				root=insert(root,key);
            }             
            break;
					
			case 2: 
                printf("\nEnter the Node you want to delete : \n");
				scanf("%d",&key);
				root=delete(root,key);
				break;
			
			case 3: 
                printf("\nPreorder sequence:\n");
				preorder(root);
				printf("\n\nInorder sequence:\n");
				inorder(root);
				printf("\n");
				break;

            case 4:
                exit(0);

            default:
            printf("Enter a valid Choice!!\n");		
		}
	}
}
