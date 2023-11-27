#include <stdio.h>
#include <string.h>
#include <ctype.h>
char key[30];
void search(char box[5][5], char a, char b, int arr[])
{
    int i, j, t;
    for (i = 0; i < 5; i++)
    {

        for (j = 0; j < 5; j++)
        {

            if (box[i][j] == a)
            {
                arr[0] = i;
                arr[1] = j;
            }
            else if (box[i][j] == b)
            {
                arr[2] = i;
                arr[3] = j;
            }
        }
    }
}
int mod5(int a)
{
    if (a < 0)
        return ((a + 5) % 5);
    else
        return (a % 5);
}
void mapping(char temp[], char box[5][5])
{
    int i, t, a[4], length;
    length = strlen(temp);

    for (i = 0; i < length; i += 2)
    {

        search(box, temp[i], temp[i + 1], a);

        if (a[0] == a[2])
        {
            temp[i] = box[a[0]][mod5(a[1] + 1)];
            temp[i + 1] = box[a[0]][mod5(a[3] + 1)];
        }
        else if (a[1] == a[3])
        {
            temp[i] = box[mod5(a[0] + 1)][a[1]];
            temp[i + 1] = box[mod5(a[2] + 1)][a[1]];
        }
        else
        {
            temp[i] = box[a[0]][a[3]];
            temp[i + 1] = box[a[2]][a[1]];
        }
    }
    for (t = 0; t < length; t++)
        printf("%c\t", temp[t]);
    printf("\n");
}
void digram(char str[], char box[5][5])
{
    int size, check, t, p = 0, q = 0, l, li, len, c = 0;
    char temp[30];
    char x = 'x';
    len = strlen(str);
    for (p = 0; p < len; p++)
    {

        temp[q] = str[p];
        if (str[p] == str[p + 1])
        {
            c = c + 1;
            if (c % 2 != 0)
            {
                temp[q + 1] = 'x';
                q = q + 2;
                temp[q] = '\0';
            }
            else
            {
                q = q + 1;
                temp[q] = '\0';
            }
        }
        else
        {
            q = q + 1;
            temp[q] = '\0';
        }
    }
    size = strlen(temp);
    check = size % 2;
    if (check != 0)
    {
        strncat(temp, &x, 1);
    }
    li = strlen(temp);
    for (t = 0; t < li; t++)
        printf("%c\t", temp[t]);
    printf("\n");

    mapping(temp, box);
}
void encryptplayfair(char key[])
{

    char str[30];
    int size, l, t, m, n, hold = -1, len, p = 0, q = 0, c = 0;
    static int i, j;
    char box[5][5];
    char value;
    int count[26];
    for (t = 0; t < 26; t++)
        count[t] = 0;

    l = strlen(key);

    for (t = 0; t < l; t++)
    {

        count[key[t] - 97] = count[key[t] - 97] + 1;
        //printf("%d ", count[key[t] - 97]);
    }

    for (m = 0; m < 5; m++)
    {
        for (n = 0; n < 5; n++)
            box[m][n] = '\0';
    }

    for (t = 0; t < l; t++)
    {
        if (count[key[t] - 97] > 0 && key[t] != 'j')
        {

            count[key[t] - 97] = hold;
            box[i][j] = key[t];

            j++;
            if (j == 5)
            {
                i++;
                j = 0;
            }
        }
    }
    for (t = 0; t < 26; t++)
    {
        if (count[t] == 0 && t != 9)
        {
            box[i][j] = (char)(t + 97);
            j++;
            if (j == 5)
            {
                i++;
                j = 0;
            }
        }
    }
    m = 0;
    n = 0;
    for (m = 0; m < 5; m++)
    {
        for (n = 0; n < 5; n++)

        {
            printf("%c\t", box[m][n]);
        }
        printf("\n");
    }

    printf("Enter the plain text\n");
    scanf("%s", str);
    digram(str, box);
}
void demapping(char temp[], char box[5][5])
{

    int i, t, a[4], length;
    length = strlen(temp);

    for (i = 0; i < length; i += 2)
    {

        search(box, temp[i], temp[i + 1], a);

        if (a[0] == a[2])
        {
            temp[i] = box[a[0]][mod5(a[1] - 1)];
            temp[i + 1] = box[a[0]][mod5(a[3] - 1)];
        }
        else if (a[1] == a[3])
        {
            temp[i] = box[mod5(a[0] - 1)][a[1]];
            temp[i + 1] = box[mod5(a[2] - 1)][a[1]];
        }
        else
        {
            temp[i] = box[a[0]][a[3]];
            temp[i + 1] = box[a[2]][a[1]];
        }
    }
    for (t = 0; t < length; t++)
        printf("%c\t", temp[t]);
    printf("\n");
}
void decryptplayfair(char key[])
{
    char temp[30];
    char str[30];
    int size, l, t, m, n, hold = -1, len, p = 0, q = 0, c = 0;
    static int i, j;
    char box[5][5];
    char value;
    int count[26];
    for (t = 0; t < 26; t++)
        count[t] = 0;

    l = strlen(key);

    for (t = 0; t < l; t++)
    {

        count[key[t] - 97] = count[key[t] - 97] + 1;
    }
    for (m = 0; m < 5; m++)
    {
        for (n = 0; n < 5; n++)
            box[m][n] = '\0';
    }
    for (t = 0; t < l; t++)
    {
        if (count[key[t] - 97] > 0 && key[t] != 'j')
        {

            count[key[t] - 97] = hold;
            box[i][j] = key[t];

            j++;
            if (j == 5)
            {
                i++;
                j = 0;
            }
        }
    }

    for (t = 0; t < 26; t++)
    {
        if (count[t] == 0 && t != 9)
        {
            box[i][j] = (char)(t + 97);
            j++;
            if (j == 5)
            {
                i++;
                j = 0;
            }
        }
    }
    m = 0;
    n = 0;
    for (m = 0; m < 5; m++)
    {
        for (n = 0; n < 5; n++)

        {
            printf("%c\t", box[m][n]);
        }
        printf("\n");
    }

    printf("Enter the encrypted text\n");
    scanf("%s", str);
    demapping(str, box);
}
void main()
{
    int i, j;
    char key[30];
    printf("Enter the key \n");
    scanf("%s", key);
    char temp[30];
    int ch;
    while (1)
    {
        printf("Select Operation:\n1. Eencryption\n2. Decryption\n3. EXIT\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            encryptplayfair(key);
            break;
        case 2:
            decryptplayfair(key);
            break;
        case 3:
            main();
        }
    }
}