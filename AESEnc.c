#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int i, j;
char pl[17], plain[4][4], hex[32];

void StrToHex(char str[])
{
    j = 0;
    int l, ascii[16], q, r;
    l = strlen(str);
    printf("%d\n", l);
    printf("%c\n", str[0]);
    printf("%c\n", str[15]);
    for (i = 0; i < l; i++)
    {
        ascii[i] = (int)str[i];
        q = ascii[i];
        printf("%d\n", q);
        while (q != 0)
        {
            r = q % 16;
            if (r < 10)
            {
                hex[j++] = 48 + r;
            }
            else
            {
                hex[j++] = 55 + r;
            }
            q = q / 16;
        }
    }
}

void main()
{
    printf("Enter the Plain Text : \n");
    scanf("%s", &pl);
    for (i = 0; i < 16; i++)
    {
        if (pl[i] == '\0')
        {
            pl[i] = 'z';
        }
    }
    pl[i] = '\0';
    printf("The Plain Text To Be Encrypted is :\n%s\n", pl);
    printf("The Hexadecimal Representation is : \n");
    StrToHex(pl);
    for (i = 0; i < 32; i = i++)
    {
        printf("%c", hex[i]);
    }
}