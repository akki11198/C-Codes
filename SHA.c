#include <stdio.h>
#include <string.h>
#include <math.h>
void StrToBin(char a[512], int text[512], int n, int k)
{
    int temp, i = 0, j = n;
    int val;
    double hold;
    temp = (int)a[k];
    for (i = 7; i >= 0; i--)
    {
        hold = pow(2, i);
        val = (int)hold;
        text[j] = (int)(temp / val);
        temp = temp % (val);
        j++;
    }
}
void BinToHex(int arr[], int m)
{
    int i = 0, j, k;
    char result[m];
    int temp;
    j = 0;
    for (i = 0; i < 160; i = i + 4)
    {
        temp = (((arr[i]) * 1000) + ((arr[i + 1]) * 100) + ((arr[i + 2]) * 10) + ((arr[i + 3]) * 1));
        switch (temp)
        {
        case 0:
            result[j] = '0';
            j++;
            break;
        case1:
            result[j] = '1';
            j++;
            break;
        case 10:
            result[j] = '2';
            j++;
            break;
        case 11:
            result[j] = '3';
            j++;
            break;
        case 100:
            result[j] = '4';
            j++;
            break;
        case 101:
            result[j] = '5';
            j++;
            break;
        case 110:
            result[j] = '6';
            j++;
            break;
        case 111:
            result[j] = '7';
            j++;
            break;
        case 1000:
            result[j] = '8';
            j++;
            break;
        case 1001:
            result[j] = '9';
            j++;
            break;
        case 1010:
            result[j] = 'A';
            j++;
            break;
        case 1011:
            result[j] = 'B';
            j++;
            break;
        case 1100:
            result[j] = 'C';
            j++;
            break;
        case 1101:
            result[j] = 'D';
            j++;
            break;
        case 1110:
            result[j] = 'E';
            j++;
            break;
        case 1111:
            result[j] = 'F';
            j++;
            break;
        default:
            continue;
        }
    }
    for (i = 0; i < m; i++)
        printf("%c", result[i]);
}
void HexToBin(int n, char arr[9], int result[32])
{
    int i, j = 0;
    for (i = 0; i < 32; i++)
        result[i] = 0;
    for (i = 0; i < n; i++)
    {
        switch (arr[i])
        {
        case 0:
            result[j] = 0;
            result[j + 1] = 0;
            result[j + 2] = 0;
            result[j + 3] = 0;
            j = j + 4;
            break;
        case 1:
            result[j] = 0;
            result[j + 1] = 0;
            result[j + 2] = 0;
            result[j + 3] = 1;
            j = j + 4;
            break;
        case 2:
            result[j] = 0;
            result[j + 1] = 0;
            result[j + 2] = 1;
            result[j + 3] = 0;
            j = j + 4;
            break;
        case 3:
            result[j] = 0;
            result[j + 1] = 0;
            result[j + 2] = 1;
            result[j + 3] = 1;
            j = j + 4;
            break;
        case 4:
            result[j] = 0;
            result[j + 1] = 1;
            result[j + 2] = 0;
            result[j + 3] = 0;
            j = j + 4;
            break;
        case 5:
            result[j] = 0;
            result[j + 1] = 1;
            result[j + 2] = 0;
            result[j + 3] = 1;
            j = j + 4;
            break;
        case 6:
            result[j] = 0;
            result[j + 1] = 1;
            result[j + 2] = 1;
            result[j + 3] = 0;
            j = j + 4;
            break;
        case 7:
            result[j] = 0;
            result[j + 1] = 1;
            result[j + 2] = 1;
            result[j + 3] = 1;
            j = j + 4;
            break;
        case 8:
            result[j] = 1;
            result[j + 1] = 0;
            result[j + 2] = 0;
            result[j + 3] = 0;
            j = j + 4;
            break;
        case 9:
            result[j] = 1;
            result[j + 1] = 0;
            result[j + 2] = 0;
            result[j + 3] = 1;
            j = j + 4;
            break;
        case 'A':
        case 'a':
            result[j] = 1;
            result[j + 1] = 0;
            result[j + 2] = 1;
            result[j + 3] = 0;
            j = j + 4;
            break;
        case 'B':
        case 'b':
            result[j] = 1;
            result[j + 1] = 0;
            result[j + 2] = 1;
            result[j + 3] = 1;
            j = j + 4;
            break;
        case 'C':
        case 'c':
            result[j] = 1;
            result[j + 1] = 1;
            result[j + 2] = 0;
            result[j + 3] = 0;
            j = j + 4;
            break;
        case 'D':
        case 'd':
            result[j] = 1;
            result[j + 1] = 1;
            result[j + 2] = 0;
            result[j + 3] = 1;
            ;
            j = j + 4;
            ;
            break;
        case 'E':
        case 'e':
            result[j] = 1;
            result[j + 1] = 1;
            result[j + 2] = 1;
            result[j + 3] = 0;
            j = j + 4;
            break;
        case 'F':
        case 'f':
            result[j] = 1;
            result[j + 1] = 1;
            result[j + 2] = 1;
            result[j + 3] = 1;
            j = j + 4;
            break;
        }
    }
}
void lshift(int arr[32], int s)
{
    int temp, i, j;
    for (i = 0; i < s; i++)
    {
        temp = arr[0];
        for (j = 0; j <= 30; j++)
        {
            arr[j] = arr[j + 1];
        }
        arr[31] = temp;
    }
}
void sum(int A[32], int B[32])
{
    int n = 32, carry[32], i, j;
    i = n - 1;
    while (i >= 0)
    {
        B[i] = A[i] + B[i];
        if (B[i] > 1)
        {
            carry[i - 1] = 1;
            B[i] = B[i] % 2;
            B[i - 1] = B[i - 1] + carry[i - 1];
        }
        i--;
    }
}
void XOR(int x[32], int temp[32])
{
    int i = 0, a1 = 0, a2 = 0;
    for (i = 0; i < 32; i++)
    {
        a2 = x[i];
        a1 = temp[i];
        if (a1 == a2)
            x[i] = 0;
        else
            x[i] = 1;
    }
}
int SHAcalc(int a1, int a2, int a3, int ch)
{
    int t = 0;
    int t1 = a1;
    int t2 = a2;
    int t3 = a3;
    if (ch == 1)
    {
        t = (t1 & t2) | ((!t1) & t3);
    }
    else if (ch == 2)
    {
        t = (t1 ^ t2);
        t = (t ^ t3);
    }
    else if (ch == 3)
    {
        t = (t1 & t2) | (t1 & t3) | (t2 & t3);
    }
    else
    {
        t = (t1 ^ t2) ^ t3;
    }
    if (t == 0)
        return 0;
    else
        return 1;
}
void r1(int pt[80][32], int A[32], int B[32], int C[32], int D[32], int E[32])
{
    char K[9] = {5, 'A', 8, 2, 7, 9, 9, 9};
    int temp[32], temp1[32];
    int i, j, p = 0;
    int x[32], k = 0, g[32], hold[32];
    for (j = 0; j < 32; j++)
    {
        temp1[j] = 0;
        temp[j] = 0;
        x[j] = 0;
        g[j] = 0;
    }
    i = 0;
    for (i = 0; i < 20; i++)
    {
        for (j = 0; j < 32; j++)
            x[j] = pt[i][j];
        for (p = 0; p < 32; p++)
            g[p] = SHAcalc(B[p], C[p], D[p], 1);
        sum(g, E);
        for (j = 0; j < 32; j++)
        {
            hold[j] = A[j];
        }
        lshift(A, 5);
        sum(A, E);
        sum(x, E);
        HexToBin(8, K, temp);
        sum(temp, E);
        for (j = 0; j < 32; j++)
        {
            A[j] = E[j];
        }
        for (j = 0; j < 32; j++)
        {
            E[j] = D[j];
        }
        for (j = 0; j < 32; j++)
        {
            D[j] = C[j];
        }
        lshift(B, 30);
        for (j = 0; j < 32; j++)
        {
            C[j] = B[j];
        }
        for (j = 0; j < 32; j++)
        {
            B[j] = hold[j];
        }
    }
    printf("After Round 1\n\n");
    printf("A\n");
    for (i = 0; i < 32; i++)
        printf("%d", A[i]);
    printf("\n");
    printf("B\n");
    for (i = 0; i < 32; i++)
        printf("%d", B[i]);
    printf("\n");
    printf("C\n");
    for (i = 0; i < 32; i++)
        printf("%d", C[i]);
    printf("\n");
    printf("D\n");
    for (i = 0; i < 32; i++)
        printf("%d", D[i]);
    printf("\n");
    printf("E\n");
    for (i = 0; i < 32; i++)
        printf("%d", E[i]);
    printf("\n");
}
void r2(int pt[80][32], int A[32], int B[32], int C[32], int D[32], int E[32])
{
    char K[9] = {6, 'E', 'D', 9, 'E', 'B', 'A', 1};
    int temp[32], temp1[32];
    int x[32], k = 0, g[32], hold[32];
    int i, j, p = 0;
    for (j = 0; j < 32; j++)
    {
        temp1[j] = 0;
        temp[j] = 0;
        x[j] = 0;
        g[j] = 0;
        hold[j] = 0;
    }
    i = 20;
    for (i = 20; i < 40; i++)
    {
        for (j = 0; j < 32; j++)
            x[j] = pt[i][j];
        for (j = 0; j < 32; j++)
            g[j] = SHAcalc(B[j], C[j], D[j], 2);
        sum(g, E);
        for (j = 0; j < 32; j++)
        {
            hold[j] = A[j];
        }
        lshift(A, 5);
        sum(A, E);
        sum(x, E);
        HexToBin(8, K, temp);
        sum(temp, E);
        for (j = 0; j < 32; j++)
        {
            A[j] = E[j];
        }

        for (j = 0; j < 32; j++)
        {
            E[j] = D[j];
        }
        for (j = 0; j < 32; j++)
        {
            D[j] = C[j];
        }
        lshift(B, 30);
        for (j = 0; j < 32; j++)
        {
            C[j] = B[j];
        }
        for (j = 0; j < 32; j++)
        {
            B[j] = hold[j];
        }
    }
    printf("\nAfter Round 2\n\n");
    printf("A\n");
    for (i = 0; i < 32; i++)
        printf("%d", A[i]);
    printf("\n");
    printf("B\n");
    for (i = 0; i < 32; i++)
        printf("%d", B[i]);
    printf("\n");
    printf("C\n");
    for (i = 0; i < 32; i++)
        printf("%d", C[i]);
    printf("\n");
    printf("D\n");
    for (i = 0; i < 32; i++)
        printf("%d", D[i]);
    printf("\n");
    printf("E\n");
    for (i = 0; i < 32; i++)
        printf("%d", E[i]);
    printf("\n");
}
void r3(int pt[80][32], int A[32], int B[32], int C[32], int D[32], int E[32])
{

    char K[9] = {8, 'F', 1, 'B', 'B', 'C', 'D', 'C'};
    int temp[32], temp1[32];
    int i, j, p = 0;
    int x[32], k = 0, g[32], hold[32];
    for (j = 0; j < 32; j++)
    {
        temp1[j] = 0;
        temp[j] = 0;
        x[j] = 0;
        g[j] = 0;
        hold[j] = 0;
    }

    for (i = 40; i < 60; i++)
    {
        for (j = 0; j < 32; j++)
            x[j] = pt[i][j];
        for (p = 0; p < 32; p++)
            g[p] = SHAcalc(B[p], C[p], D[p], 3);
        sum(g, E);
        for (j = 0; j < 32; j++)
        {
            hold[j] = A[j];
        }
        lshift(A, 5);
        sum(A, E);
        sum(x, E);
        HexToBin(8, K, temp);
        sum(temp, E);
        for (j = 0; j < 32; j++)
        {
            A[j] = E[j];
        }

        for (j = 0; j < 32; j++)
        {
            E[j] = D[j];
        }
        for (j = 0; j < 32; j++)
        {
            D[j] = C[j];
        }
        lshift(B, 30);
        for (j = 0; j < 32; j++)
        {
            C[j] = B[j];
        }
        for (j = 0; j < 32; j++)
        {
            B[j] = hold[j];
        }
    }
    printf("\nAfter Round 3\n\n");
    printf("A\n");
    for (i = 0; i < 32; i++)
        printf("%d", A[i]);
    printf("\n");
    printf("B\n");
    for (i = 0; i < 32; i++)
        printf("%d", B[i]);
    printf("\n");
    printf("C\n");
    for (i = 0; i < 32; i++)
        printf("%d", C[i]);
    printf("\n");
    printf("D\n");
    for (i = 0; i < 32; i++)
        printf("%d", D[i]);
    printf("\n");
    printf("E\n");
    for (i = 0; i < 32; i++)
        printf("%d", E[i]);
    printf("\n");
}
void r4(int pt[80][32], int A[32], int B[32], int C[32], int D[32], int E[32])
{
    char K[9] = {'C', 'A', 6, 2, 'C', '1', 'D', 6};
    int temp[32], temp1[32];
    int i, j, p = 0;
    int x[32], k = 0, t[32], g[32], hold[32];
    for (i = 60; i < 80; i++)
    {
        for (j < 0; j < 32; j++)
            x[j] = pt[i][j];

        for (j = 0; j < 32; j++)
            g[j] = SHAcalc(B[j], C[j], D[j], 4);

        sum(g, E);

        for (j = 0; j < 32; j++)
        {
            hold[j] = A[j];
        }
        lshift(A, 5);
        sum(A, E);
        sum(x, E);
        HexToBin(8, K, temp);
        sum(temp, E);
        for (j = 0; j < 32; j++)
        {
            A[j] = E[j];
        }
        for (j = 0; j < 32; j++)
        {
            E[j] = D[j];
        }
        for (j = 0; j < 32; j++)
        {
            D[j] = C[j];
        }
        lshift(B, 30);
        for (j = 0; j < 32; j++)
        {
            C[j] = B[j];
        }
        for (j = 0; j < 32; j++)
        {
            B[j] = hold[j];
        }
    }
    printf("\nAfter Round 4\n\n");
    printf("A\n");
    for (i = 0; i < 32; i++)
        printf("%d", A[i]);
    printf("\n");
    printf("B\n");
    for (i = 0; i < 32; i++)
        printf("%d", B[i]);
    printf("\n");
    printf("C\n");
    for (i = 0; i < 32; i++)
        printf("%d", C[i]);
    printf("\n");
    printf("D\n");
    for (i = 0; i < 32; i++)
        printf("%d", D[i]);
    printf("\n");
    printf("E\n");
    for (i = 0; i < 32; i++)
        printf("%d", E[i]);
    printf("\n");
}
void pad(int n, int text[512])
{
    int pl[64], temp, val, i, j = 55, pbits = 0;
    double hold;
    temp = n;
    for (i = 0; i < 64; i++)
        pl[i] = 0;
    for (i = 8; i >= 0; i--)
    {
        hold = pow(2, i);
        val = (int)hold;
        pl[j] = (int)(temp / val);
        temp = temp % val;
        j++;
    }
    printf("Message length in bits\n");
    for (i = 0; i < 64; i++)
        printf("%d", pl[i]);
    printf("\n");
    pbits = 512 - 64 - n;
    text[n] = 1;
    for (i = n + 1; i < 448; i++)
        text[i] = 0;
    j = 0;
    for (i = 448; i < 512; i++)
    {
        text[i] = pl[j];
        j++;
    }
}
void main()
{
    char arr[512], a[9] = {6, 7, 4, 5, 2, 3, 0, 1}, b[9] = {'e', 'f', 'c', 'd', 'a', 'b', 8, 9};
    char c[9] = {9, 8, 'b', 'a', 'd', 'c', 'f', 'e'};
    char d[9] = {1, 0, 3, 2, 5, 4, 7, 6};
    char e[9] = {'c', 3, 'd', 2, 'e', 1, 'f', 0};
    int A[32], B[32], C[32], D[32], E[32], ZA[32], ZB[32], ZC[32], ZD[32], ZE[32], result[160];
    int n, text[512], len, i, j, k;
    int pt[80][32], temp[32], temp1[32];
    printf("Enter The Plain Text to be Encrypted : \n");
    gets(arr);
    len = strlen(arr);
    n = 0;
    for (i = 0; i < len; i++)
    {
        StrToBin(arr, text, n, i);
        n = n + 8;
    }
    printf("Plain Text In Binary Form :\n");
    for (i = 0; i < n; i++)
        printf("%d", text[i]);
    printf("\n");
    pad(n, text);
    printf("Plain Text After Padding : \n");
    for (i = 0; i < 512; i++)
        printf("%d", text[i]);
    printf("\n");
    for (i = 0; i < 80; i++)
    {
        for (j = 0; j < 32; j++)
        {
            pt[i][j] = 0;
        }
    }
    for (i = 0; i < 32; i++)
    {
        temp[i] = 0;
        temp1[i] = 0;
        A[i] = 0;
        B[i] = 0;
        C[i] = 0;
        D[i] = 0;
        E[i] = 0;
        ZA[i] = 0;
        ZB[i] = 0;
        ZC[i] = 0;
        ZD[i] = 0;
        ZE[i] = 0;
    }
    k = 0;
    for (i = 0; i < 16; i++)
    {
        for (j = 0; j < 32; j++)
        {
            pt[i][j] = text[k];
            k++;
        }
    }
    k = 0;
    for (i = 16; i < 80; i++)
    {
        for (j = 0; j < 32; j++)
        {
            temp[j] = pt[i - 16][j];
            temp1[j] = pt[i - 14][j];
            XOR(temp, temp1);
            temp1[j] = pt[i - 8][j];
            XOR(temp, temp1);
            temp1[j] = pt[i - 3][j];
            XOR(temp, temp1);
            pt[i][j] = temp[j];
        }
    }
    HexToBin(8, e, E);
    for (i = 0; i < 32; i++)
        ZE[i] = E[i];
    HexToBin(8, d, D);
    for (i = 0; i < 32; i++)
        ZD[i] = D[i];
    HexToBin(8, c, C);
    for (i = 0; i < 32; i++)
        ZC[i] = C[i];
    HexToBin(8, b, B);
    for (i = 0; i < 32; i++)
        ZB[i] = B[i];
    HexToBin(8, a, A);
    for (i = 0; i < 32; i++)
        ZB[i] = B[i];
    r1(pt, A, B, C, D, E);
    r2(pt, A, B, C, D, E);
    r3(pt, A, B, C, D, E);
    r4(pt, A, B, C, D, E);
    sum(ZA, A);
    sum(ZB, B);
    sum(ZC, C);
    sum(ZD, D);
    sum(ZE, E);
    for (i = 0, j = 0; i < 32; i++)
    {
        result[j] = A[i];
        j++;
    }
    for (i = 0, j = 32; i < 32; i++)
    {
        result[j] = B[i];
        j++;
    }
    for (i = 0, j = 64; i < 32; i++)
    {
        result[j] = C[i];
        j++;
    }
    for (i = 0, j = 96; i < 32; i++)
    {
        result[j] = D[i];
        j++;
    }
    for (i = 0, j = 128; i < 32; i++)
    {
        result[j] = E[i];
        j++;
    }
    printf("\n");

    printf("\nHash Digest of the Input Message is :\n");
    BinToHex(result, 40);
}