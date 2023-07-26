#include <stdio.h>
#define MAX_TASKS 10
typedef struct {
    int id;
    int period;
    int executionTime;
    int arrivalTime;
} Task;
void scheduleTasks(Task tasks[], int numTasks) {
    int currentTime = 0;
    printf("Scheduled tasks:\n");
    while (1) {
        int earliestDeadline = -1;
        int selectedTask = -1;

        for (int i = 0; i < numTasks; i++) {
            if (tasks[i].arrivalTime <= currentTime) {
                if (earliestDeadline == -1 || tasks[i].period < earliestDeadline) {
                    earliestDeadline = tasks[i].period;
                    selectedTask = i;
                }
            }
        }
        if (selectedTask == -1)
            break;

        printf("Task %d at time %d\n", tasks[selectedTask].id, currentTime);

        currentTime += tasks[selectedTask].executionTime;

        tasks[selectedTask].arrivalTime += tasks[selectedTask].period;
    }
}
int main() {
    Task tasks[MAX_TASKS];
    int numTasks;

    printf("Enter the number of tasks (maximum %d): ", MAX_TASKS);
    scanf("%d", &numTasks);

    for (int i = 0; i < numTasks; i++) {
        printf("Enter details for Task %d:\n", i + 1);

        tasks[i].id = i + 1;

        printf("Period: ");
        scanf("%d", &tasks[i].period);

        printf("Execution time: ");
        scanf("%d", &tasks[i].executionTime);

        printf("Arrival time: ");
        scanf("%d", &tasks[i].arrivalTime);
    }
    scheduleTasks(tasks, numTasks);

    return 0;
}
