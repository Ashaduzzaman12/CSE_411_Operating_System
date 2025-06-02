//Round Robin

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int pid;
    int arrival_time;
    int burst_time;
    int remaining_time;
    int completion_time;
    int turnaround_time;
    int waiting_time;
} Process;

void preemptive_scheduling(Process processes[], int n)
{
    int current_time = 0;
    int completed = 0;
    int shortest_remaining_time_index = -1;
    int shortest_remaining_time = __INT_MAX__;

    while (completed != n)
    {
        shortest_remaining_time_index = -1;
        shortest_remaining_time = __INT_MAX__;

        for (int i = 0; i < n; i++)
        {
            if (processes[i].arrival_time <= current_time && processes[i].remaining_time > 0)
            {
                if (processes[i].remaining_time < shortest_remaining_time)
                {
                    shortest_remaining_time = processes[i].remaining_time;
                    shortest_remaining_time_index = i;
                }
            }
        }

        if (shortest_remaining_time_index == -1)
        {
            current_time++;
            continue;
        }

        processes[shortest_remaining_time_index].remaining_time--;
        current_time++;

        if (processes[shortest_remaining_time_index].remaining_time == 0)
        {
            completed++;
            processes[shortest_remaining_time_index].completion_time = current_time;
            processes[shortest_remaining_time_index].turnaround_time =
                processes[shortest_remaining_time_index].completion_time -
                processes[shortest_remaining_time_index].arrival_time;
            processes[shortest_remaining_time_index].waiting_time =
                processes[shortest_remaining_time_index].turnaround_time -
                processes[shortest_remaining_time_index].burst_time;
        }
    }
}

void print_results(Process processes[], int n)
{
    printf("PID\tArrival Time\tBurst Time\tCompletion Time\tTurnaround Time\tWaiting Time\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", processes[i].pid, processes[i].arrival_time,
               processes[i].burst_time, processes[i].completion_time,
               processes[i].turnaround_time, processes[i].waiting_time);
    }

    float avg_turnaround_time = 0;
    float avg_waiting_time = 0;
    for (int i = 0; i < n; i++)
    {
        avg_turnaround_time += processes[i].turnaround_time;
        avg_waiting_time += processes[i].waiting_time;
    }

    avg_turnaround_time /= n;
    avg_waiting_time /= n;

    printf("\nAverage Turnaround Time: %.2f\n", avg_turnaround_time);
    printf("Average Waiting Time: %.2f\n", avg_waiting_time);
}

int main()
{
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    Process processes[n];

    for (int i = 0; i < n; i++)
    {
        processes[i].pid = i + 1;
        printf("Enter arrival time for process %d: ", i + 1);
        scanf("%d", &processes[i].arrival_time);
        printf("Enter burst time for process %d: ", i + 1);
        scanf("%d", &processes[i].burst_time);
        processes[i].remaining_time = processes[i].burst_time;
    }

    preemptive_scheduling(processes, n);
    print_results(processes, n);

    return 0;
}

/*

5
2
6
1
3
4
2
0
5
6
4
*/
