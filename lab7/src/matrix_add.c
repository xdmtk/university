#include <aio.h>
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <unistd.h>

#include <lab7/matrix_add.h>


int main(int argc, char ** argv) {

    struct state st;

    /* Validate CLI arguments */
    if (validate_args(argc, argv, &st) == ARG_FAIL) {
        fprintf(stderr, "Failed to parse CLI arguments!");
        exit(EXIT_FAILURE);
    }

    /* Get start time */
    st.start_time = time(NULL);

    /* Generate random scalar value to add to matrix */
    st.scalar = rand() % 101;

    /* Generate block size based on blocks supplied via CLI args */
    st.block_size = st.size / st.blocks;
    
    /* Begin read/add/write async pipeline */
    process_matrix(&st);

    return 0;
}


/**
 * @brief process_matrix - Manages the async read/write pipeline
 * @param st - State information including time values, scalar value,
 * and block size
 *
 */
void process_matrix(struct state * st) {

    int offset;
    struct aiocb last, current, next;

    /* Set the aiocb 'current' struct to be ready for a read operation on stdin at offset 0 */
    set_aio_attributes(&current, 0, BLOCK_OFFSET, STDIN_FILENO);

    /* Prime the pump by reading the first block */
    aio_read(&current);
    
    /* Yes this sort of defeats the point, but the way the program is laid
     * out generally defeats the point of async IO in the first place. 
     * You can't do any operations on an aiocb struct until the async operation
     * completes, and since the actual calculation (matrix_add()) is synchronous, 
     * you are held up on doing any calculations before guarenteeing that the
     * aio_read() has completed, and likewise you are held up on fsync'ing 
     * the buffer from aio_write() to stdout until you are sure aio_write() has 
     * completely written out the block. 
     *
     * So we have to busy wait here using the EINPROGRESS error return value
     * from aio_error(), which ceases being true as soon as the op has completed
     */
    while (aio_error(&current) == EINPROGRESS){};

    /* Make a call to aio_return - Not 100% necessary since if the read or write
     * fails, we have much bigger problems that can't be solved by just bailing out
     * early - However it seems to be part of the general convention to do this when 
     * utilizing the aio_***() functions */
    aio_return(&current);

    /* Here begins the main async processing loop that reads blocks of
     * BLOCK_OFFSET ( a macro that squares the value of (block_size*4), since
     * 4 bytes are needed to process an individual column
     */
    for (offset = BLOCK_OFFSET; offset < TOTAL_SIZE; offset += BLOCK_OFFSET) {

        /* Begin async IO read for next block */
        set_aio_attributes(&next, offset, BLOCK_OFFSET, STDIN_FILENO);
        
        /* Execute read on the next block */
        aio_read(&next);
        
        /* See busy wait justification above in first call to aio_error() */
        while (aio_error(&next) == EINPROGRESS){};

        /* Add scalar to last read block */
        matrix_add(&current, st);

        /* Copy the current block into the last block */
        memcpy(&last, &current, sizeof(struct aiocb));

        /* Prep the last block to be written to stdout */
        set_aio_attributes(&last, offset, BLOCK_OFFSET, STDOUT_FILENO);

        /* Write the block to stdout */
        aio_write(&last);
        
        /* See busy wait justification above in first call to aio_error() */
        while (aio_error(&last) == EINPROGRESS){};

        /* Still not so sure why this call is necessary */
        aio_return(&last);
        
        /* Sync the write output to disk */
        aio_fsync(O_SYNC, &last);

        /* Overwrite the current block that has already been copied to 'last' and
         * written to stdout, with the next block prepped for aio_reads */
        memcpy(&current, &next, sizeof(struct aiocb));
    }

    /* Last drain the pump by handling the last block */
    matrix_add(&current, st);

    /* Write the last 'current' block to stdout */
    set_aio_attributes(&current, offset, BLOCK_OFFSET, STDOUT_FILENO);
    aio_write(&current);
    while (aio_error(&current) == EINPROGRESS){};
    aio_return(&current);
    aio_fsync(O_SYNC, &current);
}


/**
 * @brief matrix_add - Performs the actual matrix addition on the given buffer
 * from the aiocb struct
 * @param request - The aiocb struct containing the buffer data from the last async read
 * @param st - State information including scalar value and block size
 *
 */
void matrix_add(struct aiocb *request, struct state *st) {

    unsigned int i, num;
    char num_buf[5];

    /* Begin reading the aiocb buffer */
    for (i = 0; i < request->aio_nbytes; i += 4) {

        /* Zero out the buffer that will parse the numbers read from
         * the aiocb buf */
        memset(num_buf, '\0', 5);

        /* Read the aiocb_buf 4 bytes at a time, since the maximum value
         * for the scalar and integer is between -100 and 200, the number to be
         * read can occupy a maximum of 4 bytes (100 added to max
         * num value of 100) */
        memcpy(num_buf, (void *)request->aio_buf+i, 4);

        /* Parse the number from the buffer */
        num = strtol(num_buf, NULL, 10);

        /* Add the scalar to the parsed number */
        num += st->scalar;

        /* Zero out the num buffer again */
        memset(num_buf, '\0', 5);

        /* Write the number back to the num_buf */
        sprintf(num_buf, "%4d", num);

        /* Write the num_buf contents back to the aio_buf */
        memcpy((void *)request->aio_buf+i, num_buf, 4);

    }


}


/**
 * @brief set_aio_attributes - Called to setup the aiocb struct in preperation to
 * be passed to the aio_read/aio_write/aio_return operations.
 *
 * Starts by zeroing out the struct via memset, then sets the target file descriptor
 * (either stdin, or stdout), and then sets the block offset to read
 * and the block size to read, and allocates a buffer for the 'aio_buf' section
 * of the aiocb struct, and lastly sets priority level to 0 (seems irrelevant for
 * the purpose of this lab, but must be set)
 *
 * @param request - The aiocb struct pointer
 * @param offset - Offset where to start reading from the matrix
 * @param block_size - How many bytes to read from the offset
 * @param fd - Set to stdin for reads and stdout for writes
 */
void set_aio_attributes(struct aiocb *request, off_t offset, size_t block_size, int fd) {
   
    /* Here we zero out the aiocb struct _only_ if this aiocb struct is destined for 
     * a call to aio_read().. Why? Because aiocb structs destined for aio_write() calls
     * have already been zeroed out (for garbaged elimination), since they are simply 
     * aiocb structs converted from read-bound to write-bound. 
     *
     * Likewise, and this was a huge bug I absolutely could not figure out until now, 
     * when set_aio_attributes() would zero out a write bound struct, it effectiely
     * erased the pointer to the aio_buf containing the matrix values that have the 
     * scalar added to them, so thats why it never actually wrote anything to stdout. 
     *
     * I thought the buffer was full, could have sworn it was in GDB!, but I apparently 
     * just did not look hard enough!!!
     */
    if (fd == STDIN_FILENO) {

        /* Zero out the aiocb struct */
        memset(request, 0, sizeof(struct aiocb));
    }

    /* Allow the caller to set the file descriptor to read/write to.
     * Should either be stdin for reads, and stdout for writes */
    request->aio_fildes = fd;

    /* Set the offset - or set it to 0 if writing to stdout*/
    request->aio_offset = (fd == STDIN_FILENO ? offset : 0);

    /* Set the amount of bytes to read to the given block size */
    request->aio_nbytes = block_size;

    /* Supply the buffer to the aiocb struct for reads only */
    if (fd == STDIN_FILENO) {
        request->aio_buf = malloc(block_size);
    }

    /* Set the request priority (arbitrary since all requests are of the same
     * priority) */
    request->aio_reqprio = 0;

}

/**
 * @brief validate_args - Validates CLI arguments
 * @param state - Holds state information for matrix size and block size
 * @param argc - Argument count
 * @param argv - Argument vector
 * @return - Macro indicating argument parse status
 */
int validate_args(int argc, char ** argv, struct state * st) {

    char * num_validator;

    if (argc != 3) {
        fprintf(stderr, "Requires 2 arguments!\n" USAGE_STR);
        return ARG_FAIL;
    }

    /* Parse size argument */
    st->size = strtol(argv[1], &num_validator, BASE_10);

    /* Then validate it using *endptr param of strtol() */
    if (!IS_VALID_INT(1, num_validator)) {
        fprintf(stderr, "Size specified: %s - not a valid integer\n", argv[1]);
        return ARG_FAIL;
    }

    /* Parse blocks argument */
    st->blocks = strtol(argv[2], &num_validator, BASE_10);

    /* Then validate it using *endptr param of strtol() */
    if (!IS_VALID_INT(2, num_validator)) {
        fprintf(stderr, "Size specified: %s - not a valid integer\n", argv[1]);
        return ARG_FAIL;
    }

    /* Make sure blocks divides into total size */
    if (st->size % st->blocks) {
        fprintf(stderr, "Blocks do not evenly divide into total size!");
        return ARG_FAIL;
    }

    return ARG_OK;
}
