#ifndef LAB0_MAIN_H
#define LAB0_MAIN_H
#define READ_FROM_FILE 0
#define READ_FROM_STDIN 1
#define FILE_PATH_ARGV 1
/**
 * First call at program execution, validates program commandline
 * arguments, validates file path specified in arguments.
 *
 * @param argc - Argument count
 * @param argv - Pointer to array of string literals with arguments
 * @return - Validation status - 0 for failure, 1 for success
 */
int validate_args(int, char **);
#endif //LAB0_MAIN_H
