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

/**
 * Parses and tokenizes the contents of the specified
 * file.
 * @param file_path - Input file path
 * @param len - Amount of tokens successfully parsed
 * @param mode - Mode to read from STDIN or File
 * @return  - Pointer to array of string literals representing
 * file contents as tokens
 */
char **read_tokens(char *file_path, size_t *len, int mode, char **argv, int argc);

/**
 * Since we aren't allowed to use getchar() or fgetc() for I/O,
 * this wrapper around read() simulates getchar()/fgetc()
 * @param fd
 * @param mode
 * @return
 */
char read_char_primitive(int fd, struct token_indices *t, char *buf);

/**
 * Appends a token from the token buffer to the dynamically allocated
 * list of tokens.
 *
 * @param tokens
 * @param token_buffer
 * @param t
 */
char ** append_tokens(char *tokens, struct token_indices *t);

/**
 * Called to operate on each character read and determine the current
 * status of the parse. Checks for delimiters and EOF conditions
 *
 * @param c
 * @param token_buffer
 * @param file_tokens
 * @param t
 * @return
 */
int tokenize(char c, char *file_tokens, struct token_indices *t);
#endif //LAB0_PARSE_H
