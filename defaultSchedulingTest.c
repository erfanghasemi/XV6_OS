#include "types.h"
#include "stat.h"
#include "user.h"

int
main()
{   
    int p = 0;
    int childID;
    int i, j, k;

    p = fork();
    for(i=0;i<9;i++){
        if(p != 0){
            p = fork();
        }
        else
        {
            break;
        }
    }    

    if(p == 0)
    {   
        childID = getpid();
        for(j=0;j<200;j++)
        {
            printf(1,"[%d]:[%d]\n",childID,i);
        }
    }

    for (k = 0; k < 10; k++)
        wait();

    exit();
}