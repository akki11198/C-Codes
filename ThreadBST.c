#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
 
struct node
{
        int info;
        struct node *left;
        struct node *right;
        bool Lthread;
        bool Rthread;
        
}*root = NULL; 
struct node *succrssor(struct node *temp)
{
        if(temp->Rthread==true)
                return temp->right;
        else
        {
                temp=temp->right;
                while(temp->Lthread==false)
                        temp=temp->left;
                return temp;
        }
}
struct node *predecesor(struct node *temp)
{
        if(temp->Lthread==true)
                return temp->left;
        else
        {
                temp=temp->left;
                while(temp->Rthread==false)
                        temp=temp->right;
                return temp;
        }
}  
struct node *case_a(struct node *root, struct node *par,struct node *temp )
{
        if(par==NULL) 
                root=NULL;
        else if(temp==par->left)
        {
                par->Lthread=true;
                par->left=temp->left;
        }
        else
        {
                par->Rthread=true;
                par->right=temp->right;
        }
        free(temp);
        return root;
} 
struct node *case_b(struct node *root,struct node *par,struct node *temp)
{
        struct node *child,*s,*p;

        if(temp->Lthread==false)
                child=temp->left;
        else               
                child=temp->right;
 
 
        if(par==NULL ) 
                root=child;
        else if( temp==par->left)
                par->left=child;
        else                    
                par->right=child;
 
        s=succrssor(temp);
        p=predecesor(temp);
 
        if(temp->Lthread==false) 
                        p->right=s;
        else
        {
                if(temp->Rthread==false) 
                        s->left=p;
        }
 
        free(temp);
        return root;
}
struct node *case_c(struct node *root, struct node *par,struct node *temp)
{
        struct node *succ,*parsucc;
        parsucc = temp;
        succ = temp->right;
        while(succ->left!=NULL)
        {
                parsucc = succ;
                succ = succ->left;
        }
 temp->info = succ->info;
 
        if(succ->Lthread==true && succ->Rthread==true)
                root = case_a(root, parsucc,succ);
        else
                root = case_b(root, parsucc,succ);
        return root;
} 
void inorder( struct node *root)
{
        struct node *temp;
        if(root == NULL )
        {
                printf("Tree is empty");
                return;
        } 
        temp=root;
        while(temp->Lthread==false)
                temp=temp->left;
 
        while( temp!=NULL )
        {
                printf("%d ->",temp->info);
                temp=succrssor(temp);
        }
} 
void preorder(struct node *root )
{
        struct node *temp;
        if(root==NULL)
        {
                printf("Tree is empty");
                return;
        }
        temp=root; 
        while(temp!=NULL)
        {
                printf("%d ->",temp->info);
                if(temp->Lthread==false)
                        temp=temp->left;
                else if(temp->Rthread==false)
                        temp=temp->right;
                else
                {
                    while(temp!=NULL && temp->Rthread==true)
                            temp=temp->right;
                    if(temp!=NULL)
                            temp=temp->right;
                }
        }
}
struct node *insert(struct node *root, int ikey)
{
        struct node *tmp,*par,*temp; 
        int found=0; 
        temp = root;
        par = NULL; 
        while( temp!=NULL )
        {
                if( ikey == temp->info)
                {
                        found =1;
                        break;
                }
                par = temp;
                if(ikey < temp->info)
                {
                        if(temp->Lthread == false)
                                temp = temp->left;
                        else
                                break;
                }
                else
                {
                        if(temp->Rthread == false)
                                temp = temp->right;
                        else
                                break;
                }
        } 
        if(found)
                printf("\nDuplicate key");
        else
        { 
                tmp=(struct node *)malloc(sizeof(struct node));
                tmp->info=ikey;
                tmp->Lthread = true;
                tmp->Rthread = true;
                if(par==NULL)
                {
                        root=tmp;
                        tmp->left=NULL;
                        tmp->right=NULL;
                }
                else if( ikey < par->info )
                {
                        tmp->left=par->left;
                        tmp->right=par;
                        par->Lthread=false;
                        par->left=tmp;
                }
                else
                {
                        tmp->left=par;
                        tmp->right=par->right;
                        par->Rthread=false;
                        par->right=tmp;
                }
        }
        return root;
}
void main( )
{
        int ch,num;
        while(1)
        {
                printf("\n");
                printf("1.Insert\n");
                printf("2.Inorder Traversal\n");
                printf("3.Preorder Traversal\n");
                printf("4.Quit\n");
                printf("\nEnter your choice : \n");
                scanf("%d",&ch);
 
                switch(ch)
                {
                 case 1:
                        printf("\nEnter the number to be inserted : ");
                        scanf("%d",&num);
                        root = insert(root,num);
                        break;
  
                 case 2:
                        printf("The Inorder Traversal is :- \n");
                        inorder(root);
                        break;
 
                 case 3:
                        printf("The Preorder Traversal is :- \n");
                        preorder(root);
                        break; 
                 case 4:
                         exit(1); 
                 default:
                        printf("\nWrong ch\n");
                }
        }
}