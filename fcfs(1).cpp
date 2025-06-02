#include <stdio.h>
int main(){

    int  p[10],at[10],bt[10],ct[10],tat[10],wt[10],i,j,temp=0,n;
    float awt=0,atat=0,total_tat=0,total_wt=0;
    printf("enter no of proccess you want:");
    scanf("%d",&n);
    printf("enter %d process:",n);
    for(i=0;i<n;i++)
    {
    scanf("%d",&p[i]);
    }
    printf("enter %d arrival time:",n);
    for(i=0;i<n;i++)
    {
    scanf("%d",&at[i]);
    }
    printf("enter %d burst time:",n);
    for(i=0;i<n;i++)
    {
    scanf("%d",&bt[i]);
    }

    
    // Sorting based on Arrival Time (Bubble Sort)
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (at[j] > at[j + 1]) {
                // Swap Arrival Time
                temp = at[j];
                at[j] = at[j + 1];
                at[j + 1] = temp;
                
                // Swap Burst Time
                temp = bt[j];
                bt[j] = bt[j + 1];
                bt[j + 1] = temp;

                // Swap Process ID
                temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }

    // Calculate Completion Time (CT)
    int time = 0; // Tracks CPU time
    for (i = 0; i < n; i++) {
        if (time < at[i]) {
            time = at[i]; // Handling CPU idle time
        }
        ct[i] = time + bt[i]; // Completion Time
        time = ct[i]; // Update current time
    }

    // Calculate Turnaround Time (TAT) and Waiting Time (WT)
    for (i = 0; i < n; i++) {
        tat[i] = ct[i] - at[i]; // TAT = CT - AT
        wt[i] = tat[i] - bt[i]; // WT = TAT - BT
        total_tat += tat[i]; // Accumulate for average
        total_wt += wt[i];   // Accumulate for average
    }

    // Print the result
    printf("\nP\tAT\tBT\tCT\tTAT\tWT");
    for (i = 0; i < n; i++) {
        printf("\nP%d\t%d\t%d\t%d\t%d\t%d", p[i], at[i], bt[i], ct[i], tat[i], wt[i]);
    }

    // Print average values
    printf("\n\nAverage Turnaround Time: %.2f", total_tat / n);
    printf("\nAverage Waiting Time: %.2f\n", total_wt / n);

    return 0;
}

