#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <errno.h>
#define _spc_ "\n\n"


/* Function prototypes */
int show_menu(void);
void handle_selection(int selection);
int get_unbiased_exp(float dec_in);
void exit_program(void);
void write_mantissa(unsigned char *mantissa, float mantissa_float);
void write_exponent(float *dec_in, unsigned char * biased_exp, int * unbiased_exp, int sign);
void write_sign(float dec_in, unsigned char *sign);


/* Main function */
int main(void) {
    
    /* Continue indefinitely until termination is signaled from menu */
    while (1) {
        handle_selection(show_menu()); 
    }
}

void decimal_to_floating(void) {
    
    float dec_in;
    int unbiased_exp;
    unsigned char biased_exp[8], mantissa[23], hex[8], sign[1];
    
    /* Input decimal */
    printf(_spc_"Enter the decimal representation:");

    /* Bad input? Exit the program */
    if (!scanf("%f",&dec_in))
        exit_program();
    
    /* Write out the sign bit */
    write_sign(dec_in, sign);
    
    /* Write out the exponent bits */
    write_exponent(&dec_in, biased_exp, &unbiased_exp, sign[0] == '1' ? -1 : 1);
    
    /* Write out the mantissa bits */
    write_mantissa(mantissa, dec_in/pow(2,unbiased_exp) - 1.0);

}

void write_sign(float dec_in, unsigned char *sign) {
    sign[0] = dec_in < 0 ? '1' : '0';
}



void write_exponent(float *dec_in, unsigned char * biased_exp, int * unbiased_exp, int sign) {
    int i, biased_exp_int;

    /* Calculate integer representation of biased exponet */
    biased_exp_int = 127 + (*unbiased_exp = get_unbiased_exp(*dec_in));
   
    /* Make positive for sake of calculation */
    *dec_in *= sign;
    
    /* Convert biased exponet to binary char array */
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

int get_unbiased_exp(float dec_in) {

    int i, exp, exp_cnt, exp_inc;
    i = exp = exp_cnt = 0;
    
    exp_inc  = (dec_in < 1 && dec_in > -1) ? -1 : 1;
    dec_in *= dec_in < 0 ? -1 : 1;

    for (; i < 8; i++) {
        if (dec_in - pow(2,exp) >= 0) {
            dec_in -= pow(2,exp);
            exp_cnt++; 
        }
        exp += exp_inc;
    }

    return exp_cnt;
}





/* Input handler for menu selections */
void handle_selection(int selection) {
    if (selection == 1) decimal_to_floating();
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
void exit_program() {
    printf("\n\nProgram Terminated Normally");
    exit(0);
}


