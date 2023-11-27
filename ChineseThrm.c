#include <stdio.h>
int mi(int a, int m)
{
    a = a % m;
    for (int x = 1; x < m; x++)
    {
        if ((a * x) % m == 1)
            return x;
    }
}
void main()
{
    int a[10], m[10], M = 1, Mul[10], Mulinv[10], n, i, X = 0;
    printf("Enter the No. of Equations :\n");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("Enter the Value of a%d  : ", i + 1);
        scanf("%d", &a[i]);
        printf("Enter the Value of m%d  : ", i + 1);
        scanf("%d", &m[i]);
    }
    for (i = 0; i < n; i++)
    {
        M = M * m[i];
    }
    printf("%d\n", M);
    for (i = 0; i < n; i++)
    {
        Mul[i] = M / m[i];
        printf("%d\n", Mul[i]);
    }
    for (i = 0; i < n; i++)
    {
        Mulinv[i] = mi(Mul[i], m[i]);
        int y = mi(11, 26);
        printf("%d", y);
    }
    for (i = 0; i < n; i++)
    {
        X = X + (a[i] * Mul[i] * Mulinv[i]);
    }
    printf("The Value of X is : %d\n", X);
}