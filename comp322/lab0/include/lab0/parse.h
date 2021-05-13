#ifndef LAB0_PARSE_H
#define LAB0_PARSE_H

#define PARSE_FAIL -1
#define PARSE_OK 0
#define TOKEN_SIZE 8
#define BUFFER_SIZE 4096*16
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

struct token_indices {
    int buffer_index;
    int token_count;
    int bit_count;
    int read_buffer_index;
};

char **read_tokens(char *file_path, size_t *len, int mode, char **argv, int argc);
char read_char_primitive(int fd, struct token_indices *t, char *buf);

char ** append_tokens(char *tokens, struct token_indices *t);

int tokenize(char c, char *file_tokens, struct token_indices *t);
#endif //LAB0_PARSE_H
