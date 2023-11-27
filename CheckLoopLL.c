#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};
void insert(struct Node **head, int item)
{

    struct Node *new = (struct Node *)malloc(sizeof(struct Node));

    new->data = item;

    new->next = *head;

    *head = new;
}
void detectLoop(struct Node *head)
{
    int loop = 0;
    struct Node *slow = head, *fast = head;

    while (slow && fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            loop = 1;
        }
    }
    if (loop == 1)
    {
        printf("Loop exist in linked list\n");

        slow = head;

        while (fast != slow)
        {
            fast = fast->next;
            slow = slow->next;
        }

        printf("\nstart node of loop is: %d", fast->data);
    }
    else
        printf("Loop does not exist in linked list\n");
}
void main()
{
    int item, n, i;

    struct Node *head = NULL;
    printf("Enter the no of elements to be inserted: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &item);
        insert(&head, item);
    }
    //head->next->next->next->next = head;
    detectLoop(head);
}