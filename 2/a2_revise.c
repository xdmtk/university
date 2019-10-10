#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>
#include <stdint.h>
#include <limits.h>
#define _spc_ "\n\n"
    
union f_bits {
    float decimal;
    uint32_t decimal_mem;
};

struct bit_state {
    unsigned char sign[2];
    unsigned char exponent[9];
    unsigned char mantissa[24];
};



/* Decimal to IEEE-754 functions */
void decimal_to_floating(void);
void write_bits(union f_bits float_mem, struct bit_state * bs);

/* Menu handling functions */
void exit_program(void);
int show_menu(void);
void handle_selection(int selection);



int main(void) {
    while (1) {
        handle_selection(show_menu());
    }
    return 0;
}






void decimal_to_floating(void) {
    
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

    printf("%s",items[0]);
    scanf("%f", &float_mem.decimal);

    write_bits(float_mem, &bs);

    printf("%s%s%s%s%s%s%s%x", items[1], bs.sign, items[2],
            bs.exponent, items[3], bs.mantissa, 
            items[4], float_mem.decimal_mem);
}

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

    char * items[] = {
        _spc_"*** Sign: ",
        _spc_"*** Unbiased exponent: ",
        _spc_"*** Normalized Decimal: ",
        _spc_"*** Decimal: ",
        _spc_"*** Special case: "
    };
    char * special_cases[] = {
        "+0",
        "-0",
        "+infinity",
        "-infinity",
        "NaN"
    };
}





/* Input handler for menu selections */
void handle_selection(int selection) {
    if (selection == 1) decimal_to_floating();
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


