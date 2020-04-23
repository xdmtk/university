#ifndef LAB0_CONVERT_H
#define LAB0_CONVERT_H
#define BEGIN_PRINTABLE_RANGE 0x20

#include <stddef.h>

/**
 * int_rep structure contains all data for the given token
 * to be printed to stdout
 */
struct int_rep {
    char * original_string;
    char * ascii_rep;
    char * parity;
    int val;
};

int *convert_tokens_to_ints(char **tokens, int token_count);
int bin_to_int(const char *bin_string);
struct int_rep **convert_ints_to_rep(int *int_list, size_t int_count);
char * get_parity_str(int val);
char * get_bin_str(int val);
char * get_ascii_rep(int val);
int iascii(int val);

#endif //LAB0_CONVERT_H


