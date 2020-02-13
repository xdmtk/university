#include <stdio.h>
#include <sys/stat.h>
#include <string.h>

#include <lab0/convert.h>
#include <lab0/main.h>
#include <lab0/parse.h>
#include <lab0/print.h>

int main(int argc, char ** argv) {

    char ** tokens;
    char file_path[256];
    struct int_rep ** representations;
    size_t token_count;
    int parse_mode, i;

    /* Determine stdin read or file read, and parse tokens */
    parse_mode = validate_args(argc, argv);

    tokens = read_tokens(argv[FILE_PATH_ARGV], &token_count, parse_mode, argv, argc);

    if (tokens == NULL) {
        /* On parse failure, print error message and terminate */
        printf(PARSE_ERROR_MSG);
        return -1;
    }

    /* Convert binary string tokens into integers, and then collects all printable
     * information about each integer */
    representations = convert_ints_to_rep(convert_tokens_to_ints(tokens, token_count), token_count);

    print_table(representations, token_count);

    return 0;
}

int validate_args(int argc, char **argv) {
    struct stat buf;

    /* Require 1 argument - The input file path */
    if (argc != 2) return READ_FROM_STDIN;
    return (stat(argv[1], &buf) == 0) ? READ_FROM_FILE : READ_FROM_STDIN;
}
