#ifndef LAB0_PRINT_H
#define LAB0_PRINT_H
#include "convert.h"
#include <stddef.h>

#define LINE_BREAK printf("\n")
#define HORIZONTAL_LINE "--------"
#define COLUMN_WIDTH strlen("--------")
#define JUSTIFY_LEFT 1
#define JUSTIFY_RIGHT 2
#define PRINT_LB 3

void print_table(struct int_rep **rep, int rep_count);

void print_header();

void print_column(char * str, int mode);

void print_reps(struct int_rep **rep, int rep_count);
#endif //LAB0_PRINT_H
