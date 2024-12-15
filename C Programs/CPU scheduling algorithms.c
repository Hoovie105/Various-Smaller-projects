#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define MAX_PROCESSES 100
#define FILENAME_MAX_LEN 100

// Process structure
typedef struct {
    int process_number;
    int arrival_time;
    int burst_time;
    int remaining_burst_time;
    int priority;
    int completion_time;
    int turnaround_time;
    int wait_time;
    int current_queue;
} Process;

// Function prototypes
void FIFO(Process processes[], int num_processes);
void SRTF(Process processes[], int num_processes);
void RR(Process processes[], int num_processes, int time_quantum);
void PriorityScheduling(Process processes[], int num_processes);
void MultilevelFeedback(Process processes[], int num_processes);
void calculateMetrics(Process processes[], int num_processes);
void readInputFromFile(char filename[], Process processes[], int *num_processes);
void sortProcessesByArrivalTime(Process processes[], int num_processes);
void sortProcessesByRemainingBurstTime(Process processes[], int num_processes);

int main() {
    int choice;
    printf("Choose a CPU scheduling algorithm:\n");
    printf("1. First-In-First-Out (FIFO)\n");
    printf("2. Shortest Remaining Time First (SRTF)\n");
    printf("3. Round Robin (RR)\n");
    printf("4. Priority Scheduling\n");
    printf("5. Multilevel Feedback Queue\n");
    scanf("%d", &choice);

    int num_processes, time_quantum;
    Process processes[MAX_PROCESSES];
    char filename[FILENAME_MAX_LEN];

    printf("Do you want to read input from a file? (1 for Yes, 0 for No): ");
    int use_file_input;
    scanf("%d", &use_file_input);

    if (use_file_input) {
        printf("Filename: ");
        scanf("%s", filename);
        readInputFromFile(filename, processes, &num_processes);
    } else {
        printf("Enter the number of processes: ");
        scanf("%d", &num_processes);
        printf("Format: PID, arrival time, burst time\n");
        for (int i = 0; i < num_processes; i++) {
            printf("Enter details of process %d: ", i+1);
            scanf("%d %d %d", &processes[i].process_number, &processes[i].arrival_time, &processes[i].burst_time);
            processes[i].remaining_burst_time = processes[i].burst_time;
        }
    }

    switch (choice) {
        case 1: // FIFO
            FIFO(processes, num_processes);
            break;
        case 2: // SRTF
            SRTF(processes, num_processes);
            break;
        case 3: // RR
            printf("Enter the time quantum: ");
            scanf("%d", &time_quantum);
            RR(processes, num_processes, time_quantum);
            break;
        case 4: // Priority Scheduling
            PriorityScheduling(processes, num_processes);
            break;
        case 5: // Multilevel Feedback Queue
            MultilevelFeedback(processes, num_processes);
            break;
        default:
            printf("Invalid choice.\n");
            return 1;
    }

    return 0;
}
void readInputFromFile(char filename[], Process processes[], int *num_processes) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    fscanf(file, "%d", num_processes);
    for (int i = 0; i < *num_processes; i++) {
        fscanf(file, "%d %d %d", &processes[i].process_number, &processes[i].arrival_time, &processes[i].burst_time);
        processes[i].remaining_burst_time = processes[i].burst_time;
    }

    fclose(file);
}

// Function to sort processes by arrival time
void sortProcessesByArrivalTime(Process processes[], int num_processes) {
    for (int i = 0; i < num_processes - 1; i++) {
        for (int j = 0; j < num_processes - i - 1; j++) {
            if (processes[j].arrival_time > processes[j+1].arrival_time) {
                Process temp = processes[j];
                processes[j] = processes[j+1];
                processes[j+1] = temp;
            }
        }
    }
}

// Function to sort processes by remaining burst time
void sortProcessesByRemainingBurstTime(Process processes[], int num_processes) {
    for (int i = 0; i < num_processes - 1; i++) {
        for (int j = 0; j < num_processes - i - 1; j++) {
            if (processes[j].remaining_burst_time > processes[j+1].remaining_burst_time) {
                Process temp = processes[j];
                processes[j] = processes[j+1];
                processes[j+1] = temp;
            }
        }
    }
}

// First-In-First-Out (FIFO)
void FIFO(Process processes[], int num_processes) {
    sortProcessesByArrivalTime(processes, num_processes);

    int current_time = 0;
    for (int i = 0; i < num_processes; i++) {
        if (processes[i].arrival_time > current_time)
            current_time = processes[i].arrival_time;
        processes[i].completion_time = current_time + processes[i].burst_time;
        processes[i].turnaround_time = processes[i].completion_time - processes[i].arrival_time;
        processes[i].wait_time = processes[i].turnaround_time - processes[i].burst_time;
        current_time = processes[i].completion_time;
    }

    calculateMetrics(processes, num_processes);
}

// Shortest Remaining Time First (SRTF)
void SRTF(Process processes[], int num_processes) {
    int current_time = 0;
    int completed_processes = 0;

    while (completed_processes < num_processes) {
        int shortest_remaining_index = -1;
        int shortest_remaining_time = INT_MAX;

        for (int i = 0; i < num_processes; i++) {
            if (processes[i].arrival_time <= current_time && processes[i].remaining_burst_time < shortest_remaining_time && processes[i].remaining_burst_time > 0) {
                shortest_remaining_index = i;
                shortest_remaining_time = processes[i].remaining_burst_time;
            }
        }

        if (shortest_remaining_index == -1) {
            current_time++;
            continue;
        }

        processes[shortest_remaining_index].remaining_burst_time--;
        current_time++;

        if (processes[shortest_remaining_index].remaining_burst_time == 0) {
            completed_processes++;
            processes[shortest_remaining_index].completion_time = current_time;
            processes[shortest_remaining_index].turnaround_time = processes[shortest_remaining_index].completion_time - processes[shortest_remaining_index].arrival_time;
            processes[shortest_remaining_index].wait_time = processes[shortest_remaining_index].turnaround_time - processes[shortest_remaining_index].burst_time;
        }
    }

    calculateMetrics(processes, num_processes);
}

// Round Robin (RR)
void RR(Process processes[], int num_processes, int time_quantum) {
    int remaining_processes = num_processes;
    int current_time = 0;
    int executed_processes = 0;

    while (executed_processes < num_processes) {
        for (int i = 0; i < num_processes; i++) {
            if (processes[i].remaining_burst_time > 0) {
                if (processes[i].arrival_time <= current_time) {
                    int execute_time = (processes[i].remaining_burst_time > time_quantum) ? time_quantum : processes[i].remaining_burst_time;
                    processes[i].remaining_burst_time -= execute_time;
                    current_time += execute_time;
                    if (processes[i].remaining_burst_time == 0) {
                        processes[i].completion_time = current_time;
                        processes[i].turnaround_time = processes[i].completion_time - processes[i].arrival_time;
                        processes[i].wait_time = processes[i].turnaround_time - processes[i].burst_time;
                        executed_processes++;
                    }
                } else {
                    current_time = processes[i].arrival_time;
                }
            }
        }
    }

    calculateMetrics(processes, num_processes);
}

// Priority Scheduling
void PriorityScheduling(Process processes[], int num_processes) {
    // Prompt the user to enter priorities for each process
    printf("Enter priorities for each process:\n");
    for (int i = 0; i < num_processes; i++) {
        printf("Priority for process %d: ", processes[i].process_number);
        scanf("%d", &processes[i].priority);
    }

    // Sort processes by priority
    for (int i = 0; i < num_processes - 1; i++) {
        for (int j = 0; j < num_processes - i - 1; j++) {
            if (processes[j].priority > processes[j+1].priority) {
                Process temp = processes[j];
                processes[j] = processes[j+1];
                processes[j+1] = temp;
            }
        }
    }

    int current_time = 0;
    int completed_processes = 0;

    while (completed_processes < num_processes) {
        int highest_priority_index = -1;
        int highest_priority = INT_MAX;

        for (int i = 0; i < num_processes; i++) {
            if (processes[i].arrival_time <= current_time && processes[i].priority < highest_priority && processes[i].remaining_burst_time > 0) {
                highest_priority_index = i;
                highest_priority = processes[i].priority;
            }
        }

        if (highest_priority_index == -1) {
            current_time++;
            continue;
        }

        processes[highest_priority_index].remaining_burst_time--;
        current_time++;

        if (processes[highest_priority_index].remaining_burst_time == 0) {
            completed_processes++;
            processes[highest_priority_index].completion_time = current_time;
            processes[highest_priority_index].turnaround_time = processes[highest_priority_index].completion_time - processes[highest_priority_index].arrival_time;
            processes[highest_priority_index].wait_time = processes[highest_priority_index].turnaround_time - processes[highest_priority_index].burst_time;
        }
    }

    calculateMetrics(processes, num_processes);
}


void MultilevelFeedback(Process processes[], int num_processes) {
    // Define the number of queues and initialize their time quantum
    const int num_queues = 10;
    int time_quantum[num_queues];
    for (int i = 0; i < num_queues; i++) {
        time_quantum[i] = 2 * (i + 1);
    }

    // Initialize variables to track completed processes
    int completed_processes = 0;
    int current_time = 0;

    // Run until all processes are completed
    while (completed_processes < num_processes) {
        // Flag to check if any process has been executed in this iteration
        int process_executed = 0;

        // Iterate through each process
        for (int i = 0; i < num_processes; i++) {
            // Process has arrived and not yet completed
            if (processes[i].arrival_time <= current_time && processes[i].remaining_burst_time > 0) {
                // Find the current queue level of the process
                int current_queue = processes[i].current_queue;
                if (current_queue == 0) {
                    current_queue = 1; // Newly arrived process starts from the first queue
                }

                // Execute the process for one time quantum or until it completes
                int execute_time = (processes[i].remaining_burst_time > time_quantum[current_queue - 1]) ?
                                    time_quantum[current_queue - 1] : processes[i].remaining_burst_time;
                processes[i].remaining_burst_time -= execute_time;
                current_time += execute_time;

                // If the process completes its execution
                if (processes[i].remaining_burst_time == 0) {
                    completed_processes++;
                    processes[i].completion_time = current_time;
                    processes[i].turnaround_time = processes[i].completion_time - processes[i].arrival_time;
                    processes[i].wait_time = processes[i].turnaround_time - processes[i].burst_time;
                }
                // Move the process to the next queue level if it has not completed
                else if (current_queue < num_queues) {
                    processes[i].current_queue++;
                }

                // Set the flag to indicate that a process has been executed
                process_executed = 1;
            }
        }

        // If no process was executed in this iteration, move to the next time unit
        if (!process_executed) {
            current_time++;
        }
    }
    
    calculateMetrics(processes, num_processes);
}

// Function to calculate metrics and output results
void calculateMetrics(Process processes[], int num_processes) {
    int total_turnaround_time = 0;
    int total_wait_time = 0;

    printf("\nProcess\tCompletion Time\tTurnaround Time\tWait Time\n");
    for (int i = 0; i < num_processes; i++) {
        total_turnaround_time += processes[i].turnaround_time;
        total_wait_time += processes[i].wait_time;
        printf("%d\t%d\t\t%d\t\t%d\n", processes[i].process_number, processes[i].completion_time, processes[i].turnaround_time, processes[i].wait_time);
    }

    float avg_turnaround_time = (float)total_turnaround_time / num_processes;
    float avg_wait_time = (float)total_wait_time / num_processes;

    printf("\nAverage Turnaround Time: %.2f\n", avg_turnaround_time);
    printf("Average Wait Time: %.2f\n", avg_wait_time);
}
