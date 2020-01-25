#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include "convert.h"
#include "main.h"
#include "parse.h"

int main(int argc, char ** argv) {

    char **tokens;
    int *int_list;
    size_t token_count;

    if ((tokens = validate_args(argc, argv) == READ_FROM_FILE ?
            read_file_tokens(argv[FILE_PATH_ARGV], &token_count) :
            read_stdin_tokens(&token_count)) == NULL) {
        printf(PARSE_ERROR_MSG);
        return -1;
    }

    int_list = convert_tokens(tokens, token_count);




    return 0;
}

int validate_args(int argc, char **argv) {
    /* Require 1 argument - The input file path */
    if (argc != 2) return READ_FROM_STDIN;

    /* Check for file existence */
    return access(argv[1], F_OK) != -1 ? READ_FROM_FILE : READ_FROM_STDIN;
}
