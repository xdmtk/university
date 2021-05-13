#ifndef LAB4_PHILOSOPHER_H
#define LAB4_PHILOSOPHER_H
#include <semaphore.h>

#define ARG_FAIL 0
#define ARG_SUCCESS 1

/* The default RAND_MAX is a bit too long observe the program properly */
#define MAX_SLEEP 1000000

#define BASE_10 10
#define IS_VALID_INT(arg_pos, valid) (((valid == argv[arg_pos]) || (*valid != '\0')) == 0)

#define CHOPSTICK_SEM "chopstick_number_"
#define CHOPSTICK_ALLOCATOR_SEM "chopstick_allocator"

#define PROCESS_GROUP_FILE "pgroup.txt"

#define LEFT_CHOPSTICK st->position % st->seats
#define RIGHT_CHOPSTICK (st->position+1) % st->seats

#define CRITICAL_SECTION_BLOCKED 0
#define CRITICAL_SECTION_OK 1
#define ENTER_CRITICAL 2
#define EXIT_CRITICAL 3

struct state {
    int seats;
    int position;
    int cycles;
    sem_t ** chopsticks;
    sem_t * chopstick_allocator;
};

void set_process_group(void);
int validate_args(int argc, char ** argv, struct state * st);

int hold_and_wait(struct state *st, int mode);
void init_chopstick_allocator(struct state * st);
void init_chopsticks(struct state * st);
void release_chopsticks(struct state *st);

void eat(struct state * st);
void think(struct state * st);

void sigterm_handler(int signal);

#endif //LAB4_PHILOSOPHER_H
