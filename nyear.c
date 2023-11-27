#include <stdio.h>
int main()
{
    int a[3], b[3], r[2], i, j;
    for (i = 0; i < 2; i++)
    {
        r[i] = 0;
    }
    for (i = 0; i < 3; i++)
        scanf("%d", &a[i]);
    for (i = 0; i < 3; i++)
        scanf("%d", &a[i]);

    for (i = 0; i < 3; i++)
    {
        if (a[i] > b[i])
        {
            r[0] = r[0] + 1;
            printf("%d ", r[0]);
        }
        else if (b[i] > a[i])
        {
            r[1] = r[1] + 1;
            printf("%d ", r[1]);
        }

        else if (a[i] == b[i])
        {
            break;
        }
    }
    for (j = 0; j < 2; j++)
    {
        printf("%d ", r[j]);
    }
    return 0;
}
