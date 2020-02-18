#include <time.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/times.h>
#include <unistd.h>

#include <lab1/main.h>


int main(int argc, char ** argv) {

    struct state stp, stc;
    unsigned char self_identity;
    stp.identity = PARENT;
    stc.identity = CHILD;

    /* Assign the child PID to the parent state struct. A non zero assignment
     * executes run() with the parent state struct, while a zero assignment
     * executes run() with the child state struct */
    run((stp.cpid = self_identity = fork()) ? &stp : &stc);

    /* Parent process waits for child process, assigning the return value
     * to stp.retval */
    waitpid(stp.cpid, &stp.retval,0);

    /* Allow only the parent process to get the ending execution time
     * and print out the results */
    if (self_identity != CHILD) {
        /* Get and store end time after child process terminates */
        stp.exec_end = time(NULL);

        out(&stp, &stc);
    }
    return 0;
}

void run(struct state * st) {

    /* Get and store time of execution */
    st->exec_begin = time(NULL);

    struct tms time_buf;

    /* Get and store current process PID */
    st->pid = getpid();

    /* Get and store parent process PID */
    st->ppid = getppid();

}


void out(struct state *parent, struct state *child) {
    printf("START: %d\n", parent->exec_begin);
    printf("STOP: %d\n", parent->exec_end);
}
