#include "types.h"
#include "stat.h"
#include "user.h"
Times *times;

void
AverageCBT(Times *times)
{
    uint result = 0;
    uint temp = 0;

    for (int i = 0; i < 10; i++){
        temp = times[i].runningTime;
        result += temp;
        printf(1, "the CBT for process %d is: %x\n", i, temp);
    }

    result /= 10;

    printf(1, "the average CBT is: %d\n", result);
}

void
AverageTurnArounTime(Times *times)
{
    uint result = 0;
    uint temp;

    for (int i = 0; i < 10; i++){
        temp = (times[i].creationTime - times[i].terminationTime);
        result += temp;
        printf(1, "the turnAroundTime for process %d is: %d\n", i, temp);
    }
        

    result /= 10;

    printf(1, "the average turnArounTime is: %d\n", result);
}

void
AverageWaitingTime(Times *times)
{
    uint result = 0;
    uint temp = 0;

    for (int i = 0; i < 10; i++){
        temp = (times[i].creationTime - times[i].runningTime - times[i].terminationTime);
        result += temp;
        printf(1, "the waitingTime for process %d is: %d\n", i, temp);
    }
        

    result /= 10;

    printf(1, "the average WaitingTime is: %d\n", result);
}

int
main()
{
    times = (Times *) malloc(10 * sizeof(Times));

    changePolicy(0);

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

    for (k = 0; k < 10; k++)
        wait2(&times[k]);
        

     AverageCBT(times);
     AverageTurnArounTime(times);
     AverageWaitingTime(times);

    exit();
}