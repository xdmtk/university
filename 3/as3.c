#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define _spc_ "\n\n"



struct instr {
    int src_one, src_two, dest, wait_cycle;
};



/* Menu functions */
int show_menu(void);
void exit_program(struct instr **, int);
void free_prg_mem(struct instr **, int);
void handle_selection(int, int *, struct instr **);

/* Input function */
struct instr ** read_instructions(int *);








int main(void) {

    struct instr ** instructions;
    int instructions_read;

    instructions = NULL; 

    while (1) handle_selection(show_menu(), &instructions_read, instructions);
    return 0;
}


struct instr **read_instructions(int * instr_read) {

    struct instr **instructions;
    struct instr current_instruction;
    int src_one, src_two, dest, ret;

    /* Initialize array of pointers to hold instruction struct's */
    instructions = (struct instr **) malloc(sizeof(struct instr **));

    for (*instr_read = 1, ret = 0; ret >= 0 ; ++(*instr_read)) {

        /* Print prompt and read input */
        printf("%d) ", *instr_read);
        ret = scanf(" r%d=r%d+r%d", &current_instruction.dest, &current_instruction.src_one, 
            &current_instruction.src_two);

       
        /* Dynamically expand pointer struct for new instruction entry */
        instructions = (struct instr **) realloc(instructions, sizeof(struct instr **) * (*instr_read));
        
        /* On read success, allocate new entry in pointer struct */
        instructions[*instr_read-1] = (struct instr *) malloc(sizeof(struct instr *));

        /* Copy newly read data into pointer struct */
        memcpy(instructions[*instr_read-1], &current_instruction, sizeof(struct instr));
    }
    
    return instructions;
}




/* Input handler for menu selections */
void handle_selection(int selection, int * instructions_read, struct instr ** instructions) {

    if (selection == 1) {
        
        /* Free existing instruction memory if already inputted */
        if (instructions != NULL) 
            free_prg_mem(instructions, *instructions_read);
        instructions = read_instructions(instructions_read);
    } 

}

int show_menu(void) {
    
    int input, i;
    char * items[] = {
        _spc_"Pipelined instruction performance",
        _spc_"1) Enter instructions",
        _spc_"2) determine when instructions are fetched",
        _spc_"3) Exit",
        _spc_"Enter Selection: "
    };
    
    /* Output menu choices */ 
    for (i=0; i<5; i++)
        printf("%s",items[i]);
    
    /* Get choice selection from input */
    if (scanf("%d", &input) >= 0)
        return input;

    return 0;
}

void free_prg_mem(struct instr ** instructions, int instructions_read) {
    int i;

    /* Free up all allocated memory */
    if (instructions != NULL) {
        for (i=0; i < instructions_read; i++)
            free(instructions[i]);
        free(instructions);
    }

}

void exit_program(struct instr ** instructions, int instructions_read) {
    
    if (instructions != NULL)
        free_prg_mem(instructions, instructions_read);

    printf("\n\n*** Program Terminated Normally");
    exit(0);
}


