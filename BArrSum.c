#include <stdio.h>
int add(int A[32], int B[32])
{

    int a1[32], a2[32];
    int n = 32, carry[32], i, j;

    for (j = 0; j < 32; j++)
    {
        a1[j] = A[j];
        a2[j] = B[j];
    }

    i = n - 1;

    while (i >= 0)
    {
        a2[i] = a1[i] + a2[i];

        if (a2[i] > 1)
        {
            carry[i - 1] = a2[i] - (a2[i] / 2);
            a2[i] = a2[i] % 2;
            a1[i - 1] = a1[i - 1] + carry[i - 1];
        }
        i--;
    }

    for (j = 0; j < 32; j++)
        B[j] = a2[j];
}
void main()
{
    int arr2[32], arr1[32], i, s, n;
    printf("Enter size : ");
    scanf("%d", &n);
    printf("Enter array 1: \n");
    for (i = 0; i < n; i++)
        scanf("%d", &arr1[i]);
    printf("Array is :\n");
    for (i = 0; i < n; i++)
        printf("%d ", arr1[i]);
    printf("Enter array 2: \n");
    for (i = 0; i < n; i++)
        scanf("%d", &arr2[i]);
    printf("Array is :\n");
    for (i = 0; i < n; i++)
        printf("%d ", arr2[i]);

    add(arr1, arr2);
    printf("Sum is : \n");
    for (i = 0; i < n; i++)
        printf("%d ", arr2[i]);
}