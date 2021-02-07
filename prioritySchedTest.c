#include "types.h"
#include "stat.h"
#include "user.h"


int find_class(int number);
void averageWaitingTime(Times *times, int childNumebrs[30]);
void averageTurnaroundTime(Times *times, int childNumebrs[30]);
void averageCBT(Times *times, int childNumebrs[30]);

int main(void)
{   
    int pid;
    int pids[200] = {0};
    int childNumbers[30];
    Times *times = (Times *) malloc(30 * sizeof(Times));
    
    changePolicy(1);
    setPriority(6);

    int p = 1;
    int counter = 0;
    int i, j, k;

    for(i = 0; i < 30; i++){
        if(p != 0){
            counter++;
            p = fork();
            pids[p] = counter; 
        }
         else
        {   
            setPriority(find_class(counter));           
        }
    }

    if(p == 0)
    {
        for(j=1;j<251;j++)
        {
            printf(1,"[%d]:[%d]\n",find_class(counter),j);
        }
        exit();
    }
    

    for (k = 0; k < 30; k++){
        pid = wait2(&times[k]);
        childNumbers[k] = pids[pid];
    }

    averageCBT(times, childNumbers);
    printf(1, "=======================================================\n");
    averageTurnaroundTime(times, childNumbers);
    printf(1, "=======================================================\n");
    averageWaitingTime(times, childNumbers);
    
    exit();
    return 1;
}

int
find_class(int number)
{
    if(0 < number && number < 6)
        return 6;

    else if(5 < number && number < 11)
        return 5;

    else if(10 < number && number < 16)
        return 4; 

    else if(15 < number && number < 21)
        return 3; 

    else if(20 < number && number < 26)
        return 2; 

    else if(25 < number && number < 31)
        return 1;           
    return 0;         
}

void
averageCBT(Times *times, int childNumebrs[30])
{
    int result = 0;
    int classResult1 = 0;
    int classResult2 = 0;
    int classResult3 = 0;
    int classResult4 = 0;
    int classResult5 = 0;
    int classResult6 = 0;

    for (int i = 0; i < 30; i++){  
        result += times[i].runningTime;

        if((0 < childNumebrs[i]) && (childNumebrs[i] < 6))
            classResult6 += times[i].runningTime;

        else if((5 < childNumebrs[i]) && (childNumebrs[i] < 11))
            classResult5 += times[i].runningTime;

        else if((10 < childNumebrs[i]) && (childNumebrs[i] < 16))
            classResult4 += times[i].runningTime;

        else if((15 < childNumebrs[i]) && (childNumebrs[i] < 21))
            classResult3 += times[i].runningTime; 

        else if((20 < childNumebrs[i]) && (childNumebrs[i] < 26))
            classResult2 += times[i].runningTime; 

        else if((25 < childNumebrs[i]) && (childNumebrs[i] < 31))
            classResult1 += times[i].runningTime;

        printf(1, "the CBT for child %d is: %d\n", childNumebrs[i], times[i].runningTime);
    }

    result /= 30;
    classResult1 /= 5;
    classResult2 /= 5;
    classResult3 /= 5;
    classResult4 /= 5;
    classResult5 /= 5;
    classResult6 /= 5;

    printf(1, "------- the average CBT for priority 1 is: %d -------\n", classResult1);
    printf(1, "------- the average CBT for priority 2 is: %d -------\n", classResult2);
    printf(1, "------- the average CBT for priority 3 is: %d -------\n", classResult3);
    printf(1, "------- the average CBT for priority 4 is: %d -------\n", classResult4);
    printf(1, "------- the average CBT for priority 5 is: %d -------\n", classResult5);
    printf(1, "------- the average CBT for priority 6 is: %d -------\n", classResult6);

    printf(1, "------- the average CBT is: %d -------\n", result);  
}

void
averageTurnaroundTime(Times *times, int childNumebrs[30])
{
    int result = 0;
    int classResult1 = 0;
    int classResult2 = 0;
    int classResult3 = 0;
    int classResult4 = 0;
    int classResult5 = 0;
    int classResult6 = 0;

    for (int i = 0; i < 30; i++){  
        result += (times[i].runningTime + times[i].sleepingTime + times[i].readyTime);

        if(0 < childNumebrs[i] && childNumebrs[i] < 6)
            classResult6 += (times[i].runningTime + times[i].sleepingTime + times[i].readyTime);

        else if(5 < childNumebrs[i] && childNumebrs[i] < 11)
            classResult5 += (times[i].runningTime + times[i].sleepingTime + times[i].readyTime);

        else if(10 < childNumebrs[i] && childNumebrs[i] < 16)
            classResult4 += (times[i].runningTime + times[i].sleepingTime + times[i].readyTime);

        else if(15 < childNumebrs[i] && childNumebrs[i] < 21)
            classResult3 += (times[i].runningTime + times[i].sleepingTime + times[i].readyTime); 

        else if(20 < childNumebrs[i] && childNumebrs[i] < 26)
            classResult2 += (times[i].runningTime + times[i].sleepingTime + times[i].readyTime); 

        else if(25 < childNumebrs[i] && childNumebrs[i] < 31)
            classResult1 += (times[i].runningTime + times[i].sleepingTime + times[i].readyTime);

        printf(1, "the TurnAroundTime for child %d is: %d\n", childNumebrs[i], (times[i].runningTime + times[i].sleepingTime + times[i].readyTime));
    }

    result /= 30;
    classResult1 /= 5;
    classResult2 /= 5;
    classResult3 /= 5;
    classResult4 /= 5;
    classResult5 /= 5;
    classResult6 /= 5;

    printf(1, "------- the average TurnAroundTime for priority 1 is: %d -------\n", classResult1);
    printf(1, "------- the average TurnAroundTime for priority 2 is: %d -------\n", classResult2);
    printf(1, "------- the average TurnAroundTime for priority 3 is: %d -------\n", classResult3);
    printf(1, "------- the average TurnAroundTime for priority 4 is: %d -------\n", classResult4);
    printf(1, "------- the average TurnAroundTime for priority 5 is: %d -------\n", classResult5);
    printf(1, "------- the average TurnAroundTime for priority 6 is: %d -------\n", classResult6);

    printf(1, "------- the average TurnAroundTime is: %d -------\n", result);  
}

void
averageWaitingTime(Times *times, int childNumebrs[30])
{
    int result = 0;
    int classResult1 = 0;
    int classResult2 = 0;
    int classResult3 = 0;
    int classResult4 = 0;
    int classResult5 = 0;
    int classResult6 = 0;

    for (int i = 0; i < 30; i++){  
        result += (times[i].sleepingTime + times[i].readyTime);

        if(0 < childNumebrs[i] && childNumebrs[i] < 6)
            classResult6 += (times[i].sleepingTime + times[i].readyTime);

        else if(5 < childNumebrs[i] && childNumebrs[i] < 11)
            classResult5 += (times[i].sleepingTime + times[i].readyTime);

        else if(10 < childNumebrs[i] && childNumebrs[i] < 16)
            classResult4 += (times[i].sleepingTime + times[i].readyTime);

        else if(15 < childNumebrs[i] && childNumebrs[i] < 21)
            classResult3 += (times[i].sleepingTime + times[i].readyTime); 

        else if(20 < childNumebrs[i] && childNumebrs[i] < 26)
            classResult2 += (times[i].sleepingTime + times[i].readyTime); 

        else if(25 < childNumebrs[i] && childNumebrs[i] < 31)
            classResult1 += (times[i].sleepingTime + times[i].readyTime);

        printf(1, "the WaitingTime for child %d is: %d\n", childNumebrs[i], (times[i].sleepingTime + times[i].readyTime));
    }

    result /= 30;
    classResult1 /= 5;
    classResult2 /= 5;
    classResult3 /= 5;
    classResult4 /= 5;
    classResult5 /= 5;
    classResult6 /= 5;

    printf(1, "------- the average WaitingTime for priority 1 is: %d -------\n", classResult1);
    printf(1, "------- the average WaitingTime for priority 2 is: %d -------\n", classResult2);
    printf(1, "------- the average WaitingTime for priority 3 is: %d -------\n", classResult3);
    printf(1, "------- the average WaitingTime for priority 4 is: %d -------\n", classResult4);
    printf(1, "------- the average WaitingTime for priority 5 is: %d -------\n", classResult5);
    printf(1, "------- the average WaitingTime for priority 6 is: %d -------\n", classResult6);

    printf(1, "------- the average WaitingTime is: %d -------\n", result);    
}