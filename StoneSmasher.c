#include <stdio.h>
void sort(int *arr, int n)
{
    int i, j, temp;

    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
void main()
{
    int arr[100], i, j, n, t1, t2, t3;
    printf("Enter the number of Stones: ");
    scanf("%d", &n);
    printf("Enter the Weight of Stones:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    sort(arr, n);
    while (n > 1)
    {
        t1 = arr[n - 1];
        t2 = arr[n - 2];

        if (t1 == t2)
        {
            for (j = n - 3; j < n; j++)
            {
                arr[j] = arr[j + 1];
            }
            for (j = n - 3; j < n; j++)
            {
                arr[j] = arr[j + 1];
            }
            n = n - 2;
        }
        else if (t1 > t2)
        {
            t3 = t1 - t2;
            arr[n - 2] = t2;
            n = n - 2;
            for (j = n - 3; j < n; j++)
            {
                arr[j] = arr[j + 1];
            }
            for (j = n - 3; j < n; j++)
            {
                arr[j] = arr[j + 1];
            }
            arr[n - 3] = t3;
            n = n - 1;
            sort(arr, n);
        }
    }
    if (n == 1)
    {
        printf("%d", arr[0]);
    }
    if (n == 0)
    {
        printf("0");
    }
}