typedef unsigned int   uint;
typedef unsigned short ushort;
typedef unsigned char  uchar;
typedef uint pde_t;
typedef struct times
{
    /* data */
  uint creationTime;            // allocation time
  uint terminationTime;         // exit time
  uint runningTime;             // RUNNING state
  uint readyTime;               // RUNNABLE state
  uint sleepingTime;            // SLEEPING state
} Times;