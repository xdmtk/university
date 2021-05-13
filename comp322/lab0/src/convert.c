#include <stdlib.h>

#include <lab0/convert.h>
#include <lab0/parse.h>
#include <lab0/main.h>


/**
 * Processes the list of collected tokens from input and returns
 * a list of their integer representations
 *
 * @param tokens - List of literals representing binary strings
 * @param token_count - Size of the list
 * @return - A list of integers corresponding to the input token list
 */
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


/**
 * Operates on a ascii binary string and returns the integer
 * representation
 *
 * @param bin_string - Input token
 * @return - The integer representation of the token
 */
int bin_to_int(const char *bin_string) {

    unsigned int val, i;

    /* Last minute validation for valid input */
    for (i = 0; i < TOKEN_SIZE; ++i) {
        if (bin_string[i] != '0' && bin_string[i] != '1')  {
            printf(PARSE_ERROR_MSG);
            exit(-1);
        }
    }


    for (i = val = 0; i < TOKEN_SIZE; ++i)

        /* Logical OR a 1 bit at the respective position if '1'
         * is found at the given position in the binary string */
        val |= (i < 8 && bin_string[7-i] == '1') ? 1 << i : 0;

    return val;
}


/**
 * Accepts a list of integers, and returns a list of structs
 * with all necessary information to print to stdout
 *
 * @param int_list - List of integers
 * @return - List of pointers to int_rep structures
 */
struct int_rep **convert_ints_to_rep(int *int_list, size_t int_count) {

    struct int_rep ** rep;
    int i;

    rep = malloc(sizeof(struct int_rep *)*int_count);

    /* Walk the list of integers and fill in the representations for the value */
    for (i = 0; i < (int)int_count; ++i)  {

        rep[i] = malloc(sizeof(struct int_rep));

        rep[i]->val = int_list[i];
        rep[i]->parity = get_parity_str(rep[i]->val);
        rep[i]->original_string = get_bin_str(rep[i]->val);

        /* Ignore the left most bit */
        rep[i]->val &= 0x7F;
        rep[i]->ascii_rep = get_ascii_rep(rep[i]->val);
    }
    return rep;
}


/**
 * Calculates the parity of the given value, and returns
 * a "ODD" / "EVEN" string based on the results
 *
 * @param val
 * @return - "ODD"/"EVEN" string
 */
char * get_ascii_rep(int val) {

    char * ascii_val;
    char * ascii_mneumonic[] = {
          "NUL", "SOH", "STX", "ETX", "EOT",
          "ENQ", "ACK", "BEL", "BS", "HT", "LF",
          "VT", "FF", "CR", "SO", "SI", "DLE",
          "DC1", "DC2", "DC3", "DC4", "NAK", "SYN",
          "ETB", "CAN", "EM", "SUB", "ESC", "FS",
          "GS", "RS", "US", "SPACE"
    };

    /* If not in printable range, select from prebuilt mneumonic table */
    
    // NOTE: A last minute specification says to use a function named 'iascii'
    // There is no such function.. There is `isascii()`, but this technically 
    // doesn't fulfull the requirements because non-printable ascii still 
    // return true in this scenario. So for the sake of abiding by the specification,
    // I created the 'iascii()' function to tell me whether it is a printable character
    if (iascii(val)) return ascii_mneumonic[val];

    /* Otherwise form a heap allocated, null terminated string with the ASCII value */
    ascii_val = malloc(sizeof(char)*2);
    ascii_val[0] = (char)val; ascii_val[1] = '\0';

    return ascii_val;

}


/**
 * Returns a binary string representation of the
 * given value
 * @param val
 * @return - A binary string
 */
char * get_bin_str(int val) {

    char * bin_string;
    int i;

    bin_string = malloc(sizeof(char)*TOKEN_SIZE+1);

    /* Walk the bits of the given value, insert a '1' character for each 1 bit */
    for (i = 0; i < TOKEN_SIZE; ++i)
        bin_string[7-i] = (val >> i) & 1 ? '1' : '0';
    bin_string[8] = '\0';

    return bin_string;
}


/**
 * Returns a string of the ascii representation of the given
 * value, either the mneumonic listed in `man ascii` or the
 * directly casted value
 *
 * @param val
 * @return - ASCII representation string of the given value
 */
char * get_parity_str(int val) {

    int bit_count, i;

    /* Walk the bits of the given value, increment a counter for each 1 bit */
    for (bit_count = i = 0; i < TOKEN_SIZE; ++i)
        bit_count += (val >> i) & 1;

    /* Return an EVEN/ODD string depending on the bit count */
    return bit_count % 2 ? "ODD" : "EVEN";
}

/**
 * Returns a boolean value whether the given value is within a printable range 
 */
int iascii(int val) {return val <= BEGIN_PRINTABLE_RANGE;}
