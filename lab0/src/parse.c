#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "main.h"
#include "parse.h"


char ** read_tokens(char * file_path, size_t *len, int mode) {

    FILE * fp;
    char * token_buffer, c;
    struct token_indices t;
    int i, parse_status = PARSE_OK;

    t.buffer_index = t.token_count = t.bit_count = 0;
    token_buffer = malloc(sizeof(char)*BUFFER_SIZE);
    for (i=0; i < BUFFER_SIZE; ++i) token_buffer[i] = '0';

    if (mode == READ_FROM_FILE)
        fp = fopen(file_path, "r");

    while (((c = (mode == READ_FROM_FILE ? fgetc(fp) : getchar())) != EOF) && (parse_status != PARSE_FAIL)) {
        parse_status = tokenize(c, token_buffer, &t);
    }
    *len = ++t.token_count;

    return append_tokens(token_buffer, &t);
}

char ** append_tokens(char *tokens, struct token_indices *t) {

    int i;
    char ** token_list = malloc(sizeof(char *)*t->token_count);
    for (i = 0; i < t->token_count; ++i) {
        token_list[i] = malloc(sizeof(char)*9);
        memcpy(token_list[i], tokens+(i*8), 8);
        token_list[i][8] = '\0';
    }

    return token_list;
}

int tokenize(char c, char* token_buffer, struct token_indices *t) {

    /* If delimiter is reached before 8 bits, advance the buffer_index pointer
     * to the next set of 8 bits, reset the current bit count, and increment
     * the token counter */
    if (c == ' ' && t->buffer_index % 8) {
        t->buffer_index += 8 - (t->buffer_index % 8);
        t->bit_count = 0;
        t->token_count++;
        return PARSE_OK;
    }
    /* If no delimiter was found before the end of the 8 bits,
     * the input is incorrectly formatted and should be rejected */
    else if (c != ' ' && t->bit_count >= 8) {
        return PARSE_FAIL;
    }
    else if(c == ' ' && t->bit_count == 8) {
        t->bit_count = 0;
        t->token_count++;
        return PARSE_OK;
    }
    else {
        token_buffer[t->buffer_index++] = c;
        t->bit_count++;
        return PARSE_OK;
    }
}
