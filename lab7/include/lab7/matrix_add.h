#ifndef LAB7_MATRIX_ADD_H
#define LAB7_MATRIX_ADD_H

#define ARG_FAIL -1
#define ARG_OK 1
#define USAGE_STR "usage: ./matrix_add [size] [blocks] < [matrix_file_input] > [matrix_file_output]"

#define BASE_10 10
#define IS_VALID_INT(arg_pos, valid) (((valid == argv[arg_pos]) || (*valid != '\0')) == 0)

#define BLOCK_OFFSET ((st->block_size*4)*(st->block_size*4))
#define TOTAL_SIZE ((st->size)*(st->size)*4)

struct state {
    int size;
    int blocks;
    int start_time;
    int scalar;
    int block_size;
};

int validate_args(int argc, char ** argv, struct state * st);

void process_matrix(struct state * st);
void set_aio_attributes(struct aiocb *request, off_t offset, size_t block_size, int fd);

void matrix_add(struct aiocb *request, struct state *st);

#endif //LAB7_MATRIX_ADD_H
