#include <stdio.h>

void main()
{
    int arr[10][10], r, c, i, j, k;
    scanf("%d", &r);
    scanf("%d", &c);
    printf("Enter Array :\n");
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }
    printf("The Array is : \n");
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            printf("%d", arr[i][j]);
        }
    }
}