#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define _spc_ "\n\n"


/* Set of structs to hold input/output variable data */
struct results {
    double avg_cpi, time, mips;
};

/* Sub-struct within state to hold various instruction classes */
struct instruction_class {
    int cpi, instruction_count;
};

/* Struct to be passed around various functions */
struct state {
    int frequency, instruction_classes;
    struct instruction_class * ic;
};


/* Function prototypes */
int show_menu(void);
void handle_selection(short selection, struct state * st);
void enter_parameters(struct state * st);
void print_results(struct state * st);
void invalid_selection(struct state * st);
struct results * calculate_results(struct state * st);



/* Main function */
int main(void) {
    
    struct state * st;
        
    /* Allocate for state structure to carry parameters from function
     * to function
     */
    if (!(st = (struct state *)malloc(sizeof(struct state)))) {
        exit(-1);
    }

    /* Continue indefinitely until termination is signaled from menu */
    while (1) {
        handle_selection(show_menu(), st);
    }
}


/* Input handler for menu selections */
void handle_selection(short selection, struct state * st) {

    if (selection == 1) { enter_parameters(st); }
    else if (selection == 2) { print_results(st); }
    else { invalid_selection(st); }
}



/* Function to print calculation results */
void print_results(struct state * st) {
    
    /* Declare all necessary variables and string literals */
    int i;
    struct results * res;
    char * items[] = {
        _spc_"FREQUENCY (MHz): ",
        _spc_"INSTRUCTION DISTRIBUTION"
        _spc_"CLASS\tCPI\tCOUNT",
        _spc_"PERFORMANCE VALUES",
        _spc_"AVERAGE CPI\t",
        _spc_"TIME (ms)\t",
        _spc_"MIPS\t",
    };
    
    /* Print frequency in MHz */
    printf(_spc_"%s: %d", items[0], st->frequency);
    
    /* Print out instruction distribution for all instruction 
     * classes */
    printf(_spc_"%s", items[1]);
    for (i=0; i < st->instruction_classes; i++)
        printf(_spc_"%d\t%d\t%d", i+1, st->ic[i].cpi, st->ic[i].instruction_count);
    
    /* Print out performance calculation results */
    res = calculate_results(st);
    printf("%s%s %.2f%s%.2f%s%.2f", items[2], items[3], 
            res->avg_cpi, items[4], 
            res->time, items[5],
            res->mips);
    
}
/* Function to handle calculation of all performace variables */
struct results * calculate_results(struct state * st) {
    
    /* Delcare neccesary variables and allocate space for results struct */
    int i;
    double avg_cpi, mips, time, total_ic;
    struct results * res = (struct results *) malloc(sizeof(struct
                results *));

    /* Failure to allocate exits the program */
    if (!res) {
        free(st);
        exit(-1);
    }

    /* Zero out local varibales */
    avg_cpi = mips = time = total_ic = 0;

    /* Loop through instruction classes to calculate average CPI */
    for (i = 0; i < st->instruction_classes; i++) {
        avg_cpi += st->ic[i].cpi * st->ic[i].instruction_count;
        total_ic += st->ic[i].instruction_count; 
    }

    /* Get averafe CPI by dividing it against the total instruction count */
    res->avg_cpi = avg_cpi / total_ic;

    /* Get time by multiplying average cpi by total instruction count, divided by the 
     * clock rate, ( multiplied by 1000 to calculate for MS */
    res->time = ((res->avg_cpi * total_ic)/st->frequency)*1000.00;

    res->mips = (st->frequency * pow(10.0,6.0))/(res->avg_cpi * (pow(10.0,6.0)));
    return res;
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



