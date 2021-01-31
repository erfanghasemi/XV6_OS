# include "types.h"
# include "stat.h"
# include "user.h"

int main(void)
{
    printf(1, "Parent Priority  = %d\n", getPriority());
    
    if(fork() == 0)
    {
        setPriority(0);
    }
    else
    {
        setPriority(6);
        wait();   
    }
    printf(1, "Process Priority  = %d\n", getPriority());
    exit();
    return 1;
}