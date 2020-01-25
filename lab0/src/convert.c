#include <stdlib.h>
#include <string.h>

#include "convert.h"
#include "parse.h"

int *convert_tokens(char **tokens, int token_count) {

    int * int_list, i;

    int_list = malloc(sizeof(int)*token_count);
    for (i = 0; i < token_count; ++i) {
        int_list[i] = bin_to_int(tokens[i]);
    }

    return int_list;
}

int bin_to_int(char *bin_string) {

    size_t len;
    int val, i;

    len = strlen(bin_string);
    for (i = val = 0; i < TOKEN_SIZE; ++i, val = val << 1)
        val |= (i < len && bin_string[i] == '1') ? 1 : 0;

    return val;
}
