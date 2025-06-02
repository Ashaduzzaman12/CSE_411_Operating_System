#include <stdio.h>
#include <limits.h>

int main() {
    int n, i, j, smallest, time = 0, completed = 0;
    int p[10], at[10], bt[10], remaining_bt[10], ct[10], tat[10], wt[10];
    float total_tat = 0, total_wt = 0;
    
    printf("Enter number of processes: ");
    scanf("%d", &n);
    
    printf("Enter process IDs: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &p[i]);
    }
    
    printf("Enter arrival times: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &at[i]);
    }
    
    printf("Enter burst times: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &bt[i]);
        remaining_bt[i] = bt[i];
    }
    
    int completed_flag[10] = {0};
    
    while (completed < n) {
        smallest = -1;
        int min_bt = INT_MAX;
        
        for (i = 0; i < n; i++) {
            if (at[i] <= time && remaining_bt[i] > 0 && remaining_bt[i] < min_bt) {
                min_bt = remaining_bt[i];
                smallest = i;
            }
        }
        
        if (smallest == -1) {
            time++;
            continue;
        }
        
        remaining_bt[smallest]--;
        time++;
        
        if (remaining_bt[smallest] == 0) {
            completed++;
            ct[smallest] = time;
            tat[smallest] = ct[smallest] - at[smallest];
            wt[smallest] = tat[smallest] - bt[smallest];
            total_tat += tat[smallest];
            total_wt += wt[smallest];
        }
    }
    
    printf("\nP\tAT\tBT\tCT\tTAT\tWT");
    for (i = 0; i < n; i++) {
        printf("\nP%d\t%d\t%d\t%d\t%d\t%d", p[i], at[i], bt[i], ct[i], tat[i], wt[i]);
    }
    
    printf("\n\nAverage Turnaround Time: %.2f", total_tat / n);
    printf("\nAverage Waiting Time: %.2f\n", total_wt / n);
    
    return 0;
}

