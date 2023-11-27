#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
double GCD(double a, double h)
{
    double temp;
    do
    {
        temp = fmod(a, h);
        if (temp == 0)
            return h;
        a = h;
        h = temp;
    } while (1);
}
double mi(double a, double m)
{
    a = fmod(a, m);
    for (double x = 1; x < m; x++)
    {
        if (fmod(a * x, m) == 1)
            return x;
    }
}
int expmod(int a, int b, int n)
{
    long long x = 1, y = a;
    while (b > 0)
    {
        if (b % 2 == 1)
        {
            x = (x * y) % n;
        }
        y = (y * y) % n;
        b = b / 2;
    }
    return x % n;
}
void encryption(double e, double n)
{
    char msg[10];
    double val = 0, i, enc;
    double p;
    printf("Enter the Text to be Encrypted:\n");
    scanf("%s", &msg);
    for (i = 0; i < strlen(msg); i++)
    {
        if (((double)msg[(int)i] - 96) < 10)
            val = val * 10 + ((double)msg[(int)i] - 96);
        else
        {
            val = val * 100 + ((double)msg[(int)i] - 96);
        }
    }
    printf("msg after conversion is : %d\n", (int)val);
    /*printf("Enter the Value to Encrypt:\n");
    scanf("%lf", &i);
    p = expmod((int)i, (int)e, (int)n);*/
    p = expmod((int)val, (int)e, (int)n);
    printf("The Encrypted Form is : %d\n", (int)p);
}
void decryption(double d, double n)
{
    double p, dec, enc;
    printf("Enter the Encrypted Data to Decrpt:\n");
    scanf("%lf", &enc);
    p = expmod((int)enc, (int)d, (int)n);
    printf("The Data In Decrypted(NUMERICAL) Form Is : %d\n", (int)p);
}
void main()
{
    double n, e, phi, d, i, e_inv, p1, p2;
    int ch;
    printf("Enter the Prime Numbers : \n");
    printf("P1 : ");
    scanf("%lf", &p1);
    printf("P2 : ");
    scanf("%lf", &p2);
    n = p1 * p2;
    printf("Value of N is : %d\n", (int)n);

    phi = (p1 - 1) * (p2 - 1);
    printf("Value of Phi(n) is : %d\n", (int)phi);

    printf("Enter the Value of E (between 1 and %d): ", (int)phi);
    scanf("%lf", &e);
    while (GCD(phi, e) != 1)
    {
        printf("Invalid value of e\nEnter a Valid Value :");
        scanf("%lf", &e);
    }
    e_inv = mi(e, phi);
    d = fmod(e_inv, phi);

    printf("Public Key is : (%d,%d)\n", (int)e, (int)n);
    printf("Private Key is : (%d,%d)\n", (int)d, (int)n);
    while (1)
    {
        printf("Select Operation\n1. Encryption\n2. Decryption\n3. EXIT\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            encryption(e, n);
            break;
        case 2:
            decryption(d, n);
            break;
        case 3:
            exit(0);
        }
    }
}