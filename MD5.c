#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int clsr(int arr[32], int s)
{
    int temp, i, j;
    for (i = 0; i < s; i++)
    {
        temp = arr[0];
        for (j = 0; j < 31; j++)
        {
            arr[j - 1] = arr[j + 1];
        }
        arr[31] = temp;
    }
}

int add(int a1[32], int a2[32])
{

    int n = 32, carry[32], i;
    i = n - 1;
    while (i >= 0)
    {
        a2[i] = a1[i] + a2[i];

        if (a2[i] > 1)
        {
            carry[i - 1] = a2[i] - (a2[i] / 2);
            a2[i] = a2[i] % 2;
            a1[i - 1] = a1[i - 1] + carry[i - 1];
        }
        i--;
    }
}

int fun(int b, int c, int d, int ch)
{
    int x = 0;

    if (ch == 1)
    {
        x = (b & c) | ((~b) & d);
    }
    else if (ch == 2)
    {
        x = (d & b) | ((~d) & c);
    }
    else if (ch == 3)
    {
        x = (b ^ c) ^ d;
    }
    else
    {
        if (d == 1)
            x = 0;
        else
            x = 1;

        x = (b | x);
        x = x ^ c;
    }
    return x;
}

void hex_to_binary(int n, char arr[9], int result[32])
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

void MD5_round1(int text[512], int A[32], int B[32], int C[32], int D[32])
{
    char T[64][9] = {"d76aa478", "e8c7b756", "242070db", "c1bdceee", "f57c0faf", "4787c62a", "a8304613", "fd469501",
                     "698098d8", "8b44f7af", "ffff5bb1", "895cd7be", "6b901122", "fd987193", "a679438e", "49b40821",
                     "f61e2562", "c040b340", "265e5a51", "e9b6c7aa", "d62f105d", "02441453", "d8a1e681", "e7d3fbc8",
                     "21e1cde6", "c33707d6", "f4d50d87", "455a14ed", "a9e3e905", "fcefa3f8", "676f02d9", "8d2a4c8a",
                     "fffa3942", "8771f681", "6d9d6122", "fde5380c", "a4beea44", "4bdecfa9", "f6bb4b60", "bebfbc70",
                     "289b7ec6", "eaa127fa", "d4ef3085", "04881d05", "d9d4d039", "e6db99e5", "1fa27cf8", "c4ac5665",
                     "f4292244", "432aff97", "ab9423a7", "fc93a039", "655b59c3", "8f0ccc92", "ffeff47d", "85845dd1",
                     "6fa87e4f", "fe2ce6e0", "a3014314", "4e0811a1", "f7537e82", "bd3af235", "2ad7d2bb", "eb86d391"};

    int s[16] = {7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22};

    char temp[9];
    int i, j;
    int x[32], k = 0, t[32], g[32], hold[32];

    i = 0;
    for (i = 0; i < 16; i++)
    {
        for (j = 0; j < 32; j++)
        {
            x[j] = text[k];
            k++;
        }

        for (j = 0; j < 8; j++)
            temp[j] = T[i][j];

        hex_to_binary(8, temp, t);

        for (j = 0; j < 32; j++)
            g[j] = fun(B[j], C[j], D[j], 1);

        add(g, A);

        add(x, A);

        add(t, A);

        clsr(A, s[i]);

        add(B, A);

        for (j = 0; j < 32; j++)
        {
            hold[j] = A[j];
        }
        for (j = 0; j < 32; j++)
        {
            A[j] = D[j];
        }
        for (j = 0; j < 32; j++)
        {
            D[j] = C[j];
        }
        for (j = 0; j < 32; j++)
        {
            C[j] = B[j];
        }
        for (j = 0; j < 32; j++)
        {
            B[j] = hold[j];
        }
    }
}

void MD5_round2(int text[512], int A[32], int B[32], int C[32], int D[32])
{
    char T[64][9] = {"d76aa478", "e8c7b756", "242070db", "c1bdceee", "f57c0faf", "4787c62a", "a8304613", "fd469501",
                     "698098d8", "8b44f7af", "ffff5bb1", "895cd7be", "6b901122", "fd987193", "a679438e", "49b40821",
                     "f61e2562", "c040b340", "265e5a51", "e9b6c7aa", "d62f105d", "02441453", "d8a1e681", "e7d3fbc8",
                     "21e1cde6", "c33707d6", "f4d50d87", "455a14ed", "a9e3e905", "fcefa3f8", "676f02d9", "8d2a4c8a",
                     "fffa3942", "8771f681", "6d9d6122", "fde5380c", "a4beea44", "4bdecfa9", "f6bb4b60", "bebfbc70",
                     "289b7ec6", "eaa127fa", "d4ef3085", "04881d05", "d9d4d039", "e6db99e5", "1fa27cf8", "c4ac5665",
                     "f4292244", "432aff97", "ab9423a7", "fc93a039", "655b59c3", "8f0ccc92", "ffeff47d", "85845dd1",
                     "6fa87e4f", "fe2ce6e0", "a3014314", "4e0811a1", "f7537e82", "bd3af235", "2ad7d2bb", "eb86d391"};

    int s[16] = {5, 9, 14, 20, 5, 9, 14, 20, 5, 9, 14, 20, 5, 9, 14, 20};

    char temp[9];

    int x[32], k = 0, t[32], g[32], hold[32];
    int i, j;
    i = 16;

    for (i = 16; i < 32; i++)
    {
        k = (1 + (5 * i)) % 16;
        k = (k - 1) * 32;

        for (j = 0; j < 32; j++)
        {
            x[j] = text[k];
            k++;
        }

        for (j = 0; j < 8; j++)
            temp[j] = T[i][j];

        hex_to_binary(8, temp, t);

        for (j = 0; j < 32; j++)
            g[j] = fun(B[j], C[j], D[j], 2);

        add(g, A);
        add(x, A);
        add(t, A);
        clsr(A, s[i]);
        add(B, A);

        for (j = 0; j < 32; j++)
        {
            hold[j] = A[j];
        }
        for (j = 0; j < 32; j++)
        {
            A[j] = D[j];
        }
        for (j = 0; j < 32; j++)
        {
            D[j] = C[j];
        }
        for (j = 0; j < 32; j++)
        {
            C[j] = B[j];
        }
        for (j = 0; j < 32; j++)
        {
            B[j] = hold[j];
        }
    }
}

void MD5_round3(int text[512], int A[32], int B[32], int C[32], int D[32])
{
    char T[64][9] = {"d76aa478", "e8c7b756", "242070db", "c1bdceee", "f57c0faf", "4787c62a", "a8304613", "fd469501",
                     "698098d8", "8b44f7af", "ffff5bb1", "895cd7be", "6b901122", "fd987193", "a679438e", "49b40821",
                     "f61e2562", "c040b340", "265e5a51", "e9b6c7aa", "d62f105d", "02441453", "d8a1e681", "e7d3fbc8",
                     "21e1cde6", "c33707d6", "f4d50d87", "455a14ed", "a9e3e905", "fcefa3f8", "676f02d9", "8d2a4c8a",
                     "fffa3942", "8771f681", "6d9d6122", "fde5380c", "a4beea44", "4bdecfa9", "f6bb4b60", "bebfbc70",
                     "289b7ec6", "eaa127fa", "d4ef3085", "04881d05", "d9d4d039", "e6db99e5", "1fa27cf8", "c4ac5665",
                     "f4292244", "432aff97", "ab9423a7", "fc93a039", "655b59c3", "8f0ccc92", "ffeff47d", "85845dd1",
                     "6fa87e4f", "fe2ce6e0", "a3014314", "4e0811a1", "f7537e82", "bd3af235", "2ad7d2bb", "eb86d391"};

    int s[16] = {4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23};

    char temp[9];
    int i, j;
    int x[32], k = 0, t[32], g[32], hold[32];

    for (i = 32; i < 48; i++)
    {
        k = (5 + (3 * i)) % 16;
        k = (k - 1) * 32;
        for (j = 0; j < 32; j++)
        {
            x[j] = text[k];
            k++;
        }

        for (j = 0; j < 8; j++)
            temp[j] = T[i][j];

        hex_to_binary(8, temp, t);

        for (j = 0; j < 32; j++)
        {
            g[j] = fun(B[j], C[j], D[j], 3);
        }

        add(g, A);

        add(x, A);
        add(t, A);
        clsr(A, s[i]);

        add(B, A);

        for (j = 0; j < 32; j++)
        {
            hold[j] = A[j];
        }
        for (j = 0; j < 32; j++)
        {
            A[j] = D[j];
        }
        for (j = 0; j < 32; j++)
        {
            D[j] = C[j];
        }
        for (j = 0; j < 32; j++)
        {
            C[j] = B[j];
        }
        for (j = 0; j < 32; j++)
        {
            B[j] = hold[j];
        }
    }
}

void MD5_round4(int text[512], int A[32], int B[32], int C[32], int D[32], int result[128])
{
    char T[64][9] = {"d76aa478", "e8c7b756", "242070db", "c1bdceee", "f57c0faf", "4787c62a", "a8304613", "fd469501",
                     "698098d8", "8b44f7af", "ffff5bb1", "895cd7be", "6b901122", "fd987193", "a679438e", "49b40821",
                     "f61e2562", "c040b340", "265e5a51", "e9b6c7aa", "d62f105d", "02441453", "d8a1e681", "e7d3fbc8",
                     "21e1cde6", "c33707d6", "f4d50d87", "455a14ed", "a9e3e905", "fcefa3f8", "676f02d9", "8d2a4c8a",
                     "fffa3942", "8771f681", "6d9d6122", "fde5380c", "a4beea44", "4bdecfa9", "f6bb4b60", "bebfbc70",
                     "289b7ec6", "eaa127fa", "d4ef3085", "04881d05", "d9d4d039", "e6db99e5", "1fa27cf8", "c4ac5665",
                     "f4292244", "432aff97", "ab9423a7", "fc93a039", "655b59c3", "8f0ccc92", "ffeff47d", "85845dd1",
                     "6fa87e4f", "fe2ce6e0", "a3014314", "4e0811a1", "f7537e82", "bd3af235", "2ad7d2bb", "eb86d391"};

    int s[16] = {6, 10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21};

    char temp[9];
    int i, j;
    int x[32], k = 0, t[32], g[32], hold[32];

    for (i = 48; i < 64; i++)
    {
        k = (7 * i) % 16;
        k = (k - 1) * 32;
        for (j = 0; j < 32; j++)
        {
            x[j] = text[k];
            k++;
        }

        for (j = 0; j < 8; j++)
            temp[j] = T[i][j];

        hex_to_binary(8, temp, t);

        for (j = 0; j < 32; j++)
            g[j] = fun(B[j], C[j], D[j], 4);

        add(g, A);
        add(x, A);
        add(t, A);
        clsr(A, s[i]);
        add(B, A);

        for (j = 0; j < 32; j++)
        {
            hold[j] = A[j];
        }
        for (j = 0; j < 32; j++)
        {
            A[j] = D[j];
        }
        for (j = 0; j < 32; j++)
        {
            D[j] = C[j];
        }
        for (j = 0; j < 32; j++)
        {
            C[j] = B[j];
        }
        for (j = 0; j < 32; j++)
        {
            B[j] = hold[j];
        }
    }
}

void padding(int n, int text[512])
{
    int Mlength[64], temp, val, i, j = 55, pbits = 0;
    double hold;
    temp = n;

    for (i = 0; i < 64; i++)
        Mlength[i] = 0;

    for (i = 8; i >= 0; i--)
    {
        hold = pow(2, i);
        val = (int)hold;
        Mlength[j] = (int)(temp / val);
        temp = temp % val;
        j++;
    }
    printf("Message length in bits\n");
    for (i = 0; i < 64; i++)
        printf("%d", Mlength[i]);
    printf("\n");

    pbits = 512 - 64 - n;

    text[n] = 1;
    for (i = n + 1; i < 448; i++)
        text[i] = 0;

    j = 0;
    for (i = 448; i < 512; i++)
    {
        text[i] = Mlength[j];
        j++;
    }
}
void to_binary(char a[512], int text[512], int n, int k)
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

void to_hex(int n, int arr[], int m)
{
    int i = 0, j, k;
    char result[m];
    int temp;
    j = 0;
    for (i = 0; i < n; i = i + 4)
    {
        temp = (((arr[i]) * 1000) + ((arr[i + 1]) * 100) + ((arr[i + 2]) * 10) + ((arr[i + 3]) * 1));
        switch (temp)
        {
        case 0:
            result[j] = '0';
            j++;
            break;

        case 1:
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
    puts(result);
}
void main()
{
    char arr[512], a[9] = {0, 1, 2, 3, 4, 5, 6, 7}, b[9] = {8, 9, 'A', 'B', 'C', 'D', 'E', 'F'};
    char c[9] = {'F', 'E', 'D', 'C', 'B', 'A', 9, 8};
    char d[9] = {7, 6, 5, 4, 3, 2, 1, 0};
    int A[32], B[32], C[32], D[32], ZA[32], ZB[32], ZC[32], ZD[32], result[128];
    int n, text[512], len, i, j;
    printf("Enter the Text to be Encrypted :\n");
    gets(arr);

    len = strlen(arr);

    n = 0;
    for (i = 0; i < len; i++)
    {
        to_binary(arr, text, n, i);
        n = n + 8;
    }

    printf("Input in Binary Format:\n");
    for (i = 0; i < n; i++)
        printf("%d", text[i]);

    printf("\n");

    padding(n, text);
    printf("Input after adding Padding Bits:\n");

    for (i = 0; i < 512; i++)
        printf("%d", text[i]);

    for (i = 0; i < 32; i++)
    {
        A[i] = 0;
        B[i] = 0;
        C[i] = 0;
        D[i] = 0;
        ZA[i] = 0;
        ZB[i] = 0;
        ZC[i] = 0;
        ZD[i] = 0;
    }

    hex_to_binary(8, d, D);
    for (i = 0; i < 32; i++)
        ;
    ZD[i] = D[i];

    hex_to_binary(8, c, C);
    for (i = 0; i < 32; i++)
        ;
    ZC[i] = C[i];

    hex_to_binary(8, b, B);
    for (i = 0; i < 32; i++)
        ;
    ZB[i] = B[i];

    hex_to_binary(8, a, A);
    for (i = 0; i < 32; i++)
        ;
    ZB[i] = B[i];

    MD5_round1(text, A, B, C, D);
    MD5_round2(text, A, B, C, D);
    MD5_round3(text, A, B, C, D);
    MD5_round4(text, A, B, C, D, result);

    add(ZA, A);
    add(ZB, B);
    add(ZC, C);
    add(ZD, D);

    j = 0;
    for (i = 0; i < 32; i++)
    {
        result[j] = A[i];
        j++;
    }

    for (i = 0; i < 32; i++)
    {
        result[j] = B[i];
        j++;
    }

    for (i = 0; i < 32; i++)
    {
        result[j] = C[i];
        j++;
    }

    for (i = 0; i < 32; i++)
    {
        result[j] = D[i];
        j++;
    }

    printf("\n");
    printf("Hash Function :\n");
    to_hex(128, result, 33);
}