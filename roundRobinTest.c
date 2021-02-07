#include "types.h"
#include "stat.h"
#include "user.h"

Times *times;

void
averageCBT(Times *times)
{
    int result = 0;

    for (int i = 0; i < 10; i++){       
        result += times[i].runningTime;
        printf(1, "the CBT for process %d is: %d\n", i, times[i].runningTime);
    }

    result /= 10;

    printf(1, "the average CBT is: %d\n", result);
}

void
averageTurnaroundTime(Times *times)
{
    int result = 0;

    for (int i = 0; i < 10; i++){
        result += times[i].runningTime + times[i].sleepingTime + times[i].readyTime;
        printf(1, "the turnAroundTime for process %d is: %d\n", i, times[i].runningTime + times[i].sleepingTime + times[i].readyTime);
    }
        
    result /= 10;

    printf(1, "the average turnArounTime is: %d\n", result);
}

void
averageWaitingTime(Times *times)
{
    int result = 0;

    for (int i = 0; i < 10; i++){
        result += times[i].sleepingTime + times[i].readyTime;
        printf(1, "the waitingTime for process %d is: %d\n", i, times[i].sleepingTime + times[i].readyTime);
    }
        
    result /= 10;

    printf(1, "the average WaitingTime is: %d\n", result);
}

int
main()
{   

    times = (Times *) malloc(10 * sizeof(Times));
    changePolicy(3);

    int i, j, k;
    
    for (i = 0; i < 10; i++)
    {   
        if (fork() == 0)
        {
            for (j = 1; j < 1000; j++)
                printf(1, "%d : %d\n", getpid(), j);
            exit();
        }
    }

    for (k = 0; k < 10; k++){
        wait2(&times[k]);
    }
        

    averageCBT(times);
    averageTurnaroundTime(times);
    averageWaitingTime(times);

    exit();
    return 1;
}