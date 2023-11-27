#include <stdio.h>
#include <string.h>

void main()
{
    int n, i;
    char str[20];
    printf("Enter the String :\n");
    scanf("%s", &str);
    n = strlen(str);
    for (int i = 0; i < n; i++)
    {
        int count = 1;
        while (i < n - 1 && str[i] == str[i + 1])
        {
            count++;
            i++;
        }
        printf("%c%d", str[i], count);
    }
}