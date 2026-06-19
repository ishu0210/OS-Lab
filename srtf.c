#include <stdio.h>

int main()
{
    int at[10], bt[10], pr[10];
    int n, i, j, temp;

    printf("Enter number of processes: ");
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        printf("Process %d\n",i+1);
        printf("Arrival Time: ");
        scanf("%d",&at[i]);

        printf("Burst Time: ");
        scanf("%d",&bt[i]);

        pr[i]=i+1;
    }

    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(bt[i] > bt[j])
            {
                temp=bt[i];
                bt[i]=bt[j];
                bt[j]=temp;

                temp=pr[i];
                pr[i]=pr[j];
                pr[j]=temp;
            }
        }
    }

    printf("\nExecution Order:\n");

    for(i=0;i<n;i++)
        printf("P%d ",pr[i]);

    return 0;
}