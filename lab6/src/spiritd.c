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

#include <lab6/spiritd.h>

/* Signal flags for daemon to respond to */
volatile sig_atomic_t term = 0;
volatile sig_atomic_t usr1 = 0;
volatile sig_atomic_t usr2 = 0;


int main(void) {
    
    struct state st;
    st.moles[0] = st.moles[1] = 0;

    
    /* Find the mole binary path for later calls to execve() */
    if (!get_mole_bin_path(&st)) {
        fprintf(stderr, "Could not find 'mole' executable, "
                "please run 'make moles'\n");
        exit(EXIT_FAILURE);
    }
    
    /* Handle all daemon coding standards */
    daemon_init(&st);
    
    /* Register signals */
    register_signals();
    
    /* Main daemon event loop */
    while (respond_to_signals(&st)) sleep(1);

}


/**
 * @brief get_mole_bin_path - Looks for the 'mole' executable
 * in the current working directory and stores the fully qualified 
 * path in state structure 
 *
 * @param st - Holds state information for the program
 */
int get_mole_bin_path(struct state *st) {
    
    struct stat buf;
    char bin_path[4096];
    
    /* Form the fully qualified pathname of the mole binary
     * This should be in the same initial working directory as the
     * spiritd binary */
    memset(bin_path, '\0', 4096);
    getcwd(bin_path, 4096);
    strcat(bin_path, "/mole");
    
    /* Check for existence */
    if (stat(bin_path, &buf) == 0) {
        strcpy(st->mole_bin_path, bin_path);
        return true;
    }
         
    return false;
}


/**
 * @brief daemon_init - Handles all necessary startup code
 * for initializing a Linux daemon, namely 
 * - Fork and exit
 * - Set file creation mask to 0
 * - Set session ID and process group 
 * - Change current working directory to root 
 * - Close all unneeded file descriptors
 * - Reopen file descriptors to map to /dev/null
 */
void daemon_init(struct state * st) {
    
    /* Fork off the parent and exit, allowing the child to continue
     * on a successful call to fork() */
    fork_and_exit(st);

    /* Set file creation mask to 0 */
    umask(0);
    
    /* Create a new session */
    st->sid = setsid();
    
    /* Change the current working directory to "/" */
    chdir(ROOT_DIR);
    
    /* Close all unneeded file descriptors and map standard
     * file descriptors to /dev/null */
    redirect_file_descriptors();
}


/**
 * @brief fork_and_exit - Handles the initial child fork needed 
 * to initialize a daemon process in Linux 
 */
void fork_and_exit(struct state * st) {
    
    
    /* First things first, fork off the parent and exit */
    if ((st->ret = fork()) < 0) {

        /* Fork failure exits the parent with failure return status */
        fprintf(stderr, "Daemon failed to fork child process\n");
        exit(EXIT_FAILURE); 
    }
    else if (st->ret > 0) {

        /* Fork success exits parent process normally */
        exit(EXIT_SUCCESS);
    }
}


/**
 * @brief redirect_file_descriptors - Closes out 
 * all standard file descriptors, and redirects them to
 * /dev/null
 */
void redirect_file_descriptors(void) {
    
    int fd = open(DEV_NULL, O_WRONLY);

    /* Reroute stdin, stdout, and stderr to /dev/null 
     * (this isn't technically necessary when we are closing stdin, stdout, 
     * and stderr in the following lines, but the Lab instructions specifically
     * call for this) */
    dup2(fd, STDIN_FILENO);
    dup2(fd, STDOUT_FILENO);
    dup2(fd, STDERR_FILENO);
    
    /* Close out existing file descriptors */
    close(STDIN_FILENO);
    close(STDOUT_FILENO);
    close(STDERR_FILENO);
}


/**
 * @brief respond_to_signals - Called repeatedly in the main
 * daemon loop to check on the signal flags and respond accordingly
 */
int respond_to_signals(struct state * st) {
    
    int rand_mole, usr_flag;
    char mole_string[6];
    char * args[3];


    memset(mole_string, '\0', 6);
    usr_flag = 0;

    /* Respond to SIGTERM by killing all children and exiting */
    if (term) {
        kill(st->moles[0], SIGKILL);
        kill(st->moles[1], SIGKILL);
        exit(EXIT_SUCCESS);
    }
    /* On SIGUSR1, kill mole 1 and randomly create mole 1 or 2 */
    else if (usr1) {
        
        /* If mole 1 exists (noted by an existing PID), kill it */
        if (st->moles[0]) 
            kill(st->moles[0], SIGKILL);

        /* Set mole 1 PID to 0 */
        st->moles[0] = 0;

        --usr1;
        ++usr_flag;
    }
    else if (usr2) {
        
        /* If mole 2 exists (noted by an existing PID), kill it */
        if (st->moles[1]) 
            kill(st->moles[1], SIGKILL);

        /* Set mole 2 PID to 0 */
        st->moles[1] = 0;

        --usr2;
        ++usr_flag;
    }
    

    /* Exec new random mole if either USR1 or USR2 has been caught */
    if (usr_flag) {

        /* Kill random mole number */
        rand_mole = rand() % 2;

        /* Prepare the argument vector the upcoming call to execve() */
        sprintf(mole_string, "mole%d", (rand_mole ? 2 : 1));
        args[0] = st->mole_bin_path; 
        args[1] = mole_string;

        /* Terminate the argument vector with a null pointer - execve() sets 
         * errno to EFAULT when  this is not the case */
        args[2] = (char *)0;


        
        /* If the random mole selected doesn't already exist, fork from the daemon to
         * use the child process to execve a new mole, and exit after execution (as to keep 
         * only 1 daemon process) */
        if (!st->moles[rand_mole] && !(st->moles[rand_mole] = fork() )) {

            execve(st->mole_bin_path, args, NULL);

            /* Exit child after executing mole */
            exit(EXIT_SUCCESS);
        }


    }
    return true;
}



/**
 * @brief register_signals - Register signals
 * TERM, USR1, and USR2 to universal signal handler 
 */
void register_signals(void) {
    
    int sigs[] = {SIGTERM, SIGUSR1, SIGUSR2}, i;

    for (i=0; i<3; ++i) { 
        if (signal(sigs[i], signal_handler) == SIG_ERR) {
            exit(EXIT_FAILURE);
        }
    }

}


/** 
 * @brief signal_handler - Updates the corresponding signal flag 
 * after catching a given signal 
 */
void signal_handler(int signal) {
    switch (signal) {
        case SIGTERM: ++term; break;
        case SIGUSR1: ++usr1; break;
        case SIGUSR2: ++usr2; break;
    }
}


