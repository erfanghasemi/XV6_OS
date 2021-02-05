typedef unsigned int   uint;
typedef unsigned short ushort;
typedef unsigned char  uchar;
typedef uint pde_t;

// Struct (Added)
typedef struct times
{
  int creationTime;            // allocation time (Added)
  int runningTime;             // RUNNING state (Added)
  int readyTime;               // RUNNABLE state (Added)
  int sleepingTime;            // SLEEPING state (Added)
} Times;
