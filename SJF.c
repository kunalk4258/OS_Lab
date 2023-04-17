#include <stdio.h>

struct process
{
    int pid;        
    int burst;      
    int arrival;    
    int waiting;    
    int turnaround; 
};

int main()
{
    int n, i, j;
    struct process p[10], temp;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("\nProcess %d\n", i + 1);
        printf("Enter the process ID: ");
        scanf("%d", &p[i].pid);
        printf("Enter the burst time: ");
        scanf("%d", &p[i].burst);
        printf("Enter the arrival time: ");
        scanf("%d", &p[i].arrival);
    }
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (p[i].arrival > p[j].arrival)
            {
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }
    int total_waiting = 0, total_turnaround = 0;
    for (i = 0; i < n; i++)
    {
        int shortest = i;
        for (j = i + 1; j < n; j++)
        {
            if (p[j].burst < p[shortest].burst)
            {
                shortest = j;
            }
        }
        temp = p[i];
        p[i] = p[shortest];
        p[shortest] = temp;
        p[i].waiting = total_waiting - p[i].arrival;
        p[i].turnaround = p[i].waiting + p[i].burst;
        total_waiting += p[i].burst;
        total_turnaround += p[i].turnaround;
    }
    float avg_waiting = (float)total_waiting / n;
    float avg_turnaround = (float)total_turnaround / n;
    printf("\nProcess\tBurst time\tArrival time\tWaiting time\tTurnaround time\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", p[i].pid, p[i].burst, p[i].arrival, p[i].waiting, p[i].turnaround);
    }
    printf("\nAverage waiting time: %.2f", avg_waiting);
    printf("\nAverage turnaround time: %.2f\n", avg_turnaround);

    return 0;
}