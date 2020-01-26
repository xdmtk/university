#ifndef LAB0_CONVERT_H
#define LAB0_CONVERT_H

#define ODD_PARITY 0
#define EVEN_PARITY 1
#define BEGIN_PRINTABLE_RANGE 0x20

struct int_rep {
    char * original_string;
    char * ascii_rep;
    char * parity;
    int val;
};

/**
 * Processes the list of collected tokens from input and returns
 * a list of their integer representations
 *
 * @param tokens - List of literals representing binary strings
 * @param token_count - Size of the list
 * @return - A list of integers corresponding to the input token list
 */
int *convert_tokens_to_ints(char **tokens, int token_count);

/**
 * Operates on a ascii binary string and returns the integer
 * representation
 *
 * @param bin_string - Input token
 * @return - The integer representation of the token
 */
int bin_to_int(char *bin_string);

/**
 * Accepts a list of integers, and returns a list of structs
 * with all necessary information to print to stdout
 *
 * @param int_list - List of integers
 * @return - List of pointers to int_rep structures
 */
struct int_rep **convert_ints_to_rep(int *int_list, size_t int_count);

char * get_parity_str(int val);
char * get_bin_str(int val);
char * get_ascii_rep(int val);
#endif //LAB0_CONVERT_H
