#include <limits.h>
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

#include <lab5/paging.h>


int main(int argc, char ** argv) {
    
    struct state st;

    /* Validate CLI arguments */
    if (validate_args(&st, argc, argv) == ARG_FAIL) {
        fprintf(stderr, "Failed to parse CLI arguments" USAGE_STR);
        return -1;
    }
    
    /* Make page number and offset calculations, store in st */
    calcuate_page_offset(&st);
    
    /* Print results */
    fprintf(stdout, "The address %d contains:\n"
                    "page number = %d\n"
                    "offset = %d\n",
                    st.address, st.page_number,
                    st.offset
            );

        
    return 0;
}


/**
 * @brief calculate_page_offset
 * @param state - Holds state information for address, offset and page number
 */
void calcuate_page_offset(struct state *st) {
    
    st->page_number = (uint32_t) st->address / PAGE_SIZE;
    st->offset = (uint32_t) st->address % PAGE_SIZE;
}


/**
 * @brief validate_args - Validates CLI arguments
 * @param state - Holds state information for address, offset and page number
 * @param argc - Argument count
 * @param argv - Argument vector
 * @return - Macro indicating argument parse status
 */
int validate_args(struct state *st, int argc, char ** argv) {
   
    char * num_validator;
    long int_temp;

    /* Requires exactly one argument (the 32 bit address) */
    if (argc != 2) return ARG_FAIL; 
    
    /* Parse the CLI argument as long integer (casted to uint32_t) */
    int_temp = strtol(argv[1], &num_validator, BASE_10);
    
    /* Verify parse status from strtol using the validator pointer and 
     * make sure parsed number is valid 32 bit address */
    if (!IS_VALID_INT(1, num_validator) || (int_temp < 0 || int_temp > INT_MAX)) {
        fprintf(stderr, "Argument %s not a valid integer\n", argv[1]);
        return ARG_FAIL;
    }
    
    /* Store result in st */
    st->address = int_temp;
    
    /* If parse was successful, return ARG_OK macro */
    return ARG_OK; 
}





