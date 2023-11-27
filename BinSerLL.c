struct Node* midNode(struct Node* start, struct Node* last) 
{ 
    if (start == NULL) 
        return NULL; 
  
    struct Node* slow = start; 
    struct Node* fast = start -> nxt; 
  
    while (fast != last) 
    { 
        fast = fast -> nxt; 
        if (fast != last) 
        { 
            slow = slow -> nxt; 
            fast = fast -> nxt; 
        } 
    } 
  
    return slow; 
}   
struct Node* Search() 
{
    int val; 
    struct Node* start = (struct Node *)malloc(sizeof(struct Node)); 
    struct Node* last = (struct Node *)malloc(sizeof(struct Node)); 
    struct Node* mid = (struct Node *)malloc(sizeof(struct Node)); 
    printf("Enter the value you want to search : \n");
    scanf("%d",&val);

    start = head;
    last = NULL;
    while(last->nxt != NULL)
    last = last->nxt;
  
    do
    {          
        mid = midNode(start, last); 
  
        if (mid == NULL) 
            printf("List Empty\n");
            return NULL;
  
        if (mid -> data == val) 
            printf("Value present in the list\n"); 
  
        else if (mid -> data < val) 
            start = mid -> nxt; 
  
        else
            last = mid; 
  
    } 
    while (last == NULL || last != start); 
    printf("Value Not in the List\n"); 
}