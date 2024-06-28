#include <stdio.h>
#include <stdbool.h>

typedef struct {
    int pid;             // Process ID
    int burst_time;      // Burst Time
    int arrival_time;    // Arrival Time
    int waiting_time;    // Waiting Time
    int turnaround_time; // Turnaround Time
    int remaining_time;  // Remaining Time
} Process;

void calculateTimes(Process processes[], int n, int quantum) {
    int current_time = 0;
    int completed = 0;
    bool found = false;

    while (completed != n) {
        found = false;
        for (int i = 0; i < n; i++) {
            if (processes[i].arrival_time <= current_time && processes[i].remaining_time > 0) {
                found = true;
                if (processes[i].remaining_time > quantum) {
                    current_time += quantum;
                    processes[i].remaining_time -= quantum;
                } else {
                    current_time += processes[i].remaining_time;
                    processes[i].remaining_time = 0;
                    processes[i].turnaround_time = current_time - processes[i].arrival_time;
                    processes[i].waiting_time = processes[i].turnaround_time - processes[i].burst_time;
                    completed++;
                }
            }
        }
        if (!found) {
            current_time++;
        }
    }
}

void printGanttChart(Process processes[], int n, int quantum) {
    printf("Gantt Chart:\n|");
    int current_time = 0;
    int completed = 0;

    while (completed != n) {
        for (int i = 0; i < n; i++) {
            if (processes[i].arrival_time <= current_time && processes[i].remaining_time > 0) {
                printf(" P%d |", processes[i].pid);
                if (processes[i].remaining_time > quantum) {
                    current_time += quantum;
                    processes[i].remaining_time -= quantum;
                } else {
                    current_time += processes[i].remaining_time;
                    processes[i].remaining_time = 0;
                    completed++;
                }
            }
        }
    }
    printf("\n0");

    current_time = 0;
    completed = 0;
    while (completed != n) {
        for (int i = 0; i < n; i++) {
            if (processes[i].arrival_time <= current_time && processes[i].remaining_time > 0) {
                if (processes[i].remaining_time > quantum) {
                    current_time += quantum;
                    processes[i].remaining_time -= quantum;
                    printf("   %d", current_time);
                } else {
                    current_time += processes[i].remaining_time;
                    processes[i].remaining_time = 0;
                    completed++;
                    printf("   %d", current_time);
                }
            }
        }
    }
    printf("\n");
}

int main() {
    int n, quantum;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    printf("Enter the time quantum: ");
    scanf("%d", &quantum);

    Process processes[n];

    for (int i = 0; i < n; i++) {
        processes[i].pid = i + 1;
        printf("Enter arrival time for process P%d: ", processes[i].pid);
        scanf("%d", &processes[i].arrival_time);
        printf("Enter burst time for process P%d: ", processes[i].pid);
        scanf("%d", &processes[i].burst_time);
        processes[i].remaining_time = processes[i].burst_time;
    }

    calculateTimes(processes, n, quantum);
    printf("Completed calculating time\n");

    double total_waiting_time = 0, total_turnaround_time = 0;

    printf("\nProcess\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        total_waiting_time += processes[i].waiting_time;
        total_turnaround_time += processes[i].turnaround_time;
        printf("P%d\t%d\t\t%d\t\t%d\t\t%d\n", processes[i].pid, processes[i].arrival_time, processes[i].burst_time, processes[i].waiting_time, processes[i].turnaround_time);
    }

    double avg_waiting_time = total_waiting_time / n;
    double avg_turnaround_time = total_turnaround_time / n;

    printf("\nAverage Waiting Time: %.2f\n", avg_waiting_time);
    printf("Average Turnaround Time: %.2f\n", avg_turnaround_time);

    printGanttChart(processes, n, quantum);

    return 0;
}