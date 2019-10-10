#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>
#include <stdint.h>
#include <string.h>
#include <limits.h>

#define _spc_ "\n\n"
#define NAN_SPECIAL 0xFF


/* TODO: Maybe name these a bit better */
union f_bits {
    float decimal;
    uint32_t decimal_mem;
};

union d_bits {
    float float_mem;
    uint32_t decimal;
};

struct bit_state {
    unsigned char sign[2];
    unsigned char exponent[9];
    unsigned char mantissa[24];
};



/* Decimal to IEEE-754 functions */
void decimal_to_floating(void);
void write_bits(union f_bits float_mem, struct bit_state * bs);
int in_hex_table(char * c, int size);
void floating_to_decimal(void);

/* Menu handling functions */
void exit_program(void);
int show_menu(void);
void handle_selection(int selection);


/* Can I really not have a void main function ? */
int main(void) {
    while (1) handle_selection(show_menu());
    return 0;
}






void decimal_to_floating(void) {
    
    /* Declare and initialize stack memory */
    union f_bits float_mem;
    struct bit_state bs;
    char * items[] = {
        _spc_"Enter the decimal representation: ",
        _spc_"*** Sign: ",
        _spc_"*** Biased exponent: ",
        _spc_"*** Mantissa: ",
        _spc_"*** IEEE HEX: "
    };
    bs.sign[1] = bs.exponent[8] = bs.mantissa[23] = '\0';
    
    /* Print prompt and read response into float union */
    printf("%s",items[0]);
    scanf("%f", &float_mem.decimal);
    
    /* Get the binary representation of the floating point
     * of the union, store in struct with char represented 
     * bit fields
     */
    write_bits(float_mem, &bs);
    
    /* Print results */
    printf("%s%s%s%s%s%s%s%x", items[1], bs.sign, items[2],
            bs.exponent, items[3], bs.mantissa, 
            items[4], float_mem.decimal_mem);
}


/* Iterate through uint32_t representation of float bits to get
 * sign, exponent, and mantissa bit fields
 */
void write_bits(union f_bits float_mem, struct bit_state * bs) {
    
    int b,i;
    for (i = b = 0; i < 1; i++)
        bs->sign[b] = ((float_mem.decimal_mem >> (31 - i)) & 0x1) == 1 ? '1' : '0';
    for (b = 0; b < 8; i++, b++)
        bs->exponent[b] = ((float_mem.decimal_mem >> (31 - i)) & 0x1) == 1 ? '1' : '0';
    for (b = 0; b < 23; i++, b++)
        bs->mantissa[b] = ((float_mem.decimal_mem >> (31 - i)) & 0x1) == 1 ? '1' : '0';

}


void floating_to_decimal(void) {
    
    union d_bits decimal_mem;
    int i, flag;
    char buffer[256];
    char * items[] = {
        _spc_"*** Sign: ",
        _spc_"*** Unbiased exponent: ",
        _spc_"*** Normalized Decimal: ",
        _spc_"*** Decimal: ",
        _spc_"*** Special case: "
    };
    char * special_cases[] = {
        "+0",
        "-0"
        "+infinity",
        "-infinity",
        "NaN"
    };
    for (i=0; i<256; i++) buffer[i] = '\0'; 
    
    /* May need to change this prompt */
    printf("Enter the IEE-745 representation: ");
    scanf("%s", &buffer);
    
    if (!in_hex_table(buffer, strlen(buffer)))
        flag = NAN_SPECIAL;

    decimal_mem.decimal = strtol(buffer, NULL, 16);
    

    
}



int in_hex_table(char * c, int size) {
    int flag, i,j;
    unsigned char byte_table[] = {
        '0','1','2','3','4',
        '5','6','7','8','9',
        'A','B','C','D','E',
        'F'
    };
    
    if (size > 8) return 0;
    for (flag = i = 0; i < size; i++) {
        for (j = 0; j < 16; j++) {
            if (byte_table[j] == c[i])
                flag = 1;
        }
        if (!flag) break;
        if (size - i != 1) flag = 0;
    }
    return flag;
}




/* Input handler for menu selections */
void handle_selection(int selection) {
    if (selection == 1) decimal_to_floating();
    if (selection == 2) floating_to_decimal();
    else exit_program();
}

int show_menu(void) {
    
    int input, i;
    char * items[] = {
        _spc_"Floating-point conversion:",
        _spc_"1) Decimal to IEEE-754 conversion",
        _spc_"2) IEEE-754 to Decimal conversion",
        _spc_"3) Exit",
        _spc_"Enter Selection"
    };
    
     
    for (i=0; i<5; i++)
        printf("%s",items[i]);
    
    /* Get choice selection from input */
    if (scanf("%d", &input) >= 0)
        return input;

    return 0;
}

/* Free allocated structures */
void exit_program(void) {
    printf("\n\nProgram Terminated Normally");
    exit(0);
}


