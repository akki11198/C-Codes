#include <stdio.h>
void main()
{
    int x, i, j;
    printf("Enter Range of Sequence\n");
    scanf("%d", &x);
    for (i = 1; i <= x; i++)
    {
        for (j = 1; j <= i; j++)
        {
            printf("%d ", j);
        }
        printf("\n");
    }
}