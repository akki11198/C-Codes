#include <stdio.h>
int findlarge(int a[], int n)
{
int i;
int largest = a[0];
for (i=1;i<n;i++) 
{
 if (a[i] > largest)
 largest = a[i];
}
return largest;
}
void countsort(int a[], int n, int d)
{
int b[n]; 
int i, count[10] = { 0 };
for (i = 0; i < n; i++)
count[(a[i] / d) % 10]++; 
for (i = 1; i < 10; i++) 
count[i] += count[i - 1]; 
for(i = n - 1; i >= 0; i--) 
{
b[count[(a[i] / d) % 10] - 1] = a[i];
count[(a[i] / d) % 10]--;
}
for (i = 0; i < n; i++)
a[i] = b[i];
} 

void radsort(int a[], int n)
{
int m = findlarge(a, n);
int d;
for (d = 1; m / d > 0; d *= 10)
countsort(a, n, d);
}
int main()
{
int n, max = 0, a[100], i;
printf("Enter number of elements:  ");
scanf("%d", &n);
for (i = 0; i < n; i++)
{
 scanf("%d", &a[i]);
}
 radsort(a,n);
printf("The Sorted array is : \n");
for(i=0;i<n;i++)
printf("%d\n", a[i]);

 return 0;
}