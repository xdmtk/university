#ifndef LAB6_SPIRITD_H
#define LAB6_SPIRITD_H

#define ROOT_DIR "/"
#define DEV_NULL "/dev/null"

#define true 1
#define false 0

struct state {
    pid_t ret;
    pid_t sid;
    pid_t moles[2];
    char * mole_bin_path;
};

int get_mole_bin_path(struct state *st);

void daemon_init(struct state * st);
void fork_and_exit(struct state * st);
void redirect_file_descriptors(void);

void register_signals(void); 
void signal_handler(int signal);

int respond_to_signals(struct state * st);
#endif //LAB6_SPIRITD_H
