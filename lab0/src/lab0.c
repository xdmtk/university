#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "lab0.h"

int main(int argc, char ** argv) {

    char **tokens;
    size_t token_count;
    if (!validate_args(argc, argv)) return -1;

    tokens = read_file_tokens(argv[1], &token_count);
    return 0;
}

int validate_args(int argc, char **argv) {
    /* Require 1 argument - The input file path */
    if (argc != 2) return 0;

    /* Check for file existence */
    return access(argv[1], F_OK) != -1;
}

char **read_file_tokens(char *file_path, size_t *len) {

    /* Declarations */
    FILE * fp;
    char ** file_tokens;
    char token_buffer[8] = {'\0'};
    char c;
    int token_index, token_alloc_count, token_buffer_index;

    /* Set counters, open file and allocate token array */
    token_index = token_buffer_index = 0; token_alloc_count = 1;
    fp = fopen(file_path, "r");
    file_tokens = malloc(sizeof(char *) * token_alloc_count);

    /* Parse and tokenize file contents by character */
    while ((c = fgetc(fp)) != EOF) {

        /* Add characters to token buffer before reaching delimiter */
        if (c != ' ' && token_buffer_index < 8)
            token_buffer[token_buffer_index++] = c;

        /* If we haven't reached the delimiter before 8 character maximum,
         * the input is not correctly formatted. Terminate parsing and return NULL */
        else if (c != ' ' && token_buffer_index >= 8)
            return NULL;

        /* Once the delimiter is reached, copy the buffer into a space allocated
         * in the token array, reset buffer limit counters, resize the token array
         * and continue parsing */
        else
            append_file_token(&token_index, &token_alloc_count, &token_buffer_index, file_tokens, token_buffer);
    }
    /* After a successfull parse, call append_file_token again to get the last parsed token before EOF */
    append_file_token(&token_index, &token_alloc_count, &token_buffer_index, file_tokens, token_buffer);

    /* Write the amount of tokens successfully parsed to len */
    *len = token_alloc_count - 1;

    return file_tokens;
}


void append_file_token(int *i, int *j, int *k, char **file_tokens, char *token_buffer) {
    file_tokens[*i] = malloc(sizeof(char) * 8);
    memcpy(file_tokens[*i], token_buffer, *k);
    *i += 1; *j += 1;
    file_tokens = realloc(file_tokens, sizeof(char *) * (*j));
    *k = 0;
}
