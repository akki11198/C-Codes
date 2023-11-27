#include<stdio.h>
#include<stdlib.h>

struct Node
{
   int data;
   struct Node *next;
}*front = NULL,*rear = NULL;

void push(int item)
{
   struct Node *newNode;
   newNode = (struct Node*)malloc(sizeof(struct Node));
   if (newNode == NULL)
   {
   printf("Overflow\n");
   exit(0);
   }
   newNode->data = item;
   newNode -> next = NULL;
   if(front == NULL)
      front = rear = newNode;
   else{
      rear -> next = newNode;
      rear = newNode;
   }
}
void pop()
{
   if(front == NULL)
      printf("Queue is Empty\n");
   else{
      struct Node *temp = front;
      front = front -> next;
      printf("Deleted element: %d\n", temp->data);
      free(temp);
   }
}
void display()
{
   if(front == NULL)
      printf("Queue is Empty\n");
   else{
      struct Node *temp = front;
      while(temp->next != NULL){
	 printf("%d--->",temp->data);
	 temp = temp -> next;
      }
      printf("%d--->NULL\n",temp->data);
   }
}
int main()
{
  int x , c;

  for (;;)
  {
    printf("1. Push operation.\n");
    printf("2. Pop operation.\n");
    printf("3. Traverse Queue.\n");
    printf("4. Exit.\n");
    printf("Enter your choice : ");
    scanf("%d",&c);

    switch (c)
    {
      case 1:
        printf("Enter the Element You want to insert: ");
        scanf("%d",&x);
        push(x);    
        break;

      case 2:
          pop();
          break;

      case 3:
        printf("The elements currently in the Stack are : ");
        display();
        break;

      case 4:
        exit(0);
    }
  }
}