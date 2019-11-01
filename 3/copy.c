#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define _spc_ "\n\n"
#define true 1
#define false 0

struct state {
    struct instr ** instructions;
    int instruction_count;
};

struct instr {
    int src_one, src_two, dest, cycle;
};

/* Menu functions */
int show_menu(void);
void exit_program(struct state *);
void free_prg_mem(struct state *, int);
void handle_selection(int, struct state *); 

/* Core functions */
void read_instructions(struct state *);
int analyze_instructions(struct state *);
void print_instructions(struct state *);

/* Helper functions */
void inc_cycles(struct state *, int);
int set_dep(struct state *, int *, int *);





int main(void) {

    struct state * st = (struct state *) calloc(1,sizeof(struct state *));
    while (1) handle_selection(show_menu(), st);
}





/* Function to collect instruction data via user input */
void read_instructions(struct state *st) {
    
    int i;
    free_prg_mem(st, false);

    /* Get instruction count */
    printf("Enter number of instructions: ");
    scanf("%d", &st->instruction_count);
    
    /* Allocate memory for instruction pointer array */
    st->instructions = (struct instr **) malloc(sizeof(struct instr **)*st->instruction_count);
    
    /* Read instructions */
    for (i = 0; i < st->instruction_count; ++i) {
        
        /* Allocate memory for instruction pointer */
        st->instructions[i] = (struct instr *) malloc(sizeof(struct instr *));

        /* Get register information in format rX=rY+rZ */
        printf("%d) ", i+1);
        scanf(" r%d=r%d+r%d", &st->instructions[i]->dest, 
                &st->instructions[i]->src_one, 
                &st->instructions[i]->src_two);

        /* Set initial cycle number based on input order */
        st->instructions[i]->cycle = i+1;
    }
}

/* Function to print instructions and cycle count */
void print_instructions(struct state *st) {
    
    int i,j, total_cycles;

    /* Calculate cycle count and instruction cycle # */
    total_cycles = analyze_instructions(st);
    for (i = 0; i < st->instruction_count; ++i) {
        
        /* Print cycle # per instruction */
        printf("Total number of cycles: %d"_spc_
                "Instruction %d Fetched at Cycle %d"_spc_, 
                total_cycles, i+1, st->instructions[i]->cycle);

        /* Insert tabs corresponding to fetch cycle */
        for (j = 0; j < st->instructions[i]->cycle - 1; j++) printf("\t");

        /* Print instruction cycle operations */
        printf("IF\tID\tEX\tMM\tWB"_spc_);
    }
}


int analyze_instructions(struct state *st) {
   
    int i, j, dep, dep_cycle, stalled;
    i = j = stalled = dep_cycle = 0; dep  = -1;

    /* Iterate through intructions and begin tracking dependencies */
    for (i = 0; i < st->instruction_count; ) {
        
        /* Check for dependencies on either source register */
        if (st->instructions[i]->src_one == dep || st->instructions[i]->src_two == dep)

            /* If found, increment all pending instruction fetch cycle # */
            inc_cycles(st, i);

        /* If we are still waiting for a register result, decrement the cycles to go before
         * the result is resolved */
        if (dep_cycle)  --dep_cycle;

        /* Otherwise set the next destination register as the new dependency, and increment the
         * instruction iterator 'i' */
        else set_dep(st, &dep_cycle, &i);
    }
    
    /* Return total cycles by adding 4 to last instruction fetch cycle # */
    return st->instructions[i-1]->cycle+4;
}





/* Helper function to increment the fetch cycle # of all instructions
 * after the specified index */
void inc_cycles(struct state *st, int index) {

    for (; index < st->instruction_count; ++index)
        st->instructions[index]->cycle += 1;
}

/* Helper function to reset the dependency cycle count, increment the instruction
 * iterator, and set the next dependent register */
int set_dep(struct state *st, int * dep_cycle, int * iter) {

    *dep_cycle = 1;
    ++(*iter);
    return st->instructions[(*iter)-1]->dest;
}





/* Input handler for menu selections */
void handle_selection(int selection, struct state * st) {

    if (selection == 1) read_instructions(st);
    else if (selection == 2) print_instructions(st);
    else exit_program(st);
}

int show_menu(void) {
    
    int input, i;
    char * items[] = {
        _spc_"Pipelined instruction performance", _spc_"1) Enter instructions",
        _spc_"2) Determine when instructions are fetched", _spc_"3) Exit",
        _spc_"Enter Selection: "
    };
    
    /* Output menu choices */ 
    for (i=0; i<5; i++) printf("%s",items[i]);
    
    /* Get choice selection from input */
    if (scanf("%d", &input) >= 0) return input;
    else return 0;
}

void free_prg_mem(struct state *st, int exit) {

    int i;
    /* Free up all allocated memory */
    if (st->instructions != NULL) {
        for (i=0; i < st->instruction_count; i++) free(st->instructions[i]);
        free(st->instructions);
    }
    if (exit) free(st);
}

void exit_program(struct state *st) {
    
    free_prg_mem(st, true);
    printf("\n\n*** Program Terminated Normally");
    exit(0);
}
