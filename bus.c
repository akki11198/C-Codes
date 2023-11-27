#include <stdio.h>

int main(void)
{
    int x, seat[100], i;
    scanf("%d", &x);
    for (i = 0; i < x; i++)
    {
        scanf("%d", &seat[i]);
    }
    for (i = 0; i < x; i++)
    {
        if ((seat[i] - 1) < (100 - seat[i]))
        {
            printf("LEFT\n");
        }
        else
        {
            printf("RIGHT\n");
        }
    }
}
