#include <stdio.h>
#include <stdlib.h>
 
#define MAX 50
 
void push();
void pop();
void MinEl();
void display();
int array[MAX];
int rear = - 1;
int front = - 1;\
int min =0;
void main()
{
    int choice;
    while (1)
    {
        printf("1.Push \n");
        printf("2.Pop \n");
        printf("3.Display The Queue \n");
        printf("4.Display Min element\n");
        printf("5.Quit \n");
        printf("Enter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
            push();
            break;
            case 2:
            pop();
            break;
            case 3:
            display();
            break;
            case 4:
            MinEl();
            break;
            case 5:
            exit(0);
            
            printf("Wrong choice \n");
        }
    }
}
void push()
{
    int x;
    if (rear == MAX - 1)
    printf("Queue Overflow \n");
    else
    {
        if (front == - 1)
        
        front = 0;
        printf("Inset the element in queue : ");
        scanf("%d", &x);
        rear = rear + 1;
        array[rear] = x;
    }
}
 
void pop()
{
    if (front == - 1 || front > rear)
    {
        printf("Queue Underflow \n");
        return ;
    }
    else
    {
        printf("Element deleted from queue is : %d\n", array[front]);
        front = front + 1;
    }
}
 
void MinEl()
{
   int i;
    
        printf("Min Element of Queue is : \n");
        min = array[1];
        for (i = front+1; i <= rear; i++)
        {
            if(array[i]<min)
            min = array[i];            
        }
        printf("%d \n", min);
        
} 
void display()
{
    int i;
    if (front == - 1)
        printf("Queue is empty \n");
    else
    {
        printf("Queue is : \n");
        for (i = front; i <= rear; i++)
            printf("%d ", array[i]);
        printf("\n");
    }
}