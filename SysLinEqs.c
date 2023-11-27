#include <stdio.h>
int INV(int x, int n)
{
    int i, inv;
    if (x < 0)
    {
        x = x * -1;
        for (i = 1; i <= x; i++)
        {
            inv = ((i * n) + 1);
            if (inv % x == 0)
            {
                break;
            }
        }
        inv = (inv / x) * -1;
        return inv;
    }
    else
    {
        for (i = 1; i <= x; i++)
        {
            inv = ((i * n) + 1);
            if (inv % x == 0)
            {
                break;
            }
        }
        inv = (inv / x);
        return inv;
    }
}
void main()
{
    int arr[3], brr[3], crr[3], mrr[3][1], n, num = 3, i, j, k, det, detInv, prd = 0;
    int mat[3][3], inv[3][3], mul[3], invT[3][3];
    for (i = 0; i < num; i++)
    {
        printf("Enter the Value of a,b,c and m for Eq. %d: \n", i + 1);
        printf("a%d : ", i + 1);
        scanf("%d", &arr[i]);
        printf("b%d : ", i + 1);
        scanf("%d", &brr[i]);
        printf("c%d : ", i + 1);
        scanf("%d", &crr[i]);
        printf("m%d : ", i + 1);
        scanf("%d", &mrr[i][0]);
    }
    printf("Enter the Value of n : ");
    scanf("%d", &n);

    printf("The Equations are : \n");
    for (i = 0; i < num; i++)
    {
        printf("%dx + %dy +%dz = %d(mod %d)\n", arr[i], brr[i], crr[i], mrr[i][0], n);
    }

    for (i = 0; i < num; i++)
    {
        for (j = 0; j < num; j++)
        {
            mat[i][0] = arr[i];
            mat[i][1] = brr[i];
            mat[i][2] = crr[i];
        }
    }
    printf("The Eq. Matrix is : \n");
    for (i = 0; i < num; i++)
    {
        for (j = 0; j < num; j++)
        {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
    det = mat[0][0] * (mat[1][1] * mat[2][2] - mat[2][1] * mat[1][2]) - mat[0][1] * (mat[1][0] * mat[2][2] - mat[1][2] * mat[2][0]) + mat[0][2] * (mat[1][0] * mat[2][1] - mat[1][1] * mat[2][0]);
    printf("The Determinant of Matrix is : %d\n", det);

    detInv = INV(det, n);
    printf("The Inverse of Determinant is : %d\n", detInv);

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            inv[i][j] = (((mat[(i + 1) % 3][(j + 1) % 3] * mat[(i + 2) % 3][(j + 2) % 3]) - (mat[(i + 1) % 3][(j + 2) % 3] * mat[(i + 2) % 3][(j + 1) % 3])) * detInv);
        }
    }
    for (i = 0; i < num; i++)
    {
        for (j = 0; j < num; j++)
        {
            printf("%d ", inv[i][j]);
        }
        printf("\n");
    }
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            invT[j][i] = inv[i][j];
        }
    }
    printf("The Inverse of the Given Matrix is : \n");
    for (i = 0; i < num; i++)
    {
        for (j = 0; j < num; j++)
        {
            printf("%d ", invT[i][j]);
        }
        printf("\n");
    }

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {

            prd = prd + invT[i][j] * mrr[j][0];
        }

        if (prd < 0)
            mul[i] = (prd % n) + n;
        else
            mul[i] = (prd % n);
        prd = 0;
    }

    printf("The Solution of the Given System is : \n");
    for (i = 0; i < 3; i++)
    {
        printf("%d \n", mul[i]);
    }
}