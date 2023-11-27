
#include <stdio.h>
#include <stdlib.h>

#define ORDER 3

typedef struct BTNode
{
    int data;
    int keys[ORDER - 1];
    struct BTNode *p[ORDER];
} Node;
Node *root = NULL;
typedef enum KeyType
{
    Duplicate,
    SearchFail,
    Success,
    InsertIt,
    LessKeys,
} KeyType;
int searchLoc(int key, int *KeyArray, int data)
{
    int LOC = 0;
    while (LOC < data && key > KeyArray[LOC])
        LOC++;
    return LOC;
}
KeyType ins(Node *ptr, int key, int *upKey, Node **new)
{
    Node *newPtr, *lastPtr;
    int LOC, i, data, split;
    int newKey, lastKey;
    KeyType value;
    if (ptr == NULL)
    {
        *new = NULL;
        *upKey = key;
        return InsertIt;
    }
    data = ptr->data;
    LOC = searchLoc(key, ptr->keys, data);
    if (LOC < data && key == ptr->keys[LOC])
        return Duplicate;
    value = ins(ptr->p[LOC], key, &newKey, &newPtr);
    if (value != InsertIt)
        return value;
    if (data < ORDER - 1)
    {
        LOC = searchLoc(newKey, ptr->keys, data);
        for (i = data; i > LOC; i--)
        {
            ptr->keys[i] = ptr->keys[i - 1];
            ptr->p[i + 1] = ptr->p[i];
        }
        ptr->keys[LOC] = newKey;
        ptr->p[LOC + 1] = newPtr;
        ++ptr->data;
        return Success;
    }
    if (LOC == ORDER - 1)
    {
        lastKey = newKey;
        lastPtr = newPtr;
    }
    else
    {
        lastKey = ptr->keys[ORDER - 2];
        lastPtr = ptr->p[ORDER - 1];
        for (i = ORDER - 2; i > LOC; i--)
        {
            ptr->keys[i] = ptr->keys[i - 1];
            ptr->p[i + 1] = ptr->p[i];
        }
        ptr->keys[LOC] = newKey;
        ptr->p[LOC + 1] = newPtr;
    }
    split = (ORDER - 1) / 2;
    (*upKey) = ptr->keys[split];
    (*new) = (Node *)malloc(sizeof(Node));
    ptr->data = split;
    (*new)->data = ORDER - 1 - split;
    for (i = 0; i < (*new)->data; i++)
    {
        (*new)->p[i] = ptr->p[i + split + 1];
        if (i < (*new)->data - 1)
            (*new)->keys[i] = ptr->keys[i + split + 1];
        else
            (*new)->keys[i] = lastKey;
    }
    (*new)->p[(*new)->data] = lastPtr;
    return InsertIt;
}
void insert(int key)
{
    Node *new;
    int upKey;
    KeyType value;
    value = ins(root, key, &upKey, &new);
    if (value == Duplicate)
        printf("Key already available\n");
    if (value == InsertIt)
    {
        Node *temp1 = root;
        root = (Node *)malloc(sizeof(Node));
        root->data = 1;
        root->keys[0] = upKey;
        root->p[0] = temp1;
        root->p[1] = new;
    }
}
void display(Node *ptr, int space)
{
    if (ptr)
    {
        int i;
        for (i = 1; i <= space; i++)
            printf(" ");
        for (i = 0; i < ptr->data; i++)
            printf("%d ", ptr->keys[i]);
        printf("\n");
        for (i = 0; i <= ptr->data; i++)
            display(ptr->p[i], space + 4);
    }
}
KeyType del(Node *ptr, int key)
{
    int LOC, i, pvt, data, min;
    int *KeyArray;
    KeyType value;
    Node **p, *lptr, *rptr;

    if (ptr == NULL)
        return SearchFail;
    data = ptr->data;
    KeyArray = ptr->keys;
    p = ptr->p;
    min = (ORDER - 1) / 2;

    LOC = searchLoc(key, KeyArray, data);
    if (p[0] == NULL)
    {
        if (LOC == data || key < KeyArray[LOC])
            return SearchFail;
        for (i = LOC + 1; i < data; i++)
        {
            KeyArray[i - 1] = KeyArray[i];
            p[i] = p[i + 1];
        }
        return --ptr->data >= (ptr == root ? 1 : min) ? Success : LessKeys;
    }
    if (LOC < data && key == KeyArray[LOC])
    {
        Node *qp = p[LOC], *qp1;
        int nkey;
        while (1)
        {
            nkey = qp->data;
            qp1 = qp->p[nkey];
            if (qp1 == NULL)
                break;
            qp = qp1;
        }
        KeyArray[LOC] = qp->keys[nkey - 1];
        qp->keys[nkey - 1] = key;
    }
    value = del(p[LOC], key);
    if (value != LessKeys)
        return value;

    if (LOC > 0 && p[LOC - 1]->data > min)
    {
        pvt = LOC - 1;
        lptr = p[pvt];
        rptr = p[LOC];
        rptr->p[rptr->data + 1] = rptr->p[rptr->data];
        for (i = rptr->data; i > 0; i--)
        {
            rptr->keys[i] = rptr->keys[i - 1];
            rptr->p[i] = rptr->p[i - 1];
        }
        rptr->data++;
        rptr->keys[0] = KeyArray[pvt];
        rptr->p[0] = lptr->p[lptr->data];
        KeyArray[pvt] = lptr->keys[--lptr->data];
        return Success;
    }
    if (LOC < data && p[LOC + 1]->data > min)
    {
        pvt = LOC;
        lptr = p[pvt];
        rptr = p[pvt + 1];
        lptr->keys[lptr->data] = KeyArray[pvt];
        lptr->p[lptr->data + 1] = rptr->p[0];
        KeyArray[pvt] = rptr->keys[0];
        lptr->data++;
        rptr->data--;
        for (i = 0; i < rptr->data; i++)
        {
            rptr->keys[i] = rptr->keys[i + 1];
            rptr->p[i] = rptr->p[i + 1];

            rptr->p[rptr->data] = rptr->p[rptr->data + 1];
            return Success;
        }

        if (LOC == data)
            pvt = LOC - 1;
        else
            pvt = LOC;

        lptr = p[pvt];
        rptr = p[pvt + 1];
        lptr->keys[lptr->data] = KeyArray[pvt];
        lptr->p[lptr->data + 1] = rptr->p[0];
        for (i = 0; i < rptr->data; i++)
        {
            lptr->keys[lptr->data + 1 + i] = rptr->keys[i];
            lptr->p[lptr->data + 2 + i] = rptr->p[i + 1];
        }
        lptr->data = lptr->data + rptr->data + 1;
        free(rptr);
        for (i = LOC + 1; i < data; i++)
        {
            KeyArray[i - 1] = KeyArray[i];
            p[i] = p[i + 1];
        }
        return --ptr->data >= (ptr == root ? 1 : min) ? Success : LessKeys;
    }
}
void DelNode(int key)
{
    Node *temp1;
    KeyType value;
    value = del(root, key);
    switch (value)
    {
    case SearchFail:
        printf("Key %d is not available\n", key);
        break;
    case LessKeys:
        temp1 = root;
        root = root->p[0];
        free(temp1);
        break;
    default:
        return;
    }
}
void inorder(Node *ptr)
{
    if (ptr)
    {
        if (ptr->data >= 1)
        {
            inorder(ptr->p[0]);
            printf("%d ", ptr->keys[0]);
            inorder(ptr->p[1]);
            if (ptr->data == 2)
            {
                printf("%d ", ptr->keys[1]);
                inorder(ptr->p[2]);
            }
        }
    }
}
int main()
{
    int key, ch;
    while (1)
    {
        printf("1. Insert\n2. Delete\n3. Display Tree\n4. Inorder Display\n5. EXIT\n");
        printf("Enter your Choice : \n");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("Enter the key : ");
            scanf("%d", &key);
            insert(key);
            printf("\n");
            break;
        case 2:
            printf("Enter the key : ");
            scanf("%d", &key);
            DelNode(key);
            printf("\n");
            break;
        case 3:
            printf("Btree is :\n");
            display(root, 0);
            printf("\n");
            break;

        case 4:
            printf("The Inorder is : ");
            inorder(root);
            printf("\n");
            break;

        case 5:
            exit(0);
        }
    }
}