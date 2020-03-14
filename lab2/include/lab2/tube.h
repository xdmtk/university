#ifndef LAB2_TUBE_H
#define LAB2_TUBE_H
#define ARG_FAIL 0x1
#define ARG_OK 0x2
#define ZERO_BUFFER(buf, size) for (i=0;i<size;++i) buf[i] = '\0'
#define IS_INIT(var) (var != -1)
#define READ_END 0
#define WRITE_END 1
#define PIPE_BUFFER_SIZE 4096*16*4

struct state {
    pid_t child1_pid;
    pid_t child2_pid;
    char ** child1_exec_args;
    char ** child2_exec_args;
    char * child1_exec_path;
    char * child2_exec_path;
    int child1_retval;
    int child2_retval;
};

int validate_args(int argc, char ** argv, struct state * st);
int run(struct state * st);

#endif //LAB2_TUBE_H
