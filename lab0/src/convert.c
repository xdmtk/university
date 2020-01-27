#include <stdlib.h>
#include <string.h>

#include "convert.h"
#include "parse.h"

int *convert_tokens_to_ints(char **tokens, int token_count) {

    int * int_list, i;

    /* Dynamically allocate integer array */
    int_list = malloc(sizeof(int)*token_count);
    for (i = 0; i < token_count; ++i)

        /* Parse each binary string and place the resulting integer
         * into int_list */
        int_list[i] = bin_to_int(tokens[i]);

    free(tokens);
    return int_list;
}

int bin_to_int(char *bin_string) {

    size_t len;
    int val, i;

    /* Iterate through the binary string */
    len = strlen(bin_string) > 8 ? 8 : strlen(bin_string);
    for (i = val = 0; i < TOKEN_SIZE; ++i)

        /* Logical OR a 1 bit at the respective position if '1'
         * is found at the given position in the binary string */
        val |= (i < len && bin_string[7-i] == '1') ? 1 << i : 0;

    return val;
}

struct int_rep **convert_ints_to_rep(int *int_list, size_t int_count) {

    struct int_rep ** rep;
    int i;

    rep = malloc(sizeof(struct int_rep *)*int_count);
    for (i = 0; i < int_count; ++i)  {

        rep[i] = malloc(sizeof(struct int_rep));

        rep[i]->val = int_list[i];
        rep[i]->parity = get_parity_str(rep[i]->val);
        rep[i]->original_string = get_bin_str(rep[i]->val);
        rep[i]->ascii_rep = get_ascii_rep(rep[i]->val);
    }
    return rep;
}

char * get_ascii_rep(int val) {

}

char * get_bin_str(int val) {

    char * bin_string;
    int i;

    bin_string = malloc(sizeof(char)*TOKEN_SIZE+1);

    /* Walk the bits of the given value, insert a '1' character for each 1 bit */
    for (i = 0; i < TOKEN_SIZE; ++i)
        bin_string[i] = (val >> i) & 1 ? '1' : '0';
    bin_string[8] = '\0';

    return bin_string;
}

char * get_parity_str(int val) {

    int bit_count, i;

    /* Walk the bits of the given value, increment a counter for each 1 bit */
    for (bit_count = i = 0; i < TOKEN_SIZE; ++i)
        bit_count += (val >> i) & 1;

    /* Return an EVEN/ODD string depending on the bit count */
    return bit_count % 2 ? "ODD" : "EVEN";
}
