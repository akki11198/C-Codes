#include <stdio.h>
 
void main ()
{
    int matrix[10][10];
    int i, j, m, n;
    int count = 0;
    scanf("%d %d", &m, &n);
    for (i = 0; i < m; ++i)
    {
        for (j = 0; j < n; ++j)
        {
            scanf("%d", &matrix[i][j]);
            if (matrix[i][j] == 0)
            {
                ++count;
            }
        }
    }
    if (count > ((m * n) / 2))
    {
        printf("The given matrix is Sparse Matrix !!! \n");
    }
    else
        printf("The given matrix is not a Sparse Matrix \n");
    printf("There are %d number of Zeros.", count);
}
