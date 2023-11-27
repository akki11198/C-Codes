#include <stdio.h>
void main()
{
    int arr[50],temp[10],i,j,k,n,sum,flag=0,t1=0,t2=1,t3=2,count=0;
    printf("Enter the no of elements in array: \n");
    scanf("%d",&n);
    printf("Enter the Elements : \n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("Enter the Required Sum: \n");
    scanf("%d",&sum);

    for(i=0;i<n-2;i++)
    {
        for(j=i+1;j<n-1;j++)
        {
            for(k=j+1;k<n;k++)
            {
                if((arr[i] + arr[j] + arr[k]) == sum )
                {
                    count++;
                    temp[t1] = arr[i];
                    temp[t2] = arr[j];
                    temp[t3] = arr[k];
                    t1 = t1+3;
                    t2 = t2+3;
                    t3 = t3+3;
                }

            }
        }
    }
    if(count != 0)
    {
        i=0;
        printf("Sum is found!!\nThere are %d triplets:\n",count);
        while(i<(count*3))
        {
            printf("%d , %d and %d\n",temp[i],temp[i+1],temp[i+2]);
            i=i+3;
        }
    }
    else
    {
        printf("No Triplet with the Given Sum!!\n");
    }
    

}