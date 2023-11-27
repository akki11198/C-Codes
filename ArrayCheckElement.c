#include <stdio.h>
void main()
{
    int i, j, row, col, key, arr[8][8], flag = 0;
    printf("ENter the No. Of ROWS: \n");
    scanf("%d", &row);
    printf("ENter the No. Of COLUMNS: \n");
    scanf("%d", &col);
    printf("Enter the Elements of the MATRIX\n");
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }
    printf("The Matrix is:\n");
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    printf("Enter the Element to Check :\n");
    scanf("%d", &key);
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            if (key == arr[i][j])
            {
                printf("Element is In the Matrix at (%d,%d)\n", i, j);
                flag = 1;
            }
        }
    }
    if (flag == 0)
    {
        printf("Element Not in the Array!!\n");
    }
}