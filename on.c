#include <stdio.h>
void main()
{
    int x, n, i, j = 0, ans = 0, t;
    scanf("%d", &n);
    while (n > 0)
    {
        x = n % 10;
        switch (x)
        {
        case 0:
            ans = ans + 9;
            n = n / 10;
            ans = ans * 10;
            break;
        case 1:
            ans = ans + 8;
            n = n / 10;
            ans = ans * 10;
            break;
        case 2:
            ans = ans + 7;
            n = n / 10;
            ans = ans * 10;
            break;
        case 3:
            ans = ans + 6;
            n = n / 10;
            ans = ans * 10;
            break;
        case 4:
            ans = ans + 5;
            n = n / 10;
            ans = ans * 10;
            break;
        case 5:
            ans = ans + 4;
            n = n / 10;
            ans = ans * 10;
            break;
        case 6:
            ans = ans + 3;
            n = n / 10;
            ans = ans * 10;
            break;
        case 7:
            ans = ans + 2;
            n = n / 10;
            ans = ans * 10;
            break;
        case 8:
            ans = ans + 1;
            n = n / 10;
            ans = ans * 10;
            break;
        case 9:
            ans = ans + 0;
            n = n / 10;
            ans = ans * 10;
            break;
        }
    }
    i = ans;
    while (i > 0)
    {
        t = i % 10;
        j = j + t;
        i = i / 10;
        j = j * 10;
    }
    printf("%d", j / 10);
}