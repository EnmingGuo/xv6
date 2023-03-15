#include "kernel/types.h"
#include "kernel/stat.h"
#include "kernel/timer.h"
#include "user/user.h"
#include "kernel/param.h"
#include "kernel/fs.h"
#include "kernel/fcntl.h"
#include "kernel/syscall.h"
#include "kernel/memlayout.h"
#include "kernel/riscv.h"

int main(int argc, char *argv[])
{
    //printf("Starting time at %l\n", SYSTIME(0));
    int pid = fork();
   
   uint64 START_TIME = SYSTIME(0);
    if (pid == 0)
    {
      if(argc==1) exit(0);
        exec(argv[1], argv + 1);
        
    }
    
        wait((int *)0);
        printf("DURATION: %l\t EXEC RETURN;\n", (SYSTIME(0) - START_TIME));
    

    exit(0);
}