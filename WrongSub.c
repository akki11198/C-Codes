#include <stdio.h>
void main()
{
    int x, y, a;
    scanf("%d %d", &x, &y);
    while (y > 0)
    {
        if (x % 10 == 0)
        {
            x = x / 10;
        }
        else
        {
            x = x - 1;
        }
        y = y - 1;
    }
    printf("%d", x);
}