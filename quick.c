#include<stdio.h>
void quicksort(int a[100],int f,int l)
{
int i, j, pivot, temp;
if(f<l)
{
pivot=f;
i=f;
j=l;
while(i<j)
{
while(a[i]<=a[pivot]&&i<l)
i++;
while(a[j]>a[pivot])
j--;
if(i<j)
{
temp=a[i];
a[i]=a[j];
a[j]=temp;
}
}
temp=a[pivot];
a[pivot]=a[j];
a[j]=temp;
quicksort(a,f,j-1);
quicksort(a,j+1,l);
}
}
int main()
{
int i, count, a[100];
scanf("%d",&count);
for(i=0;i<count;i++)
scanf("%d",&a[i]);
quicksort(a,0,count-1);
printf("Order of Sorted elements: ");
for(i=0;i<count;i++)
printf(" %d",a[i]);
}
