#include <stdio.h>
#include <stdlib.h>
  
void push(int);
void pop(int);
void create();
void check(int);
void display();
 
int que[25];
int front, rear;
 
void main()
{
    int n, ch;
 
    printf("\n1 - Insert an element");
    printf("\n2 - Delete an element");
    printf("\n3 - Display elements");
    printf("\n4 - Exit");
 
    create();
 
    while (1)
    {
        printf("\nEnter your choice : ");    
        scanf("%d", &ch);
 
        switch (ch)
        {
        case 1: 
            printf("\nEnter value to be inserted : ");
            scanf("%d",&n);
            push(n);
            break;
        case 2:
            printf("\nEnter value to delete : ");
            scanf("%d",&n);
            pop(n);
            break;
        case 3: 
            display();
            break;
        case 4: 
            exit(0);
        default: 
            printf("\nChoice is incorrect, Enter a correct choice");
        }
    }
}
void create()
{
    front = rear = -1;
}
void push(int data)
{
    if (rear >= 25 - 1)
    {
        printf("\nQueue overflow no more elements can be inserted");
        return;
    }
    if ((front == -1) && (rear == -1))
    {
        front++;
        rear++;
        que[rear] = data;
        return;
    }    
    else
        check(data);
    rear++;
}
void check(int data)
{
    int i,j;
 
    for (i = 0; i <= rear; i++)
    {
        if (data >= que[i])
        {
            for (j = rear + 1; j > i; j--)
            {
                que[j] = que[j - 1];
            }
            que[i] = data;
            return;
        }
    }
    que[i] = data;
}
void pop(int data)
{
    int i;
 
    if ((front==-1) && (rear==-1))
    {
        printf("\nQueue is empty no elements to delete");
        return;
    }
 
    for (i = 0; i <= rear; i++)
    {
        if (data == que[i])
        {
            for (; i < rear; i++)
            {
                que[i] = que[i + 1];
            }
 
        que[i] = -99;
        rear--;
 
        if (rear == -1) 
            front = -1;
        return;
        }
    }
    printf("\n%d not found in queue to delete", data);
}
void display()
{
    if ((front == -1) && (rear == -1))
    {
        printf("\nQueue is empty");
        return;
    }
 
    for (; front <= rear; front++)
    {
        printf(" %d ", que[front]);
    }
 
    front = 0;
}