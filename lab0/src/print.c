#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <lab0/print.h>

void print_table(struct int_rep **rep, int rep_count) {
    print_header();
    print_reps(rep, rep_count);
    free(rep);
}

void print_header() {

    int i;
    char * header[] = {"Original", "ASCII", "Decimal", "Parity"};

    for (i = 0; i < 4; ++i) print_column(header[i], JUSTIFY_LEFT); LINE_BREAK;
    for (i = 0; i < 4; ++i) print_column(HORIZONTAL_LINE, PRINT_LB); LINE_BREAK;
}

void print_reps(struct int_rep **rep, int rep_count) {

    int i;
    char buf[4] = {'\0'};
    for (i = 0; i < rep_count; ++i) {

        print_column(rep[i]->original_string, JUSTIFY_LEFT);
        print_column(rep[i]->ascii_rep, JUSTIFY_RIGHT);

        sprintf(buf, "%d", rep[i]->val);
        print_column(buf, JUSTIFY_RIGHT);

        print_column(rep[i]->parity, JUSTIFY_LEFT);

        /* No T-Error column */
        //print_column((!strcmp(rep[i]->parity, "ODD") ? "TRUE" : "FALSE"), JUSTIFY_LEFT);

        LINE_BREAK;
    }
}

void print_column(char * str, int mode) {

    int i, spaces;

    if (mode == JUSTIFY_LEFT) {
        printf(str);
        for (i = 0, spaces = COLUMN_WIDTH - strlen(str); i < spaces; ++i)
            printf(" ");
    }
    else if (mode == JUSTIFY_RIGHT) {
        for (i = 0, spaces = COLUMN_WIDTH - strlen(str); i < spaces; ++i)
            printf(" ");
        printf(str);
    }
    else  {
        printf(str);
    }
    printf(" ");
}


