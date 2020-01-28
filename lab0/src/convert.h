#ifndef LAB0_CONVERT_H
#define LAB0_CONVERT_H

#define ODD_PARITY 0
#define EVEN_PARITY 1
#define BEGIN_PRINTABLE_RANGE 0x20

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

/**
 * Pads the given binary string with 0's to the right
 *
 * @param bin_string - Input binary string
 * @param len - Length of binary string
 * @return - Pointer to new, padded binary string
 */
char * pad_bin_string(char *bin_string, int len);

/**
 * Calculates the parity of the given value, and returns
 * a "ODD" / "EVEN" string based on the results
 *
 * @param val
 * @return - "ODD"/"EVEN" string
 */
char * get_parity_str(int val);

/**
 * Returns a binary string representation of the
 * given value
 * @param val
 * @return - A binary string
 */
char * get_bin_str(int val);

/**
 * Returns a string of the ascii representation of the given
 * value, either the mneumonic listed in `man ascii` or the
 * directly casted value
 *
 * @param val
 * @return - ASCII representation string of the given value
 */
char * get_ascii_rep(int val);
#endif //LAB0_CONVERT_H
