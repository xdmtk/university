#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#include <lab6/moles.h>


int main(int argc, char ** argv) {
    
    /* Open log file for appending */
    FILE * fp = fopen(generate_log_path(argv[0]), "a");
    
    /* Write the appropriate string to the log file based on 
     * the contents of argv[1] (not argv[0]) */
    fprintf(fp, ((!strcmp(argv[1], "mole1") ? "Pop Mole 1\n" : "Pop Mole 2\n")));

    /* Add newline character */
    fclose(fp);

}


/** 
 * @brief generate_log_path - Quick helper function to get the 
 * home path of the user 
 *
 * @param char * exec_path - The fully qualified path of the mole binary
 */
char * generate_log_path(char * exec_path) {
    
    char * log_path = malloc(sizeof(char)*4096);
    memset(log_path, '\0', 4096);

    //strcat(log_path, "/home/")
        
    /* A tricky section that makes this lab not so trivial...
     *
     * To find the home path indicated by `~/lab6.log`, we need
     * to expand the tilde to the executing user's home directory. 
     *
     * Though when called via execve() from a daemon process, getenv("USER") 
     * returns NULL. So instead, we need to do some examination of the
     * argv[0] argument (the full executable path of the mole), to find
     * the /home/$USER/ substring and use it to construct the path to the log 
     * file.
     */
    //strcat(log_path, getenv("USER"));
    
    strcat(log_path, get_home_path(exec_path)); 
    strcat(log_path, "/lab6.log");
    
    return log_path;
}


/** 
 * @brief get_home_path - Analyzes the fully qualified path 
 * of the mole program, and extracts the /home/$USER string
 * as a means of expanding the ~ in ~/lab6.lgo
 *
 * @param char * exec_path - The fully qualified path of the mole binary
 */
char * get_home_path(char * exec_path) {

    int i,len, slash_count = 0;
    char * home_user_path;
    
    len = strlen(exec_path);
    for (i = 0; i < len; ++i) {
        
        if (exec_path[i] == '/')
            slash_count++;
        
        if (slash_count == 3)
            break;
    }
    
    home_user_path = malloc(sizeof(char)*(i+2));
    memset(home_user_path, '\0', i+2);
    strncpy(home_user_path, exec_path, i);
    
    return home_user_path;
}
