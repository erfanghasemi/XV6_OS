#include "types.h"
#include "stat.h"
#include "user.h"

int
main()
{   
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

    for (k = 0; k < 10; k++)
        wait();

    exit();
}