#include <stdio.h>
#include <stdlib.h>
#define _spc_ "\n\n"

struct instruction_class {
    int cpi, instruction_count;
};

struct state {
    int frequency, instruction_classes;
    struct instruction_class * ic;
};

int show_menu(void);
void handle_selection(short selection, struct state * st);
void enter_parameters(struct state * st);
void print_results(struct state * st);
void invalid_selection(struct state * st);


int main(void) {
    
    short selection;
    struct state * st;
        
    /* Allocate for state structure to carry parameters from functin
     * to function
     */
    if (!(st = (struct state *)malloc(sizeof(struct state)))) {
        printf("\nCould not allocate memory. Exiting!\n");
        exit(-1);
    }

    /* Continue indefinitely until termination is signaled from menu */
    while (1) {
        selection = show_menu();
        handle_selection(selection, st);
    }
}


/* Input handler for menu selections */
void handle_selection(short selection, struct state * st) {

    switch (selection) {
        case 1:
            enter_parameters(st);
            break;
        case 2:
            print_results(st);
            break;
        case 3:
            exit(0);
            break;
        default:
            invalid_selection(st);
            break;
    }
}


void print_results(struct state * st) {
   
    int i;
    char * items[] = {
        _spc_"FREQUENCY (MHz): ",
        _spc_"INSTRUCTION DISTRIBUTION"
        _spc_"CLASS\tCPI\tCOUNT\n",
        _spc_"PERFORMANCE VALUES",
        _spc_"AVERAGE CPI\t",
        _spc_"TIME (ms)\t",
        _spc_"MIPS\t",
        _spc_"Nicholas Martinez"
    };
    
    /* Print frequency in MHz */
    printf(_spc_"%s: %d", items[0], st->frequency);
    
    /* Print out instruction distribution for all instruction 
     * classes */
    printf(_spc_"%s", items[1]);
    for (i=0; i < st->instruction_classes; i++)
        printf(_spc_"%d\t%d\t%d", i+1, st->ic[i].cpi, st->ic[i].instruction_count);
    
    /* TODO: Make computation for Average CPI, TIME, MIPS */


}



/* Function that provides the prompts for parameter entry */
void enter_parameters(struct state * st) {
    
    int i;
    /* Sequential prompt listing */
    char * items[] = {
        _spc_"Enter the frequency of the machine (MHz): ",
        _spc_"Enter the number of instruction classes: ",
        _spc_"Enter CPI of class ",
        _spc_"Enter instruction count of class "
    };
    
    /* Collect frequency of machine */
    printf("%s", items[0]);
    scanf("%d", &st->frequency);

    /* Collect number of instruction classes */
    printf("%s", items[1]);
    scanf("%d", &st->instruction_classes);

    /* Allocate memory for number of instruction classes specified */
    if (!(st->ic = (struct instruction_class *) malloc(sizeof(struct instruction_class *)
            *st->instruction_classes))) {

        printf("\nCould not allocate memory. Exiting!\n");
        free(st);
        free(st->ic);
        exit(-1);
    }
    
    /* Collect parameters for # of instruction classes specified */ 
    for (i=0; i < st->instruction_classes; i++) {

        printf("%s%d: ", items[2], i+1);
        scanf("%d", &st->ic[i].cpi);
        
        printf("%s%d (millions): ", items[3], i+1);
        scanf("%d", &st->ic[i].instruction_count);
    }
}



int show_menu(void) {
    
    int i,input;
    char * items[] = {
        _spc_"1) Enter parameters",
        _spc_"2) Print Results",
        _spc_"3) Quit",
        _spc_"Enter Selection: "
    };
    
    /* Print menu options */
    for (i=0; i<4; i++)
        printf("%s",items[i]);
    
    /* Get choice selection from input */
    if (scanf("%d", &input) >= 0)
        return input;

    return 0;
}


/* Free allocated structures */
void invalid_selection(struct state * st) {
    printf("\nInvalid selection. Exiting!\n");
    free(st->ic);
    free(st);
    exit(0);
}

