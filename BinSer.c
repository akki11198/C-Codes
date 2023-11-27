#include <stdio.h>
int BinSer(int arr[], int f, int l, int k)
{
    int m;
    if(l>=f)
    {
        m=f+(l+f)/2;
        if(arr[m] == k)
        {
            return m;
        }
        else if( arr[m] < k)
        {
           BinSer(arr,m+1,l,k) ;
        }
        else
        {
            BinSer(arr,f,m-1,k);
        }
    }   
}
void main()
{
int a[100],n,i,key,loc=-1;
scanf("%d",&n);
for(i=0;i<n;i++)
scanf("%d",&a[i]);
scanf("%d",&key);
loc = BinSer(a,0,n-1,key);
if(loc != -1)
{
    printf("Element Found at Index %d",loc);
}
else
    printf("No Such Element");

}
