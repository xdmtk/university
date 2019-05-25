/* Nicholas Martinez - COSCI 542 - Hart - May 22 2019 - HOMEWORK 14
/
/
/!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-/
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
 *                      Homework #14                        !
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
 *   Date: 05/22/19
 *    
 *   --->> 
       

        WARNING WARNING WARNING WARNING
        WARNING WARNING WARNING WARNING
        WARNING WARNING WARNING WARNING
        WARNING WARNING WARNING WARNING
        WARNING WARNING WARNING WARNING
        WARNING WARNING WARNING WARNING
        !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

        THIS PROGRAM TAKES A VERY LONG 
        TIME TO EXECUTE, TO SPEED UP 
        EXECUTION, UNCOMMENT THE MULTI-
        THREADING SECTION IN MAIN() AND
        COMPILED WITH THE FLAG '-pthread'
        TO ENABLE MULTITHREAD EXECUTION

        !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
        WARNING WARNING WARNING WARNING
        WARNING WARNING WARNING WARNING
        WARNING WARNING WARNING WARNING
        WARNING WARNING WARNING WARNING
        WARNING WARNING WARNING WARNING
        WARNING WARNING WARNING WARNING










 
         CS 542 Hw14: Probability functions

        For each of the following functions, estimate the answer by doing a million trials.

        A. double monotonic(unsigned a, unsigned b);
        Consider a sequence of b #'s, where each number is randomly chosen to be an int in [0, a). What is the probability that the sequence is monotonic? (That is, either (non-strictly) monotonically increasing or decreasing.)
        For instance, if a were 2 and b were 3, we'd have 2^3 == 8 possibilities:
            000	001	010	011	100	101	110	111
            m	m		m	m		m	m
        where the 6 monotonic possibilities are marked with m, so we'd expect an answer close to 0.75; your function doesn't do the mathematical calculation, it creates a random 3-bit value 1000000 times and returns the fraction of times the 3-bit value is monotonic.

        B. double strictlyMonotonic(unsigned a, unsigned b);
        Just like the last problem, but now the sequence must be strictly monotonic (no repeated numbers). (So, we'd expect strictlyMonotonic(2, 3) to return 0.)

        C. double okNesting(unsigned n);
            Randomly shuffle 2n chars, where n of the chars are ( and n of the chars are ).
            What is the probability that the parens will properly nest?
            For example, with n == 2 we would have
                (())	properly nested
                ()()	properly nested
                ())(	not properly nested
                )(()	not properly nested
                )()(	not properly nested
                ))((	not properly nested

        D. double duel(double a, double b);
        Mr. A and Mr. B can’t reach an accord on the most pleasing way to format a C++ statement block, so they decide to fight a duel with pistols. The bullets are laced with cyanide, so the first hit will be fatal. Mr. A shoots first, and the duelists courteously take turns shooting. Mr. A hits his target with probability a, and Mr. B hits his target with probability b. They continue until someone is hit.
        What is the probability that Mr. A wins the duel?

        E. double flip(double p, unsigned n, unsigned k);
        We have a crooked coin that comes up heads with probability p. We flip the coin n times; what is the probability that we get exactly k heads?

        F. double prettyLady(unsigned gridX, unsigned gridY,
        unsigned ladyX, unsigned ladyY);
        I need to travel from the origin to the point (gridX, gridY), following the integer grid lines. As usual, I require that my distance be minimum (which is gridX + gridY). Among all possible paths, I pick one at random and follow it.
        Unknown to me, there is a pretty lady at the (ladyX, ladyY) intersection. What is the probability that I will pass her intersection on the way my (gridX, gridY) destination?
        For example, if (gridX, gridY) were (2, 2) and (ladyX, ladyY) were (1,1), then I have 6 possible paths:
            NNEE: no pretty lady
            NENE: pretty lady
            NEEN: pretty lady
            ENNE: pretty lady
            ENEN: pretty lady
            EENN: no pretty lady
        So, I would expect prettyLady(2, 2, 1, 1) to return a number close to 0.667

        Write a main that calls the above 6 functions. main’s job is to convince you that your functions are probably right. You decide the details of your main.




        SAMPLE OUPUT:::::
            [~/school/discr] (master) > run
            Average percentage of wins for Mr. A in a duel with probability range for Mr. A at %43 and probability range for Mr. B at %0.72 after 10 trials of 1,000,000 duels: %43.452
            Average percentage of strictly monotonic for a(2) and b(3) after 10 trials of 1,000,000 sequences: %0
            Average percentage of monotonic for a(2) and b(3) after 10 trials of 1,000,000 sequences: %79.5441
            Average percentage of passes on pretty lady with grid coords x(13) and y(9) with grid size x(20) and y(20) is 0
            Average percentage of 7 heads with probability 0.72 and flips 20 : %0.05857
            Average percentage of nested properly for n(50) after 10 trials of 1,000,000 sequences: %0.14992

 *
 *
 *
*/


#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <cmath>
#include <cctype>

#include <vector>
#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
#include <map>
#include <thread>


double monotonic(unsigned a, unsigned b);
double strictly_monotonic(unsigned a, unsigned b);
double ok_nesting(unsigned n);
double duel(double a, double b);
double flip(double p, unsigned n, unsigned k);
double pretty_lady(unsigned gridX, unsigned gridY, unsigned ladyX, unsigned ladyY);


void randomize_sequence(unsigned int * sequence, int sequence_len, int max_val);
int analyze_monotonic(unsigned int * sequence, int sequence_len);
int analyze_strict_monotonic(unsigned int * sequence, int sequence_len);


void init_constants(std::map<std::string, double> & c_map);
inline void exec_monotonic(std::map<std::string, double> constants);
inline void exec_ok_nested(std::map<std::string, double> constants);
inline void exec_strict_monotonic(std::map<std::string, double> constants);
inline void exec_duel(std::map<std::string, double> constants);
inline void exec_flip(std::map<std::string, double> constants);
inline void exec_pretty_lady(std::map<std::string, double> constants);


int main() {

    std::map<std::string, double> c_map;
    init_constants(c_map);

    /**
     * WARNING !!!!! THIS PROGRAM TAKES A VERY LONG TIME TO
     * FINISH!! UNCOMMENT THE MULTITHREADING SECTION BELOW
     * AND COMPILE WITH FLAG '-pthread' TO SPEED UP EXECUTION!!!
     */
    /*
        std::thread t_monotonic(exec_monotonic, c_map);
        std::thread t_strict_monotonic(exec_strict_monotonic, c_map);
        std::thread t_ok_nested(exec_ok_nested, c_map);
        std::thread t_duel(exec_duel, c_map);
        std::thread t_flip(exec_flip, c_map);
        std::thread t_plady(exec_pretty_lady, c_map);

        t_monotonic.join();
        t_strict_monotonic.join();
        t_ok_nested.join();
        t_duel.join();
        t_flip.join();
        t_plady.join();

        return 0;
    */


    exec_monotonic(c_map);
    exec_strict_monotonic(c_map);
    exec_ok_nested(c_map);
    exec_duel(c_map);
    exec_flip(c_map);
    exec_pretty_lady(c_map);

    return 0;
}






/**
 * FUNCTION 1
 *
 *
 * Consider a sequence of b #'s, where each number 
 * is randomly chosen to be an int in [0, a). What is the probability 
 * that the sequence is monotonic? (That is, either (non-strictly) 
 * monotonically increasing or decreasing.)
 * For instance, if a were 2 and b were 3, we'd have 2^3 == 8 possibilities:
 *
 * @param a - Base
 * @param b - Sequence length
 *
 * @return - Returns percentage of monotonic sequences formed in a/b combination
 */
double monotonic(unsigned a, unsigned b) {
    
    // Allocate set of 'b' values for sequence
    unsigned int * sequence = (unsigned int *) calloc(sizeof(unsigned int), b);
    
    // Set limiter for increments
    int limit = 1000000;
    
    // Init counter for monotonic sequences
    int counter = 0;
    
    // Begin constructing sequences
    for (int x = 0; x < limit; ++x) {

        // Increment the sequences as if it were base a
        randomize_sequence(sequence, b, a);
        
        // Increment the counter if the sequence is monotonic 
        counter += analyze_monotonic(sequence, b);
    }
    free(sequence); 
    return (double)counter/(double)limit;
}


/**
 * FUNCTION 2
 *
 * 
 * Just like the last problem, but now the sequence must be 
 * strictly monotonic (no repeated numbers). (So, we'd expect 
 * strictlyMonotonic(2, 3) to return 0.)
 *
 * Once again essentially a duplicate of the above, verbosity is 
 * on purpose
 *
 * @param a - Base
 * @param b - Sequence length
 *
 * @return - Returns percentage of monotonic sequences formed in a/b combination
 */
double strictly_monotonic(unsigned a, unsigned b) {
    
    // Allocate set of 'b' values for sequence
    unsigned int * sequence = (unsigned int *) calloc(sizeof(unsigned int), b);
    
    // Set limiter for increments
    int limit = 1000000;
    
    // Init counter for monotonic sequences
    int counter = 0;
    
    // Begin constructing sequences
    for (int x = 0; x < limit; ++x) {

        // Increment the sequences as if it were base a
        randomize_sequence(sequence, b, a);
        
        // Increment the counter if the sequence is monotonic 
        counter += analyze_strict_monotonic(sequence, b);
    }
    
    free(sequence); 
    return (double)counter/(double)limit;
}




/**
 * FUNCTION 3
 *  Randomly shuffle 2n chars, where n of the chars are ( and n of the chars are ).
 *  What is the probability that the parens will properly nest?
 *  For example, with n == 2 we would have
 *  (())    properly nested
 *  ()()    properly nested
 *  ())(    not properly nested
 *  )(()    not properly nested
 *  )()(    not properly nested
 *  ))((    not properly nested
 *
 * @param n - Amount of chars
 *
 * @return - Returns percentage of monotonic sequences formed in a/b combination
 */
double ok_nesting(unsigned n) {
    
    // Seed random generator 
    srand(time(NULL));

    // Allocate 2n bytes space for parenthesis tokens and sequence to hold
    char parens[] = { '(' , ')' };

    int ok_nest = 0;
    int TRIALS = 1000000;
    
    for (int y = 0; y < TRIALS; ++y) {

        char * paren_sequence = (char *) calloc(sizeof(char), 2*n);
        std::stack<char> paren_stack;
        
        // Fill parenthesis sequence with either ( or )
        for (int x = 0; x < 2*n; ++x) {
            paren_sequence[x] = parens[rand() % 2];
        }

        // Begin stack push/pop operations on parens
        for (int x = 0; x < 2*n; ++x) {
            
            // Push first element, or push opening parens
            if (!x || paren_sequence[x] == '(') {
                paren_stack.push(paren_sequence[x]);
                continue;
            }

            if (paren_sequence[x] == ')' && paren_stack.size() && paren_stack.top() == '(') {
                paren_stack.pop();
            }
            else {
                paren_stack.push(paren_sequence[x]);
            }
        }
        if (!paren_stack.size()) {
            ok_nest++;
        }
        free(paren_sequence);
    }
    
    return (double)ok_nest/(double)TRIALS;

}




/**
 * FUNCTION 4
 *
 *  Mr. A and Mr. B can’t reach an accord on the most pleasing way to format a C++ statement 
 *  block, so they decide to fight a duel with pistols. The bullets are laced with cyanide, 
 *  so the first hit will be fatal. Mr. A shoots first, and the duelists courteously take turns 
 *  shooting. Mr. A hits his target with probability a, and Mr. B hits his target with probability b. 
 *
 *  They continue until someone is hit.
 *  What is the probability that Mr. A wins the duel?
 *
 * @return - 
 */
double duel(double a, double b) {
    
    // First assert that a and b are percentages 
    assert((a < 1) && (b < 1));

    // Set duel win counters to 0
    int a_win = 0;
    int b_win = 0;
    
    // Bring percentage into number 0 - 100
    a *= 100;
    b *= 100;
   

    // Start 1 million trials
    for (int x = 0; x < 1000000; ++x) {

        // Generate a random integer and add a random double value between 0 - 1
        // to simulate generating a random double between 0-100
        double a_shot = (rand() % 100) + ((double)rand()/RAND_MAX);

        // If the number generated falls within the range of 0 - probablity of a
        // then Mr. A's shot has landed in the probable range of accuracy
        if (a_shot <= a) {

            // Thus Mr. A has won the duel
            a_win++;
        }

        // Since Mr. A has won, no need to calculate Mr. B's shot
        continue;
        

        // If Mr. A missed, then repeat the calculation with Mr. B and 
        // the probable range of accuracy listed for Mr. B
        double b_shot = (rand() % 100) + ((double)rand()/RAND_MAX);
        if (b_shot <= b) {
            b_win++;
        }
    }

    return (double)a_win/1000000.0;
}


/**
 * We have a crooked coin that comes up heads with probability p
 *  We flip the coin n times; what is the probability that we 
 *  get exactly k heads?
 */

double flip(double p, unsigned n, unsigned k) {
    
    srand(time(NULL));
    const int trials = 1000000;
    const int p_prob = p*100;
    double main_count = 0;

    for (int x = 0; x < trials; ++x) {
        
        int count = 0;

        for (int y = 0; y < n; ++y) {
            double flip = (rand() % 100) + ((double)rand()/RAND_MAX);
            if (flip <= p_prob) {
                count++;
            }
        }

        if (count == k) {
            main_count++;
        }
    }

    return main_count/(double)trials;
}




/**
 * 
 * 
 *  I need to travel from the origin to the point (gridX, gridY), 
 *  following the integer grid lines. As usual, I require that my distance be 
 *  minimum (which is gridX + gridY). Among all possible paths, I pick one at random and follow it.
 *  Unknown to me, there is a pretty lady at the (ladyX, ladyY) intersection. 
 *  What is the probability that I will pass her intersection on the way my (gridX, gridY) destination?
 *      For example, if (gridX, gridY) were (2, 2) and (ladyX, ladyY) were (1,1), then I have 6 possible paths:
 *          NNEE: no pretty lady
 *          NENE: pretty lady
 *          NEEN: pretty lady
 *          ENNE: pretty lady
 *          ENEN: pretty lady
 *          EENN: no pretty lady
 *      So, I would expect prettyLady(2, 2, 1, 1) to return a number close to 0.667
*/
double pretty_lady(unsigned gridX, unsigned gridY, unsigned ladyX, unsigned ladyY) {
    
    srand(time(NULL));
    const int trials = 1000000;
    int passed_lady = 0;
    
    for (int rounds = 0; rounds < trials; ++rounds) {
        int x = 0;
        int y = 0;
        while (x < gridX && y < gridY) {
            if (rand() % 2) {
                if (x < gridX) {
                    x++;
                    continue;
                }
                if (y < gridY) {
                    y++;
                }
            }
            else {
                if (y < gridY) {
                    y++;
                    continue;
                }
                if (x < gridX) {
                    x++;
                }
            }
            if (x == ladyX && y == ladyY) {
                passed_lady++;
            }
        }
    }

    return (double)passed_lady/(double)trials;
}




/**
 * Increments sequence as if it were base 'sequence_max_val', starting from position 0
 *
 * Recursively called with increasing position parameter when reached 'sequence_max_val' 
 * on particular digit
 *
 * @param sequence - Sequence of numbers
 * @param sequence_max_val - Base of incremement
 * @param pos - Position to start incrementing 
 *
 * @return void
 */
void randomize_sequence(unsigned int * sequence, int sequence_len, int max_val) {

    srand(time(NULL)); 
    for (int x = 0; x < sequence_len; ++x) {
        sequence[x] = rand() % max_val;
    }

}



/**
 * Analyzes the given sequence and returns whether the sequences
 * is monotonic, ( both increasing or decreasing )
 *
 * @param sequence - Sequence to analyze
 * @param sequence_len - Total length of sequence (b)
 *
 * @return bool - Whether the sequence is monotonic 
 */
int analyze_monotonic(unsigned int * sequence, int sequence_len) {

    bool is_monotonic = 0;
    
    // Check increasing monotonic
    for (int x = 0; x < sequence_len-1; ++x) {
        if (sequence[x] <= sequence[x+1]) {
            is_monotonic = 1;
        }
        else {
            is_monotonic = 0;
            break;
        }
    }

    // Do not check decreasing if increasing monotonic is true
    if (is_monotonic) {
        return true;
    }
    
    // Check decreasing monotonic
    for (int x = 0; x < sequence_len-1; ++x) {
        if (sequence[x] >= sequence[x+1]) {
            is_monotonic = 1;
        }
        else {
            return 0;
        }
    }
    return 1;

}



/**
 * Analyzes the given sequence and returns whether the sequences
 * is strictly monotonic, ( both increasing or decreasing )
 *
 * Very similar to analyze_monotonic, verbosity is on purpose
 *
 * @param sequence - Sequence to analyze
 * @param sequence_len - Total length of sequence (b)
 *
 * @return bool - Whether the sequence is monotonic 
 */
int analyze_strict_monotonic(unsigned int * sequence, int sequence_len) {

    bool is_monotonic = 0;

    // Run duplicate check before analyzing monotonic
    std::map<int,int> dupe_check;
    for (int x = 0; x < sequence_len; ++x) {
        
        // Enter values and seen types in map
        dupe_check[sequence[x]]++;
    }

    // Iterate over map to find duplicate values ( map entries with over 1 as val )
    std::map<int,int>::iterator it = dupe_check.begin();
    for ( ; it != dupe_check.end(); ++it) {
        if (it->second > 1) {
            //std::cout << "Found duplicate, not strictly monotonic" << std::endl;
            return 0;
        }
    }




    
    // Check increasing monotonic
    for (int x = 0; x < sequence_len-1; ++x) {
        if (sequence[x] <= sequence[x+1]) {
            is_monotonic = 1;
        }
        else {
            is_monotonic = 0;
            break;
        }
    }

    // Do not check decreasing if increasing monotonic is true
    if (is_monotonic) {
        return true;
    }
    
    // Check decreasing monotonic
    for (int x = 0; x < sequence_len-1; ++x) {
        if (sequence[x] >= sequence[x+1]) {
            is_monotonic = 1;
        }
        else {
            return 0;
        }
    }
    return 1;

}







/**
 * Exec functions 
 *
 * Parent functions that execute the main task (monotonic, strictly_monotonic, ok_nested, etc..)
 * and calculate results among trials 
 * 
 * @param constants - Map full of operating constraints for executing trials
 */

inline void exec_monotonic(std::map<std::string, double> constants) {

    // Trials for function 1 monotonic 
    for (int x = 0; x < constants["trials"]; ++x) {
        constants["monotonic_total"] += monotonic(constants["a"], constants["b"]);
    }

    std::cout << "Average percentage of monotonic for a(" << constants["a"] << ") and b(" << constants["b"]
        << ") after 10 trials of 1,000,000 sequences: %" 
        << (((double)constants["monotonic_total"]/(double)constants["trials"])*100) << std::endl;
}


inline void exec_strict_monotonic(std::map<std::string, double> constants) {

    // Trials for function 2 strictly monotonic 
    for (int x = 0; x < constants["trials"]; ++x) {
        constants["strict_monotonic_total"] += strictly_monotonic(constants["a"],constants["b"]);
    }
    
    std::cout << "Average percentage of strictly monotonic for a(" << constants["a"] << ") and b(" << constants["b"]
        << ") after 10 trials of 1,000,000 sequences: %" 
        << ((double)(constants["strict_monotonic_total"] /(double)constants["trials"])*100) << std::endl;
    
}


inline void exec_ok_nested(std::map<std::string, double> constants) {

    // Trials for function 3 ok nested 
    for (int x = 0; x < constants["trials"]; ++x) {
        constants["nested_total"] += ok_nesting(constants["nested_limit"]);
    }
    
    std::cout << "Average percentage of nested properly for n(" << constants["nested_limit"]
        << ") after 10 trials of 1,000,000 sequences: %" 
        << ((double)(constants["nested_total"]/(double)constants["trials"])*100) << std::endl;
}


inline void exec_duel(std::map<std::string, double> constants) {

    // Trials for function 3 ok nested 
    for (int x = 0; x < constants["trials"]; ++x) {
        constants["duel_total"] += duel(constants["mr_a"], constants["mr_b"]);
    }
    
    std::cout << "Average percentage of wins for Mr. A in a duel with probability range for Mr. A at %" 
        << constants["mr_a"]*100 << " and probability range for Mr. B at %"
        << constants["mr_b"] << " after 10 trials of 1,000,000 duels: %" 
        << ((double)(constants["duel_total"]/(double)constants["trials"])*100) << std::endl;
}


inline void exec_flip(std::map<std::string, double> constants) {

    // Trials for function 4 flip
    for (int x = 0; x < constants["trials"]; ++x) {
        constants["flip_total"] += flip(constants["probability"], constants["flips"], constants["heads"]);
    }
    
    std::cout << "Average percentage of " << constants["heads"] << " heads with probability " 
        << constants["probability"] 
        << " and flips "
        << constants["flips"]
        << " : %"
        << ((double)(constants["flip_total"]/(double)constants["trials"])*100) << std::endl;
       

}


inline void exec_pretty_lady(std::map<std::string, double> constants) {

    // Trials for function 5 pretty_lady
    for (int x = 0; x < constants["trials"]; ++x) {
        constants["p_lady_total"] += pretty_lady(constants["gridx"], constants["gridy"], 
                                        constants["pladyx"], constants["pladyy"]);
    }
    
    std::cout << "Average percentage of passes on pretty lady with grid coords x(" 
        << constants["pladyx"] << ")" 
        << " and y("
        << constants["pladyy"] << ")"
        << " with grid size x(" 
        << constants["gridx"]  << ")"
        <<  " and y("
        << constants["gridy"] << ")"
        << " is " 
        << ((double)(constants["p_lady_total"]/(double)constants["trials"])*100) << std::endl;

}

/**
 *
 * Initializes map of constraints for executing trials
 *
 */
void init_constants(std::map<std::string, double>& c_map) {

    c_map["monotonic_total"] = 0;
    c_map["strict_monotonic_total"] = 0;
    c_map["nested_total"] = 0;
    c_map["duel_total"] = 0;
    c_map["flip_total"] = 0;
    c_map["p_lady_total"] = 0;
   
    c_map["trials"] = 50;
   
    
    c_map["a"]  = 2;
    c_map["b"] = 3;
    c_map["nested_limit"] = 50;
  
    
    c_map["mr_a"] = .43;
    c_map["mr_b"] = .72;
    
    
    c_map["probability"] = .72;
    c_map["flips"] = 20;
    c_map["heads"] = 7;


    c_map["gridx"] = 20;
    c_map["gridy"] = 20;
    c_map["pladyx"] = 13;
    c_map["pladyy"] = 9;

}
