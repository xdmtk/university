#include <stdio.h>
#include <stdlib.h>

struct instruction_class {
    int instruction_count;
};

struct state {
    int frequency, instruction_classes;
    struct instruction_class * ic;
};

int show_menu(void);
void handle_selection(int selection, struct state * st);
void enter_parameters(struct state * st);
void invalid_selection(struct state * st);


int main(void) {
    
    int selection;
    struct state * st;

    if (!(st = (struct state *)malloc(sizeof(struct state)))) {
        printf("\nCould not allocate memory. Exiting!\n");
        exit(-1);
    }


    while (1) {
        selection = show_menu();
        handle_selection(selection, st);
    }
}


void handle_selection(int selection, struct state * st) {

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


void enter_parameters(struct state * st) {
    
    char * items[] = {
        "\n\nEnter the frequency of the machine (MHz): ",
        "\n\nEnter the number of instruction classes: ",
        "\n\nEnter CPI of class "
    };

    printf("%s", items[1]);
    scanf("%d", &st->frequency);

    printf("%s", items[2]);
    scanf("%d", &st->instruction_classes);

    if (!(st->ic = (struct instruction_class *) malloc(sizeof(struct instruction_class *)
            *st->instruction_classes))) {
        printf("\nCould not allocate memory. Exiting!\n");
        free(st);
        exit(-1);
    }
    






}



int show_menu(void) {

    int i,input;
    char * items[] = {
        "1) Enter parameters\n\n",
        "2) Print Results\n\n",
        "3) Quit\n\n"};
    
    for (i=0; i<3; i++)
        printf("%s",items[i]);

    if (scanf("%d", &input) >= 0)
        return input;
    return 0;
}


