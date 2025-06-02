#include <stdio.h>

int main() {
    int p[10], at[10], bt[10], ct[10], tat[10], wt[10], priority[10], completed[10] = {0};
    int i, n, min_priority, min_index, current_time = 0, completed_count = 0;
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
    }

    printf("Enter %d priority values (lower value = higher priority): ", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &priority[i]);
    }

    // Process selection based on non-preemptive priority scheduling
    while (completed_count < n) {
        min_priority = 9999; // Set a large number for comparison
        min_index = -1;

        // Find the highest priority process that has arrived and is not completed
        for (i = 0; i < n; i++) {
            if (at[i] <= current_time && !completed[i]) { // Process must have arrived and not be completed
                if (priority[i] < min_priority || (priority[i] == min_priority && at[i] < at[min_index])) {
                    min_priority = priority[i];
                    min_index = i;
                }
            }
        }

        if (min_index == -1) {
            // No process is available, move time forward
            current_time++;
        } else {
            // Process the selected job
            ct[min_index] = current_time + bt[min_index];
            tat[min_index] = ct[min_index] - at[min_index]; // TAT = CT - AT
            wt[min_index] = tat[min_index] - bt[min_index]; // WT = TAT - BT

            // Update total values for averages
            total_tat += tat[min_index];
            total_wt += wt[min_index];

            // Mark as completed
            completed[min_index] = 1;
            completed_count++;

            // Move time forward
            current_time = ct[min_index];
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
