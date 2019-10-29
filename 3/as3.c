#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define _spc_ "\n\n"



struct instr {
    int src_one, src_two, dest, wait_cycle;
};



/* Menu functions */
void handle_selection(int);
int show_menu(void);
void exit_program(void);

/* Input function */
struct instr ** read_instructions(int *);








int main(void) {
    while (1) handle_selection(show_menu());
    return 0;
}


struct instr **read_instructions(int * instr_read) {

    struct instr **instructions;
    struct instr current_instruction;
    int src_one, src_two, dest;
    
    /* Initialize array of pointers to hold instruction struct's */
    instructions = (struct instr **) malloc(sizeof(struct instr **));

    for (*instr_read = 1; ; ++(*instr_read)) {

        /* Print prompt and read input */
        printf("%d) ");
        if (scanf("r%d=r%d+r%d\n", &current_instruction.dest, &current_instruction.src_one, 
            &current_instruction.src_two) <= 0)
            break;
       
        /* Dynamically expand pointer struct for new instruction entry */
        instructions = (struct instr **) realloc(instructions, *instr_read);
        
        /* On read success, allocate new entry in pointer struct */
        instructions[*instr_read-1] = (struct instr *) malloc(sizeof(struct instr *));

        /* Copy newly read data into pointer struct */
        memcpy(instructions[*instr_read-1], &current_instruction, sizeof(struct instr));
    }
    
    return instructions;
}




/* Input handler for menu selections */
void handle_selection(int selection) {
    int instructions_read;
    if (selection == 1) read_instructions(&instructions_read);

}

int show_menu(void) {
    
    int input, i;
    char * items[] = {
        _spc_"Pipelined instruction performance"
        _spc_"1) Enter instructions"
        _spc_"2) determine when instructions are fetched"
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

void exit_program(void) {
    printf("\n\n*** Program Terminated Normally");
    exit(0);
}


