#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include "convert.h"
#include "main.h"
#include "parse.h"

int main(int argc, char ** argv) {

    char **tokens;
    struct int_rep ** representations;
    size_t token_count;

    /* Determine stdin read or file read, and parse tokens */
    if ((tokens = validate_args(argc, argv) == READ_FROM_FILE ?
            read_file_tokens(argv[FILE_PATH_ARGV], &token_count) :
            read_stdin_tokens(&token_count)) == NULL) {

        /* On parse failure, print error message and terminate */
        printf(PARSE_ERROR_MSG);
        return -1;
    }

    /* Convert binary string tokens into integers, and then collects all printable
     * information about each integer */
    representations = convert_ints_to_rep(convert_tokens_to_ints(tokens, token_count), token_count);





    return 0;
}

int validate_args(int argc, char **argv) {
    struct stat buf;

    /* Require 1 argument - The input file path */
    if (argc != 2) return READ_FROM_STDIN;
    return stat(argv[1], &buf) == 0;
}
