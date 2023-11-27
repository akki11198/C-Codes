#include <stdio.h>
#define inf 999
void warshall(int gr[10][10], int n)
{
    int i, j, k, wr[10][10];
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (gr[i][j] == 0 && i != j)
            {
                wr[i][j] = inf;
            }
            else if (gr[i][j] == 0 && i == j)
            {
                wr[i][j] = 0;
            }
            else
            {
                wr[i][j] = gr[i][j];
            }
        }
    }
    for (k = 0; k < n; k++)
    {
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                if (wr[i][j] > wr[i][k] + wr[k][j])
                {
                    wr[i][j] = wr[i][k] + wr[k][j];
                }
            }
        }
    }
    printf("The Shortest Distance Matrix Is:\n");
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
            if (wr[i][j] == inf)
            {
                printf("inf ");
            }
            else
            {
                printf("%d ", wr[i][j]);
            }
        }
        printf("\n");
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (wr[i][j] == inf)
            {
                printf("No Connection From %d to %d\n", i, j);
            }
            else
            {
                printf("The Shortest Distance from %d to %d is : %d\n", i, j, wr[i][j]);
            }
        }
    }
}
void main()
{
    int gr[10][10], i, j, n, k;
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
    warshall(gr, n);
}
