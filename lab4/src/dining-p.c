#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <semaphore.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/times.h>
#include <time.h>
#include <unistd.h>

#include <lab4/dining-p.h>



/* It turns out that back in Lab 3, having a signal handler read/write 
 * to an ordinary global variable is _bad_, however because any global variable reads
 * from synchronous sections of the code are guarenteed to happen _after_
 * the signal handler has written to it (as opposed to at the exact same time)
 * due to the pause() loop that waits for an emitted signal, it turned out
 * not to have caused any problems.
 *
 * Though in this program, it is definitely possible for a signal handler to write
 * to a global at the exact same time that global is read by the synchronous
 * code, therefore we need to use a sig_atomic_t type variable to use as our flag
 * for SIGTERM exits, and add the volatile keyword to it as well, forcing the compiler
 * to avoid caching/optimizing this variable as it may change at any given moment.
 */
volatile sig_atomic_t exit_flag = 0;



int main(int argc, char ** argv) {

    struct state st;
    
    /* Validate CLI arguments for seat/position */
    if (validate_args(argc, argv, &st) == ARG_FAIL) {
        fprintf(stderr, "CLI Argument validation failed!\n");
        return -1;
    }
    
    /* Register SIGTERM to signal handler */
    if ((signal(SIGTERM, sigterm_handler) == SIG_ERR) 

            /* Also registering SIGINT (sent by CTRL-C) here, since 
             * this is the typical way this program will close during testing */
            || (signal(SIGINT, sigterm_handler) == SIG_ERR)) { 

        fprintf(stderr, "Could not register signal!\n");
        return -1;
    }

    /* Set process group ID */
    set_process_group();

    /* Seed random generator */
    srand(time(NULL));

    /* Create named semaphores representing chopsticks if they haven't already
     * been created */
    init_chopsticks(&st);
    
    /* Create named allocator semaphore, to solve the critical section problem among
     * philosophers attempting to initiate their eat/think cycle */
    init_chopstick_allocator(&st);

    /* Enter Eat/Think cycle until SIGTERM is caught and updates
     * the exit_flag atomic variable */
    while (!exit_flag) {

        /* Part II - Hold and wait before entering critical section */
        if (hold_and_wait(&st, ENTER_CRITICAL) == CRITICAL_SECTION_OK) {
            eat(&st);
            think(&st);
            st.cycles++;
            
            /* Post to the allocator semaphore when eat/think cycle is complete */
            hold_and_wait(&st, EXIT_CRITICAL);
        }
        else {

            /* Dont get stuck in the hold and wait loop if SIGTERM
             * has been issued */
            if (exit_flag) break;
        }
    }
    
    /* Close, unlink, and free chopstick/semaphore resources */
    release_chopsticks(&st);
    return 0;
}



/**
 * @brief eat - Philosopher eating function. Prints to stdout a message to indicate
 * the philosopher is eating, and then sleeps for a random amount of time
 * before returning
 *
 * @param struct state st - Program state containing philosopher position/seat
 */
void eat(struct state * st) {
    
    /* Lock the chopstick semaphores to the left and right of the philosopher */
    if (sem_wait(st->chopsticks[LEFT_CHOPSTICK]) != -1 && 
            sem_wait(st->chopsticks[RIGHT_CHOPSTICK]) != -1) {
        
        /* If the philosopher could pick both chopsticks up, start eating */
        fprintf(stdout, "Philosopher #%d is eating\n", st->position);
        usleep(rand() % MAX_SLEEP);
    }
}



/**
 * @breif think - Philosopher thinking function. Prints to stdout a message to indicate
 * the philosopher is thinking, and then sleeps for a random amount of time
 * before returning
 *
 * @param struct state st - Program state containing philosopher position/seat
 */
void think(struct state * st) {

    /* Unlock the chopstick semaphores to the left and right of the philosopher */
    if (sem_post(st->chopsticks[LEFT_CHOPSTICK]) != -1 &&
            sem_post(st->chopsticks[RIGHT_CHOPSTICK]) != -1) {

        fprintf(stdout, "Philosopher #%d is thinking\n", st->position);
        usleep(rand() % MAX_SLEEP);
    }
}



/**
 * @brief init_chopstick_allocator - This function represents the 
 * "Hold and Wait" portion of Part II. Here we allocate an additional
 * semaphore, which will be used to make sure that no more than one philosopher can 
 * execute their critical sections at any given moment (picking up or putting down
 * their chopstick).
 *
 * @param struct state st - Program state chopstick semaphors and allocator semaphore 
 */
void init_chopstick_allocator(struct state * st) {
    st->chopstick_allocator = sem_open(CHOPSTICK_ALLOCATOR_SEM, O_CREAT, 0644, 1);
}



/**
 * @brief hold_and_wait - This function determines whether the chopstick_allocator
 * semaphore is available to wait on. If it is, the function returns a macro indicating
 * the philosopher has permission to execute its critical section (eat or think)
 *
 * This function executes essentially as a busy wait
 *
 * @param struct state st - Program state chopstick semaphors and allocator semaphore 
 * @param int mode - Macro indicating entering or exiting critical code section
 */
int hold_and_wait(struct state *st, int mode) {

    /* If called with the ENTER_CRITICAL macro, execute sem_trywait() to 
     * busy wait on the allocator semaphore. Return a macro indicating whether
     * the caller has permission to execute its critical section */
    if (mode == ENTER_CRITICAL) {

        return (sem_trywait(st->chopstick_allocator) >= 0) ? CRITICAL_SECTION_OK 
            : CRITICAL_SECTION_BLOCKED;
    }

    /* If called with the EXIT_CRITICAL macro, the caller posts to the 
     * allocator semaphore, indicating that it has finished its critical section,
     * and other callers busy waiting on this semaphore can now enter their 
     * critical sections */
    else if (mode == EXIT_CRITICAL) {

        sem_post(st->chopstick_allocator);
        return CRITICAL_SECTION_OK;
    }
    return CRITICAL_SECTION_OK;
}



/** 
 * @brief init_chopsticks - This function opens the named semaphores
 * representing the chopsticks on the table, and stores them into
 * the dynamically allocated array of semaphores stored in the program
 * state structure
 *
 * @param struct state st - Program state containing the semaphore array 
 */
void init_chopsticks(struct state * st) {

    int i;
    char chopstick_sem_name[32];

    /* Allocate the chopstick semaphore array */
    st->chopsticks = malloc(sizeof(sem_t *)*st->seats);

    /* Create as many chopsticks as there are seats */
    for (i = 0; i < st->seats; ++i) {

        /* Zero out the semaphore name buffer */
        memset(chopstick_sem_name,0,32);

        /* Create a new named semaphore of the macro CHOPSTICK_SEM with a
         * numbered suffix to identify the chopstick */
        sprintf(chopstick_sem_name, CHOPSTICK_SEM "%d", i);
        

        /* Open the semaphore and store it's pointer into the semaphore array
         * in the program state structure */
        st->chopsticks[i] = sem_open(chopstick_sem_name, O_CREAT, 0644, 1);
    }
}



/** 
 * @brief release_chopsticks - This function closes the named semaphores
 * representing the chopsticks on the table, by iterating through the 
 * semaphore array and calling sem_close() on all named semaphores
 *
 * @param struct state st - Program state containing the semaphore array 
 */
void release_chopsticks(struct state * st) {
    
    int i;
    char chopstick_sem_name[32];
    
    for (i = 0; i < st->seats; ++i) {

        /* Close the semaphore and check for error */
        if (sem_close(st->chopsticks[i]) == -1) {
            fprintf(stderr, "Failed to close named semaphore "
                    CHOPSTICK_SEM "%d!\n", i);
        }
    
        /* Zero out the semaphore name buffer and similar to init_chopsticks()
         * generate the semaphore name by using the name macro and appending 
         * a its identifying number for the unlinking process */
        memset(chopstick_sem_name,0,32);
        sprintf(chopstick_sem_name, CHOPSTICK_SEM "%d", i);
        
        /* Unlink the semaphore and check for errors */
        if (sem_unlink(chopstick_sem_name) == -1) {

            /* Leaving this error message out since the first philosopher to exit will 
             * be able to unlink (physically remove) the named semaphores, and the rest
             * will fail because they've already been destroyed */
            //fprintf(stderr, "Failed to unlink named semaphore "
            //          CHOPSTICK_SEM "%d!\n", i);
        }
        
    }
    
    /* Print to stderr amount of completed cycles */
    fprintf(stderr, "Philospher #%d completed %d cycles\n", 
            st->position, st->cycles);

    /* Close out the allocator chopstick */
    sem_close(st->chopstick_allocator);
    sem_unlink(CHOPSTICK_ALLOCATOR_SEM);

    /* Free the dynamically allocated semaphore array */
    free(st->chopsticks);
}



/**
 * @brief validate_args - Validates CLI arguments for seats/position 
 * specification
 *
 * @param argc - Count of total CLI arguments
 * @param argv - CLI Argument vector
 * @param st - Program state struct - Holds parsed CLI args
 *
 * @return int - Macro indicating CLI argument parse success/failure 
 */
int validate_args(int argc, char ** argv, struct state * st) {

    char * num_validator;
    
    /* Need at least seat and position argument specified */
    if (argc < 3) {
        fprintf(stderr, "usage: dining-p [seats] [position]\n");
        return ARG_FAIL;
    }
   
    /* Parse seat argument to integer */
    st->seats = strtol(argv[1], &num_validator, BASE_10);

    /* Then validate it using *endptr param of strtol() */
    if (!IS_VALID_INT(1, num_validator) || st->seats <= 1) {
        fprintf(stderr, "Seats specified: %s - not a valid integer\n", argv[1]);
        return ARG_FAIL;
    }


    /* Parse seat argument to integer */
    st->position = strtol(argv[2], &num_validator, BASE_10);

    /* Then validate it using *endptr param of strtol() */
    if (!IS_VALID_INT(2, num_validator)) {
        fprintf(stderr, "Position specified: %s - not a valid integer\n", argv[2]);
        return ARG_FAIL;
    }
    
    /* Validate whether specified position is in valid range of specified seats */
    if (st->position > st->seats) {
        fprintf(stderr, "Position specified: %s - greater than total seats %s\n",
                argv[2], argv[1]);
        return ARG_FAIL;
    }
    
    st->cycles = 0;
    return ARG_SUCCESS;
}


/**
 * @brief set_process_group - Checks for the existence 
 * of a file that contains the process group for the group of 
 * philosopher processes. If no such file exists, a file is created
 * and the process group ID number of this instance is written to the file.
 *
 * If the file does exist, it is read, and the process group ID for this
 * instance is manually set to the number read from the file 
 */
void set_process_group(void) {

    struct stat buf;
    FILE * fp;
    
    /* Check for file existence */
    if (stat(PROCESS_GROUP_FILE, &buf) == 0) {

        char * line = NULL;
        size_t len = 0;

        /* Open for reading */
        fp = fopen(PROCESS_GROUP_FILE, "r");
        
        /* Read the existing process group ID */
        getline(&line, &len, fp);

        /* Set this instance process group ID */
        setpgid(getpid(), strtol(line, NULL, 10));
        fclose(fp);
    }
    else {

        char pidbuf[16];
        memset(pidbuf, '\0', 16);
        
        /* Open for writing */
        fp = fopen(PROCESS_GROUP_FILE, "w");

        /* Convert this process group ID to string */
        sprintf(pidbuf, "%d", getpgid(getpid()));

        /* Write it to file */
        fwrite(pidbuf, sizeof(char), sizeof(pidbuf), fp);
        fclose(fp);
    }

}


/**
 * @brief sigterm_handler - Signal handler for the SIGTERM signal. Updates 
 * the atomic volatile flag to indicate the program should exit from 
 * the eat/think cycle
 *
 * @param int signal - The signal macro caught 
 */
void sigterm_handler(int signal) {
    if (signal == SIGTERM || signal == SIGINT) exit_flag = 1;
}
