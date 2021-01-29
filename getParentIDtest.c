# include "types.h"
# include "stat.h"
# include "user.h"

int main()
{    
    int p;

    printf(1, "--------------Start Testing--------------\n");
    printf(1, "This is process %d and the parent id is %d\n", getpid(), getparentid());
    p = fork();
    
    if(p == 0)
    {    
        printf(1, "----------------Step One----------------\n");
        printf(1, "This is process %d and the parent id is %d\n", getpid(), getparentid());
        
        p = fork();

        if(p == 0)
        {
            printf(1, "----------------Step two----------------\n");
            printf(1, "This is process %d and the parent id is %d\n", getpid(), getparentid());

            p = fork();
            if(p == 0)
            {
                printf(1, "----------------Step three----------------\n");
                printf(1, "This is process %d and the parent id is %d\n", getpid(), getparentid());
            }

            wait();
        }
        wait();
    }
    wait();

    return 0;
}