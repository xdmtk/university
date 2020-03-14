#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/times.h>
#include <unistd.h>

#include <lab2/launch.h>


int main(int argc, char ** argv) {
    
    
    struct state st;
    
    /* Validate CLI arguments */
    if (validate_args(argc, argv, &st) == ARG_FAIL) {

        /* Print to stderr on argument parse failure */
        fprintf(stderr, "Bad argument format or exec path doesn't exist\n");

        /* Exit with -1 error status */
        exit(-1);
    }
    
    /* Call run(), performing all required actions for the program */
    return run(&st);
}



/**
 * 
 * This function executes all required actions for the program, namely
 *      
 *      Forking a child process
 *      Prints the child process PID on stderr 
 *      Prints any error output from the child on stderr (Not specified but implied via screenshot)
 *      Prints the return value of the child on stderr
 *
 * The new argv structure is already prepared and stored in st->child_exec_args in the call 
 * to validate_args() 
 *
 * @param struct state *st - General state structure holding information related to the program 
 * @return int - Returns 0 for parent, returns execve() value for child 
 */
int run(struct state * st) {
  

    /* Declarations for pipe buffer and pipe file descriptor array */
    int pipe_link[2], i;
    char pipe_buffer[4096];

    /* Zero out the pipe buffer */
    ZERO_BUFFER(pipe_buffer, 4096);

    /* Setup a pipe */
    pipe(pipe_link);
    
    /* The program forks a child process - Return value of fork allows only
     * the parent to call waitpid(), storing the return value of the child in
     * st->child_retval */
    if ((st->child_pid = fork())) {
        
        /* Since the parent process isn't writing to the pipe, we can close the write end */
        close(pipe_link[1]);

        /* Print child PID to stderr */
        fprintf(stderr, "%s: $$ = %d\n", st->child_exec_path, st->child_pid);

        /* Wait for child to finish executing and store return value in st->child_retval */
        waitpid(st->child_pid, &st->child_retval, 0);
        
        /* If the child finished with a non-zero return value, we need to read the pipe to
         * get the contents of the childs write to stderr */
        if (st->child_retval) {

            /* Read the read-only pipe file descriptor into the pipe buffer */
            read(pipe_link[0], pipe_buffer, sizeof(pipe_buffer));

            /* Close the read side of the pipe */
            close(pipe_link[0]);

            /* Print that data to stderr on the parent process */
            fprintf(stderr, "%s", pipe_buffer);
        }

        /* Print child return value to stderr */
        fprintf(stderr, "%s: $? = %d\n", st->child_exec_path, WEXITSTATUS(st->child_retval));
    }

    /* If fork() returns 0, we are operating with the child process */
    else {

        /* Declare storage for execve's return value */
        int retval;
        
        /* Setup the child's stderr file descriptor to write to the pipe we created */
        dup2(pipe_link[1], STDERR_FILENO);

        /* Execute the specified process with the argv formed in the state structure */
        retval = execve(st->child_exec_path, st->child_exec_args, NULL);

        /* Close both ends of the pipe */
        close(pipe_link[0]); 
        close(pipe_link[1]);

        /* Child process returns the value returned from execve() */
        return retval;

    }
    return 0;
}




/**
 * Function to validate the command line arguments supplied to the program,
 * namely the path of the binary the child process should execute 
 *
 * @param - argc - Argument count
 * @param - argv - Argument vector
 * @param - st - State structure 
 * @return - int - Macro indicating validation status 
 *
 */
int validate_args(int argc, char ** argv, struct state * st) {

    struct stat buf;
    int child_argc;
    
    /* Require at least a path to the binary the child should execute */
    if (argc < 2) return ARG_FAIL;
    
    /* Validate the path to the binary, while assigning it to 
     * st->child_exec_path */
    if (stat(st->child_exec_path = argv[1], &buf) != 0) {
        
        /* If stat() failed, the path either does not exist or the permissions
         * to access were not sufficient */
        return ARG_FAIL;
    }


    /* If extra arguments were specified for the binary the child process should invoke
     * copy them into st->child_exec_args */
    if ((child_argc = argc - 1)) {
        st->child_exec_args = malloc(sizeof(char *)*(child_argc));
        memcpy(st->child_exec_args, argv+1, sizeof(char*)*child_argc);
    }
    /* Otherwise designate st->child_exec_args as NULL */
    else {
        st->child_exec_args = NULL;
    }
    
    /* Return ARG_OK macro for successful binary path verification */
    return ARG_OK;
}
