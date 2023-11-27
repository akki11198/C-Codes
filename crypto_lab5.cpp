#include <iostream>
#include <cstring>

using namespace std;

void hex_to_bin(char input[], char output[])
{
    int i = 0;
    while (input[i]) {
        switch (input[i]) {
        case '0':
            strcat(output, "0000");
            break;
        case '1':
            strcat(output, "0001");
            break;
        case '2':
            strcat(output, "0010");
            break;
        case '3':
            strcat(output, "0011");
            break;
        case '4':
            strcat(output, "0100");
            break;
        case '5':
            strcat(output, "0101");
            break;
        case '6':
            strcat(output, "0110");
            break;
        case '7':
            strcat(output, "0111");
            break;
        case '8':
            strcat(output, "1000");
            break;
        case '9':
            strcat(output, "1001");
            break;
        case 'A':
        case 'a':
            strcat(output, "1010");
            break;
        case 'B':
        case 'b':
            strcat(output, "1011");
            break;
        case 'C':
        case 'c':
            strcat(output, "1100");
            break;
        case 'D':
        case 'd':
            strcat(output, "1101");
            break;
        case 'E':
        case 'e':
            strcat(output, "1110");
            break;
        case 'F':
        case 'f':
            strcat(output, "1111");
            break;
        default:
            cout << "Invalid hexadecimal digit : " << input[i];
            exit(0);
        }
        i++;
    }
}

char bin_to_hex(char input[])
{
    int i, j, f;
    char pattern_bin[16][5] = {"0000", "0001", "0010", "0011", "0100", "0101", "0110", "0111", "1000", "1001", "1010", "1011", "1100", "1101", "1110", "1111"};
    for(i = 0; i < 16; i++)
    {
        f = 1;
        for(j = 0; pattern_bin[i][j] != '\0'; j++)
        {
            if(pattern_bin[i][j] != input[j])
                f = 0;
        }
        if(f == 1)
        {
            switch (i) {
            case 0:
                return '0';
                break;
            case 1:
                return '1';
                break;
            case 2:
                return '2';
                break;
            case 3:
                return '3';
                break;
            case 4:
                return '4';
                break;
            case 5:
                return '5';
                break;
            case 6:
                return '6';
                break;
            case 7:
                return '7';
                break;
            case 8:
                return '8';
                break;
            case 9:
                return '9';
                break;
            case 10:
                return 'A';
                break;
            case 11:
                return 'B';
                break;
            case 12:
                return 'C';
                break;
            case 13:
                return 'D';
                break;
            case 14:
                return 'E';
                break;
            case 15:
                return 'F';
                break;
            default:
                cout << "Invalid bit string ";
            }
        }
    }
}

void dec_to_bin(int input, char output[])
{
    switch (input) {
    case 0:
        strcat(output, "0000");
        break;
    case 1:
        strcat(output, "0001");
        break;
    case 2:
        strcat(output, "0010");
        break;
    case 3:
        strcat(output, "0011");
        break;
    case 4:
        strcat(output, "0100");
        break;
    case 5:
        strcat(output, "0101");
        break;
    case 6:
        strcat(output, "0110");
        break;
    case 7:
        strcat(output, "0111");
        break;
    case 8:
        strcat(output, "1000");
        break;
    case 9:
        strcat(output, "1001");
        break;
    case 10:
        strcat(output, "1010");
        break;
    case 11:
        strcat(output, "1011");
        break;
    case 12:
        strcat(output, "1100");
        break;
    case 13:
        strcat(output, "1101");
        break;
    case 14:
        strcat(output, "1110");
        break;
    case 15:
        strcat(output, "1111");
        break;
    default:
        cout << "Invalid decimal digit " << input;
    }
}

void left_shift(char arr[])
{
    int i;
    char temp = arr[0];
    for (i = 0; i < 27; i++)
        arr[i] = arr[i + 1];
    arr[i] = temp;
    temp = arr[28];
    for (i = 28; i < 55; i++)
        arr[i] = arr[i + 1];
    arr[i] = temp;
}

void display(char arr[])
{
    int i;
    for(i = 0; arr[i]!='\0'; i++)
        cout << arr[i];
    cout << "\n";
}

void XOR(char input1[], char input2[])
{
    int i;
    for(i = 0; input1[i] != '\0'; i++)
    {
        if(input1[i] == input2[i])
            input1[i] = '0';
        else
            input1[i] = '1';
    }
}

int pattern_s_matcher(char input[])
{
    int i, j, f;
    char pattern_s[64][7] = {"000000", "000010", "000100", "000110", "001000", "001010", "001100", "001110", "010000", "010010", "010100", "010110", "011000", "011010", "011100", "011110", "000001", "000011", "000101", "000111", "001001", "001011", "001101", "001111", "010001", "010011", "010101", "010111", "011001", "011011", "011101", "011111", "100000", "100010", "100100", "100110", "101000", "101010", "101100", "101110", "110000", "110010", "110100", "110110", "111000", "111010", "111100", "111110", "100001", "100011", "100101", "100111", "101001", "101011", "101101", "101111", "110001", "110011", "110101", "110111", "111001", "111011", "111101", "111111"};
    for(i = 0; i < 64; i++)
    {
        f = 1;
        for(j = 0; pattern_s[i][j] != '\0'; j++)
        {
            if(pattern_s[i][j] != input[j])
                f = 0;
        }
        if(f == 1)
            return i;
    }
}

class Key
{
public:
    int pd[56] = {57, 49, 41, 33, 25, 17, 9, 1, 58, 50, 42, 34, 26, 18, 10, 2, 59, 51, 43, 35, 27, 19, 11, 3, 60, 52, 44, 36, 63, 55, 47, 39, 31, 23, 15, 7, 62, 54, 46, 38, 30, 22, 14, 6, 61, 53, 45, 37, 29, 21, 13, 5, 28, 20, 12, 4};
    int it[16] = {1, 1, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 1};
    int cp[48] = {14, 17, 11, 24, 1, 5, 3, 28, 15, 6, 21, 10, 23, 19, 12, 4, 26, 8, 16, 7, 27, 20, 13, 2, 41, 52, 31, 37, 47, 55, 30, 40, 51, 45, 33, 48, 44, 49, 39, 56, 34, 53, 46, 42, 50, 36, 29, 32};
    char key_hex[17] = "", key_binary[65] = "", key_binary_derived[57] = "", k1[49] = "", k2[49] = "", k3[49] = "", k4[49] = "", k5[49] = "", k6[49] = "", k7[49] = "", k8[49] = "", k9[49] = "", k10[49] = "", k11[49] = "", k12[49] = "", k13[49] = "", k14[49] = "", k15[49] = "", k16[49] = "";
    int i;
    Key()
    {
        for(i = 0; i < 56; i++)
            pd[i] -= 1;
        for(i = 0; i < 48; i++)
            cp[i] -= 1;
    }
    void input()
    {
        cin.getline(key_hex,17);
        hex_to_bin(key_hex, key_binary);
        for(i = 0; i < 56; i++)
            key_binary_derived[i] = key_binary[pd[i]];
        key_binary_derived[i] = '\0';
        for(i = 0; i < it[0]; i++)
            left_shift(key_binary_derived);
        for(i = 0; i < 48; i++)
            k1[i] = key_binary_derived[cp[i]];
        k1[i] = '\0';
        for(i = 0; i < it[1]; i++)
            left_shift(key_binary_derived);
        for(i = 0; i < 48; i++)
            k2[i] = key_binary_derived[cp[i]];
        k2[i] = '\0';
        for(i = 0; i < it[2]; i++)
            left_shift(key_binary_derived);
        for(i = 0; i < 48; i++)
            k3[i] = key_binary_derived[cp[i]];
        k3[i] = '\0';
        for(i = 0; i < it[3]; i++)
            left_shift(key_binary_derived);
        for(i = 0; i < 48; i++)
            k4[i] = key_binary_derived[cp[i]];
        k4[i] = '\0';
        for(i = 0; i < it[4]; i++)
            left_shift(key_binary_derived);
        for(i = 0; i < 48; i++)
            k5[i] = key_binary_derived[cp[i]];
        k5[i] = '\0';
        for(i = 0; i < it[5]; i++)
            left_shift(key_binary_derived);
        for(i = 0; i < 48; i++)
            k6[i] = key_binary_derived[cp[i]];
        k6[i] = '\0';
        for(i = 0; i < it[6]; i++)
            left_shift(key_binary_derived);
        for(i = 0; i < 48; i++)
            k7[i] = key_binary_derived[cp[i]];
        k7[i] = '\0';
        for(i = 0; i < it[7]; i++)
            left_shift(key_binary_derived);
        for(i = 0; i < 48; i++)
            k8[i] = key_binary_derived[cp[i]];
        k8[i] = '\0';
        for(i = 0; i < it[8]; i++)
            left_shift(key_binary_derived);
        for(i = 0; i < 48; i++)
            k9[i] = key_binary_derived[cp[i]];
        k9[i] = '\0';
        for(i = 0; i < it[9]; i++)
            left_shift(key_binary_derived);
        for(i = 0; i < 48; i++)
            k10[i] = key_binary_derived[cp[i]];
        k10[i] = '\0';
        for(i = 0; i < it[10]; i++)
            left_shift(key_binary_derived);
        for(i = 0; i < 48; i++)
            k11[i] = key_binary_derived[cp[i]];
        k11[i] = '\0';
        for(i = 0; i < it[11]; i++)
            left_shift(key_binary_derived);
        for(i = 0; i < 48; i++)
            k12[i] = key_binary_derived[cp[i]];
        k12[i] = '\0';
        for(i = 0; i < it[12]; i++)
            left_shift(key_binary_derived);
        for(i = 0; i < 48; i++)
            k13[i] = key_binary_derived[cp[i]];
        k13[i] = '\0';
        for(i = 0; i < it[13]; i++)
            left_shift(key_binary_derived);
        for(i = 0; i < 48; i++)
            k14[i] = key_binary_derived[cp[i]];
        k14[i] = '\0';
        for(i = 0; i < it[14]; i++)
            left_shift(key_binary_derived);
        for(i = 0; i < 48; i++)
            k15[i] = key_binary_derived[cp[i]];
        k15[i] = '\0';
        for(i = 0; i < it[15]; i++)
            left_shift(key_binary_derived);
        for(i = 0; i < 48; i++)
            k16[i] = key_binary_derived[cp[i]];
        k16[i] = '\0';
    }
};

class DesEncryption
{
public:
    int ip[64] = {58, 50, 42, 34, 26, 18, 10, 2, 60, 52, 44, 36, 28, 20, 12, 4, 62, 54, 46, 38, 30, 22, 14, 6, 64, 56, 48, 40, 32, 24, 16, 8, 57, 49, 41, 33, 25, 17, 9, 1, 59, 51, 43, 35, 27, 19, 11, 3, 61, 53, 45, 37, 29, 21, 13, 5, 63, 55, 47, 39, 31, 23, 15, 7};
    int fp[64];
    int ep[48] = {32, 1, 2, 3, 4, 5, 4, 5, 6, 7, 8, 9, 8, 9, 10, 11, 12, 13, 12, 13, 14, 15, 16, 17, 16, 17, 18, 19, 20, 21, 20, 21, 22, 23, 24, 25, 24, 25, 26, 27, 28, 29, 28, 29, 30, 31, 32, 1};
    int sp[32] = {16, 7, 20, 21, 29, 12, 28, 17, 1, 15, 23, 26, 5, 18, 31, 10, 2, 8, 24, 14, 32, 27, 3, 9, 19, 13, 30, 6, 22, 11, 4, 25};
    int s1[64] = {14, 4, 13, 1, 2, 15, 11, 8, 3, 10, 6, 12, 5, 9, 0, 7, 0, 15, 7, 4, 14, 2, 13, 1, 10, 6, 12, 11, 9, 5, 3, 8, 4, 1, 14, 8, 13, 6, 2, 11, 15, 12, 9, 7, 3, 10, 5, 0, 15, 12, 8, 2, 4, 9, 1, 7, 5, 11, 3, 14, 10, 0, 6, 13};
    int s2[64] = {15, 1, 8, 14, 6, 11, 3, 4, 9, 7, 2, 13, 12, 0, 5, 10, 3, 13, 4, 7, 15, 2, 8, 14, 12, 0, 1, 10, 6, 9, 11, 5, 0, 14, 7, 11, 10, 4, 13, 1, 5, 8, 12, 6, 9, 3, 2, 15, 13, 8, 10, 1, 3, 15, 4, 2, 11, 6, 7, 12, 0, 5, 14, 9};
    int s3[64] = {10, 0, 9, 14, 6, 3, 15, 5, 1, 13, 12, 7, 11, 4, 2, 8, 13, 7, 0, 9, 3, 4, 6, 10, 2, 8, 5, 14, 12, 11, 15, 1, 13, 6, 4, 9, 8, 15, 3, 0, 11, 1, 2, 12, 5, 10, 14, 7, 1, 10, 13, 0, 6, 9, 8, 7, 4, 15, 14, 3, 11, 5, 2, 12};
    int s4[64] = {7, 13, 14, 3, 0, 6, 9, 10, 1, 2, 8, 5, 11, 12, 4, 15, 13, 8, 11, 5, 6, 15, 0, 3, 4, 7, 2, 12, 1, 10, 14, 9, 10, 6, 9, 0, 12, 11, 7, 13, 15, 1, 3, 14, 5, 2, 8, 4, 3, 15, 0, 6, 10, 1, 13, 8, 9, 4, 5, 11, 12, 7, 2, 14};
    int s5[64] = {2, 12, 4, 1, 7, 10, 11, 6, 8, 5, 3, 15, 13, 0, 14, 9, 14, 11, 2, 12, 4, 7, 13, 1, 5, 0, 15, 10, 3, 9, 8, 6, 4, 2, 1, 11, 10, 13, 7, 8, 15, 9, 12, 5, 6, 3, 0, 14, 11, 8, 12, 7, 1, 14, 2, 13, 6, 15, 0, 9, 10, 4, 5, 3};
    int s6[64] = {12, 1, 10, 15, 9, 2, 6, 8, 0, 13, 3, 4, 14, 7, 5, 11, 10, 15, 4, 2, 7, 12, 9, 5, 6, 1, 13, 14, 0, 11, 3, 8, 9, 14, 15, 5, 2, 8, 12, 3, 7, 0, 4, 10, 1, 13, 11, 6, 4, 3, 2, 12, 9, 5, 15, 10, 11, 14, 1, 7, 6, 0, 8, 13};
    int s7[64] = {4, 11, 2, 14, 15, 0, 8, 13, 3, 12, 9, 7, 5, 10, 6, 1, 13, 0, 11, 7, 4, 9, 1, 10, 14, 3, 5, 12, 2, 15, 8, 6, 1, 4, 11, 13, 12, 3, 7, 14, 10, 15, 6, 8, 0, 5, 9, 2, 6, 11, 13, 8, 1, 4, 10, 7, 9, 5, 0, 15, 14, 2, 3, 12};
    int s8[64] = {13, 2, 8, 4, 6, 15, 11, 1, 10, 9, 3, 14, 5, 0, 12, 7, 1, 15, 13, 8, 10, 3, 7, 4, 12, 5, 6, 11, 0, 14, 9, 2, 7, 11, 4, 1, 9, 12, 14, 2, 0, 12, 10, 13, 15, 3, 5, 8, 2, 1, 14, 7, 4, 10, 8, 13, 15, 8, 9, 0, 3, 5, 6, 11};
    char ciphertext_hex[17] = "", ciphertext_binary[65] ="", ciphertext_binary_derived[65] ="", plaintext_hex[17] = "", plaintext_binary[65] = "", plaintext_binary_derived[65] = "", plaintext_binary_derived_left[33] = "", plaintext_binary_derived_right[33] = "";
    int i, j, c;
    DesEncryption()
    {
        for(i = 0; i < 64; i++)
            ip[i] -= 1;
        for(i = 0; i < 64; i++)
            fp[ip[i]] = i;
        for(i = 0; i < 48; i++)
            ep[i] -= 1;
        for(i = 0; i < 32; i++)
            sp[i] -= 1;
    }

    void input()
    {
        cin.getline(plaintext_hex,17);
        hex_to_bin(plaintext_hex, plaintext_binary);
        for(i = 0; i < 64; i++)
            plaintext_binary_derived[i] = plaintext_binary[ip[i]];
        plaintext_binary_derived[i] = '\0';
        for(i = 0; i < 32; i++)
        {
            plaintext_binary_derived_left[i] = plaintext_binary[ip[i]];
            plaintext_binary_derived_right[i] = plaintext_binary[ip[i+32]];
        }
        plaintext_binary_derived_left[i] = '\0';
        plaintext_binary_derived_right[i] = '\0';
    }
    void des_function(char k[])
    {
        char r_ep[49] = "", r_s[33] = "", r_sp[33] = "", temp[7] = "";
        for(i = 0; i < 48; i++)
            r_ep[i] = plaintext_binary_derived_right[ep[i]];
        r_ep[i] = '\0';
        XOR(r_ep, k);
        for(i = 0; i < 6; i++)
            temp[i] = r_ep[i];
        temp[i] = '\0';
        i = pattern_s_matcher(temp);
        dec_to_bin(s1[i], r_s);
        for(i = 0; i < 6; i++)
            temp[i] = r_ep[i+6];
        temp[i] = '\0';
        i = pattern_s_matcher(temp);
        dec_to_bin(s2[i], r_s);
        for(i = 0; i < 6; i++)
            temp[i] = r_ep[i+12];
        temp[i] = '\0';
        i = pattern_s_matcher(temp);
        dec_to_bin(s3[i], r_s);
        for(i = 0; i < 6; i++)
            temp[i] = r_ep[i+18];
        temp[i] = '\0';
        i = pattern_s_matcher(temp);
        dec_to_bin(s4[i], r_s);
        for(i = 0; i < 6; i++)
            temp[i] = r_ep[i+24];
        temp[i] = '\0';
        i = pattern_s_matcher(temp);
        dec_to_bin(s5[i], r_s);
        for(i = 0; i < 6; i++)
            temp[i] = r_ep[i+30];
        temp[i] = '\0';
        i = pattern_s_matcher(temp);
        dec_to_bin(s6[i], r_s);
        for(i = 0; i < 6; i++)
            temp[i] = r_ep[i+36];
        temp[i] = '\0';
        i = pattern_s_matcher(temp);
        dec_to_bin(s7[i], r_s);
        for(i = 0; i < 6; i++)
            temp[i] = r_ep[i+42];
        temp[i] = '\0';
        i = pattern_s_matcher(temp);
        dec_to_bin(s8[i], r_s);
        for(i = 0; i < 32; i++)
            r_sp[i] = r_s[sp[i]];
        r_sp[i] = '\0';
        XOR(r_sp, plaintext_binary_derived_left);
        strcpy(plaintext_binary_derived_left, plaintext_binary_derived_right);
        strcpy(plaintext_binary_derived_right, r_sp);
    }
    void print()
    {
        char temp[5] = "";
        for(i = 0; i < 8; i++)
        {
            c = 0;
            for(j = 4 * i; j < 4 * i + 4; j++)
                temp[c++] = plaintext_binary_derived_right[j];
            temp[c] = '\0';
            ciphertext_hex[i] = bin_to_hex(temp);
        }
        for(i = 0; i < 8; i++)
        {
            c = 0;
            for(j = 4 * i; j < 4 * i + 4; j++)
                temp[c++] = plaintext_binary_derived_left[j];
            temp[c] = '\0';
            ciphertext_hex[i+8] = bin_to_hex(temp);
        }
        ciphertext_hex[i+8] = '\0';
        display(ciphertext_hex);
    }
    void output()
    {
        char temp[5] = "";
        hex_to_bin(ciphertext_hex, ciphertext_binary);
        for(i = 0; i < 64; i++)
            ciphertext_binary_derived[i] = ciphertext_binary[fp[i]];
        for(i = 0; i < 16; i++)
        {
            c = 0;
            for(j = 4 * i; j < 4 * i + 4; j++)
                temp[c++] = ciphertext_binary_derived[j];
            temp[c] = '\0';
            ciphertext_hex[i] = bin_to_hex(temp);
        }
        ciphertext_hex[i] = '\0';
        display(ciphertext_hex);
    }
};

int main()
{
    int i;
    Key key;
    cout << "Enter Key (64 bit hexadecimal) : ";
    key.input();
    DesEncryption desencryption;
    cout << "Enter Plaintext (64 bit hexadecimal) : ";
    desencryption.input();
    cout << "R0L0_E (64 bit hexadecimal) : ";
    desencryption.print();
    desencryption.des_function(key.k1);
    cout << "R1L1_E (64 bit hexadecimal) : ";
    desencryption.print();
    desencryption.des_function(key.k2);
    cout << "R2L2_E (64 bit hexadecimal) : ";
    desencryption.print();
    desencryption.des_function(key.k3);
    cout << "R3L3_E (64 bit hexadecimal) : ";
    desencryption.print();
    desencryption.des_function(key.k4);
    cout << "R4L4_E (64 bit hexadecimal) : ";
    desencryption.print();
    desencryption.des_function(key.k5);
    cout << "R5L5_E (64 bit hexadecimal) : ";
    desencryption.print();
    desencryption.des_function(key.k6);
    cout << "R6L6_E (64 bit hexadecimal) : ";
    desencryption.print();
    desencryption.des_function(key.k7);
    cout << "R7L7_E (64 bit hexadecimal) : ";
    desencryption.print();
    desencryption.des_function(key.k8);
    cout << "R8L8_E (64 bit hexadecimal) : ";
    desencryption.print();
    desencryption.des_function(key.k9);
    cout << "R9L9_E (64 bit hexadecimal) : ";
    desencryption.print();
    desencryption.des_function(key.k10);
    cout << "R10L10_E (64 bit hexadecimal) : ";
    desencryption.print();
    desencryption.des_function(key.k11);
    cout << "R11L11_E (64 bit hexadecimal) : ";
    desencryption.print();
    desencryption.des_function(key.k12);
    cout << "R12L12_E (64 bit hexadecimal) : ";
    desencryption.print();
    desencryption.des_function(key.k13);
    cout << "R13L13_E (64 bit hexadecimal) : ";
    desencryption.print();
    desencryption.des_function(key.k14);
    cout << "R14L14_E (64 bit hexadecimal) : ";
    desencryption.print();
    desencryption.des_function(key.k15);
    cout << "R15L15_E (64 bit hexadecimal) : ";
    desencryption.print();
    desencryption.des_function(key.k16);
    cout << "R16L16_E (64 bit hexadecimal) : ";
    desencryption.print();
    cout << "Ciphertext (64 bit hexadecimal) : ";
    desencryption.output();
    return 0;
}
