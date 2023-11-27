#include<stdio.h>
void position(int a[])
{
    int low,high,mid,pos;
    while(a[high]==0)
    {
        low=high;
        high=2*high;
    }
    while(low<=high)
    {
    mid=(low+high)/2;
    if(a[mid]==1&& (a[mid-1]==0||mid==0))
    pos=mid;
    else if(a[mid]==1)
    high=mid-1;
    else
    low=mid+1;
    }
    printf("1s first occurance is at index: %d",pos);
}
void main()
{
   
    int arr[100], n,j;
    printf("Enter the no of elementd to be inserted in array: ");
    scanf("%d",&n);
    printf("Enter the elements:\n");
    for(j=0;j<n;j++)
    scanf("%d",&arr[j]);
    position(arr);
}