#include <stdio.h>
#include <stdlib.h>

struct Process {
    int pid;
    int arrival_time;
    int burst_time;
    int turnaround_time;
    int waiting_time;
    int response_time;
};

void display(struct Process p[], int n, const char *algorithm_name) {
    printf("\n=== %s ===\n", algorithm_name);

    printf("Gantt Chart: | ");
    for (int i = 0; i < n; i++) {
        printf("P%d ", p[i].pid);
    }
    printf("|\n");

    printf("PID\tAT\tBT\tWT\tTAT\tRT\n");
    int total_waiting_time = 0, total_turnaround_time = 0, total_response_time = 0;
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", p[i].pid,
               p[i].arrival_time, p[i].burst_time,
               p[i].waiting_time, p[i].turnaround_time, p[i].response_time);

        total_waiting_time += p[i].waiting_time;
        total_turnaround_time += p[i].turnaround_time;
        total_response_time += p[i].response_time;
    }

    printf("\nAverage Waiting Time: %.2f\n", (float)total_waiting_time / n);
    printf("Average Turnaround Time: %.2f\n", (float)total_turnaround_time / n);
    printf("Average Response Time: %.2f\n", (float)total_response_time / n);
}

void fcfs(struct Process p[], int n) {
    int current_time = 0;

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (p[j].arrival_time > p[j + 1].arrival_time) {
                struct Process temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (current_time < p[i].arrival_time)
            current_time = p[i].arrival_time;
        p[i].response_time = current_time - p[i].arrival_time;
        p[i].waiting_time = p[i].response_time;
        current_time += p[i].burst_time;
        p[i].turnaround_time = current_time - p[i].arrival_time;
    }

    display(p, n, "First Come First Served (FCFS)");
}

void sjf(struct Process p[], int n) {
    int completed[100] = {0};
    int completed_count = 0;
    int current_time = 0;

    struct Process order[n];

    while (completed_count < n) {
        int idx = -1;
        int min_bt = 1e9;

        for (int i = 0; i < n; i++) {
            if (!completed[i] && p[i].arrival_time <= current_time) {
                if (p[i].burst_time < min_bt ||
                    (p[i].burst_time == min_bt && p[i].arrival_time < p[idx].arrival_time)) {
                    min_bt = p[i].burst_time;
                    idx = i;
                }
            }
        }

        if (idx == -1) {
            current_time++;
            continue;
        }

        p[idx].waiting_time = current_time - p[idx].arrival_time;
        if (p[idx].waiting_time < 0) p[idx].waiting_time = 0;

        p[idx].response_time = p[idx].waiting_time;
        current_time += p[idx].burst_time;
        p[idx].turnaround_time = current_time - p[idx].arrival_time;

        order[completed_count] = p[idx];
        completed[idx] = 1;
        completed_count++;
    }

    display(order, n, "Shortest Job First (Non-preemptive)");
}

int main() {
    int n;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process p[n];

    for (int i = 0; i < n; i++) {
        p[i].pid = i + 1;
        printf("Enter Arrival Time and Burst Time for Process %d: ", p[i].pid);
        scanf("%d %d", &p[i].arrival_time, &p[i].burst_time);
    }

    fcfs(p, n);
    sjf(p, n);

    return 0;
}

