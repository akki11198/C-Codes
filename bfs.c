#include <stdio.h>

int gr[10][10], front = -1, rear = -1, q[10], vis[10];

void push(int key)
{
    if (rear == -1)
    {
        q[++rear] = key;
        front++;
    }
    else
        q[++rear] = key;
}
int pop()
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
    int vert, i;
    push(st);
    vis[st] = 1;
    vert = pop();
    if (vert != 0)
        printf("%d ", vert);
    while (vert != 0)
    {
        for (i = 1; i <= v; i++)
            if ((gr[vert][i] != 0) && (vis[i] == 0))
            {
                push(i);
                vis[i] = 1;
            }
        vert = pop();
        if (vert != 0)
            printf("%d ", vert);
    }
    for (i = 1; i <= v; i++)
        if (vis[i] == 0)
            bfs(i, v);
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
    printf("Enter the starting Vertex : ");
    scanf("%d", &st);
    printf("The BFS Traversal is : \n");
    bfs(st, v);
}