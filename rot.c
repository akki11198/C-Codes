#include <stdio.h>
int main()
{
    int arr[1000], num, rot, i, j, temp;
    scanf("%d", &num);
    scanf("%d", &rot);
    for (i = 1; i <= num; i++)
    {
        arr[i - 1] = i;
    }
    for (i = 0; i < num; i++)

    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    for (i = 0; i < rot; i++)
    {
        temp = arr[0];
        for (j = 0; j < num - 1; j++)
        {
            arr[j] = arr[j + 1];
        }
        arr[num - 1] = temp;
    }
    for (i = 0; i < num; i++)
    {
        printf("%d ", arr[i]);
    }
}