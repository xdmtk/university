#ifndef LAB2_LAUNCH_H
#define LAB2_LAUNCH_H
#define ARG_FAIL 0x1
#define ARG_OK 0x2
#define ZERO_BUFFER(buf, size) for (i=0;i<size;++i) buf[i] = '\0'

struct state {
    pid_t child_pid;
    int child_retval;
    char * child_exec_path;
    char ** child_exec_args;
};

int validate_args(int argc, char ** argv, struct state * st);
int run(struct state * st);

#endif //LAB2_LAUNCH_H
