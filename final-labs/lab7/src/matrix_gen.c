#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#include <lab7/matrix_gen.h>


int main(int argc, char ** argv) {
    
    int size;

    if ((size = validate_args(argc,argv)) == ARG_FAIL) {
        fprintf(stderr, "Failed to parse CLI arguments!\n");
        exit(EXIT_FAILURE);
    }

    generate_matrix(size);
    return 0;
}


/**
 * @brief generate_matrix - Prints matrix contents to stdout 
 *
 * @param size - Size for SizeXSize matrix
 */
void generate_matrix(int size) {

    int row,col;

    srand(time(NULL));
    
    /* Generate matrix one column at a time. Each column is 4 bytes,
     * being the maximum amount of characters a number -100 to 100 can
     * occupy. The matrix_add program will need to parse numbers 4 on 
     * intervals of 4 bytes each */
    for (row = 0; row < size; ++row) 
        for (col = 0; col < size; ++col)

            /* rand() generates a number from 0-100 inclusive, 
             * and the second rand() determines whether to modify the
             * sign of the given column number */
            fprintf(stdout, "%4d", (rand() % 101) 
                    * ((rand() % 2) ? 1 : -1));
    
}


/**
 * @brief validate_args - Validates CLI arguments for seats/position
 * specification
 *
 * @param argc - Count of total CLI arguments
 * @param argv - CLI Argument vector
 *
 * @return int - On failure, a macro indicating CLI argument parse failure
 *             - On success, returns an integer size specified in the arguments
 */
int validate_args(int argc, char ** argv) {
    
    int size;
    char * validator;

    if (argc != 2) {
        fprintf(stderr, "Missing required arguments\n");
        return ARG_FAIL;
    }

    size = strtol(argv[1], &validator, BASE_10);
    
    if (!IS_VALID_INT(1, validator)) {
        fprintf(stderr, "%s is not a valid integer!\n", argv[1]);
        return ARG_FAIL;
    }
    
    return size;
}
