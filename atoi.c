#include <stdio.h>
#include <string.h>

int newAtoi(char* str)
{
    int res = 0;
    int sign = 1;
    int i = 0;
    if (str[0] == '-') 
    {
        sign = -1;
        i++;
    }
    for (i=1; str[i] != '\0'; i++)
        res = res * 10 + str[i] - '0';
    return sign * res;
}
int main()
{
    char str[20];
    int x;
    printf("Enter the Numeric String: \n");
    gets(str);
    x = newAtoi(str);
    printf("the Digit form of the Numeric String is %d ", x);
    return 0;
}