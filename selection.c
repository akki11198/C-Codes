#include <stdio.h>
int main()
{
int i, j, n, temp, a[100],min;
scanf("%d",&n);
for(i=0;i<n;i++)
scanf("%d",&a[i]);
for(i=0;i<n;i++)
{
    min = i;
for(j=i+1;j<n;j++)
{
if(a[i]>a[j])
min = j;
{
temp=a[i];
a[i]=a[min];
a[min]=temp;
}
}
}
printf("Sorted elements: ");
for(i=0;i<n;i++)
printf(" %d",a[i]);
}
