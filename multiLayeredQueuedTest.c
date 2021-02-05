#include "types.h"
#include "stat.h"
#include "user.h"

Times *times;

void
averageCBT(Times *times)
{
int result = 0;
int counter = 0;
int layer = 0;
int layer_result = 0;

for (int i = 0; i < 40; i++){ 
counter++; 
result += times[i].runningTime;
layer_result += times[i].runningTime;
printf(1, "the CBT for process %d is: %d\n", i, times[i].runningTime);

if (counter == 10){
counter = 0;
layer_result /= 10;
printf(1, "+++++++ the average CBT for class %d is: %d +++++++\n", layer, layer_result);
layer_result = 0;
layer++;
}
}

result /= 40;

printf(1, "------- the average CBT is: %d -------\n", result);
}

void
averageTurnaroundTime(Times *times)
{
int result = 0;
int counter = 0;
int layer = 0;
int layer_result = 0;

for (int i = 0; i < 40; i++){ 
counter++; 
result += (times[i].runningTime + times[i].sleepingTime + times[i].readyTime);
layer_result += (times[i].runningTime + times[i].sleepingTime + times[i].readyTime);
printf(1, "the TurnAroundTime for process %d is: %d\n", i, (times[i].runningTime + times[i].sleepingTime + times[i].readyTime));
if (counter == 10){
counter = 0;
layer_result /= 10;
printf(1, "+++++++ the average TurnAroundTime for layer %d is: %d +++++++\n", layer, layer_result);
layer_result = 0;
layer++;
}
}

result /= 40;

printf(1, "------- the average TurnAroundTime is: %d -------\n", result);
}

void
averageWaitingTime(Times *times)
{
int result = 0;
int counter = 0;
int layer = 0;
int layer_result = 0;

for (int i = 0; i < 40; i++){ 
counter++; 
result += (times[i].sleepingTime + times[i].readyTime);
layer_result += (times[i].sleepingTime + times[i].readyTime);
printf(1, "the waitingTime for process %d is: %d\n", i, (times[i].sleepingTime + times[i].readyTime));

if (counter == 10){
counter = 0;
layer_result /= 10;
printf(1, "+++++++ the average waitingTime for layer %d is: %d +++++++\n", layer, layer_result);
layer_result = 0;
layer++;
}
}

result /= 40;

printf(1, "------- the average waitingTime is: %d -------\n", result);
}

int find_class(int number);
int find_class2(int number);

int main(void)
{ 
times = (Times *) malloc(40 * sizeof(Times));
changePolicy(4);
//setPriority(1);

int p = 1;
int counter = 0;
int i, j, k;

for(i = 0; i < 40; i++){
if(p != 0){
counter++;
p = fork(); 
}
else
{ 
if ((1 <= counter) && (counter <= 10))
enQueue(0);
else if ((11 <= counter) && (counter >= 20))
enQueue(1);
else if ((21 <= counter) && (counter >= 30)){
enQueue(2);
setPriority(find_class(counter));
} 
else if ((31 <= counter) && (counter >= 40)){
enQueue(3);
setPriority(find_class2(counter));
} 
}
}

if(p == 0)
{
for(j=1;j<200;j++)
{
printf(1,"[%d]:[%d]\n",counter,j);
}
exit();
}

for (k = 0; k < 40; k++){
wait2(&times[k]);
}

averageCBT(times);
printf(1, "=======================================================\n");
averageTurnaroundTime(times);
printf(1, "=======================================================\n");
averageWaitingTime(times);
exit();
return 1;
}

int
find_class(int number)
{
if(21 <= number && number <= 24)
return 4;

else if(25 <= number && number <= 26)
return 3;

else if(27 <= number && number <= 28)
return 2; 

else if(29 <= number && number <= 30)
return 1; 

return 0; 
}

int
find_class2(int number)
{
if(31 <= number && number <= 34)
return 4;

else if(35 <= number && number <= 36)
return 3;

else if(37 <= number && number <= 38)
return 2; 

else if(39 <= number && number <= 40)
return 1; 

return 0; 
}
