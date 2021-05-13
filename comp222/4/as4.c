/* 

   Nicholas Martinez
   Programming Assignment 4: Cache Simulation
   Comp 222 - Fall 2019 
   Meeting Time: 1100-1215

*/



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define _spc_ "\n"
#define _msg_ "\n\n*** "
#define _err_ "\n\n*** Error – "
#define _errdsh_ "\n\n*** Error - "
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
    u_int32_t mem_size_words, cache_size_words, block_size_words;
    unsigned char initialzied, tag_bit_pos;
    u_int32_t mem_size_blocks, cache_size_blocks;
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
void print_header();

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
    print_header();
    struct state * st = (struct state *)malloc(sizeof(struct state *));
    st->params = (struct program_meta *)malloc(sizeof(struct program_meta *));
    while (true) handle_selection(show_menu(), st);
}











/* Write Cache Function */
void write_to_cache(struct state *st) {
    
    u_int32_t index, tag, write_addr, hit, val, word_loc;
    char * items[] = {
        _spc_"Enter Main Memory Address to Write:",
        _msg_"Cache hit",
        _spc_"Enter Value to Write:",
    };
    char * errors[] = {
        _msg_"Write Miss - First Load Block from Memory",
        _err_"Write Address Exceeds Memory Address Space",
    };
    
    /* Input/Output Write Address*/
    printf("%s", items[0]);
    scanf("%d", &write_addr);

    /* Validate write address */
    if (write_addr > st->params->mem_size_words) {
        printf("%s", errors[WRITE_ADDR_EXCEED]);
        scanf("%d", &val);
        return;
    }

    /* Input/Output Value to Write*/
    printf("%s", items[2]);
    scanf("%d", &val);
    
    
    /* Find cache index to read cache contents */
    index = write_addr / st->params->cache_size_blocks < st->params->cache_size_blocks ? 
        write_addr % st->params->cache_size_blocks : 
        (write_addr / (st->params->cache_size_blocks)) % st->params->cache_size_blocks;
    word_loc = write_addr % st->params->block_size_words;
    tag = write_addr >> st->params->tag_bit_pos;


    /* Print hit or miss depending on tag match */
    printf("%s", (hit = (st->cache->lines[index].tag ==
                         tag )) ? items[CACHE_HIT] : errors[WRITE_MISS]);

    /* On Write-Miss, free existing line block, allocate new lineblock of specified BS */
    free(st->cache->lines[index].line_block);
    st->cache->lines[index].line_block = (int *) malloc(sizeof(int)*st->params->block_size_words);

    /* Write data from val to cache */
    memcpy(st->cache->lines[index].line_block+word_loc, &val, sizeof(val));
    
    /* Write-through to memory */
    memcpy(&st->memory[write_addr], &val, sizeof(val));

    /* Update tag */
    st->cache->lines[index].tag = tag;
    
    /* Output resulting content message */
    form_content_msg(word_loc, index, tag, val);
}








/* Read Cache Function */
void read_from_cache(struct state *st) {
    
    int index, tag, read_addr, hit, word_loc;
    char * items[] = {
        _spc_"Enter Main Memory Address to Read:",
        _msg_"Cache hit"
    };
    char * errors[] = {
        _msg_"Read Miss - First Load Block from Memory",
        _err_"Read Address Exceeds Memory Address Space",
    };
    
    /* Input/Output */
    printf("%s", items[0]);
    scanf("%d", &read_addr);
    
    /* Validate read address */
    if (read_addr > st->params->mem_size_words) {
        printf("%s", errors[READ_ADDR_EXCEED]);
        return;
    }
    
    /* Find cache index to read cache contents */
    index = read_addr / st->params->cache_size_blocks < st->params->cache_size_blocks ? 
        read_addr % st->params->cache_size_blocks : 
        (read_addr / (st->params->cache_size_blocks)) % st->params->cache_size_blocks;
    word_loc = read_addr % st->params->block_size_words;
    tag = read_addr >> st->params->tag_bit_pos;
    
    /* Print hit or miss depending on tag match */
    printf("%s", (hit = (st->cache->lines[index].tag == 
            tag )) ? items[CACHE_HIT] : errors[READ_MISS]);
    
    /* On Read-Miss, free existing line block, allocate new lineblock of specified BS */
    if (!hit) {
        free(st->cache->lines[index].line_block);
        st->cache->lines[index].line_block = (int *) malloc(sizeof(int)*st->params->block_size_words);

        /* Copy data from main memory of block size spec, update tag */
        memcpy(st->cache->lines[index].line_block+word_loc, &st->memory[read_addr], st->params->block_size_words);
        st->cache->lines[index].tag = tag;
    }
    st->cache->lines[index].tag = tag;
    
    /* Output resulting content message */
    form_content_msg(word_loc, index, tag, st->cache->lines[index].line_block[word_loc]);
}

void form_content_msg(int word, int line, int tag, int val) {
    printf(_spc_"*** Word %d of Cache Line %d with Tag %d contains the Value %d",
            word, line, tag, val);
}























/* Parameter entry function */
void enter_params(struct state *st) {
    
    int error_code;
    char * items[] = {
        _spc_"Enter main memory size (words): ",
        _spc_"Enter cache size (words): ",
        _spc_"Enter block size (words/block): ",
        _msg_"All Input Parameters Accepted. Starting to Process Write/Read Requests"
    };
    char * errors[] = {
        _errdsh_"Main Memory Size is not a Power of 2",
        _errdsh_"Block Size is not a Power of 2",
        _errdsh_"Cache Size is not a Power of 2",
        _errdsh_"Block Size is Larger than Cache Size"
    };

    /* Clear out all existing params on new/re-entry */
    free(st->params);
    st->params = (struct program_meta *) malloc(sizeof(struct program_meta));
    
    /* Output prompts and input parameters */
    printf("%s", items[0]);
    scanf("%d", &st->params->mem_size_words);
    printf("%s", items[1]);
    scanf("%d", &st->params->cache_size_words);
    printf("%s", items[2]);
    scanf("%d", &st->params->block_size_words);

    /* Set block counts for memory and cache for later address computation */
    st->params->cache_size_blocks = st->params->cache_size_words / st->params->block_size_words;
    st->params->mem_size_blocks = st->params->mem_size_words / st->params->block_size_words;

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
    
    if (!is_pow2(st->params->mem_size_words))
        return MEM_SIZE_ERR;;
    if (!is_pow2(st->params->cache_size_words))
        return CACHE_SIZE_ERR;
    if (!is_pow2(st->params->block_size_words))
        return BLOCK_SIZE_ERR;
    if (st->params->block_size_words > st->params->cache_size_words)
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

/* Initialize cache function */
void initialize_cache(struct state *st) {
    
    int i;

    /* Allocate main memory and cache */
    st->memory = (int *) malloc(sizeof(int)*st->params->mem_size_words);
    st->cache = (struct program_cache *) malloc(sizeof(struct program_cache *));
    st->cache->lines = (struct cache_line *) malloc(sizeof(struct cache_line)*
            (st->params->cache_size_words / st->params->block_size_words));
    
    /* Initialize main memory */
    for (i = 0; i < st->params->mem_size_words; ++i)
         st->memory[i] = st->params->mem_size_words - i;
    
    /* Initialize cache memory */
    for (i = 0; i < st->params->cache_size_words / st->params->block_size_words; ++i) {
        st->cache->lines[i].tag = -1;
        st->cache->lines[i].line_block = NULL;
    }
    
    /* Determine shift amount for tag bits based on cache size */
    for (i = 0; i < 32 && (((st->params->cache_size_words >> i) & 0x1) == 0x0); ++i)
        ++st->params->tag_bit_pos;
}


















void print_header() {
    printf("Programming Assignment 4: Cache Simulation\nComp 222 - Fall 2019");
};

/* Input handler for menu selections */
void handle_selection(int selection, struct state * st) {
    if (selection == 1) enter_params(st);
    else if ((selection == 2 || selection == 3) && (!st->params->initialzied))
        printf(_errdsh_"Invalid Menu Option Selected");
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
        _spc_"Enter selection: "
    };
    
    /* Output menu choices */ 
    for (i=0; i<(int)(sizeof(items)/sizeof(char *)); i++) printf("%s",items[i]);
    
    /* Get choice selection from input */
    if (scanf("%d", &input) >= 0) return input;
    else return 0;
}

/* TODO: Needs work */
void free_prg_mem(struct state *st) {

    int i; 
    /* Free main memory */
    free(st->memory);
    
    /* Free cache line blocks */
    if (st->params->initialzied) {
        for (i = 0; i < st->params->cache_size_blocks; ++i)
            free(st->cache->lines[i].line_block);
    
        /* Free cache blocks */
        free(st->cache->lines);
    }

    /* Free cache */
    free(st->cache);
    
}

void exit_program(struct state *st) {
    
    free_prg_mem(st);
    printf(_spc_"*** Memory Freed Up - Program Terminated Normally");
    exit(0);
}
