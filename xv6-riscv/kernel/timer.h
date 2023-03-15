#include "param.h"

uint64 SYSTIME(int id);

uint64 SYSINTERVAL(int id);

void UpdateInterval(int interval);

void PrintInterval();

void PrintTime();

void PrintDynamicInterval();

/* The following variables are initialized by start.c */
// Load the timer_scratch data used for timervec interrupt handler.
// timer_scratch[id][0..2] : space for timervec to save registers for CPU[id].
// timer_scratch[id][3] : address of CLINT MTIMECMP register for CPU[id].
// timer_scratch[id][4] : desired interval (in cycles) between timer interrupts for CPU[id].
// timer_scratch[id][5] : address of CLINT MTIME register
// timer_scratch[id][6] : value of current time in mtime register
extern uint64 timer_scratch[NCPU][7];
extern struct spinlock tscratch_lock;
