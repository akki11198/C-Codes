#include<stdio.h>
#include<stdlib.h>

void main()
{
    int i,j,a[10][10],b[10][10],p[10][10],r1=0,c1=0,r2=0,c2=0,count=0;

    printf("Dimensions of first sparse matrix: ");
    scanf("%d %d",&r1,&c1);
    printf("Enter the elements of matrix: \n");
    for(i=0;i<r1;i++)
    {
        for(j=0;j<c1;j++)
        {
            scanf("%d",&a[i][j]);
            if (a[i][j]==0)
            count++;
        
        }
    }
    if (count < ((r1*c1)/2))
    {
    printf("Not a sparse matrix");
    exit(0);
    }
    else
    {
     printf("The First Matrix is:");
    for(i=0;i<r1;i++)
    {
        printf("\n");
        for(j=0;j<c1;j++)
        {
            printf("%d ",a[i][j]);
        }
    }
    }
    printf("\nDimensions of second sparse matrix: ");
    scanf("%d %d",&r2,&c2);
      if(c1 != r2)
    {
        printf("The matrices are not of proper order and cant be multiplied\n");
        exit(0);
    }
    printf("Enter the elements of matrix: \n");
    for(i=0;i<r2;i++)
    {
        for(j=0;j<c2;j++)
        {
            scanf("%d",&b[i][j]);
            if (b[i][j]==0)
            count++;
        }
    }
    if (count < ((r2*c2)/2))
    {
    printf("Not a sparse matrix");
    exit(0);
    }
    else
    {
    printf("The Second Matrix is:");
    for(i=0;i<r2;i++)
    {
        printf("\n");
        for(j=0;j<c2;j++)
        {
            printf("%d ",b[i][j]);
        }
    }
    }
    for(i=0;i<r1;i++)
    {
        for(j=0;j<c2;j++)
        {
            p[i][j] = 0;
        }
    }
    for (int i = 0; i < r1; i++)
     {
      for (int j = 0; j < c2; j++) 
      {
         for (int k = 0; k < c1; k++) 
         {
            p[i][j] += a[i][k] * b[k][j];
         }
      }
   }
   printf("\nThe Product is:\n");
   for (int i = 0; i < r1; i++)
     {
      for (int j = 0; j < c2; j++) 
      {
          printf("%d ",p[i][j]);
      }
      printf("\n");
     
    }
}

    
      