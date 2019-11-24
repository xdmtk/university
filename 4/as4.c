#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define _spc_ "\n\n"
#define true 1
#define false 0

/* State struct to pass around function calls, simplifies parameter entry */
struct state {
};



/* Menu functions */
int show_menu(void);
void handle_selection(int, struct state *); 
void exit_program(struct state *st);

int main(void) {
    struct state * st = (struct state *)malloc(sizeof(struct state *));
    handle_selection(show_menu(), st);
}





/* Input handler for menu selections */
void handle_selection(int selection, struct state * st) {
    if (selection == 3) exit_program(st);
    return;
}

int show_menu(void) {
    
    int input, i;
    char * items[] = {
        _spc_"Main Menu - Main Memory to Cache Memory Mapping",
        _spc_"------------------------------------------------",
        _spc_"1) Enter Configuration Parameters",
        _spc_"2) Read from Cache",
        _spc_"3) Write to Cache",
        _spc_"4) Quit Program",
        _spc_"Enter selection:"
    };
    
    /* Output menu choices */ 
    for (i=0; i<sizeof(items)/sizeof(char *); i++) printf("%s",items[i]);
    
    /* Get choice selection from input */
    if (scanf("%d", &input) >= 0) return input;
    else return 0;
}

void exit_program(struct state *st) {
    
    printf(_spc_"*** Memory Freed Up - Program Terminated Normally");
    exit(0);
}
