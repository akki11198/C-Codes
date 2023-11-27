#include <stdio.h>
#include <math.h>
#include <string.h>
void main()
{
    char str[100];
    int i, j = 0, len, ans = 0, num[100];
    scanf("%s", &str);
    len = strlen(str);
    for (i = 0; i < len; i++)
    {
        if (str[i] == '0')
        {
            num[i] = 0;
        }
        else if (str[i] == '1')
        {
            num[i] = 1;
        }
    }
    for (i = len - 1; i >= 0; i--)
    {
        //printf("%d ", num[i]);
        ans = ans + (num[i] * pow(2, j));
        j++;
    }
    printf("\n%d\n", ans);
    for (i = 0; i < len; i++)
    {
        if (ans == pow(2, i))
        {
            printf("The No is A Power of TWO");
        }
    }
}