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
void invalid_selection();


int main(void) {
    
    int selection;
    struct state * st = (struct state *)malloc(sizeof(struct state));


    while (1) {
        selection = show_menu();
        handle_selection(selection, st);
    }
}


void handle_selection(int selection, struct state * st) {

    switch (selection) {
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        default:
            invalid_selection();
            break;
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


