#ifndef LAB0_LAB0_H
#define LAB0_LAB0_H

/**
 * First call at program execution, validates program commandline
 * arguments, validates file path specified in arguments.
 *
 * @param argc - Argument count
 * @param argv - Pointer to array of string literals with arguments
 * @return - Validation status - 0 for failure, 1 for success
 */
int validate_args(int, char **);

/**
 * Parses and tokenizes the contents of the specified
 * file.
 * @param file_path
 * @return  - Pointer to array of string literals representing
 * file contents as tokens
 */
char **read_file_tokens(char *file_path, size_t *len);


void append_file_token(int *i, int *j, int *k, char **file_tokens, char *token_buffer);
#endif //LAB0_LAB0_H
