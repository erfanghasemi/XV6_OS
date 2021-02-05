#include "types.h"
#include "stat.h"
#include "user.h"

Times *times;

void
averageCBT(Times *times)
{
    int result = 0;
    int counter = 0;
    int class = 6;
    int class_result = 0;

    for (int i = 0; i < 30; i++){  
        counter++;     
        result += times[i].runningTime;
        class_result += times[i].runningTime;
        if (counter == 5){
            counter = 0;
            class_result /= 5;
            printf(1, "the average CBT for class %d is: %d\n", class, class_result);
            class_result = 0;
            class--;
        }
        printf(1, "the CBT for process %d is: %d\n", i, times[i].runningTime);
    }

    result /= 30;

    printf(1, "the average CBT is: %d\n", result);
}

void
averageTurnaroundTime(Times *times)
{
    int result = 0;
    int counter = 0;
    int class = 6;
    int class_result = 0;

    for (int i = 0; i < 30; i++){  
        counter++;     
        result += (times[i].runningTime + times[i].sleepingTime + times[i].readyTime);
        class_result += (times[i].runningTime + times[i].sleepingTime + times[i].readyTime);
        if (counter == 5){
            counter = 0;
            class_result /= 5;
            printf(1, "the average TurnAroundTime for class %d is: %d\n", class, class_result);
            class_result = 0;
            class--;
        }
        printf(1, "the TurnAroundTime for process %d is: %d\n", i, (times[i].runningTime + times[i].sleepingTime + times[i].readyTime));
    }

    result /= 30;

    printf(1, "the average TurnAroundTime is: %d\n", result);
}

void
averageWaitingTime(Times *times)
{
    int result = 0;
    int counter = 0;
    int class = 6;
    int class_result = 0;

    for (int i = 0; i < 30; i++){  
        counter++;     
        result += (times[i].sleepingTime + times[i].readyTime);
        class_result += (times[i].sleepingTime + times[i].readyTime);
        if (counter == 5){
            counter = 0;
            class_result /= 5;
            printf(1, "the average waitingTime for class %d is: %d\n", class, class_result);
            class_result = 0;
            class--;
        }
        printf(1, "the waitingTime for process %d is: %d\n", i, (times[i].sleepingTime + times[i].readyTime));
    }

    result /= 30;

    printf(1, "the average waitingTime is: %d\n", result);
    
}

int find_class(int number);

int main(void)
{   
    times = (Times *) malloc(30 * sizeof(Times));
    changePolicy(1);
    setPriority(1);

    int p = 1;
    int counter = 0;
    int i, j, k;

    for(i = 0; i < 30; i++){
        if(p != 0){
            counter++;
            p = fork(); 
        }
        else
        {   
            setPriority(find_class(counter));
        }
    }

    if(p == 0)
    {
        for(j=1;j<50;j++)
        {
            printf(1,"[%d]:[%d]\n",find_class(counter),j);
        }
    }
    

    for (k = 0; k < 30; k++){
        wait2(&times[k]);
    }

    averageCBT(times);
    averageTurnaroundTime(times);
    averageWaitingTime(times);
    
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