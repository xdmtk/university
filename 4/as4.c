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
#define _msg_ "\n\n*** "
#define _err_ "\n\n*** Error - "
#define MEM_SIZE_ERR 0
#define BLOCK_SIZE_ERR 1
#define CACHE_SIZE_ERR 2
#define BLOCK_CACHE_ERR 3
#define READ_MISS 0
#define WRITE_MISS 0
#define READ_ADDR_EXCEED 1
#define WRITE_ADDR_EXCEED 1
#define CACHE_HIT 1
#define PARAMS_OK 4
#define true 1
#define false 0



struct program_meta {
    int mem_size, cache_size, block_size;
    unsigned char initialzied, tag_bit_pos;
};

struct program_cache {
    struct cache_line * lines;
};

struct cache_line {
    int tag;
    int * line_block;
};

/* State struct to pass around function calls, simplifies parameter entry */
struct state {
    struct program_meta * params;
    struct program_cache * cache;
    int * memory;
};




/* Menu functions */
int show_menu(void);
void handle_selection(int, struct state *); 
void free_prg_mem(struct state *st);
void exit_program(struct state *st);

/* Core functions */
void enter_params(struct state *st);
void read_from_cache(struct state *st);
void write_to_cache(struct state *st);

/* Helper functions */
int scan_args(struct state *st);
int is_pow2(int num);
void initialize_cache(struct state *st);
void form_content_msg(int word, int line, int tag, int val);



int main(void) {
    struct state * st = (struct state *)malloc(sizeof(struct state *));
    st->params = (struct program_meta *)malloc(sizeof(struct program_meta *));
    while (true) handle_selection(show_menu(), st);
}


/* Write Cache Function */
void write_to_cache(struct state *st) {
    
    int index, tag, write_addr, hit, val;
    char * items[] = {
        _spc_"Enter Main Memory Address to Write:",
        _msg_"Cache hit",
        _spc_"Enter Value to Write",
    };
    char * errors[] = {
        _err_"Write Miss - First Load Block from Memory",
        _err_"Write Address Exceeds Memory Address Space",
    };
    
    /* Input/Output */
    printf("%s", items[0]);
    scanf("%d", &write_addr);
    printf("%s", items[2]);
    scanf("%d", &val);
    
    /* Validate read address */
    if (write_addr > st->params->mem_size) {
        printf("%s", errors[WRITE_ADDR_EXCEED]);
        return;
    }
    
    /* Find cache index to read cache contents */
    index = write_addr % (st->params->cache_size/st->params->block_size);
    tag = write_addr >> st->params->tag_bit_pos;
    hit = st->cache->lines[index].tag == tag;


    /* Print hit or miss depending on tag match */
    printf("%s", hit ? items[CACHE_HIT] : errors[WRITE_MISS]);
    
    /* On Write-Miss, free existing line block, allocate new lineblock of specified BS */
    if (!hit) {
        free(st->cache->lines[index].line_block);
        st->cache->lines[index].line_block = (int *) malloc(sizeof(int)*st->params->block_size);

        /* Write data from val to cache */
        memcpy(st->cache->lines[index].line_block, &val, sizeof(val));
        
        /* Write-through to memory */
        memcpy(&st->memory[write_addr], &val, sizeof(val));

        /* Update tag */
        st->cache->lines[index].tag = tag;
    }
    
    /* Output resulting content message */
    form_content_msg(write_addr, index, tag, st->memory[write_addr]);
}








/* Read Cache Function */
void read_from_cache(struct state *st) {
    
    int index, tag, read_addr, hit;
    char * items[] = {
        _spc_"Enter Main Memory Address to Read:",
        _msg_"Cache hit"
    };
    char * errors[] = {
        _err_"Read Miss - First Load Block from Memory",
        _err_"Read Address Exceeds Memory Address Space",
    };
    
    /* Input/Output */
    printf("%s", items[0]);
    scanf("%d", &read_addr);
    
    /* Validate read address */
    if (read_addr > st->params->mem_size) {
        printf("%s", errors[READ_ADDR_EXCEED]);
        return;
    }
    
    /* Find cache index to read cache contents */
    index = read_addr % (st->params->cache_size/st->params->block_size);
    tag = read_addr >> st->params->tag_bit_pos;
    
    /* Print hit or miss depending on tag match */
    printf("%s", (hit = (st->cache->lines[index].tag == 
            tag )) ? items[CACHE_HIT] : errors[READ_MISS]);
    
    /* On Read-Miss, free existing line block, allocate new lineblock of specified BS */
    if (!hit) {
        free(st->cache->lines[index].line_block);
        st->cache->lines[index].line_block = (int *) malloc(sizeof(int)*st->params->block_size);

        /* Copy data from main memory of block size spec, update tag */
        memcpy(st->cache->lines[index].line_block, &st->memory[read_addr], st->params->block_size);
        st->cache->lines[index].tag = tag;
    }
    
    /* Output resulting content message */
    form_content_msg(read_addr, index, tag, st->memory[read_addr]);
}

void form_content_msg(int word, int line, int tag, int val) {
    printf("*** Word %d of Cache Line %d with Tag %d contains Value %d",
            word, line, tag, val);
}























/* Parameter entry function */
void enter_params(struct state *st) {
    
    int i, error_code;
    char * items[] = {
        _spc_"Enter main memory size (words):",
        _spc_"Enter cache size (words):",
        _spc_"Enter block size (words/block):",
        _msg_"All Input Parameters Accepted. Starting to Process Write/Read Requests"
    };
    char * errors[] = {
        _err_"Main Memory Size is not a Power of 2",
        _err_"Block Size is not a Power of 2",
        _err_"Cache Size is not a Power of 2",
        _err_"Block size is Larger than Cache Size"
    };

    /* Clear out all existing params on new/re-entry */
    free(st->params);
    st->params = (struct program_meta *) malloc(sizeof(struct program_meta));
    
    /* Output prompts and input parameters */
    printf("%s", items[0]);
    scanf("%d", &st->params->mem_size);
    printf("%s", items[1]);
    scanf("%d", &st->params->cache_size);
    printf("%s", items[2]);
    scanf("%d", &st->params->block_size);
    
    /* scan_args() returns with index of appropriate error code if errors are 
     * found with input parameters */
    if ((error_code = scan_args(st)) != PARAMS_OK)
        printf("%s", errors[error_code]);
    
    /* If error code was set, parameters were not initialized. Do not allow further
     * menu options unless parameters are correctly initialized */
    st->params->initialzied = error_code == PARAMS_OK ? true : false;
    if (st->params->initialzied) {
        initialize_cache(st);
        printf("%s", items[PARAMS_OK-1]);
    }
}


/* Parameter validation function */
int scan_args(struct state * st) {
    
    if (!is_pow2(st->params->mem_size))
        return MEM_SIZE_ERR;;
    if (!is_pow2(st->params->cache_size))
        return CACHE_SIZE_ERR;
    if (!is_pow2(st->params->block_size))
        return BLOCK_SIZE_ERR;
    if (st->params->block_size > st->params->cache_size)
        return BLOCK_CACHE_ERR;;
    return PARAMS_OK;
}


/* Determines whether given integer is a power of 2 */
int is_pow2(int num) {

    int i, bit_count;

    /* Take advantage of the fact that all integers that are a power of 2
     * will have exactly 1 non-zero bit, so shift and AND consecutively to
     * count the total 1-bits.*/
    for (i = 0, bit_count = 0; i < 32; ++i)
       bit_count += ((num >> i) & 0x1);

    return bit_count == 1 && (num > 1);
}


void initialize_cache(struct state *st) {
    
    int i;

    /* Allocate main memory and cache */
    st->memory = (int *) malloc(sizeof(int)*st->params->mem_size);
    st->cache = (struct program_cache *) malloc(sizeof(struct program_cache *));
    st->cache->lines = (struct cache_line *) malloc(sizeof(struct cache_line)*
            (st->params->cache_size/st->params->block_size));
    
    /* Initialize main memory */
    for (i = 0; i < st->params->mem_size; ++i)
         st->memory[i] = st->params->mem_size - i;
    
    /* Initialize cache memory */
    for (i = 0; i < st->params->cache_size/st->params->block_size; ++i) {
        st->cache->lines[i].tag = -1;
        st->cache->lines[i].line_block = NULL;
    }
    
    /* Determine shift amount for tag bits based on cache size */
    for (i = 0; i < 32 && (((st->params->cache_size >> i) & 0x1) == 0x0); ++i)
        ++st->params->tag_bit_pos;
}




















/* Input handler for menu selections */
void handle_selection(int selection, struct state * st) {
    if (selection == 1) enter_params(st);
    else if ((selection == 2 || selection == 3) && (!st->params->initialzied))
        printf(_err_"Invalid Menu Option Selected");
    else if (selection == 2) read_from_cache(st);
    else if (selection == 3) write_to_cache(st);
    else if (selection == 4) exit_program(st);
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
    for (i=0; i<(int)(sizeof(items)/sizeof(char *)); i++) printf("%s",items[i]);
    
    /* Get choice selection from input */
    if (scanf("%d", &input) >= 0) return input;
    else return 0;
}

void free_prg_mem(struct state *st) {

    int i; 
    /* Free main memory */
    free(st->memory);
    
    /* Free cache line blocks */
    for (i = 0; i < st->params->cache_size; ++i)
        free(st->cache->lines[i].line_block);
    
    /* Free cache blocks */
    free(st->cache->lines);

    /* Free cache */
    free(st->cache);
    
}

void exit_program(struct state *st) {
    
    free_prg_mem(st);
    printf(_spc_"*** Memory Freed Up - Program Terminated Normally");
    exit(0);
}
