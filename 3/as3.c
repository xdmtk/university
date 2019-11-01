#include <stdio.h>

#include <stdlib.h>
#include <string.h>

#define _spc_ "\n\n"

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
void free_prg_mem(struct state *);
void handle_selection(int, struct state *); 

void read_instructions(struct state *);


void analyze_instructions(struct state *);




int main(void) {
    struct state * st = (struct state *) calloc(1,sizeof(struct state *));
    while (1) handle_selection(show_menu(), st);
}






void analyze_instructions(struct state *st) {
    
    int i, j, deps_count, stalled;
    
    /* List of register numbers that are currently awaiting a result */
    int deps[32], 
    
    /* A mapping of registers to their index with the corresponding amount of 
     * cycles before the register result is available
     */
    deps_cycle[32];


    /* Initialize register mappings to -1, for proper indexing of 0-31 registers */
    for (i = 0; i < 32; ++i) deps[i] = deps_cycle[i] = -1;

    /* Initialize the deps[] stack pointer and stall flag to 0 */
    deps_count = stalled = 0;
   
    /* Iterate through intructions and begin tracking dependencies */
    for (i = 0; i < st->instruction_count; ++i) {
        
        /* If either source register of the given instructions is currently awaiting
         * a result, set the 'stalled' flag
         */
        for (j = 0; j < 32; ++j) {
            if (st->instructions[i]->src_one == deps[j] || st->instructions[i]->src_two == deps[j]) {
                stalled = 1;
                break;
            }
        }

        /* If the pipeline is stalled, increment the cycle count for every instruction after 
         * the current instruction in the pipeline
         */
        if (stalled) {
            for (j = i; j < st->instruction_count; ++j)
                st->instructions[j]->cycle++;
            stalled = !stalled;
        }

       // TODO: Start decrementing the cycle count of registers awating results  
       
        for (j = 0; j < deps_count; ++j) {
            if (--deps_cycle[deps[j]] <= 0) {
                deps_cycle[deps[j]] = -1;
                deps[j] = -1;
            }
        }
       
        /* Add current destination register to dependency list */
       deps[deps_count++] = st->instructions[i]->dest;

       deps_cycle[st->instructions[i]->dest] = 3;
    }
}





/* Function to collect instruction data via user input */
void read_instructions(struct state *st) {
    
    int i;
    
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
        scanf(" r%d=r%d+r%d", &st->instructions[i]->dest, &st->instructions[i]->src_one, 
                &st->instructions[i]->src_two);

        /* Set initial cycle number based on input order */
        st->instructions[i]->cycle = i+1;
    }
}






/* Input handler for menu selections */
void handle_selection(int selection, struct state * st) {

    if (selection == 1) read_instructions(st);
    else if (selection == 2) analyze_instructions(st);
    else exit_program(st);
}

int show_menu(void) {
    
    int input, i;
    char * items[] = {
        _spc_"Pipelined instruction performance",
        _spc_"1) Enter instructions",
        _spc_"2) Determine when instructions are fetched",
        _spc_"3) Exit",
        _spc_"Enter Selection: "
    };
    
    /* Output menu choices */ 
    for (i=0; i<5; i++) printf("%s",items[i]);
    
    /* Get choice selection from input */
    if (scanf("%d", &input) >= 0) return input;
    else return 0;
}

void free_prg_mem(struct state *st) {

    int i;
    /* Free up all allocated memory */
    if (st->instructions != NULL) {
        for (i=0; i < st->instruction_count; i++)
            free(st->instructions[i]);
        free(st->instructions);
    }
    free(st);
}

void exit_program(struct state *st) {
    
    free_prg_mem(st);
    printf("\n\n*** Program Terminated Normally");
    exit(0);
}


