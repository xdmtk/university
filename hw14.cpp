/* Nicholas Martinez - COSCI 542 - Hart - April 10 2019 - HOMEWORK 10
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
 *                      Homework #8                         !
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



double monotonic(unsigned a, unsigned b);
double strictly_monotonic(unsigned a, unsigned b);
double ok_nesting(unsigned n);


void randomize_sequence(unsigned int * sequence, int sequence_len, int max_val);
int analyze_monotonic(unsigned int * sequence, int sequence_len);
int analyze_strict_monotonic(unsigned int * sequence, int sequence_len);


int main() {
    
    double monotonic_total = 0;
    double strict_monotonic_total = 0;
    double nested_total = 0;
    int TRIALS = 10;
    int a = 7;
    int b = 5;
    int nested_limit = 50;
    
   
   /* 
    for (int x = 0; x < TRIALS; ++x) {
        monotonic_total += monotonic(a,b);
    }

    std::cout << "Average percentage of monotonic for a(" << a << ") and b(" << b 
        << ") after 10 trials of 1,000,000 sequences: %" 
        << ((monotonic_total/(double)TRIALS)*100) << std::endl;




    for (int x = 0; x < TRIALS; ++x) {
        strict_monotonic_total += strictly_monotonic(a,b);
    }
    
    std::cout << "Average percentage of strictly monotonic for a(" << a << ") and b(" << b 
        << ") after 10 trials of 1,000,000 sequences: %" 
        << ((strict_monotonic_total/(double)TRIALS)*100) << std::endl;
    */
    

    for (int x = 0; x < TRIALS; ++x) {
        nested_total += ok_nesting(nested_limit);
    }
    
    std::cout << "Average percentage of nested properly for n(" << nested_limit 
        << ") after 10 trials of 1,000,000 sequences: %" 
        << ((nested_total/(double)TRIALS)*100) << std::endl;




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
