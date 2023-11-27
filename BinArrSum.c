#include <stdio.h>
void main()
{
    int i, j, n, a1[32], a2[32], carry[32];
    printf("Enter the size of the numbers : ");
    scanf("%d", &n);

    printf("Enter the first no. :\n");
    for (i = 0; i < n; i++)
        scanf("%d", &a1[i]);
    printf("The First Number is : ");
    for (i = 0; i < n; i++)
    {
        carry[i] = 0;
        printf("%d ", a1[i]);
    }
    printf("\nEnter the second no. :\n");
    for (i = 0; i < n; i++)
        scanf("%d", &a2[i]);
    printf("\nThe Second Number is : ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", a2[i]);
    }
    i = n - 1;
    while (i >= 0)
    {
        a2[i] = a1[i] + a2[i];
        printf("\n%d ", a2[i]);
        if (a2[i] > 1)
        {
            carry[i - 1] = 1;
            printf("\n carry of %d is %d", i, carry[i - 1]);
            a2[i] = a2[i] % 2;
            printf("\nindex %d --  value %d", i, a2[i]);
            a2[i - 1] = a2[i - 1] + carry[i - 1];
        }
        i--;
    }
    printf("\nThe Sum Is :\n");
    for (i = 0; i < n; i++)
        printf("%d ", a2[i]);
}