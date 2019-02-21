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

#include <cmath>
#include <cstdio>
#include <cctype>
#include <cstdlib>
#include <cstring>

#define FLI 0xFF0
#define FLN 0xFF1
#define FLT 0xFF2
#define FIN 0xFF3
#define FIT 0xFF4
#define FNT 0xFF5
#define LIN 0xFF6
#define LIT 0xFF7
#define LNT 0xFF8
#define INT 0xFF9

#define F 0
#define I 1
#define L 2
#define N 3
#define T 4

#define ERROR -1

#define MODE_ARITH 0xEEFF
#define MODE_GEOM 0xEE00

#define FILNT_CHECK 1
#define NUM_CHECK 1.1
#define true 1
#define false 0

int validate_args(int mode_val, const char * arg);
double validate_args(double mode_val, const char * arg);
int parse_args(char * argv[], int argc, double vals[]);


void calculate_master(double vals[]);
int combination_dictionary(double vals[]);

void find_t(double vals[], int combination, unsigned char second_pass, int mode);
void find_n(double vals[], int combination, unsigned char second_pass, int mode);
void find_l(double vals[], int combination, unsigned char second_pass, int mode);
void find_i(double vals[], int combination, unsigned char second_pass, int mode);
void find_f(double vals[], int combination, unsigned char second_pass, int mode);


double pow(double base, double power);
int mode_global=0;
// How to use program, give input via CLI
const char * usage_str = "\n\nUsage: ./{executable} [ mode ] [ filnt ] [ value 1 ]"
                            " [ filnt ] [ value 2 ] [ filnt ] [ value 3 ]\n"
                            "* * * * * * * * * * * * * * * * * * * * * * * * \n"
                            "\n"
                            "Example: ./{executable} arithmatic t 3.6 f 1.1 L 1.3   <<-- Translation:\n"
                            "Arithmatic sequence totaling 3.6, first term 1.1 and last term "
                            "is 1.3.\n"
                            "\n\n"
                            "Example: ./{executable} geometric L 9 I 3 F 3   <<-- Translation:\n"
                            "Geometric sequence with first term 3, last term 9, and incremented"
                            "is 1.3.\n\n";


int main(int argc, char * argv[]) {
    
    // Initialize an array for FILNT values
    double vals[] = {0, 0, 0, 0, 0};

    // Parse arguments and make sure correct amount of arguments given 
    // Should be 8, program name + 3 of FILNT and 3 of numbers for FILNT
    if ((argc != 8) || (parse_args(argv,argc,vals) == ERROR))  {
        if (argc != 8) {
            printf("\nPlease enter 3 values for F I L N T");
        }
        printf(usage_str);
        exit(1);
    }
    
    calculate_master(vals);
    printf("\nF: %.2f \nI: %.2f \nL: %.2f \nN: %.2f \nT: %.2f\n", vals[F], vals[I], vals[L], vals[N], vals[T]);

}


/*
 * F - First term of sequences
 * I - Incremental value
 * L - Last term of sequence
 * N - Number of terms
 * T - Total sum value of terms
 *
 * 
 */ 

void calculate_master(double vals[]) {
    int initial_comb = combination_dictionary(vals);
    if (initial_comb == ERROR) {
        printf("\nDuplicate values detected.. please enter only one of each filnt value");
        printf(usage_str);
        exit(1);
    }
    switch (initial_comb) {
        case FIT: find_l(vals, initial_comb, false, mode_global); break;
        case FLI:
        case FIN: find_t(vals, initial_comb, false, mode_global); break; 
        case FLN:
        case FLT:
        case FNT: find_i(vals, initial_comb, false, mode_global); break;
        case LIN:
        case LIT:
        case LNT:
        case INT: find_f(vals, initial_comb, false, mode_global); break;
    }
}

/* F Combinations For arithmatic 
 * 
 * ILN - Valid - {1, 2, 3} , I=1 L=3, N=3, ->  F= L-((N*I)+1)
 * ILT - Valid - {1 2 3} , I=1 L=3 T=6 ->  Find N -> (L-I)+(L-I)...==T iterations is N
 * NIT - Invalid - {1, 2, 3} , N=3, I=1, T=6 -> F= NEED L 
 * NTL - Valid - {1, 2, 3} , N=3, T=6, L=3 -> F= NEED I
 */
void find_f(double vals[], int combination, unsigned char second_pass, int mode) {
    
    if (mode == MODE_ARITH) {
        if (!second_pass) {
            switch (combination) {
                case LIT: {
                    find_n(vals, LIT, false, MODE_ARITH);
                    vals[F] = vals[L] - ((vals[N]*vals[I])+1);
                    return;
                }
                case LIN: {
                    vals[F] = vals[L] - ((vals[N]*vals[I])+1);
                    find_t(vals, LIN, true, MODE_ARITH);
                    return;
                }
                case LNT: {
                    find_i(vals, LNT, false, MODE_ARITH);
                    vals[F] = vals[L] - ((vals[N]*vals[I])+1);
                    return;
                }
                case INT: {
                    find_l(vals, INT, false, MODE_ARITH);
                    vals[F] = vals[L] - ((vals[N]*vals[I])+1);
                    return;
                }
            }
        }
        vals[F] = vals[L] - ((vals[N]*vals[I])+1);
        return;
    }
`   else if (mode == MODE_GEOM) {
        if (!second_pass) {
            switch (combination) {
                case LIT: {
                    find_n(vals, LIT, false, MODE_GEOM);
                    vals[F] = (vals[L]/pow(vals[I],vals[N]-1));
                    return;
                }
                case LIN: {
                    vals[F] = (vals[L]/pow(vals[I],vals[N]-1));
                    find_t(vals, LIN, true, MODE_GEOM);
                    return;
                }
                case LNT: {
                    find_i(vals, LNT, false, MODE_GEOM);
                    vals[F] = (vals[L]/pow(vals[I],vals[N]-1));
                    return;
                }
                case INT: {
                    find_l(vals, INT, false, MODE_GEOM);
                    vals[F] = (vals[L]/pow(vals[I],vals[N]-1));
                    return;
                }
            }
        }
        vals[F] = (vals[L]/pow(vals[I],vals[N]-1));
        return;
    }
}


    


void find_i(double vals[], int combination, unsigned char second_pass, int mode) {
    
    if (mode_global == (MODE_ARITH)) {
        if (!second_pass) {
            switch (combination) {
                case FLN: {
                    vals[I] = (vals[L] - vals[F])/(vals[N]-1);
                    find_t(vals, FLN, true, MODE_ARITH);
                    return;
                }
                case FNT: {
                    find_l(vals,FNT, false, MODE_ARITH);
                    vals[I] = (vals[L] - vals[F])/(vals[N]-1);
                    return;
                }
                case FLT: {
                    find_n(vals, FLT, false, MODE_ARITH);
                    vals[I] = (vals[L] - vals[F])/(vals[N]-1);
                    return;
                }
                case LNT: {
                    vals[I] = (vals[L] - vals[F])/(vals[N]-1);
                    return;
                }

            }
        }
        vals[I] = (vals[L] - vals[F])/(vals[N]-1);
        return;
    }
    else if (mode_global == (MODE_GEOM)) {
        if (!second_pass) {
            switch (combination) {
                case FLN: {
                    vals[I] = root(vals[L]/vals[F],vals[N]-1);
                    find_t(vals,FLN, true, MODE_GEOM);
                    return;
                }
                case FNT: {
                    find_l(vals,FNT, false, MODE_GEOM):
                    vals[I] = root(vals[L]/vals[F],vals[N]-1);
                    return;

                }
                case FLT: {
                    find_n(vals, FLT, false, MODE_GEOM);
                    vals[I] = root(vals[L]/vals[F],vals[N]-1);
                    return;
                }
                case LNT: {
                    find_f(vals, LNT, false, MODE_GEOM);
                    vals[I] = root(vals[L]/vals[F],vals[N]-1);
                    return;
                }

            }
        }
    }
    return;
}


void find_l(double vals[], int combination, unsigned char second_pass, int mode) {

    if (mode_global == (MODE_ARITH)) {
        if (!second_pass) {
            switch (combination) {
                case FIT: {
                    double x,terms;
                    for (x=vals[F], terms=1; x < vals[T]; x += vals[I]) {
                        terms++;
                    }
                    vals[N] = terms;
                    vals[L] = x;
                    return;
                }
                case FNT: {
                    while (true) {
                        double x,t,i,n;
                        for (x=vals[F], t=0, i=1, n=1; n < vals[N]; n++) {
                            x += i;
                            t += x;
                            if (t == vals[T]) {
                                vals[L] = x;
                                vals[I] = i;
                                return;
                            }
                        }
                    }
                }
            }
        }
    }
    else if (mode_global == MODE_GEOM) {
        switch (combination) {
            case FIT: {
                vals[L] = vals[F]/vals[T];
                vals[N] = vals[I]/vals[T];
                double x;
                for (x=0; x < vals[N] ; x++) {
                    x += 1;
                }
                return;
            }
            case FNT: {
                double gp = vals[F]/vals[N];
                double x;
                for (x=0; x < vals[N] ; x++) {
                    x += 1;
                }
                vals[L] = vals[F]/vals[N];
                return;
            }
        }
    }
}

void find_n(double vals[], int combination, unsigned char second_pass, int mode) {
    
    if (mode_global == (MODE_ARITH)) {
        if (!second_pass) {
            switch (combination) {
                case LIT: {
                    double l,t,count;
                    for (t=vals[L], count=1, l=vals[L]; t < vals[T]; count++) {
                        l -= vals[I];
                        t += l;
                        if (t == vals[T]) {
                            vals[N] = count;
                            vals[F] = l;
                            return;
                        }
                    }
                }
                case FLT: {
                    vals[N] = (vals[T]*2)/(vals[F] + vals[L]);
                    return;
                }
            }
        }
    }
    else if (mode_global == MODE_GEOM) {
        switch (combination) {
            case LIT: {
                double l,t,count;
                for (t=vals[L], count=1, l=vals[L]; t < vals[T]; count++) {
                    l -= vals[I];
                    t += l;
                    if (t == vals[T]) {
                        vals[N] = count;
                        vals[F] = l;
                        return;
                    }
                }
            }
            case FLT: {
                vals[N] = (vals[T]*2)/(vals[F] + vals[L]);
                return;
            }
        }
    }
    return;
}




void find_t(double vals[], int combination, unsigned char second_pass, int mode) {
    if (mode_global == MODE_ARITH) {
        if (!second_pass) {
            switch (combination) {
                case FLI: {
                    double t=0;
                    double count=1;
                    for (double f=vals[F]; f < vals[L]; f += vals[I]) {
                        t += f;
                        count++;
                    }
                    vals[T] = t;
                    vals[N] = count;
                    return;
                }
                case FIN: {
                    double f,t=0;
                    double l,count=1;
                    for (f=vals[F]; count < vals[N]; count++) {
                        f += vals[I];
                        t += f;
                    }
                    vals[T] = t;
                    vals[L] = f;
                    return;
                }
            }
        }
        

        double f,t=0;
        double l,count=1;
        for (f=vals[F]; count < vals[N]; count++) {
            f += vals[I];
            t += f;
        }
        vals[T] = t+1;
        return;

    }
    else if (mode_global == MODE_GEOM) {
        if (!second_pass) {
            switch (combination) {
                case FLN: {
                }
            }
        }
    }

}

// Returns macro based on combination found for initial values
int combination_dictionary(double vals[]) {
    
    int f,i,l,n,t;
    f=i=l=n=t=0;
    for (int x=0; x<5; ++x) {
        if (vals[x]) {
            switch (x) {
                case 0: f++; break;
                case 1: i++; break;
                case 2: l++; break;
                case 3: n++; break;
                case 4: t++; break;
            }
        }
    }
    if (f && l && i) {  return FLI; };
    if (f && l && n) {  return FLN; };
    if (f && l && t) {  return FLT; };
    if (f && i && n) {  return FIN; };
    if (f && i && t) {  return FIT; };
    if (f && n && t) {  return FNT; };
    if (l && i && n) {  return LIN; };
    if (l && i && t) {  return LIT; };
    if (l && n && t) {  return LNT; };
    if (i && n && t) {  return INT; };
    return ERROR;
}








// Overloaded validation for string/char arguments
int validate_args(int mode_val, const char * arg) {
    
    if (mode_val == FILNT_CHECK) {
        // Determine valid 'filnt' argument given, both upper and lowercase
        // supported
        const char * valid_args[] = { "f", "i", "l", "n", "t" };
        const char * valid_args_upper[] = { "F", "I", "L", "N", "T" };

        for (int x=0; x < 5; ++x) {
            // If the argument matches anything in filnt or FILNT, return the #define 
            // constant FILNT for the argument position
            if (!(strcmp(arg, valid_args[x])) || (!(strcmp(arg, valid_args_upper[x])))) {
                    return x;
            }
        }
        // Otherwise error
        return ERROR;
    }
}


// Overloaded validation for numerical arguments
double validate_args(double mode_val, const char * arg) {
    // Determine valid numerical argument following alpha argument
    if (mode_val == NUM_CHECK) {
        double res;
        try {
            // Make sure following argument from filnt is numerical
            for (int x=0; x < strlen(arg); ++x) {
                if (isalpha(arg[x])) {
                    return ERROR;
                }
            }
            // Convert to float
            res = atof(arg);
            return res;
        } 
        catch (int e) {
            // Return error for exception
            return ERROR;
        }
    }
}


// Get command line arguments and parse correspdonding values
int parse_args(char * argv[], int argc, double vals[]) {
            
    // Check mode, arithmetic or geometric 
    if (!(strcmp(argv[1], "arithmetic"))) {
        mode_global = MODE_ARITH;
    }
    else if (!(strcmp(argv[1], "geometric"))) {
        mode_global = MODE_GEOM;
    }
    else {
        printf("\nInvalid mode specified '%s'", argv[1]);
        return ERROR;
    }



    // Iterate through args
    for (int x=2; x < argc; x += 2) {
        
        // Get the alpha argument (filnt) and the numerical argument ( number that follows filnt) 
        int res_alpha = validate_args(FILNT_CHECK, argv[x]);
        double res_num = validate_args(NUM_CHECK, argv[x+1]);
       
        // Any issues with parsing, stop at first argument error deteted
        if ((res_alpha == ERROR) || (res_num == ERROR)) {
            printf("\nError in argument %d - Please enter arguments correctly", x);
            return ERROR;
        }
    

        // Otherwise store argument values in appropriate position 
        // of vals[], using FILNT macros
        switch (res_alpha) {
            case F:
                vals[F] = res_num;
                break;
            case I:
                vals[I] = res_num;
                // We want I to be nonzero, check
                if (!res_num) { 
                    printf("\nValue for I must be nonzero\n");
                    return ERROR;
                }
                break;
            case L:
                vals[L] = res_num;
                break;
            case N:
                vals[N] = res_num;
                // We want N to be greater than 1
                if (res_num <= 1) {
                    printf("\nValue for N must be greater than 1\n");
                    return ERROR;
                }
                break;
            case T:
                vals[T] = res_num;
                break;
        }
    }

}

double root(double input, double n)
{
  return round(pow(input, 1.0/n));
}
