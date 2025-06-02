#include <stdio.h>

int main() {
    int p[10], at[10], bt[10], ct[10], tat[10], wt[10], priority[10], remaining_bt[10];
    int i, n, max_priority, max_index, current_time = 0, completed_count = 0;
    float total_tat = 0, total_wt = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter process IDs: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &p[i]);
    }

    printf("Enter %d arrival times: ", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &at[i]);
    }

    printf("Enter %d burst times: ", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &bt[i]);
        remaining_bt[i] = bt[i]; // Initialize remaining burst time
    }

    printf("Enter %d priority values (higher value = higher priority): ", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &priority[i]);
    }

    int completed[10] = {0};

    while (completed_count < n) {
        max_priority = -1;
        max_index = -1;

        // Find the highest priority proc


        \ess that has arrived and is not completed
        for (i = 0; i < n; i++) {
            if (at[i] <= current_time && remaining_bt[i] > 0) {
                if (priority[i] > max_priority || (priority[i] == max_priority && at[i] < at[max_index])) {
                    max_priority = priority[i];
                    max_index = i;
                }
            }
        }

        if (max_index == -1) {
            current_time++; // If no process is available, move time forward
        } else {
            remaining_bt[max_index]--; // Process for 1 time unit
            current_time++;

            // If process is completed
            if (remaining_bt[max_index] == 0) {
                ct[max_index] = current_time;
                tat[max_index] = ct[max_index] - at[max_index]; // TAT = CT - AT
                wt[max_index] = tat[max_index] - bt[max_index]; // WT = TAT - BT

                total_tat += tat[max_index];
                total_wt += wt[max_index];
                completed[max_index] = 1;
                completed_count++;
            }
        }
    }

    // Print the result
    printf("\nP\tAT\tBT\tPR\tCT\tTAT\tWT");
    for (i = 0; i < n; i++) {
        printf("\nP%d\t%d\t%d\t%d\t%d\t%d\t%d", p[i], at[i], bt[i], priority[i], ct[i], tat[i], wt[i]);
    }

    // Print average values
    printf("\n\nAverage Turnaround Time: %.2f", total_tat / n);
    printf("\nAverage Waiting Time: %.2f\n", total_wt / n);

    return 0;
}
