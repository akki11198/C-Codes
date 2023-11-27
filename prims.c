
#include <stdio.h>
#include <stdlib.h>
#define inf 9999
int prims(int gr[10][10], int st[10][10], int n)
{
    int cost[10][10], i, j, t1, t2, dis, d[10], prev[10], v[10], edges, wt;
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
        {
            if (gr[i][j] == 0)
                cost[i][j] = inf;
            else
                cost[i][j] = gr[i][j];
            st[i][j] = 0;
        }
    d[0] = 0;
    v[0] = 1;
    for (i = 1; i < n; i++)
    {
        d[i] = cost[0][i];
        prev[i] = 0;
        v[i] = 0;
    }
    wt = 0;
    edges = n - 1;
    while (edges > 0)
    {
        dis = inf;
        for (i = 1; i < n; i++)
            if (v[i] == 0 && d[i] < dis)
            {
                t2 = i;
                dis = d[i];
            }
        t1 = prev[t2];
        st[t1][t2] = d[t2];
        st[t2][t1] = d[t2];
        edges--;
        v[t2] = 1;
        for (i = 1; i < n; i++)
            if (v[i] == 0 && cost[i][t2] < d[i])
            {
                d[i] = cost[i][t2];
                prev[i] = t2;
            }
        wt = wt + cost[t1][t2];
    }
    return (wt);
}
int main()
{
    int i, j, weight, gr[10][10], st[10][10], n;
    printf("Enter No. of Vertices in the Graph : ");
    scanf("%d", &n);
    printf("Enter The Adjacency Matrix:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &gr[i][j]);
        }
    }
    printf("The Adjacency Matrix Is:\n");
    printf("   ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", i);
    }
    printf("\n");
    for (i = 0; i < n; i++)
    {
        printf("%d  ", i);
        for (j = 0; j < n; j++)
        {
            printf("%d ", gr[i][j]);
        }
        printf("\n");
    }
    weight = prims(gr, st, n);
    printf("Spanning Tree Matrix:\n");
    printf("   ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", i);
    }
    printf("\n");
    for (i = 0; i < n; i++)
    {
        printf("%d  ", i);
        for (j = 0; j < n; j++)
        {
            printf("%d ", st[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (st[i][j] != 0)
            {
                printf("Edge Between %d and %d of weight %d\n", i, j, st[i][j]);
            }
        }
    }
    printf("\nTotal cost of Prims Minimum Spanning Tree = %d", weight);
}
