/* 

   Nicholas Martinez
   Programming Assignment 4: Cache Simulation
   Comp 222 - Fall 2019 
   Meeting Time: 1100-1215

*/



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define _spc_ "\n\n"
#define _err_ "\n\n*** Error - "
#define MAIN_MEM_ERR 0
#define BLOCK_SIZE_ERR 1
#define CACHE_SIZE_ERR 2
#define BLOCK_CACHE_ERR 3
#define true 1
#define false 0

/* State struct to pass around function calls, simplifies parameter entry */
struct state {
    struct program_meta * params;
};

struct program_meta {
    int mem_size, cache_size, block_size;
    unsigned char initialzied;
};



/* Menu functions */
int show_menu(void);
void handle_selection(int, struct state *); 
void exit_program(struct state *st);

/* Core functions */
void enter_params(struct state *st);

/* Helper functions */
int scan_args(struct state *st);





int main(void) {
    struct state * st = (struct state *)malloc(sizeof(struct state *));
    st->params = (struct program_meta *)malloc(sizeof(struct program_meta *));
    handle_selection(show_menu(), st);
}






void enter_params(struct state *st) {
    
    int i, error_code;
    char * items[] = {
        _spc_"Enter main memory size (words):",
        _spc_"Enter cache size (words):",
        _spc_"Enter block size (words/block):",
    };
    char * errors[] = {
        _err_"Main Memory Size is not a Power of 2",
        _err_"Block Size is not a Power of 2",
        _err_"Cache Size is not a Power of 2",
        _err_"Block size is larger than cache size"
    };

    /* Clear out all existing params on new/re-entry */
    free(st->params);
    
    /* Output prompts and input parameters */
    for (i = 0; i < (int)(sizeof(items)/sizeof(char *)); ++i) {
        printf("%s", items[i]);
        scanf("%d", (int *)&st->params+(sizeof(int)*i));
    }
    
    /* scan_args() returns with index of appropriate error code if errors are 
     * found with input parameters */
    if ((error_code = scan_args(st)) < (int)(sizeof(errors)/sizeof(char *)))
        printf("%s", errors[error_code]);
    
    /* If error code was set, parameters were not initialized. Do not allow further
     * menu options unless parameters are correctly initialized */
    st->params->initialzied = error_code < (int)(sizeof(errors)/sizeof(char *)) ? true : false;
}

int scan_args(struct state * st) {



    return 
}























/* Input handler for menu selections */
void handle_selection(int selection, struct state * st) {
    if (selection == 3) exit_program(st);
    return;
}

int show_menu(void) {
    
    int input, i;
    char * items[] = {
        _spc_"Main Menu - Main Memory to Cache Memory Mapping",
        _spc_"------------------------------------------------",
        _spc_"1) Enter Configuration Parameters",
        _spc_"2) Read from Cache",
        _spc_"3) Write to Cache",
        _spc_"4) Quit Program",
        _spc_"Enter selection:"
    };
    
    /* Output menu choices */ 
    for (i=0; i<sizeof(items)/sizeof(char *); i++) printf("%s",items[i]);
    
    /* Get choice selection from input */
    if (scanf("%d", &input) >= 0) return input;
    else return 0;
}

void exit_program(struct state *st) {
    
    printf(_spc_"*** Memory Freed Up - Program Terminated Normally");
    exit(0);
}
