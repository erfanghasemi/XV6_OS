# include "types.h"
# include "stat.h"
# include "user.h"


int main(void)
{   
    printf(1, "Parent Policy Mode = %d\n", getPolicy());
    changePolicy(2);
    printf(1, "Parent Policy Mode = %d\n", getPolicy());
    fork();
    wait();
    exit();
    return 1;
}