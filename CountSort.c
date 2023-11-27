#include <stdio.h>  
void countsort(int a[], int k, int n)  
{  
    int i, j;  
    int b[100], c[100];  
    for (i = 0; i <= k; i++)  
        c[i] = 0;  
    for (j = 1; j <= n; j++)  
        c[a[j]] = c[a[j]] + 1;  
    for (i = 1; i <= k; i++)  
        c[i] = c[i] + c[i-1];  
    for (j = n; j >= 1; j--)  
    {  
        b[c[a[j]]] = a[j];  
        c[a[j]] = c[a[j]] - 1;  
    }  
    printf("The Sorted array is : ");  
    for (i = 1; i <= n; i++)  
        printf("%d ", b[i]);  
}  

int main()  
{  
    int n, k = 0, a[100], i;  
    scanf("%d", &n);  
    for (i = 1; i <= n; i++)  
    {  
        scanf("%d", &a[i]);  
        if (a[i] > k) {  
            k = a[i];  
        }  
    }  
    countsort(a, k, n); 

    return 0; 
}  