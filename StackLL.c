#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *link;
};
struct Node *top;
void push(int data)
{

    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));

    if (!temp)
    {
        printf("Stack Overflow\n");
        exit(0);
    }
    temp->data = data;
    temp->link = top;
    top = temp;
}
int pop()
{
    int k;
    struct Node *temp;

    if (top == NULL)
    {
        printf("Stack Empty\n");
        exit(0);
    }
    else
    {
        temp = top;
        top = top->link;
        temp->link = NULL;
        k = temp->data;
        free(temp);
        return k;
    }
}
void display()
{
    struct Node *temp;
    if (top == NULL)
    {
        printf("Stack Empty\n");
        exit(0);
    }
    else
    {
        temp = top;
        while (temp != NULL)
        {
            printf(" %d ,", temp->data);
            temp = temp->link;
        }
        printf("\n");
    }
}
int main()
{
    int x, c;
    for (;;)
    {
        printf("1. Push operation.\n");
        printf("2. Pop operation.\n");
        printf("3. Traverse stack.\n");
        printf("4. Exit.\n");
        printf("Enter your choice : ");
        scanf("%d", &c);

        switch (c)
        {
        case 1:
            printf("Enter the Element You want to insert: ");
            scanf("%d", &x);
            push(x);
            break;

        case 2:
            x = pop();
            printf("Element removed from the stack is %d.\n", x);
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