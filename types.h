typedef unsigned int   uint;
typedef unsigned short ushort;
typedef unsigned char  uchar;
typedef uint pde_t;
typedef struct times
{
    /* data */
  int creationTime;            // allocation time
  int runningTime;             // RUNNING state
  int readyTime;               // RUNNABLE state
  int sleepingTime;            // SLEEPING state
} Times;