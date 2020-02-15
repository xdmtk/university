#ifndef LAB1_MAIN_H
#define LAB1_MAIN_H
#define PARENT 0x0
#define CHILD 0x1

struct state {
    unsigned char identity;
    time_t exec_begin;
    pid_t ppid;
    pid_t pid;
    pid_t cpid;
    int retval;
    time_t utime;
    time_t stime;
    time_t c_utime;
    time_t c_stime;
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
 * @param st
 */
void out(struct state *st);
#endif //LAB1_MAIN_H
