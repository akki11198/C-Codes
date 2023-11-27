#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* nxt;
};
struct Node* head;

void insert()
{
    int key;
    printf("Enter the Element to insert : ");
    scanf("%d",&key);
    struct Node* new = (struct Node *)malloc(sizeof(struct Node));
    struct Node* temp = (struct Node *)malloc(sizeof(struct Node));
    new->data = key;
    if(head == NULL)  
    {  
        new->nxt = NULL;   
        head = new;  
    }  
    else  
    {  
        temp = head;  
        while(temp->nxt!=NULL)  
        {  
            temp = temp->nxt;  
        }
        temp->nxt = new;    
        new->nxt = NULL;  
    }  
   printf("Node inserted.\n");          
} 
void display()
{
    struct Node* temp = head;
    if(temp == NULL)
    printf("List is Empty ");

    while(temp!= NULL)
    {
    printf("%d -> ",temp->data);
    temp = temp->nxt;
    }
    printf("\n");
}
void swap(struct Node *head, int k)
{
	struct Node *x, *y, *temp_x = NULL, *temp_y = head;

	struct Node *temp = head;
	for (int i = 1; i < k && temp; i++) {
		temp_x = temp;
		temp = temp->nxt;
	}
	x = temp;
	if (temp == NULL)
		return;

	struct Node *ptr = head;
	while (temp->nxt) {
		temp_y = ptr;
		ptr = ptr->nxt;
		temp = temp->nxt;
	}
	y = ptr;
	if (x->nxt == y)
	{
		x->nxt = y->nxt;
		y->nxt = x;
		temp_x->nxt = y;
	}
	else if (y->nxt == x)
	{
		y->nxt = x->nxt;
		x->nxt = y;
		temp_y->nxt = x;
	}
	else if (x == head)
	{
		head = y;
		y->nxt = x->nxt;
		temp_y->nxt = x;
		x->nxt = NULL;
	}
	else if (y == head)
	{
		head = x;
		x->nxt = y->nxt;
		temp_x->nxt = y;
		y->nxt = NULL;
	}

	else {
		ptr = y->nxt;
		y->nxt = x->nxt;
		x->nxt = ptr;

		temp_x->nxt = y;
		temp_y->nxt = x;
	}
}

void main()
{
    int ch,k;
    while(1)
    {
        printf("Select the Operation : \n1. Insertion\n2. Traversal\n3. Swap Nth node from Front and End\n4. EXIT\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            insert();
            break;

            case 2:
            display();
            break;

            case 3:
            printf("Enter the value of K : \n");
            scanf("%d",&k);
            swap(head,k);
            break;

            case 4:
            exit(0);

        }

    }
}