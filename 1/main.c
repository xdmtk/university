#include <stdio.h>
#include <stdlib.h>

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
            break;
        case 3:
            break;
        default:
            invalid_selection(st);
            break;
    }
}


/* Function that provides the prompts for parameter entry */
void enter_parameters(struct state * st) {
    
    int i;
    /* Sequential prompt listing */
    char * items[] = {
        "\n\nEnter the frequency of the machine (MHz): ",
        "\n\nEnter the number of instruction classes: ",
        "\n\nEnter CPI of class ",
        "\n\nEnter instruction count of class "
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
        "1) Enter parameters\n\n",
        "2) Print Results\n\n",
        "3) Quit\n\n"};
    
    /* Print menu options */
    for (i=0; i<3; i++)
        printf("%s",items[i]);
    
    /* Get choice selection from input */
    if (scanf("%d", &input) >= 0)
        return input;

    return 0;
}


