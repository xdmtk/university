#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>
#include <string.h>
#include <errno.h>
#define _spc_ "\n\n"

void decimal_to_floating(void);
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
    
    float decimal;
   
    unsigned char * decimal_mem;
    unsigned char sign[2], exponent[9], mantissa[24];
    sign[1] = exponent[8] = mantissa[23] = '\0';

    char * items[] = {
        _spc_"Enter the decimal representation: ",
        _spc_"*** Sign: ",
        _spc_"*** Biased exponent: ",
        _spc_"*** Mantissa: ",
        _spc_"*** IEEE HEX: "
    };

    printf("%s",items[0]);
    scanf("%f", &decimal);
    

    /* Trying different approach */
    decimal_mem = reinterpret_cast<unsigned char *>(&decimal);
    memcpy(sign,decimal_mem,1);
    memcpy(exponent,decimal_mem+1,8);
    memcpy(mantissa,decimal_mem+9,23);
    
    printf("%s%s%s%s%s%s%s", items[1], sign,
            items[2], exponent, items[3], mantissa,
            items[4]);

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


