#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "parse.h"


char **read_file_tokens(char *file_path, size_t *len) {

    /* Declarations */
    FILE * fp;
    char ** file_tokens;
    char token_buffer[8] = {'\0'}, c;
    int parse_status;
    struct token_indices t;

    /* Set counters, open file and allocate token array */
    t.token_index = t.buffer_index = parse_status = 0; t.token_alloc = 1;
    fp = fopen(file_path, "r");
    file_tokens = malloc(sizeof(char *) * t.token_alloc);

    /* Parse and tokenize file contents by character */
    // TODO: Ask whether using fgetc() is OK
    while ((c = (char)fgetc(fp)) != EOF && parse_status != PARSE_FAIL)
        parse_status = tokenize(c, token_buffer, file_tokens, &t);

    /* After a successful parse, call append_token again to get the last parsed token before EOF */
    append_token(file_tokens, token_buffer, &t);

    /* Write the amount of tokens successfully parsed to len */
    *len = t.token_alloc - 1;

    return file_tokens;
}


char **read_stdin_tokens(size_t *len) {return NULL;};

void append_token(char **tokens, char *token_buffer, struct token_indices *t) {

    /* Allocate new space for the token buffer collected in the token array */
    tokens[t->token_index] = malloc(sizeof(char) * 8);

    /* Copy the k's worth of tokens to the buffer */
    memcpy(tokens[t->token_index], token_buffer, t->buffer_index);

    /* Update the indices for the token array */
    t->token_index += 1; t->token_alloc += 1;

    /* Resize the token buffer for additional appending */
    tokens = realloc(tokens, sizeof(char *) * (t->token_alloc));

    /* Reset the token buffer counter */
    t->buffer_index = 0;
}

int tokenize(char c, char *token_buffer, char **file_tokens, struct token_indices *t) {

    /* Add characters to token buffer before reaching delimiter */
    if (c != ' ' && t->buffer_index < 8)
        token_buffer[t->buffer_index++] = c;

        /* If we haven't reached the delimiter before 8 character maximum,
         * the input is not correctly formatted. Terminate parsing and return NULL */
    else if (c != ' ' && t->buffer_index >= 8)
        return PARSE_FAIL;

        /* Once the delimiter is reached, copy the buffer into a space allocated
         * in the token array, reset buffer limit counters, resize the token array
         * and continue parsing */
    else
        append_token(file_tokens, token_buffer, t);

    return PARSE_OK;
}
