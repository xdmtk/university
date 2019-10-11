#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>
#include <stdint.h>
#include <string.h>
#include <limits.h>

#define _spc_ "\n\n"

#define NOT_SPECIAL 0x1
#define IS_NAN 0xFFFFFFFF
#define POSITIVE_ZERO 0x0
#define NEGATIVE_ZERO 0x80000000
#define POSITIVE_INF  0x7F800000
#define NEGATIVE_INF  0xFF800000


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

/* IEEE-754 to Decimal functions */
void floating_to_decimal(void);
int in_hex_table(char * c, int size);
int is_nan(union d_bits decimal_mem);
float calculate_normalized(int mantissa_bits);

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
        _spc_"*** IEEE HEX: ",
        _spc_"*** The IEEE-754 representation is: "

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
    
    if (float_mem.decimal_mem != 0x0)
        /* Print results */
        printf("%s%s%s%s%s%s%s%.8x", items[1], bs.sign, items[2],
                bs.exponent, items[3], bs.mantissa, 
                items[4], float_mem.decimal_mem);
    else 
        printf("%s%s%s%s%s%s%s%f", items[1], bs.sign, items[2],
                bs.exponent, items[3], bs.mantissa, 
                items[5], float_mem.decimal);
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
    int i, unbiased_exp, special_index = 0;
    float normalized_decimal; 
    char buffer[256], sign[2] = {'\0', '\0'};
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
    for (i=0; i<256; i++) buffer[i] = '\0'; 
    
  

    /* Prompt and input */
    printf("Enter the IEE-754 representation: ");
    scanf("%s", buffer);

    /* Invalid hex immediately output as NaN */
    if (!in_hex_table(buffer, strlen(buffer))) {
        printf("%s-%s%s", items[0], items[4], special_cases[4]);
        return;
    }
    
    /* Parse hex */
    decimal_mem.decimal = strtol(buffer, NULL, 16);
    
    /* Check special cases */
    switch (decimal_mem.decimal) {
        case POSITIVE_INF: special_index = 3; break;
        case NEGATIVE_INF: special_index = 4; break;
        case POSITIVE_ZERO: special_index = 1; break;
        case NEGATIVE_ZERO: special_index = 2; break;
    } 

    /* Print special cases output */
    if ((is_nan(decimal_mem) == IS_NAN) || special_index) {
        printf("%s%c%s%s", items[0], 
                special_index == 1 || special_index == 3 ? '+' : '-',
                items[4], special_index ? special_cases[special_index-1] : 
                special_cases[4]);
        return;
    }
    
    /* Print values in normal cases */
    sign[0] = ((decimal_mem.decimal >> 31) & 0x1) ? '-' : '+';
    unbiased_exp = ((decimal_mem.decimal >> 23) & 0xFF) - 127;

    /* TODO: This is wrong. Need to get the mantissa bits and do the 2^-n calculation */
    normalized_decimal = calculate_normalized(decimal_mem.decimal & 0x7FFFFF);
    
    printf("%s%s%s%d%s%f%s%f", items[0], sign, items[1], unbiased_exp,
            items[2], normalized_decimal, items[3], decimal_mem.float_mem);

}

float calculate_normalized(int mantissa_bits){
    
    int i;
    float sum = 0;

    for (i=1; i < 24; i++)
        sum += ((mantissa_bits >> (23 - i)) & 0x1) ? pow(2, (-1)*i) : 0;
    return sum+1;
}


int is_nan(union d_bits decimal_mem) {
    if (decimal_mem.decimal != POSITIVE_INF 
            && decimal_mem.decimal != NEGATIVE_INF
            && ((decimal_mem.decimal >> 23 == 0x1FF)
            || decimal_mem.decimal >> 23 == 0xFF)
            && ((decimal_mem.decimal & 0x7FFFFF) != 0x0)) {
        return IS_NAN;
    }
    return NOT_SPECIAL;
}

int in_hex_table(char * c, int size) {
    int flag, i,j;
    unsigned char byte_table[] = {
        '0','1','2','3','4',
        '5','6','7','8','9',
        'A','B','C','D','E',
        'F'
    };
    
    /* Must be a valid 32 bit hex number */
    if (size > 8) return 0;

    /* Check if all hex is valid - Lowercase OK */
    for (flag = i = 0; i < size; i++) {
        for (j = 0; j < 16; j++) {

            int is_lower = c[i] >= 97 && c[i] <= 122;
            if (byte_table[j] == c[i] || 
                    (is_lower && (byte_table[j] == (c[i] - 32))))
                flag = 1;
        }
        /* Break if hex digit not in byte table */
        if (!flag) break;
        if (size - i != 1) flag = 0;
    }
    return flag;
}




/* Input handler for menu selections */
void handle_selection(int selection) {
    if (selection == 1) decimal_to_floating();
    else if (selection == 2) floating_to_decimal();
    else exit_program();
}

int show_menu(void) {
    
    int input, i;
    char * items[] = {
        _spc_"Floating-point conversion:",
        _spc_"1) Decimal to IEEE-754 conversion",
        _spc_"2) IEEE-754 to Decimal conversion",
        _spc_"3) Exit",
        _spc_"Enter Selection: "
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
    printf("\n\n*** Program Terminated Normally");
    exit(0);
}


