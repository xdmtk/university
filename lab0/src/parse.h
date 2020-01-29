#ifndef LAB0_PARSE_H
#define LAB0_PARSE_H

#define PARSE_FAIL -1
#define PARSE_OK 0
#define TOKEN_SIZE 8
#include <stddef.h>

struct token_indices {
    int buffer_index;
    int token_index;
    int token_alloc;
};

/**
 * Parses and tokenizes the contents of the specified
 * file.
 * @param file_path - Input file path
 * @param len - Amount of tokens successfully parsed
 * @return  - Pointer to array of string literals representing
 * file contents as tokens
 */
char **read_file_tokens(char *file_path, size_t *len);

/**
 * Parses and tokenizes the contents of stdin
 * @param len - Amount of tokens successfully parsed
 * @return  - Pointer to array of string literals representing
 * file contents as tokens
 */
char **read_stdin_tokens(size_t *len);

/**
 * Appends a token from the token buffer to the dynamically allocated
 * list of tokens. Manages the resizing of the token list.
 *
 * @param tokens
 * @param token_buffer
 * @param t
 */
void append_token(char **tokens, char *token_buffer, struct token_indices *t);

/**
 * Called to operate on each character read and determine the current
 * status of the parse. Checks for delimiters and EOF conditions
 * @param c
 * @param token_buffer
 * @param file_tokens
 * @param t
 * @return
 */
int tokenize(char c, char *token_buffer, char **file_tokens, struct token_indices *t);
#endif //LAB0_PARSE_H
