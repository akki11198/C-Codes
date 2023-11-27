#include<stdio.h>  
#include<stdlib.h>  
struct node  
{  
    int key;
    struct node *prev;  
    struct node *next;  
      
}; 
struct node *data;  
void DelBig()
{
struct node *temp;  
    if(data == NULL)  
    {  
        printf("\n Empty");  
    }   
    else  
    {          temp = data;   
        while(temp -> next != data)  
        {  
            temp = temp -> next;  
        }  
        temp -> next = data -> next;  
        data -> next -> prev = temp;  
        free(data);  
        data = temp -> next;  
    }  
}
void DelEnd()
{
struct node *ptr;  
    if(data == NULL)  
    {  
        printf("\n Empty");  
    }   
    else   
    {  
        ptr = data;   
        if(ptr->next != data)  
        {  
            ptr = ptr -> next;   
        }  
        ptr -> prev -> next = data;  
        data -> prev = ptr -> prev;    
        free(ptr);  
        printf("\n node deleted\n");  
    }  
}
void insert()
{
struct node *ptr,*temp;   
   int item;  
   ptr = (struct node *)malloc(sizeof(struct node));  
   if(ptr == NULL)  
   {  
       printf("\nOVERFLOW");  
   }  
   else  
   {  
    printf("\nEnter Item value");  
    scanf("%d",&item);  
    ptr->key=item;  
   if(data==NULL)  
   {  
      data = ptr;  
      ptr -> next = data;   
      ptr -> prev = data;   
   }  
   else   
   {  
       temp = data;   
    while(temp -> next != data)  
    {  
        temp = temp -> next;   
    }  
    temp -> next = ptr;  
    ptr -> prev = temp;  
    data -> prev = ptr;  
    ptr -> next = data;  
    data = ptr;  
   }  
   printf("\nNode inserted\n");  
}
}
void Display()  
{  
    struct node *ptr;  
    ptr=data;  
    if(data == NULL)  
    {  
        printf("\nnothing to print");  
    }     
    else  
    {  
        printf("\n printing values ... \n");  
          
        while(ptr -> next != data)  
        {  
          
            printf("%d\n", ptr -> key);  
            ptr = ptr -> next;  
        }  
        printf("%d\n", ptr -> key);  
    }  
              
}  
void main ()
{
 int ch;
 for(;;)
 {
 printf("\n1.Insert\n2.Delete from Beginning\n3.Delete from last\n4.Display\n5.Exit\n");  
 printf("\nEnter your choice?\n");  
 scanf("%d",&ch);
 switch(ch)
 {
     case 1:
     insert();
     break;
     case 2:
     DelBig();
     break;
     case 3:
     DelEnd();
     break;
     case 4:
     Display();
     break;
     case 5:
     exit(0);
 }
 }
}  
