// given a 2d matrix, find the prefix sum of it
#include <stdio.h>
#include <stdlib.h>
void main()
{
    int i, j, r, c, s1, s2, e1, e2, ans;
    printf("Enter the number of rows and columns: ");
    scanf("%d%d", &r, &c);
    int a[r][c];
    printf("Enter the elements: ");
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    for (i = 1; i < r; i++)
    {
        a[i][0] = a[i][0] + a[i - 1][0];
    }
    for (i = 1; i < c; i++)
    {
        a[0][i] = a[0][i] + a[0][i - 1];
    }

    for (i = 1; i < r; i++)
    {
        for (j = 1; j < c; j++)
        {
            a[i][j] = a[i][j] + a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];
        }
    }
    printf("The prefix sum matrix is: \n");
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    printf("Enter the starting Index: ");
    scanf("%d %d", &s1, &s2);
    printf("Enter the ending Index: ");
    scanf("%d %d", &e1, &e2);
    ans = a[e1][e2] - a[e1][s2 - 1] - a[s1 - 1][e2] + a[s1 - 1][s2 - 1];
    printf("Total Users In the Area: %d", ans);
}
