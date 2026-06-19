#include <stdio.h>

int main()
{
    int i, NOP, sum=0, count=0, y;
    int quant, wt=0, tat=0;
    int at[10], bt[10], temp[10];

    float avg_wt, avg_tat;

    printf("Total number of process: ");
    scanf("%d", &NOP);

    y = NOP;

    for(i=0;i<NOP;i++)
    {
        printf("\nArrival Time P%d: ", i+1);
        scanf("%d", &at[i]);

        printf("Burst Time P%d: ", i+1);
        scanf("%d", &bt[i]);

        temp[i] = bt[i];
    }

    printf("Enter Time Quantum: ");
    scanf("%d", &quant);

    for(sum=0,i=0;y!=0;)
    {
        if(temp[i] <= quant && temp[i] > 0)
        {
            sum += temp[i];
            temp[i] = 0;
            count = 1;
        }
        else if(temp[i] > 0)
        {
            temp[i] -= quant;
            sum += quant;
        }

        if(temp[i]==0 && count==1)
        {
            y--;
            wt += sum-at[i]-bt[i];
            tat += sum-at[i];
            count=0;
        }

        if(i==NOP-1)
            i=0;
        else if(at[i+1] <= sum)
            i++;
        else
            i=0;
    }

    avg_wt=(float)wt/NOP;
    avg_tat=(float)tat/NOP;

    printf("\nAverage Waiting Time = %.2f",avg_wt);
    printf("\nAverage Turnaround Time = %.2f\n",avg_tat);

    return 0;
}