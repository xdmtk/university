#ifndef LAB1_MAIN_H
#define LAB1_MAIN_H
#define PARENT 0x1
#define CHILD 0x0
#define SHARED_MEM_KEY 0xdeadbeef

struct state {
    time_t exec_begin;
    pid_t ppid;
    pid_t pid;
    pid_t cpid;
    int retval;
    time_t utime;
    time_t stime;
    time_t cutime;
    time_t cstime;
    time_t exec_end;
};

/**
 * Performs all specified functions for Lab 1, filling struct state
 * with required information
 *
 * @param st
 */
void run(struct state *st);

/**
 * Outputs all required information contained in struct state
 *
 * @param parent
 */
void out(struct state *parent, struct state *child);
#endif //LAB1_MAIN_H
