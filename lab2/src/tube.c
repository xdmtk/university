#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>

#include <lab2/tube.h>


int main(int argc, char ** argv) {
    
    
    struct state st;
    
    /* Validate CLI arguments */
    if (validate_args(argc, argv, &st) == ARG_FAIL) {

        /* Print to stderr on argument parse failure */
        fprintf(stderr, "Bad argument format or exec path for either child doesn't exist\n");

        /* Exit with -1 error status */
        exit(-1);
    }
    
    /* Call run(), performing all required actions for the program */
    return run(&st);
}



/**
 * Note: The code is verbose on purpose. 
 */
int run(struct state * st) {
  

    /* Declarations for pipe buffers and pipe file descriptor arrays */
    int parent_child_pipe[2], child_child_pipe[2], 
        parent_child_pipe_error[2], child_child_pipe_error[2], 
        i;
    char pipe_buffer[PIPE_BUFFER_SIZE], pipe_buffer_error[PIPE_BUFFER_SIZE];
    
    /* Zero out the pipe buffers */
    ZERO_BUFFER(pipe_buffer, PIPE_BUFFER_SIZE);
    ZERO_BUFFER(pipe_buffer_error, PIPE_BUFFER_SIZE);

    /* Setup pipes */
    pipe(parent_child_pipe);
    pipe(parent_child_pipe_error);
    pipe(child_child_pipe);
    pipe(child_child_pipe_error);

    
    /* The parent program forks Child 1, then checks the Child 1 PID. If this PID 
     * is non-zero, then we can continue the parent's execution to fork Child 2.
     *
     * However if the PID _is_ zero, then we cannot allow Child 1 to call fork(), as it would
     * create more processes than intended */
    if ((st->child1_pid = fork()) && (st->child1_pid) && (st->child2_pid = fork())) {
        
        /* Since the parent process isn't writing to either pipes, we can close the write ends */
        close(parent_child_pipe[WRITE_END]);
        close(parent_child_pipe_error[WRITE_END]);


        /* Print children PID's to stderr */
        fprintf(stderr, "%s: $$ = %d\n", st->child1_exec_path, st->child1_pid);
        fprintf(stderr, "%s: $$ = %d\n", st->child2_exec_path, st->child2_pid);


        /* Wait for both children to finish executing and store return value in their respective
         * retval variables */
        waitpid(st->child1_pid, &st->child1_retval, 0);
       

        /* If Child 1 returns successfully, Child 2 will have had a chance to execute,
         * write to, and close out the parent_child_pipe, so we can read from it here
         * to get the piped command output */
        if (!st->child1_retval) {
            
            /* Wait on Child 2 and assign its return value */
            waitpid(st->child2_pid, &st->child2_retval, 0);
            
            /* Read the parent_child pipe written by Child 2 */
            read(parent_child_pipe[READ_END], pipe_buffer, sizeof(pipe_buffer));
            read(parent_child_pipe_error[READ_END], pipe_buffer_error, sizeof(pipe_buffer));
            
            /* Print Child 2's stdout to stdout */
            fprintf(stdout, "%s", pipe_buffer);

            /* Print Child 2's stderr to stderr */
            fprintf(stderr, "%s", pipe_buffer_error);
        }
        
        /* However, if Child 1 errors out, Child 2 will hang because it depends on the stdout
         * from Child 1 to execute, so instead, kill Child 2 */
        else {
            kill(st->child2_pid, SIGKILL);
        }


        /* Close the read sides of both pipes */
        close(parent_child_pipe[READ_END]);
        close(parent_child_pipe_error[READ_END]);


        /* Print children return values to stderr */
        fprintf(stderr, "%s: $$ = %d\n", st->child1_exec_path, WEXITSTATUS(st->child1_retval));
        fprintf(stderr, "%s: $$ = %d\n", st->child2_exec_path, WEXITSTATUS(st->child2_retval));
    }

    /* We can control execution for Child 1 by checking whether it's PID is set to 0 
     * after the first call to fork() */
    else if (!st->child1_pid) {

        int retval;

        /* Setup the child's output file descriptors (both stdout and stderr) to write to the pipes we created */
        dup2(child_child_pipe[WRITE_END], STDOUT_FILENO);
        dup2(child_child_pipe_error[WRITE_END], STDERR_FILENO);


        /* Execute the specified process with the argv we formed earlier in the state structure */
        retval = execve(st->child1_exec_path, st->child1_exec_args, NULL);


        /* Close both ends of both pipes */
        close(child_child_pipe[WRITE_END]);
        close(child_child_pipe[READ_END]);
        close(child_child_pipe_error[WRITE_END]);
        close(child_child_pipe_error[READ_END]);

        return retval;
    }


    /* We can also control execution for Child 2 by first checking if Child 1 has a non-zero PID
     * and then checking whether Child 2's PID is 0.
     *
     * This is because after Child 1 has been forked, the parent process gets the PID value of that
     * child. Now when Child 2 is forked, Child 2 gets a copy of what is currently in the parent's
     * memory map, which includes the PID for Child 1. And of course, Child 2 get's it's own PID
     * value set to 0 (from the Child's perspective) , so we know if the caller is Child 2 by checking 
     * whether Child 1 PID has a value but Child 2 PID does not. */
    else if (st->child1_pid && !st->child2_pid) {

        int retval;

        /* Here we setup all the necessary redirection of the relevant file descriptors
         *
         * First we route stdin for our upcoming call to execve() to the
         * output that was written by Child 1 through our child_child_pipe */
        dup2(child_child_pipe[READ_END], STDIN_FILENO);

        /* Next, since the parent will receive the final output of Child 2's execve()
         * call, we route both stdout and stderr to the write end of the parent_child_pipe */
        dup2(parent_child_pipe[WRITE_END], STDOUT_FILENO);
        dup2(parent_child_pipe_error[WRITE_END], STDERR_FILENO);
    

        /* Now that all pipe redirection is in place, we call execve() with the filepath and the
         * preset argv we parsed from the CLI args, and store the return value in retval */
        retval = execve(st->child2_exec_path, st->child2_exec_args, NULL);

        /* Lastly, in order to avoid blocking, we close out all pipe ends for this process */
        close(child_child_pipe[WRITE_END]);
        close(child_child_pipe[READ_END]);

        close(parent_child_pipe[WRITE_END]);
        close(parent_child_pipe[READ_END]);

        close(parent_child_pipe_error[WRITE_END]);
        close(parent_child_pipe_error[READ_END]);

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

    struct stat buf1, buf2;
    int i;
    int child1_argc, child2_argc;
    int child1_prog_pos, child2_prog_pos, delim_pos;
    child1_prog_pos = child2_prog_pos = delim_pos = -1;

    
    /* For tube, we need at least 4 arguments
     *      The default first argument of the parent program path
     *      The filepath for the first child program
     *      A comma to separate the first program and its arguments
     *      The filepath for the second child program
     */
    if (argc < 4) return ARG_FAIL;

    /* Next we need to get a proper count of extra argv structures for 
     * each child program */
    for (i = 1; i < argc; ++i) {

        /* A bit verbose but we need to assume that the first argument 
         * after ./tube is the program filepath for Child 1 */
        if (i == 1) {
            child1_prog_pos = i;
            continue;
        }

        /* If we've hit the delimiter between child program specifications,
         * we need to assume the next argument is the filepath for Child 2 */
        if (!strcmp(argv[i],",")) {
            delim_pos = i;
            child2_prog_pos = i+1;
            continue;
        }
    }

    /* If the argument positions weren't able to be parsed correctly, reject the
     * arguments by returning ARG_FAIL */
    if (!(IS_INIT(child1_prog_pos) && IS_INIT(child2_prog_pos) && IS_INIT(delim_pos))) {
        return ARG_FAIL;
    }


    /* Now we can calculate the size of the argument vectors for Child1 and Child 2*/
    child1_argc = delim_pos - child1_prog_pos;
    child2_argc = argc - child2_prog_pos;


    /* Next we verify the file paths of both child programs */
    if ((stat(st->child1_exec_path = argv[child1_prog_pos], &buf1) != 0) 
        ||  (stat(st->child2_exec_path = argv[child2_prog_pos], &buf2) != 0)) {
        
        /* If either of the specified file paths are bad, return ARG_FAIL */
        return ARG_FAIL;
    }


    /* If both file paths are good, we can now allocate space for each child
     * programs argument vector, and copy them into st (state structure) */
    st->child1_exec_args = malloc(sizeof(char *)*(child1_argc));
    memcpy(st->child1_exec_args, argv+child1_prog_pos, sizeof(char*)*child1_argc);

    st->child2_exec_args = malloc(sizeof(char *)*(child2_argc));
    memcpy(st->child2_exec_args, argv+child2_prog_pos, sizeof(char*)*child2_argc);

    return ARG_OK;

}
