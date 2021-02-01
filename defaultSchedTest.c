#include "types.h"
#include "stat.h"
#include "user.h"

int
main()
{   
    changePolicy(0);

    int i, j, k;
    
    for (i = 0; i < 30; i++)
    {
        if (fork() == 0)
        {
            for (j = 1; j < 31; j++)
                printf(1, "%d : %d\n", getpid(), j);
            exit();
        }
    }

    for (k = 0; k < 30; k++)
        wait();

    exit();
}