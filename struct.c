#include <stdio.h>
typedef struct data
{
    int age;
    char Fname[50], ocp[20];
} dta;

void main()
{
    dta dt[10];
    FILE *fp;
    fp = fopen("Records.txt", "w+");
    int i, n;
    printf("Enter No of Records: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("Enter Age for Record no. %d: ", i + 1);
        scanf("%d", &dt[i].age);
        printf("Enter Name for Record no. %d: ", i + 1);
        scanf("%s", dt[i].Fname);
        printf("Enter Occupation  for Record no. %d: ", i + 1);
        scanf("%s", dt[i].ocp);
        fputs(dt[i].Fname, fp);
        putw(dt[i].age, fp);
        fputs(dt[i].ocp, fp);
    }

    if (fwrite != 0)
        printf("Contents to file written successfully !\n");
    printf("The Data in Records is:\n");
    for (i = 0; i < n; i++)
    {
        printf("Name: %s\nAge: %d\nOccupation: %s\n", dt[i].Fname, dt[i].age, dt[i].ocp);
    }
}