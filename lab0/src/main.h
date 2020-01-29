#ifndef LAB0_MAIN_H
#define LAB0_MAIN_H
#define READ_FROM_FILE 0
#define READ_FROM_STDIN 1
#define FILE_PATH_ARGV 1
#define PARSE_ERROR_MSG "\nFailed to parse tokens from stdin/file. Please check your input\n"

#include <stddef.h>
/**
 * First call at program execution, validates program commandline
 * arguments, validates file path specified in arguments.
 *
 * @param argc - Argument count
 * @param argv - Pointer to array of string literals with arguments
 * @return - Validation status - Returns the macro READ_FROM_FILE or READ_FROM_STDIN
 */
int validate_args(int, char **);
#endif //LAB0_MAIN_H
