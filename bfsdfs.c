#include <stdio.h>
#include <stdlib.h>
int gr[10][10], top = -1, front = -1, rear = -1, q[10], vis[10], stck[10];

void add(int key)
{
    if (rear == 9)
        printf("QUEUE FULL");
    else
    {
        if (rear == -1)
        {
            q[++rear] = key;
            front++;
        }
        else
            q[++rear] = key;
    }
}
int delete ()
{
    int k;
    if ((front > rear) || (front == -1))
        return (0);
    else
    {
        k = q[front++];
        return (k);
    }
}
void bfs(int st, int v)
{
    int p, i;
    add(st);
    vis[st] = 1;
    p = delete ();
    if (p != 0)
        printf("%d ", p);
    while (p != 0)
    {
        for (i = 1; i <= v; i++)
            if ((gr[p][i] != 0) && (vis[i] == 0))
            {
                add(i);
                vis[i] = 1;
            }
        p = delete ();
        if (p != 0)
            printf("%d ", p);
    }
    for (i = 1; i <= v; i++)
        if (vis[i] == 0)
            bfs(i, v);
}
void push(int key)
{
    if (top == 9)
        printf("Stack overflow ");
    else
        stck[++top] = key;
}
int pop()
{
    int k;
    if (top == 9)
        return (0);
    else
    {
        k = stck[top--];
        return (k);
    }
}
void dfs(int st, int v)
{
    int i, k;
    push(st);
    vis[st] = 1;
    k = pop();
    if (k != 0)
        printf("%d ", k);
    while (k != 0)
    {
        for (i = 1; i <= v; i++)
            if ((gr[k][i] != 0) && (vis[i] == 0))
            {
                push(i);
                vis[i] = 1;
            }
        k = pop();
        if (k != 0)
            printf("%d ", k);
    }
    for (i = 1; i <= v; i++)
        if (vis[i] == 0)
            dfs(i, v);
}
void main()
{
    int i, j, ch, st, v;
    printf("Enter the no of Nodes : ");
    scanf("%d", &v);
    printf("Enter the Adjacency Matrix :\n");
    for (i = 1; i <= v; i++)
    {
        for (j = 1; j <= v; j++)
        {
            scanf("%d", &gr[i][j]);
        }
    }
    printf("The Adjacency Matrix Is:\n");
    printf("   ");
    for (i = 1; i <= v; i++)
    {
        printf("%d ", i);
    }
    printf("\n");
    for (i = 1; i <= v; i++)
    {
        printf("%d  ", i);
        for (j = 1; j <= v; j++)
        {
            printf("%d ", gr[i][j]);
        }
        printf("\n");
    }
    while (1)
    {
        printf("Select Search Procedure :\n1. Bredth First Search\n2. Depth First Search\n3. Exit\n");
        scanf("%d", &ch);
        if (ch == 1 || ch == 2)
        {
            printf("Enter the starting Vertex : ");
            scanf("%d", &st);
            switch (ch)
            {
            case 1:
                printf("The BFS Traversal is : \n");
                bfs(st, v);
                printf("\n");
                break;
            case 2:
                printf("The DFS Traversal is : \n");
                dfs(st, v);
                printf("\n");
                break;
            }
        }
        else if (ch == 3)
            exit(0);
    }
}
