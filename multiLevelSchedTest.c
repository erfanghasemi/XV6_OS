#include "types.h"
#include "stat.h"
#include "user.h"


int findClass(int number);
int findQueue(int number);
void averageWaitingTime(Times *times, int childNumbers[40]);
void averageCBT(Times *times, int childNumbers[40]);
void averageTurnaroundTime(Times *times, int childNumbers[40]);

int main(void)
{   
    changePolicy(4);
    
    int pid;
    int pids[200];
    int childNumbers[40];
    Times * times = (Times *) malloc(40 * sizeof(Times));
    
    int p = 1;
    int counter = 0;
    int i, j, k;

    for(i = 0; i < 40; i++){
        if(p != 0)
        {
            counter++;
            p = fork2(findQueue(counter));
            if(p == 0)
            {
                if(findQueue(counter) == 1 || findQueue(counter) == 2)
                {   
                    setPriority(findClass(counter));
                }
            }
            else
            {
                pids[p] = counter;
            } 
        }
    }

    if(p == 0)
    {
        for(j=1;j<201;j++)
        {
            printf(1,"[%d]:[%d]\n",counter,j);
        }
        exit();
    }

    for (k = 0; k < 40; k++)
    {   
        pid = wait2(&times[k]);
        childNumbers[k] = pids[pid];
    }

    averageCBT(times, childNumbers);
    printf(1, "=======================================================\n");
    averageTurnaroundTime(times, childNumbers);
    printf(1, "=======================================================\n");
    averageWaitingTime(times,childNumbers);
    exit();
    return 1;

}

int
findClass(int number)
{
    if(number == 11 || number == 12 || number == 29 || number == 30)
       return 1;

    else if(number == 13 || number == 14 || number == 27 || number == 28)
       return 2;

    else if(number == 15 || number == 16 || number == 25 || number == 26)
       return 3;

    else if(number == 17 || number == 18 || number == 23 || number == 24)
       return 4;
    
    else if(number == 19 || number == 20 || number == 21 || number == 22)
       return 5;
    
    return 0; 
}

int
findQueue(int number)
{
    if ((1 <= number) && (number <= 10))
        return 0;
    
    else if ((11 <= number) && (number <= 20))
        return 1;
    
    else if ((21 <= number) && (number <= 30))
        return 2; 
    
    else if ((31 <= number) && (number <= 40))
        return 3;
    return -1;
}

void
averageCBT(Times *times, int childNumbers[40])
{
    int result = 0;
    int defaultResult = 0;
    int priorityResult = 0;
    int reversePriorityResult = 0;
    int roundRobinResult = 0;

    for (int i = 0; i < 40; i++)
    { 
        result += times[i].runningTime;

        if((childNumbers[i] > 0) && (childNumbers[i] < 11))
            defaultResult += times[i].runningTime;

        else if((childNumbers[i] > 10) && (childNumbers[i] < 21))
            priorityResult += times[i].runningTime;    

        else if((childNumbers[i] > 20) && (childNumbers[i] < 31))
            reversePriorityResult += times[i].runningTime;

        else if((childNumbers[i] > 30) && (childNumbers[i] < 41))
            roundRobinResult += times[i].runningTime; 


        printf(1, "the CBT for child %d is: %d\n", childNumbers[i], times[i].runningTime);
    }

    result /= 40;
    defaultResult /= 10;
    priorityResult /= 10;
    reversePriorityResult /= 10;
    roundRobinResult /= 10;

    printf(1, "------- the average CBT for default layer is: %d -------\n", defaultResult);
    printf(1, "------- the average CBT for priority layer is: %d -------\n", priorityResult);
    printf(1, "------- the average CBT for reverse priority layer is: %d -------\n", reversePriorityResult);
    printf(1, "------- the average CBT for default Round-Robin is: %d -------\n", roundRobinResult);
    

    printf(1, "------- the average TurnArCBToundTime is: %d -------\n", result);
}

void
averageTurnaroundTime(Times *times, int childNumbers[40])
{
    int result = 0;
    int defaultResult = 0;
    int priorityResult = 0;
    int reversePriorityResult = 0;
    int roundRobinResult = 0;

    for (int i = 0; i < 40; i++)
    { 
        result += (times[i].runningTime + times[i].sleepingTime + times[i].readyTime);

        if((childNumbers[i] > 0) && (childNumbers[i] < 11))
            defaultResult += (times[i].runningTime + times[i].sleepingTime + times[i].readyTime);

        else if((childNumbers[i] > 10) && (childNumbers[i] < 21))
            priorityResult += (times[i].runningTime + times[i].sleepingTime + times[i].readyTime);    

        else if((childNumbers[i] > 20) && (childNumbers[i] < 31))
            reversePriorityResult += (times[i].runningTime + times[i].sleepingTime + times[i].readyTime); 

        else if((childNumbers[i] > 30) && (childNumbers[i] < 41))
            roundRobinResult += (times[i].runningTime + times[i].sleepingTime + times[i].readyTime);  

        printf(1, "the TurnAroundTime for child %d is: %d\n", childNumbers[i], (times[i].runningTime + times[i].sleepingTime + times[i].readyTime));
    }

    result /= 40;
    defaultResult /= 10;
    priorityResult /= 10;
    reversePriorityResult /= 10;
    roundRobinResult /= 10;

    printf(1, "------- the average TurnAroundTime for default layer is: %d -------\n", defaultResult);
    printf(1, "------- the average TurnAroundTime for priority layer is: %d -------\n", priorityResult);
    printf(1, "------- the average TurnAroundTime for reverse priority layer is: %d -------\n", reversePriorityResult);
    printf(1, "------- the average TurnAroundTime for default Round-Robin is: %d -------\n", roundRobinResult);
    

    printf(1, "------- the average TurnAroundTime is: %d -------\n", result);
}

void
averageWaitingTime(Times *times, int childNumbers[40])
{
    int result = 0;
    int defaultResult = 0;
    int priorityResult = 0;
    int reversePriorityResult = 0;
    int roundRobinResult = 0;

    for (int i = 0; i < 40; i++){ 
         
        result += (times[i].sleepingTime + times[i].readyTime);

        if((childNumbers[i] > 0) && (childNumbers[i] < 11))
            defaultResult += (times[i].sleepingTime + times[i].readyTime);

        else if((childNumbers[i] > 10) && (childNumbers[i] < 21))
            priorityResult += (times[i].sleepingTime + times[i].readyTime);    

        else if((childNumbers[i] > 20) && (childNumbers[i] < 31))
            reversePriorityResult += (times[i].sleepingTime + times[i].readyTime); 

        else if((childNumbers[i] > 30) && (childNumbers[i] < 41))
            roundRobinResult += (times[i].sleepingTime + times[i].readyTime);  

        printf(1, "the WaitingTime for child %d is: %d\n", childNumbers[i], (times[i].sleepingTime + times[i].readyTime));
    }

    result /= 40;
    defaultResult /= 10;
    priorityResult /= 10;
    reversePriorityResult /= 10;
    roundRobinResult /= 10;

    printf(1, "------- the average WaitingTime for default layer is: %d -------\n", defaultResult);
    printf(1, "------- the average WaitingTime for priority layer is: %d -------\n", priorityResult);
    printf(1, "------- the average WaitingTime for reverse priority layer is: %d -------\n", reversePriorityResult);
    printf(1, "------- the average WaitingTime for default Round-Robin is: %d -------\n", roundRobinResult);
    

    printf(1, "------- the average WaitingTime is: %d -------\n", result);
}
