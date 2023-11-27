#include <stdio.h>
#include <stdlib.h>
int arr[50];
void push();
int pop();
void traverse();
int top = 0;

void push(int value) 
{
  arr[top] = value;
  top++;
}

int pop() 
{
  top--;
  return arr[top];
}

void traverse() 
{
  int i;

  if (top == 0) {
    printf("The stack is empty.\n\n");
    return;
  }

  printf("There are %d elements in the stack.\n", top);

  for (i = top - 1; i >= 0; i--)
    printf("%d\n", arr[i]);
  printf("\n");
}
void main()
{
  int el, c;

  while(1)
  {

    printf("1. Push operation.\n");
    printf("2. Pop operation.\n");
    printf("3. Traverse stack.\n");
    printf("4. Exit.\n");
    printf("Enter your choice.\n");
    scanf("%d",&c);

    switch (c)
    {
      case 1:
        if (top == 50)
          printf("Error: Overflow\n\n");
        else {
          printf("Enter a value to insert.\n");
          scanf("%d", &el);
          push(el);
        }
        break;

      case 2:
        if (top == 0)
          printf("Error: Underflow.\n\n");
        else {
          el = pop();
          printf("Element removed from the stack is %d.\n", el);
        }
        break;

      case 3:
        traverse();
        break;

      case 4:
        exit(0);
    }
  }
}

