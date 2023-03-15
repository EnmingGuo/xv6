#include "types.h"
#include "param.h"
#include "memlayout.h"
#include "riscv.h"
#include "spinlock.h"
#include "proc.h"
#include "defs.h"
#include "timer.h"

/* Safely read system time for CPU[id] */
uint64 SYSTIME(int id)
{
   uint64 time;
   acquire(&tscratch_lock);
   time = timer_scratch[id][6];
   release(&tscratch_lock);
   return time;
}

/* Safely read system interval setting for CPU[id] */
uint64 SYSINTERVAL(int id)
{
   uint64 interval;
   acquire(&tscratch_lock);
   interval = timer_scratch[id][4];
   release(&tscratch_lock);
   return interval;
}

void UpdateInterval(int interval)
{
   acquire(&tscratch_lock);
   timer_scratch[0][4] = interval;    //set clock f to interval/10th of a second
   release(&tscratch_lock);
}

void PrintInterval()
{
   printf("Set interval is: %d\n", SYSINTERVAL(0));
}

/* Prints time of most recent tick */
void PrintTime()
{
   printf("Time: %d\n", SYSTIME(0));
}
