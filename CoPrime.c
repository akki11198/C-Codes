#include <stdio.h>

int GCD(int a, int h)
{
    int temp;
    do
    {
        temp = a % h;
        if (temp == 0)
            return h;
        a = h;
        h = temp;
    } while (1);
}
void main()
{
    int num, gcd, i;
    printf("Enter the Value of n in Zn : \n");
    scanf("%d", &num);
    printf("The Elements in Zn are : \n");
    for (i = 0; i < num; i++)
    {
        printf("%d ", i);
    }
    printf("\n");
    printf("The Elements  of Z%d* are: ", num);
    for (i = 0; i < num; i++)
    {
        if (i)
        {
            gcd = GCD(num, i);
            if (gcd == 1)
            {
                printf("%d  ", i);
            }
        }
    }
}
