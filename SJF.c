#include <stdio.h>
void main()
{
    int bt[20], wt[20], tat[20], i, j, n, temp, p[20];
    float avg_wt = 0, avg_tat = 0,cpu_util;
    printf("Enter The Number of Processes :");
    scanf("%d", &n);
    printf("Enter Burst Time:\n");
    for (i = 0; i < n; i++)
    {
        printf("Process %d: ", i + 1);
        scanf("%d", &bt[i]);
        p[i] = i + 1;
    }
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (bt[j] > bt[j + 1])
            {
                temp = bt[j];
                bt[j] = bt[j + 1];
                bt[j + 1] = temp;

                temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }
    wt[0] = 0;
    for (i = 1; i < n; i++)
    {
        wt[i] = 0;
        for (j = 0; j < i; j++)
            wt[i] += bt[j];

        avg_wt += wt[i];
    }
    avg_wt = avg_wt / n;
    printf("Process\t    Burst Time\t  Waiting Time\t    Turnaround Time\n");
    for (i = 0; i < n; i++)
    {
        tat[i] = bt[i] + wt[i];
        avg_tat += tat[i];
        printf("%d\t\t%d\t\t%d\t\t\t%d\n", p[i], bt[i], wt[i], tat[i]);
    }
    avg_tat = avg_tat / n;
    cpu_util = (float)tat[n - 1] / ((float)tat[n - 1] + (float)(n - 1));
    printf("\nAverage Waiting Time=%f\n", avg_wt);
    printf("Average Turn Around Time=%f\n", avg_tat);
    printf("CPU Utilization : %f%%\n", cpu_util * 100);
}