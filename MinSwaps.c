#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n, arr[99], i, count = 0, temp;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    for (i = 0; i < n; i++)
    {
        if (arr[i] == i + 1)
        {
            if (arr[i + 1])
            {
                temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                count++;
            }
            else
            {
                temp = arr[i];
                arr[i] = arr[i - 1];
                arr[i - 1] = temp;
                count++;
            }
        }
    }
    printf("%d", count);
    return 0;
}