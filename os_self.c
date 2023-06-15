#include<stdio.h>

void calculateTurnAroundTime(int arrival[], int comp[], int turnAround[], int n) {
    for (int i = 1; i <= n; i++) {
        turnAround[i] = comp[i] - arrival[i];
    }
}

void calculateWaitingTime(int turnAround[], int burst[], int waiting[], int n) {
    for (int i = 1; i <= n; i++) {
        waiting[i] = turnAround[i] - burst[i];
    }
}

int main() {
    int n;
    int arrival[10], burst[10];
    int comp[10];
    int turnAround[10], waiting[10];
    int totalTurnAroundTime = 0;
    int totalWaitingTime = 0;

    printf("Enter the number of programs: ");
    scanf("%d", &n);
    printf("The number of programs are %d\n", n);

    printf("Enter the arrival time:\n");
    for (int i = 1; i <= n; i++) {
        scanf("%d", &arrival[i]);
    }

    printf("Enter the burst time:\n");
    for (int i = 1; i <= n; i++) {
        scanf("%d", &burst[i]);
    }

    comp[0] = 0; // First process starts at time 0

    printf("The completion time is:\n");
    for (int i = 1; i <= n; i++) {
        comp[i] = burst[i] + comp[i - 1];
        printf("Process %d: %d\n", i, comp[i]);
    }

    calculateTurnAroundTime(arrival, comp, turnAround, n);
    calculateWaitingTime(turnAround, burst, waiting, n);

    printf("Process\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 1; i <= n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", i, arrival[i], burst[i], waiting[i], turnAround[i]);

        totalWaitingTime += waiting[i];
        totalTurnAroundTime += turnAround[i];
    }

    float averageWaitingTime = (float)totalWaitingTime / n;
    float averageTurnAroundTime = (float)totalTurnAroundTime / n;

    printf("\nAverage Waiting Time: %.2f", averageWaitingTime);
    printf("\nAverage Turnaround Time: %.2f\n", averageTurnAroundTime);

    return 0;
}
