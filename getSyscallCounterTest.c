# include "types.h"
# include "stat.h"
# include "user.h"


int main(void)
{
    int p;

    printf(1, "Parent process sys_fork count = %d\n", getSyscallCounter(1));
    
    p = fork();

    if (p == 0)
    {
        printf(1, "Child process sys_fork count = %d\n", getSyscallCounter(1));

        for (int i = 0; i < 16; i++)
            getpid();

        printf(1, "child sys_getpid count %d\n", getSyscallCounter(11));
    }
    else
    {
        wait();
        printf(1, "parent fork count %d\n", getSyscallCounter(1));
        sleep(1);
        printf(1, "parent sys_sleep count %d\n", getSyscallCounter(13));
    }
    printf(1, "process sys_wait count = %d\n", getSyscallCounter(3));
    printf(1, "process sys_syscallcounter count = %d\n", getSyscallCounter(24));
    
    exit();

    return 0;
}