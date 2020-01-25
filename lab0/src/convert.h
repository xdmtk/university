#ifndef LAB0_CONVERT_H
#define LAB0_CONVERT_H

/**
 * Processes the list of collected tokens from input and returns
 * a list of their integer representations
 *
 * @param tokens - List of literals representing binary strings
 * @param token_count - Size of the list
 * @return - A list of integers corresponding to the input token list
 */
int *convert_tokens(char **tokens, int token_count);

/**
 * Operates on a ascii binary string and returns the integer
 * representation
 *
 * @param bin_string - Input token
 * @return - The integer representation of the token
 */
int bin_to_int(char *bin_string);

#endif //LAB0_CONVERT_H
