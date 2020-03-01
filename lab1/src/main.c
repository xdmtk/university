#include <time.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <sys/times.h>
#include <unistd.h>

#include <lab1/main.h>


int main(int argc, char ** argv) {

    int shmid;
    void *shm;
    struct state *stp, *stc;
    pid_t self_identity;


    /* Allocate some shared memory so the child process can write to stc */
    shmid = shmget(SHARED_MEM_KEY, sizeof(struct state)*2, 0644|IPC_CREAT);

    /* Get a void pointer to the shared memory region using the ID returned from shmget() */
    shm =  shmat(shmid, NULL, 0);

    /* Set stp (state parent) to the 0 offset of shm, and set stc (state child) to the offset
     * of shm defined by the size of the state struct in memory */
    stp = shm; stc = shm+sizeof(struct state);


    /* Execute run() to collect all information and store them in the state structures
     *
     * The return value of fork() determines whether to call run() with the child
     * or parent state structs. Likewise, a `self_identity` flag is set so only the parent
     * process can call waitpid() and output the information gathered by run() */
    run((stp->cpid = self_identity = fork()) ? stp : stc);


    /* Allow only the parent process to call waitpid(), get the ending execution time,
     * and print out the results */
    if (self_identity != CHILD) {

        /* Parent process waits for child process, assigning the return value
         * to stc.retval (Child struct return value field) */
        waitpid(stp->cpid, &stc->retval,0);

        /* Get and store end time after child process terminates */
        stp->exec_end = time(NULL);

        /* Print out the information contained in stp and stc, both filled by a call to run() */
        out(stp, stc);
    }
    return 0;
}


/* Collects all required information */
void run(struct state * st) {

    /* Get and store time of execution */
    st->exec_begin = time(NULL);

    /* Declare buffer for call to times() */
    struct tms time_buf;

    /*  - The process ID of its parent (see getppid(2))
     *
     * Get and store parent process PID */
    st->ppid = getppid();

    /*  - Its own process ID (see getpid(2))
     *
     * Get and store current process PID */
    st->pid = getpid();


    /* - The process ID of it's child (if applicable) (see fork(2))
     *
     * This already completed on line 37
     * run((stp.cpid = self_identity = fork()....
     */


    /* - The return status of its child (if applicable) (see exit(3), waitpid(2))
     *
     * This is already completed on line 46
     * waitpid(stp.cpid, &stp.retval,0);
     */


    /* Fill the time buffer */
    times(&time_buf);

    /* The program will report the following time information
     * - User time
     */
    st->utime = time_buf.tms_utime;

    /* - System time */
    st->stime = time_buf.tms_stime;

    /* - User time of child */
    st->cutime = time_buf.tms_cutime;

    /* - System time of child */
    st->cstime = time_buf.tms_cstime;
}


void out(struct state *parent, struct state *child) {


    /* Output all required information in a single call to printf() */
    printf(
           "START: %ld\n"
           "PPID:%d, PID: %d\n"
           "PPID:%d, PID: %d, CPID: %d, RETVAL: %d\n"
           "USER: %ld, SYS: %ld\n"
           "CUSER:%ld, CSYS: %ld\n"
           "STOP: %ld\n",
            parent->exec_begin,
            child->ppid, child->pid,
            parent->ppid, parent->pid, child->pid, child->retval,
            parent->utime, parent->stime,
            parent->cutime, parent->cstime,
            parent->exec_end
    );
}
