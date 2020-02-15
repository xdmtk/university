#include <time.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

#include <lab1/main.h>


int main(int argc, char ** argv) {
    struct state stp, stc;
    stp.identity = PARENT;
    stc.identity = CHILD;

    run(fork() ? &stp : &stc);
    return 0;
}

void run(struct state * st) {

    /* Get and store time of execution */
    st->exec_begin = time(NULL);

    /* Get and store current process PID */
    st->pid = getpid();

    /* Get and store parent process PID */
    st->ppid = getppid();
}

