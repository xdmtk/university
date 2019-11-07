#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define _spc_ "\n\n"
#define true 1
#define false 0

/* State struct to pass around function calls, simplifies parameter entry */
struct state {
    struct instr ** instructions;
    int instruction_count;
};

/* Instruction struct specifying details about instruction, including
 * source registers, destination registers, and fetch cycle # */
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
    char a,b,c;
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
        scanf(" %c%d=%c%d+%c%d", &a, &st->instructions[i]->dest, &b.
                &st->instructions[i]->src_one, &c,
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
    /* Print cycle # per instruction */
    printf("Total number of cycles: %d"_spc_, total_cycles);

    for (i = 0; i < st->instruction_count; ++i) {
        
                printf("Instruction %d Fetched at Cycle %d"_spc_, 
                    i+1, st->instructions[i]->cycle);

        /* Insert tabs corresponding to fetch cycle */
        for (j = 0; j < st->instructions[i]->cycle - 1; j++) printf("\t");

        /* Print instruction cycle operations */
        printf("IF\tID\tEX\tMM\tWB"_spc_);
    }
}


int analyze_instructions(struct state *st) {
    
    /* Initialization code */
    int i, j, dep_index, dep[5], dep_cycle[5], stalled;
    i = j = stalled = dep_index = 0; 
    for (;i < 5; ++i) dep[i] = dep_cycle[i] = -1; 

    /* Iterate through intructions and begin counting dependencies */
    for (i = 0; i < st->instruction_count; ) {
        
        /* Check for dependencies on either source register */
        if (is_dependency(dep, st->instructions[i]->src_one, st->instructions[i]->src_two)) {

            /* If found, increment all pending instruction fetch cycle # and set the stall flag*/
            stalled = true;
            inc_cycles(st, i);
        }

         /* Decrement all cycle counts of dependencies for each successive cycle */
        dec_dep_cycles(dep_cycle, dep);

        /* Set the new dependent register and reset stall flag */
        set_dep(st, dep_cycle, dep, &i, &stalled);
    }
    
    /* Return total cycles by adding 4 to last instruction fetch cycle # */
    return st->instructions[i-1]->cycle+4;
}



/* Helper function to check whether the given source registers are currently 
 * awaiting a result */
int is_dependency(int *dep, int src_one, int src_two) {

    int i;
    /* Walk through the dependency list to see whether the given source
     * registers are a current dependency */
    for (i = 0; i < 5; ++i) 
        if (dep[i] == src_one || dep[i] == src_two)
            return true;
    return false;
}

/* Helper function to increment the fetch cycle # of all instructions
 * after the specified index */
void inc_cycles(struct state *st, int index) {
    
    /* Walk the instructions and increment the cycle # for each */
    for (; index < st->instruction_count; ++index)
        st->instructions[index]->cycle += 1;
}

/* Helper function to decrement the stall cycles needed to remove the dependent
 * register from the dependency list */
void dec_dep_cycles(int *dep_cycle, int *dep) {
    
    int i;

    /* Walk the dependency cycle list */
    for (i = 0; i < 5; ++i) {
        
        /* Decrement the wait cycles for depedent registers if the result
         * will be non-zero */
        if (dep_cycle[i]-1 > 0)
            --dep_cycle[i];
        /* If the dependent register will have 0 cycles remaining
         * set to -1 ( arbitrary NULL value ) */
        else {
            dep_cycle[i] = -1;
            dep[i] = -1;
        }
    }
}

/* Helper function to add the next dependency to the list of depedencies 
 * and increments the instruction iterator when there is no stall present */
void set_dep(struct state *st, int *dep_cycle, int *dep, int *iter, int *stalled) {

    int i, dep_count;

    /* If there is no stall,*/
    if (!(*stalled)) {

    /* Walk the dependency list and look for the first vacant spot (marked by -1) */
        for (i = 0; i < 5; ++i)  {
            if (dep[i] == -1) {

                /* Set the destination register as a dependency */
                dep[i] = st->instructions[*iter]->dest;

                /* Also set the wait cycle counter to 2 */
                dep_cycle[i] = 2;
                break;
            }
        }
    }
    
    /* Walk the depedency list and count current depedencies by checking for -1 */
    for (i = 0, dep_count = 5; i < 5; ++i)
        dep_count += dep[i] == -1 ? -1 : 0;

    /* If we aren't stalled, or if we are stalled but its the last instruction
     * we can move the instruction iterator forward */
    if (!(*stalled) || (*iter == st->instruction_count-1 && !dep_count))
        ++(*iter);

    /* Reset the stall flag */
    *stalled = false;
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
    printf("\n\nProgram Terminated Normally");
    exit(0);
}
