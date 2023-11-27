#include <stdio.h>

void main()
{
    int arr[20], brr[20], i, j, n, itrs, sum = 0;
    printf("Enter the Size of Array:\n");
    scanf("%d", &n);
    printf("Enter the Elements of the Array : \n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Enter the NO of Iterations :\n");
    scanf("%d", &itrs);
    j = itrs;
    while (itrs > 0)
    {
        for (i = 0; i < n - 1; i++)
        {
            arr[i] = arr[i + 1] - arr[i];
        }
        itrs = itrs - 1;
        n = n - 1;
    }
    printf("The New Matrix is :\n");
    for (i = 0; i < (n - itrs); i++)
    {
        printf("%d ", arr[i]);
    }
    for (i = 0; i < (n - itrs); i++)
    {
        sum += arr[i];
    }
    printf("\nAfter %d iterations the SUM is : %d", j, sum);
}