/*!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-/
 *                                                          !
 *  ·▄▄▄▄  ▪  .▄▄ ·  ▄▄· ▄▄▄  ▄▄▄ .▄▄▄▄▄▄▄▄ .               !
 *  ██▪ ██ ██ ▐█ ▀. ▐█ ▌▪▀▄ █·▀▄.▀·•██  ▀▄.▀·               !
 *  ▐█· ▐█▌▐█·▄▀▀▀█▄██ ▄▄▐▀▀▄ ▐▀▀▪▄ ▐█.▪▐▀▀▪▄               !
 *  ██. ██ ▐█▌▐█▄▪▐█▐███▌▐█•█▌▐█▄▄▌ ▐█▌·▐█▄▄▌               !
 *  ▀▀▀▀▀• ▀▀▀ ▀▀▀▀ ·▀▀▀ .▀  ▀ ▀▀▀  ▀▀▀  ▀▀▀                !
 *                                                          !
 *  .▄▄ · ▄▄▄▄▄▄▄▄  ▄• ▄▌ ▄▄· ▄▄▄▄▄▄• ▄▌▄▄▄  ▄▄▄ ..▄▄ ·     !
 *  ▐█ ▀. •██  ▀▄ █·█▪██▌▐█ ▌▪•██  █▪██▌▀▄ █·▀▄.▀·▐█ ▀.     !
 *  ▄▀▀▀█▄ ▐█.▪▐▀▀▄ █▌▐█▌██ ▄▄ ▐█.▪█▌▐█▌▐▀▀▄ ▐▀▀▪▄▄▀▀▀█▄    !
 *  ▐█▄▪▐█ ▐█▌·▐█•█▌▐█▄█▌▐███▌ ▐█▌·▐█▄█▌▐█•█▌▐█▄▄▌▐█▄▪▐█    !
 *   ▀▀▀▀  ▀▀▀ .▀  ▀ ▀▀▀ ·▀▀▀  ▀▀▀  ▀▀▀ .▀  ▀ ▀▀▀  ▀▀▀▀     !
 *                                                          !
 *                      Homework #2                         !
 *                                                          !
 -!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!
 -!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!
 -!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!
 *
 *   CoSCi 542 - Discrete Structures 
 *   Instructor: Bob Hart
 *   Section: 21566
 *   W - 5:45PM - 10:00PM
 *
 *   --->>
 *       
 *   Name: Nicholas Martinez
 *   Date: 02/15/18
 *    
 *   --->> 
 *
 *   * A. Arithmetic sequences
 *  You may do error checking with your program if you want, but it's not required.
 *
 *  This program involves 5 numbers that are relevant in a (finite) arithmetic series.
 *  Suppose we are considering the series
 *  The 5 values we're interested in are
 *  F (the first term): 1.1
 *  I (the increment from one term to the next): 0.1
 *  L (the last term): 1.3
 *  N (the number of terms): 3
 *  T (the total of the terms): 3.6
 *
 *  Let's say that as far as this program is concerned, I has to be nonzero and N has to be > 1.
 *  (Then we don't have to worry about trivial cases.)
 *
 *  The idea here is that the user will input any 3 of these 5 values, and your program outputs the other 2.
 *  The user's input is a letter followed by a number, a letter, a number, a letter, and a number. The 3 letters 
 *  are case insensitive, all different, from FILNT; the numbers give the corresponding values.
 *
 *  For example, still considering the example    , if the user types
 *      t  3.6  f  1.1  L  1.3
 *  then the user is saying to your program, "I'm thinking of an arithmetic sequence, whose total is 3.6, whose 
 *  first term is 1.1, and whose last term is 1.3. You tell me the other 2 things." Your program should then output
 *      I  0.1  N  3
 *  
 *      The user can pick any 3 of the 5 values to input, and can input them in any order.
 *  Your program can output the two other values in either order, labeled with the appropriate letters.
 *
 *  You may recall that doubles can be problematic in that their answers are off by a tiny amount at hard-to-predict time.
 *  For instance, it would be a problem to say
 *      unsigned n = unsigned((first - last)/inc) + 1;
 *  even though that equations is mathematically correct.
 *  One way to get around that problem is to say
 *      double n = (first - last)/inc + 1;
 *  instead.
 *
 *   --->> 
*/

#include <cstdio>
#include <cstdlib>
#include <cstring>
#define F 0
#define I 1
#define L 2
#define N 3
#define T 4

#define ERROR -1

#define FILNT_CHECK 1
#define NUM_CHECK 1.1


int parse_args(char * argv[], int argc, double vals[]);
double validate_args(double mode, const char * arg);
int validate_args(int mode, const char * arg);


const char * usage_str = "\n\nUsage: ./{executable} [ filnt ] [ value 1 ]"
                            " [ filnt ] [ value 2 ] [ filnt ] [ value 3 ]\n"
                            "* * * * * * * * * * * * * * * * * * * * * * * * \n"
                            "\n"
                            "Example: ./{executable} t 3.6 f 1.1 L 1.3   <<-- Translation:\n"
                            "\n"
                            "Arithmatic sequence totaling 3.6, first term 1.1 and last term "
                            "is 1.3.\n";
















int main(int argc, char * argv[]) {
    
    double vals[5];
    if ((parse_args(argv,argc,vals) == ERROR) || (argc < 7)) {
        if (argc < 7) {
            printf("\nPlease enter 3 values for F I L N T");
        }
        printf(usage_str);
        exit(1);
    }



}

int parse_args(char * argv[], int argc, double vals[]) {

    for (int x=1; x < argc; x += 2) {
         
        int res_alpha = validate_args(FILNT_CHECK, argv[x]);
        double res_num = validate_args(NUM_CHECK, argv[x+1]);
        
        if ((res_alpha == ERROR) || (res_num == ERROR)) {
            printf("\nError in argument %d - Please enter arguments correctly", x);
            return ERROR;
        }

        switch (res_alpha) {
            case F:
                vals[F] = res_num;
                break;
            case I:
                vals[I] = res_num;
                break;
            case L:
                vals[L] = res_num;
                break;
            case N:
                vals[N] = res_num;
                break;
            case T:
                vals[T] = res_num;
                break;
        }
    }

}















int validate_args(int mode, const char * arg) {
    
    if (mode == FILNT_CHECK) {
        // Determine valid 'filnt' argument given
        const char * valid_args[] = { "f", "i", "l", "n", "t" };
        const char * valid_args_upper[] = { "F", "I", "L", "N", "T" };

        for (int x=0; x < 5; ++x) {
            if (!(strcmp(arg, valid_args[x])) || (!(strcmp(arg, valid_args_upper[x])))) {
                    return x;
            }
        }
        // Otherwise error
        return ERROR;
    }
}

double validate_args(double mode, const char * arg) {
    // Determine valid numerical argument following alpha argument
    if (mode == NUM_CHECK) {
        double res;
        try {
            res = atof(arg);
            if (!res) {
                return ERROR;
            }
            return res;
        } 
        catch (int e) {
            return ERROR;
        }
    }
}

