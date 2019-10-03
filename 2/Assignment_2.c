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


/* Main function */
int main(void) {
    
    /* Continue indefinitely until termination is signaled from menu */
    while (1) {
        handle_selection(show_menu()); 
    }
}

void decimal_to_floating(void) {
    
    float dec_in;
    int remainder, unbiased_exp;
    unsigned char biased_exp[8], mantissa[23], hex[8], sign[1];
    
    printf(_spc_"Enter the decimal representation:");
    if (!scanf("%f",&dec_in))
        exit_program();

    sign[0] = dec_in < 0 ? '1' : '0';
    unbiased_exp = 127 + get_unbiased_exp(dec_in);




    remainder = dec_in - pow(2,exp_c);




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


