#include <stdio.h>
#include <stdlib.h>


#define SIZE 50

int pop();
void push(int);

char pfix[SIZE];
int stack[SIZE], top = -1;

int main()
{
	int i, a, b, res, pEval;
	char ch;

	printf("Enter a postfix expression: \n");
	gets(pfix);

	for(i=0; pfix[i] != '\0'; i++)
	{
		ch = pfix[i];

		if(isdigit(ch))
		{
			push(ch-'0');
		}
		else if(ch == '+' || ch == '-' || ch == '*' || ch == '/')
		{
			b = pop();
			a = pop();
			
			switch(ch)
			{
				case '+': res = a+b;
					  break;
				case '-': res = a-b;
					  break;
				case '*': res = a*b;
					  break;
				case '/': res = a/b;
					  break;
			}
			
			push(res);
		}		
	
	}

	pEval = pop();
	
	printf("The postfix evaluation is: %d\n",pEval);
	
	return 0;
}

void push(int n)
{
	if (top < SIZE -1)
	{
		stack[++top] = n;
	}
	else
	{
		printf("Stack is full!\n");
		exit(-1);
	}
}
int pop()
{	
	int n;
	if (top > -1)
	{
		n = stack[top];
		stack[top--] = -1;
		return n;
	}
	else
	{
		printf("Stack is empty!\n");
		exit(-1);
	}
}