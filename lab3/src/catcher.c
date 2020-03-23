#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/times.h>
#include <unistd.h>

#include <lab3/catcher.h>

/* See line 104 for global variable justification */
int term_count = 0;

int main(int argc, char ** argv) {
   
    int len, total_signals_caught;
    struct signal_tag ** signal_arguments;

    /* First things first, the PID of the program is printed to stderr */
    fprintf(stderr, "catcher: $$ = %d\n", getpid());

    /* `len` is used to keep track of how many signals were parsed */
    len = total_signals_caught = 0;
    
    /* The call to validate_args returns either an array of structs
     * representing the signals parsed from the CLI args, or NULL on 
     * a failure to parse one or more of the signals */
    signal_arguments = validate_args(argc, argv, &len);

     /* `signal_arguments` is passed along to register_signals, and the universal signal handler
     * is registered against all specified signals. If there is an error
     * registering any of the signals, the macro REG_FAIL is returned and an 
     * error message is printed. */
    if (register_signals(signal_arguments, len) == REG_FAIL) {

        fprintf(stderr, "Failed to parse arguments and or register signals\n%s", HELP_PAGE);
        return -1;
    }

    /* If all went well with signal registration, the program enters a loop
     * calling pause() indefinitely, blocking until a signal is caught. 
     *
     * The second condition reinstalls the signal handlers to manage
     * unreliable signals 
     *
     * The third condition really isn't a condition, however it increments for
     * each time execution is continued after pause(), thereby keeping tally
     * of the total signals caught over the program lifespan
     *
     * The last condition checks whether SIGTERM has been caught more than 3
     * times. As soon as it has, the main() function returns.
     */
    while (pause() && register_signals(signal_arguments, len) 
            && ++total_signals_caught != REG_FAIL && term_count < 3) {}

    
    /* Print out the total count of signals caught */
    fprintf(stderr, "catcher: Total signals count = %d\n", total_signals_caught);

    return 0;
}


/**
 * This function is helper function to lookup the signal
 * string name of the incoming signal macro. 
 *
 * @param - int signal - The signal caught
 * @return - char * - The corresponding name of the signal
 */
char * get_signal_name_str(int signal) {
    
    int i; 
    
    /* Iterate through the signal_macro_table comparing each
     * entry with the caught signal. */
    for (i = 0; i < (int)(sizeof(signal_macro_table)/sizeof(int)); ++i) {

        /* If they match, use `i` to index into the 
         * signal_table (full of string names of the corresponding signals) 
         * and return the string at that index */
        if (signal == signal_macro_table[i]) {
            return signal_table[i];
        }
    }

    /* The function should never make it here, as every emittable signal
     * is in the signal table */
    return NULL;
}


/**
 * This is the function that every signal is handled with. When the signal
 * macro integer is passed as a param to this function, it is used to 
 * lookup the signal name string associated with it.
 *
 * @param signal - The signal macro that invoked that handler
 */
void signal_handler(int signal) {


    /* Print to stdout the signal caught */
    fprintf(stdout, "%s caught at %ld\n", get_signal_name_str(signal), time(NULL));


    /* While the instructions hint at using a static variable to keep track of
     * SIGTERM, ultimately the asynchronous nature of a signal handler makes it
     * impossible to make the main() loop aware of the need to terminate without 
     * some form of global scope.
     *
     * Its possible to just call exit() here when term_count reaches 3, however
     * it was recently stated over Slack that using exit() is bad practice. 
     *
     * So instead, term_count is global, and the main pause() loop continues
     * on the condition that term_count is less than 3.
     */
    if (signal == SIGTERM) term_count++;
}


/**
 * This function iterates the signals collected in the argument 
 * parsing functions and registers them to the signal_handler()
 * function
 *
 * @param struct signal_tag ** - A collection of signal-indices/signal-name-string 
 * pairs that map to the implementation defined signal macros
 */
int register_signals(struct signal_tag ** signal_registry, int len) {
    
    int i;

    /* Make sure arguments were successfully parsed */
    if (signal_registry == NULL) return REG_FAIL;


    /* Iterate through the signal_registry collection and register every
     * signal to the signal_handler() function */
    for (i = 0; i < len; ++i) {

        /* Here we register the implementation defined signal macro with the 
         * signal_handler function. 
         *
         * The sig_index field mapped in the signal_registry corresponds to the actual
         * signal macro in the signal_macro_table 
         *
         * If the signal handler registration fails, return SIG_ERR */
        if ((signal(signal_macro_table[signal_registry[i]->sig_index], signal_handler) == SIG_ERR)) {
            return REG_FAIL;
        }
    }
    return REG_SUCCESS;
}


/**
 * First things first, we need to verify that the arguments passed into
 * the program are correct. 
 *
 * This involves first checking if there enough arguments for runtime,
 * and second, validating all the signal names to make sure they are 
 * actually catchable signals.
 *
 * @param argc - Argument count
 * @param argv - Argument vector 
 * @return signal_tag ** - A collection of signal index/signal name pairs
 */
struct signal_tag ** validate_args(int argc, char ** argv, int * sig_len) {
    
    int i;
    /* Need at least one signal to catch */
    if (argc < 2) {
        fprintf(stderr, "\nNo signals specified to catch\n");
        return NULL;
    }
    
    /* Heap allocate a collection of signal indices and names for later
     * signal handler registration */
    struct signal_tag ** signal_registry = malloc(sizeof(struct signal_tag *)*(argc-1));
    
    /* Now we iterate the argument vector for signals and validate each one */
    for (i = 1; i < argc; ++i, *sig_len += 1) {

        /* If a signal validation fails, the program cannot continue, as the user
         * entered an invalid signal to catch. Deallocate the signal_registry and 
         * return NULL to main() */
        if ((signal_registry[i-1] = validate_signal(argv[i])) == NULL) {

            /* Print out the signal that failed to be parsed */
            fprintf(stderr, "\ninvalid signal: %s - Please check signal arguments and try again\n",argv[i]);
            return NULL;
        }
    }
    
    return signal_registry;
}


/**
 * Checks to see whether the given signal `sig_name` is a valid
 * signal by linear scanning the global signal string table
 *
 * @return signal_tag * - A pointer to a signal index/signal name pair
 */
struct signal_tag * validate_signal(char * sig_name) {
    
    int i;

    /* Iterate the signal table to determine whether the given sig_name
     * is a valid signal */
    for (i = 0; i < (int)(sizeof(signal_table)/sizeof(char *)); ++i) {
        
        /* If it is a valid signal, create a new signal_tag structure with
         * the corresponding signal index number into the table, and it's name */
        if (!strcmp(sig_name, signal_table[i])) {
            
            /* Heap allocate the signal_tag, and assign the string/index pair */
            struct signal_tag * sigtag = malloc(sizeof(struct signal_tag));
            sigtag->sig_name = signal_table[i];
            sigtag->sig_index = i;
            
            
            return sigtag;
        }
    }
    
    /* If we've made it all the way through the signal table without finding a match
     * return NULL */
    return NULL;
}
