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
    
    int i;
   
    /* Iterate through intructions and begin tracking dependencies */
    for (i = 0; i < st->instruction_count; ++i) {
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
    free(st->dependency_list);
    free(st);
}

void exit_program(struct state *st) {
    
    free_prg_mem(st);
    printf("\n\n*** Program Terminated Normally");
    exit(0);
}


