#include<stdio.h>
#include<stdlib.h>

void main()
{
    int i,j,a[10][10],tr[10][10],count=0,r,c;
    printf("Enter the dimension of the matrix: \n");
    scanf("%d %d", &r,&c);
    printf("Enter the Sparse Matrix:\n");
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            scanf("%d",&a[i][j]);
            if(a[i][j] == 0)
            count++;
        }

    }
    printf("The Entered Matrix Is:\n");
    for(i=0;i<r;i++)
    {
        
        for(j=0;j<c;j++)
        {
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
    if (count < ((r*c)/2))
    {
    printf("Not a sparse matrix\n");
    exit(0);
    }
    else
    {
        for(i=0;i<r;i++)
        {
            for(j=0;j<c;j++)
             {
                 tr[j][i] = a[i][j];
             }
        }
    }
    printf("The Transpose Of the Given Matrix Is:\n");
    for(i=0;i<c;i++)
    {
        for(j=0;j<r;j++)
        {
            printf("%d ",tr[i][j]);
        }
        printf("\n");
    }   
}