#ifndef LAB0_PRINT_H
#define LAB0_PRINT_H
#include "convert.h"

#define LINE_BREAK printf("\n")
#define HORIZONTAL_LINE "--------"
#define COLUMN_WIDTH strlen("--------")
#define JUSTIFY_LEFT 1
#define JUSTIFY_RIGHT 2
#define PRINT_LB 3

/**
 * Master function that prints the table of information
 * for each binary token
 *
 * @param rep - Pointer to int_rep structure containing token information
 * @param rep_count - Amount of tokens in the structure array
 */
void print_table(struct int_rep **rep, int rep_count);

/**
 * Function to print out the header of the table
 */
void print_header();

/**
 * Function to print a column with a given string, with
 * either a left, right, or center justification
 *
 * @param str - The given string to print
 * @param mode - The justification macros JUSTIFY_LEFT/JUSTIFY_RIGHT/PRINT_LB
 */
void print_column(char * str, int mode);

/**
 * Slave function to print_table() that prints the actual data
 * contained in the int_rep structure
 *
 * @param rep
 * @param rep_count
 */
void print_reps(struct int_rep **rep, int rep_count);
#endif //LAB0_PRINT_H
