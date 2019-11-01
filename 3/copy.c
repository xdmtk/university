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
void set_dep(struct state *, int *, int *, int *, int *);
int is_dependency(int *, int, int);
void dec_dep_cycles(int *, int *);





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
   
    int i, j, dep_index, dep[5], dep_cycle[5], stalled;
    i = j = stalled = dep_index = 0; for (;i < 5; ++i) dep[i] = dep_cycle[i] = -1; 

    /* Iterate through intructions and begin tracking dependencies */
    for (i = 0; i < st->instruction_count; ) {
        
        /* Check for dependencies on either source register */
        if (is_dependency(dep, st->instructions[i]->src_one, st->instructions[i]->src_two) != -1) {
            stalled = true;
            /* If found, increment all pending instruction fetch cycle # */
            inc_cycles(st, i);
        }

        /* If we are still waiting for a register result, decrement the cycles to go before
         * the result is resolved */
        if (stalled) dec_dep_cycles(dep_cycle, dep);
        set_dep(st, dep_cycle, dep, &i, &stalled);
    }
    
    /* Return total cycles by adding 4 to last instruction fetch cycle # */
    return st->instructions[i-1]->cycle+4;
}




int is_dependency(int *dep, int src_one, int src_two) {

    int i;
    /* Walk through the dependency list to see whether the given source
     * registers are a current dependency */
    for (i = 0; i < 5; ++i) 
        if (dep[i] == src_one || dep[i] == src_two)

            /* I forget why, but return the index of the dependency */
            return i;
    return -1;
}

/* Helper function to increment the fetch cycle # of all instructions
 * after the specified index */
void inc_cycles(struct state *st, int index) {
    
    /* Walk the instructions and increment the cycle # for each */
    for (; index < st->instruction_count; ++index)
        st->instructions[index]->cycle += 1;
}

/* Helper function to decrement the cycles to wait to remove the dependency
 * from the dependency list */
void dec_dep_cycles(int *dep_cycle, int *dep) {
    
    int i;

    /* Walk the dependency cycle list */
    for (i = 0; i < 5; ++i) {
        

        if (dep_cycle[i]-1 > 0)
            --dep_cycle[i];
        /* If the dependency count will be 0 on the next decrement,
         * change both the dependency list value 
         * and depedency cycle count to -1, the 'null' value in this case */
        else {
            dep_cycle[i] = -1;
            dep[i] = -1;
        }
    }


}

/* Helper function to add the next dependency to the list of depedencies 
 * and increments the instruction iterator when there is no stall present */
void set_dep(struct state *st, int *dep_cycle, int *dep, int *iter, int *stalled) {

    int i, dep_count = 5;

    /* If there is no stall, walk the dependency list and look for the first
     * vacant spot to insert the new dependency ( the given instruction's source 
     * register ) */
    if (!(*stalled)) {
        for (i = 0; i < 5; ++i)  {
            if (dep[i] == -1) {
                dep[i] = st->instructions[*iter]->dest;

                /* Also set the cycle counter to 3 */
                dep_cycle[i] = 3;
            }
        }
    }
/* 
 * Unsure why I needed to count the current dependencies, commenting this out for 
 * now
 *
    for (i = 0; i < 5; ++i)
        dep_count += dep[i] == -1 ? -1 : 0;
*/ 
    /* If we aren't stalled, or if we are stalled but its the last instruction
     * we can move the instruction iterator forward */
    if (!(*stalled) || *iter == st->instruction_count)
        ++(*iter);
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
