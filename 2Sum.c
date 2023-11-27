#include <stdio.h>
void main()
{
    int st, end, i, n, arr[100], tgt, sum = 0;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    printf("Enter the elements: \n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Enter the Target Value: ");
    scanf("%d", &tgt);
    st = 0;
    end = n - 1;
    while (sum != tgt && st <= end)
    {
        sum = arr[st] + arr[end];
        if (sum == tgt)
        {
            printf("For sum = %d , The Values are %d, %d on Indices %d,%d", sum, arr[st], arr[end], st, end);
            break;
        }
        else if (sum < tgt)
        {
            st++;
        }
        else
        {
            end--;
        }
    }
}