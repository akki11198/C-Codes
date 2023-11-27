#include <stdio.h>
void main()
{
    int arr[20], i, n, profit = 0, j = 0;
    printf("ENter the NO of Days Stock Price is Monitored :\n");
    scanf("%d", &n);
    printf("Enter the Price of Stock:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("The Stock Price is:\n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    for (int i = 1; i < n; i++)
    {
        if (arr[i - 1] > arr[i])
        {
            j = i;
        }
        if (arr[i - 1] <= arr[i] && (i + 1 == n || arr[i] > arr[i + 1]))
        {
            profit += (arr[i] - arr[j]);
            printf("Buy on day %d and sell on day %d\n", j + 1, i + 1);
        }
    }
    printf("Total Profit is : %d", profit);
}