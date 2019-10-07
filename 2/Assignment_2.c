#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <errno.h>

#define BUFFER_SIZE 256
#define INPUT_OK 1
#define NOT_HEX 2
#define IS_NAN 3
#define _spc_ "\n\n"


/* Function prototypes */
int show_menu(void);
void handle_selection(int selection);
void exit_program(void);



/* Decimal to IEEE-754 */
void decimal_to_floating(void);
void write_mantissa(unsigned char *mantissa, float mantissa_float);
void write_exponent(float *dec_in, unsigned char * biased_exp, int * unbiased_exp, int sign);
void write_sign(float dec_in, unsigned char *sign);
void write_hex(unsigned char *sign, unsigned char *exp, 
        unsigned char *mantissa, unsigned char *hex);
int get_unbiased_exp(float dec_in);
int handle_special(float dec_in, unsigned char *exp, 
        unsigned char *sign, unsigned char *mantissa);


/* IEEE-754 to Decimal */
void floating_to_decimal(void);
int parse_hex_input(unsigned char *buffer, unsigned char *hex_in);
int in_hex_table(unsigned char c);



/* Main function */
int main(void) {
    
    /* Continue indefinitely until termination is signaled from menu */
    while (1) {
        handle_selection(show_menu()); 
    }
}

void floating_to_decimal(void) {

    int unbiased_exp;
    unsigned char biased_exp[9], mantissa[24], sign[2] , hex_in[9], buffer[256];
    char * items[] = {
        _spc_"*** Sign: ",
        _spc_"*** Unbiased exponent: ",
        _spc_"*** Normalized Decimal: ",
        _spc_"*** Decimal: "
    };
    biased_exp[8] = mantissa[23] = hex_in[8] = sign[1] = '\0';
    
    if (parse_hex_input(buffer, hex_in) != NAN) {
        printf("nan");
        exit(0);
    }


    

}



int parse_hex_input(unsigned char *buffer, unsigned char *hex_in) {
    
    unsigned char c;
    int i,j, flag = INPUT_OK;
    
    fflush(stdin);
    /* Zero out input buffer */
    for (i=j=0; i < BUFFER_SIZE; i++) 
        buffer[i] = '\0';
    
    /* Get input and store in buffer */
    while (((c = getchar()) != '\n') && j < BUFFER_SIZE) {
        if ((j > 8) || (!in_hex_table(c)))
            flag = IS_NAN;
        buffer[j++] = c;
    } 

    return flag;
}

int in_hex_table(unsigned char c) {
    int i, flag = NOT_HEX;
    unsigned char byte_table[] = {
        '0','1','2','3','4',
        '5','6','7','8','9',
        'A','B','C','D','E',
        'F'
    };
    for (i = 0; i < 15; i++) {
        if (c == byte_table[i])
            flag = INPUT_OK;
    }
    return flag;
}


/** 
 * May need to consider an overflow/underflow situation 
 */
void decimal_to_floating(void) {
    
    float dec_in;
    int unbiased_exp;
    unsigned char biased_exp[9], mantissa[24], hex[9], sign[2];
    char * items[] = {
        _spc_"*** Sign: ",
        _spc_"*** Biased exponent: ",
        _spc_"*** Mantissa: ",
        _spc_"*** IEEE HEX: "
    };


    /* Zero out char arrays */
    biased_exp[8] = mantissa[23] = hex[8] = sign[1] = '\0';

    /* Input decimal */
    printf(_spc_"Enter the decimal representation:");

    /* Require numerical input, otherwise exit the program */
    if (!scanf("%f\n",&dec_in))
        exit_program();

    /* Check for special cases ( inf/-inf */
    if (!handle_special(dec_in, biased_exp, sign, mantissa)) { 

        /* Write out the sign bit */
        write_sign(dec_in, sign);
        
        /* Write out the exponent bits */
        write_exponent(&dec_in, biased_exp, &unbiased_exp, sign[0] == '1' ? -1 : 1);
        
        /* Write out the mantissa bits */
        write_mantissa(mantissa, dec_in/pow(2,unbiased_exp) - 1.0);

    }

    /* Write out the hex representation */
    write_hex(sign, biased_exp, mantissa, hex);
   

    /* Output results */
    printf("%s%s%s%s%s%s%s%s",
            items[0], sign, items[1], biased_exp,
            items[2], mantissa, items[3], hex);
}


/* Negative/positive check on input decimal to write sign bit */
void write_sign(float dec_in, unsigned char *sign) {

    sign[0] = dec_in < 0 ? '1' : '0';
}



/* Check for infinity on input decimal and handle appropriately */
int handle_special(float dec_in, unsigned char *exp, 
        unsigned char *sign, unsigned char *mantissa) {
    
    /* Get infinity macro */
    int flag = fpclassify(dec_in); int special = 0, i;
    
    /* Test for infinity macro */
    if (flag == FP_INFINITE || flag == (-FP_INFINITE)) {

        /* IEEE Representation of infinity, FF for exponent */
        for (i = 0; i < 8; i++)
            exp[i] = '1';

        /* IEEE Representation of infinity in mantissa, 0 */
        for (i = 0; i < 23; i++)
            mantissa[i] = '0';

        /* Sign bit determined by negative or positive infintiy */
        sign[0] = dec_in == INFINITY ? '0' : '1';

        /* Return special flag to skip normal conversion routines */
        special = 1;
    }
    return special;
}





void write_exponent(float *dec_in, unsigned char * biased_exp, int * unbiased_exp, int sign) {
    int i, biased_exp_int;

    /* Calculate integer representation of biased exponent */
    biased_exp_int = 127 + (*unbiased_exp = get_unbiased_exp(*dec_in));
   
    /* Make positive for sake of calculation */
    *dec_in *= sign;
    
    /* Convert biased exponent to binary char array */
    for (i = 7; i >= 0; i--) {
        biased_exp[i] = (biased_exp_int & 0x1) ? '1' : '0';
        biased_exp_int = biased_exp_int >> 1;
    }
}


void write_mantissa(unsigned char *mantissa, float mantissa_float) {

    int i;
    /* Convert mantisa decimal representation to binary char array */
    for (i = 0; i < 23; i++) {

        /* Get value of 2^(current_bit) */
        float pow_res = pow(2,-1 - i);

        /* Subtract from current value of mantissa float representation */
        float res = mantissa_float - pow_res;

        /* If result is still 0 or greater, mark a 1 on the current
         * mantissa bit, and set the mantissa float representation
         * to the result of the subtraction 
         */
        if (res >= 0) {
            mantissa[i] = '1';
            mantissa_float = res;
        }
        else
            mantissa[i] = '0';
    }

}

void write_hex(unsigned char *sign, unsigned char *exp, unsigned char *mantissa, 
        unsigned char *hex) {
    
    int i, j, h;
    unsigned char full[32], byte,
        byte_table[] = {
            '0','1','2','3','4',
            '5','6','7','8','9',
            'A','B','C','D','E',
            'F'
        };
        
    /* Scan the whole IEEE representation char array and use bits for hex 
     * interpretation 
     */
    memcpy(full,sign,1);
    memcpy(full+1,exp,8);
    memcpy(full+9,mantissa,23);
    
    /* Take bits 4 at a time, and convert to integer representation */
    for (i = 0, h = 0; i < 32; ) {
        for (j = 3, byte = 0; j >= 0; j--, i++) {
            byte += full[i] == '1' ? pow(2,j) : 0;
        }

        /* Use integer representation to index byte table for char representation */
        hex[h++] = byte_table[byte];
    }
}



/* Calculate the unbiased exponent needed to raise 2 to the magnitude
 * that is equal to or less than the input decimal 
 */
int get_unbiased_exp(float dec_in) {

    int i, exp, exp_cnt, exp_inc;
    i = exp = exp_cnt = 0;
    
    
    /* Negative input increments 2^n where n is decreasing */
    exp_inc  = (dec_in < 1 && dec_in > -1) ? -1 : 1;

    /* Conver to positive for sake of calculation */
    dec_in *= dec_in < 0 ? -1 : 1;

    /* Iterate through exponent values to total the n value of 2^n 
     * that equals the input decimal 
     */
    for (; ; i++) {
        if (dec_in - pow(2,exp) >= 0) {
            dec_in -= pow(2,exp);
            exp_cnt++; 
        }
        else
            break;
        exp += exp_inc;
    }

    return exp_cnt;
}





/* Input handler for menu selections */
void handle_selection(int selection) {
    if (selection == 1) decimal_to_floating();
    else if (selection == 2) floating_to_decimal();
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
    if (scanf("%d\n", &input) >= 0)
        return input;

    return 0;
}


/* Free allocated structures */
void exit_program() {
    printf("\n\nProgram Terminated Normally");
    exit(0);
}


