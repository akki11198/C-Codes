#include <stdio.h>
#include <string.h>
#include <math.h>

void main()
{
    int i,j,key[5][5],ikey[5][5],row,col,plen;
    int dev,c,h,k,n,p1[5][5],e1[5][5],d1[5][5];
    char p[20],e[20],d[20],clen;
 
    printf("Enter your plaintext : \n");
    gets(p);
    plen=strlen(p);

    printf("Dimension of key matrix : \n");
    scanf("%d",&row);
    col=row;
    j = row-(plen%row);

    if(plen%row !=0)
    {
        for(i=0;i<j;i++)
        {
            strcat(p,"x");
        }
    }
    plen=strlen(p);

    printf("ENTER ELEMENTS OF KEY MATRIX (row by row) : \n");
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            scanf("%d",&key[i][j]);
        }
    }
    printf("The key matrix is : \n");
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            printf("%d ",key[i][j]);
        }
        printf("\n");
    }
    dev = (plen)/row;
    printf("%d\n",dev);
    c=0;    
    n=0;
    for(i=0;i<dev;i++)
    {
        for(j=0;j<row;j++)
        {
            if(p[c]!='\0')
            {
                p1[i][j]=p[c]-97;
                c++;            
            }
        for(j=0;j<row;j++)
        { 
            e1[i][j]=0;
            for(k=0;k<row;k++)
            {
                e1[i][j]+=(key[i][k]*p1[k][j]);
            }
            
        }
    }
    }   
    printf("Plain Text : \n");
    printf("%s\n",p);

    printf("Encrypted Text : \n");
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            e1[i][j]=(e1[i][j]%26)+97;
            printf("%c",e1[i][j]);
        }
        
    }
    printf("\n");

    clen=strlen(e1);
    printf("%d\n",clen);
    dev = (clen)/row;
    printf("Enter inverse matrix values : \n");
    for(i=0;i<row;i++)
    {
        for(j=0;j<row;j++)
        {
            scanf("%d",&ikey[i][j]);
        }
    }
    c=0;
    n=0;
    for(i=0;i<dev;i++)
    {
        for(j=0;j<row;j++)
        {
            if(e[c]!='\0')
            {
                p1[i][j]=e[c]-97;
                c++;
            }
        }
        for(j=0;j<row;j++)
        {
            d1[i][j]=0;
            for(k=0;k<row;k++)
            {
                d1[i][j]+=(ikey[i][k]*p1[k][j]);
            }
            n++;
        }
    }
    printf("Encrypted Text : \n");
    printf("%s\n",e);

    printf("Decrypted Text : \n");
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            d1[i][j]=(d1[i][j]%26)+97;
            printf("%c",d1[i][j]);
        }
        
    }
}