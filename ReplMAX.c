#include <stdio.h>

void ReplMAX(int arr[],int n)
{
    int max,temp,i;
    max =  arr[n-1];
    arr[n-1] = 0; 
    for(i = n-2; i >= 0; i--)
    {
        temp = arr[i];
        arr[i] = max;
        if(max < temp)
        {
            max = temp;
        }           
    }
}
void main()
{
    int arr[20],i,n;
    printf("Enter the Size of the Array : \n");
    scanf("%d",&n);
    printf("Enter the Elements of the array : \n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);

    }
    printf("The Given Array is : \n");
    for(i=0;i<n;i++)
    {
        printf("%d  ",arr[i]);
    }
    ReplMAX(arr,n);
    printf("\nThe Array After replacing Every Element with the MAX Element on its Right : \n");
    printf("The Given Array is : \n");
    for(i=0;i<n;i++)
    {
        printf("%d  ",arr[i]);
    }
}