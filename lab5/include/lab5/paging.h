#ifndef LAB5_PAGING_H
#define LAB5_PAGING_H
#include <stdint.h>

#define ARG_FAIL 0x1
#define ARG_OK 0x2

#define USAGE_STR "\nusage: ./a.out <32 bit address>\n"

#define BASE_10 10
#define IS_VALID_INT(arg_pos, valid) (((valid == argv[arg_pos]) || (*valid != '\0')) == 0)

#define PAGE_SIZE 4096

struct state {
    uint32_t address;
    uint32_t page_number;
    uint32_t offset;
};


int validate_args(struct state *st, int argc, char ** argv);
void calcuate_page_offset(struct state *st);


#endif //LAB5_PAGING_H
