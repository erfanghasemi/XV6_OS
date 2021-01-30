# include "types.h"
# include "stat.h"
# include "user.h"


void printChildren(char* children);

int main(void)
{
    int p = 0;
    char* ptr = (char*)malloc(64 * sizeof(int)); 

    p = fork();

    for (int i = 0; i < 7; i++)
    {   
        if(p != 0)
        {
            p = fork();
        }
    }
    
    if(p != 0){
        getChildren(ptr);
        printChildren(ptr);
    }

    for (int i = 0; i < 8; i++)
    {
        wait();
    }

    exit();

    return 0; 
}

void
printChildren(char* children)
{   
    int i = 0;

    printf(1, "This is process %d and children are : ", getpid());

    while (children[i] != 0)
    {
        printf(1, "%d/ ", children[i]);
        i++;
    }
    printf(1, "\n");
}