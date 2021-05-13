#ifndef LAB3_LAUNCH_H
#define LAB3_LAUNCH_H

#include <signal.h>

#define REG_SUCCESS 0x1
#define REG_FAIL 0x0
#define HELP_PAGE \
    "\nThe following signals can be registered in the program: \n" \
    "\n" \
    "+-------------------------------------------------------------+\n" \
    "|  HUP  | INT    | QUIT | ILL   | TRAP | ABRT | IOT  | BUS    |\n" \
    "|  FPE  | USR1   | SEGV | USR2  | PIPE | ALRM | TERM | STKFLT |\n" \
    "|  CHLD | CLD    | CONT | TSTP  | TTIN | TTOU | URG  | XCPU   |\n" \
    "|  XFSZ | VTALRM | PROF | WINCH | TRAP | IO   | POLL | PWR    |\n" \
    "|  SYS  |        |      |       |      |      |      |        |\n" \
    "+-------------------------------------------------------------+\n" \
    "\n" \
    "Usage: ./catcher { <SIGNAL LIST> }\n" \
    "\n" \
    "Make sure to delimit the Signal list with spaces\n\n"


struct signal_tag {
    int sig_index;
    char * sig_name;
};

/* As stated in man signal, SIGKILL and SIGSTOP
 * cannot be caught */
char * signal_table[] = 
    { "HUP" , "INT", "QUIT",
      "ILL", "TRAP", "ABRT",
      "IOT", "BUS", 
      "FPE", /*"KILL",*/ "USR1",
      "SEGV", "USR2", "PIPE","ALRM",
      "TERM", "STKFLT", "CHLD",
      "CLD", "CONT", /*"STOP",*/
      "TSTP", "TTIN", "TTOU",
      "URG", "XCPU", "XFSZ",
      "VTALRM", "PROF", "WINCH",
      "IO", "POLL", "PWR",
      "SYS",/*"UNUSED"*/ }; // It also appears UNUSED is not implemented across some *nix distros

int signal_macro_table[] = 
    { SIGHUP , SIGINT, SIGQUIT,
      SIGILL, SIGTRAP, SIGABRT,
      SIGIOT, SIGBUS,
      SIGFPE, /* SIGKILL,*/ SIGUSR1,
      SIGSEGV, SIGUSR2, SIGPIPE,SIGALRM,
      SIGTERM, SIGSTKFLT, SIGCHLD,
      SIGCLD, SIGCONT, /* SIGSTOP,*/
      SIGTSTP, SIGTTIN, SIGTTOU,
      SIGURG, SIGXCPU, SIGXFSZ,
      SIGVTALRM, SIGPROF, SIGWINCH,
      SIGIO, SIGPOLL, SIGPWR,
      SIGSYS, /*SIGUNUSED*/};

void signal_handler(int signal);
int  register_signals(struct signal_tag ** signal_registry, int len);
struct signal_tag ** validate_args(int argc, char ** argv, int * sig_len);
struct signal_tag * validate_signal(char * sig_name);
char * get_signal_name_str(int signal);


#endif //LAB3_LAUNCH_H
