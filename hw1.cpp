/*
 *
 *  ·▄▄▄▄  ▪  .▄▄ ·  ▄▄· ▄▄▄  ▄▄▄ .▄▄▄▄▄▄▄▄ .
 *  ██▪ ██ ██ ▐█ ▀. ▐█ ▌▪▀▄ █·▀▄.▀·•██  ▀▄.▀·
 *  ▐█· ▐█▌▐█·▄▀▀▀█▄██ ▄▄▐▀▀▄ ▐▀▀▪▄ ▐█.▪▐▀▀▪▄
 *  ██. ██ ▐█▌▐█▄▪▐█▐███▌▐█•█▌▐█▄▄▌ ▐█▌·▐█▄▄▌
 *  ▀▀▀▀▀• ▀▀▀ ▀▀▀▀ ·▀▀▀ .▀  ▀ ▀▀▀  ▀▀▀  ▀▀▀
 *
 *  .▄▄ · ▄▄▄▄▄▄▄▄  ▄• ▄▌ ▄▄· ▄▄▄▄▄▄• ▄▌▄▄▄  ▄▄▄ ..▄▄ ·
 *  ▐█ ▀. •██  ▀▄ █·█▪██▌▐█ ▌▪•██  █▪██▌▀▄ █·▀▄.▀·▐█ ▀.
 *  ▄▀▀▀█▄ ▐█.▪▐▀▀▄ █▌▐█▌██ ▄▄ ▐█.▪█▌▐█▌▐▀▀▄ ▐▀▀▪▄▄▀▀▀█▄
 *  ▐█▄▪▐█ ▐█▌·▐█•█▌▐█▄█▌▐███▌ ▐█▌·▐█▄█▌▐█•█▌▐█▄▄▌▐█▄▪▐█
 *   ▀▀▀▀  ▀▀▀ .▀  ▀ ▀▀▀ ·▀▀▀  ▀▀▀  ▀▀▀ .▀  ▀ ▀▀▀  ▀▀▀▀
 *
 -!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!
 #
 #   CoSCi 542 - Discrete Structures 
 #   Instructor: Bob Hart
 #   Section: 21566
 #   W - 5:45PM - 10:00PM
 #
 #   --->>
 #       
 #   Name: Nicholas Martinez
 #   Date: 02/08/18
 #    
 #   --->> 
 #
 #
 #   Sample Output:
 #          [~/school/discr] (master) >>> run
 #      Factorial 4: 24
 #     Combinations for 5,2: 10
 #
 #      Permuatations for 5,2: 20
 # 
 #      AAAA
 #      BAAA
 #      CAAA
 #      BBAA
 #      CBAA
 #      CCAA
 #      BBBA
 #      CBBA
 #      CCBA
 #      CCCA
 #      BBBB
 #      CBBB
 #      CCBB
 #      CCCB
 #      CCCC
 #      Comb ABC for 4: 15
 #
 #      AA
 #      BA
 #      CA
 #      AB
 #      BB
 #      CB
 #      AC
 #      BC
 #      CC
 #      Perm ABC for 2: 9
 #
 #      CBBA
 #      BCBA
 #      BBCA
 #      CBAB
 #      BCAB
 #      CABB
 #      ACBB
 #      BACB
 #      ABCB
 #      BBAC
 #      BABC
 #      ABBC
 #      Perm ABC for 1,2,1: 12
*/

#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cassert>

#include <vector>
#include <algorithm>


/* HW Functions */
unsigned factorial(unsigned n);
unsigned comb(unsigned n, unsigned k);
unsigned perm(unsigned n, unsigned k);
unsigned combABC(unsigned n);
unsigned permABC(unsigned n);
unsigned f(unsigned a, unsigned b, unsigned c);


/* Helper Functions */
int get_comb_val(unsigned char * p_map, std::vector<unsigned char *> * v_map, int n, 
        int a_count=0, int b_count=0, int c_count=0);
int pow(int n,int k);
void inc_base_n(unsigned char * perm_map, int pos);
void dealloc_comb_vec(std::vector<unsigned char *> * v_map);



int main() {

    unsigned x = factorial(4);
    printf("Factorial 4: %d\n", x);

    x = comb(5,2);
    printf("Combinations for 5,2: %d\n\n", x);

    x = perm(5,2);
    printf("Permuatations for 5,2: %d\n\n", x);
    
    x = combABC(4);
    printf("Comb ABC for 4: %d\n\n", x);

    x = permABC(2);
    printf("Perm ABC for 2: %d\n\n", x);
    
    x = f(1,2,1);
    printf("Perm ABC for 1,2,1: %d\n\n", x);
    
    return 0;

}


/* Factorial function */
unsigned factorial(unsigned n) {

    // For any factorial, even 0, return at least 1
    unsigned ret=1;
    for(int i=n; i>0; --i){

       // For each iteration/decrement, multiply
       // to simulate factorial
       ret *= i;
    }
    return ret;
}


/* Function for combinations:
 *
 *      n!/(k!(n-k)!)
 */
unsigned comb(unsigned n, unsigned k) {
    return factorial(n)/(factorial(k)*factorial(n-k));
}


/* Function for permutations:
 *
 *      n!/((n-k)!)
 */
unsigned perm(unsigned n, unsigned k) {
    return factorial(n)/factorial(n-k);
}


/* Function for combinations among letters 'A', 'B', and 'C'
 *
 * `combABC outputs each combination of n letters, where each letter is A, B, or C. 
 * For example, combABC 4) would output 15 lines:`
 *
 */
unsigned combABC(unsigned n) {

    // Score will keep track of total non duplicate combinations of 'A', 'B', and 'C'
    int score = 0;
    
    // The maximum combinations ( duplicate included ) for a three character system ( base 3 )
    // will be 3^n, rounds will keep track of total iterations, to stay under limit
    int rounds = 0;

    // comb_map will hold all letter combinations, heap allocated once and continously
    // mutated
    unsigned char * comb_map = (unsigned char *) calloc(n,sizeof(unsigned char));

    // val_amp will store unique combinations seen in generation phase
    std::vector<unsigned char *> val_map;

    // Initialize comb_map with all 'A''s
    for (int i=0; i < n; ++i) {
        comb_map[i] = 'A';
    }
    

    do {
        // get_comb_val is given the comb_map string 'AAA...', the val_map vector, and 
        // 'n', which is the specified amount of letters, and determines whether the
        // combination in comb_map is unique or not, if so the function returns true
        // and increments score and prints the string
        if (get_comb_val(comb_map, &val_map, n)) {
            score++;
            printf("%s\n", comb_map);
        }

        
        // Here we implement a 'psuedo' base 3 system, by checking for 'C'
        // on the first digit of comb_map, if it is not yet C, we can increment it
        if (comb_map[0] != 'C') {
            comb_map[0]++;
        }
        else {
            // Otherwise call inc_base_n, which properly increment the string in base 3
            // see function for details
            inc_base_n(comb_map, 0);
        }

        // Count the total iterations for incrementing
        rounds++;
    }
    // We can't possibly have more iterations than 3^n, as 3^n 
    // represents the largest value in an 'n' digit number in base 3
    while (rounds < pow(3,n)); 

    // When finished, make sure comb_map is still a valid pointer, a free it
    comb_map ? free(comb_map) : free(NULL);

    // We also need to free all of the generated pointers contained in the val_map
    // vector
    dealloc_comb_vec(&val_map);

    // Now return the number of unique combinations
    return score;

}


/*
 *  unsigned permABC(unsigned n);
 *  permABC outputs each permutation of n letters, where each letter is A, B, or C. 
 *  For example, permABC(2) would output 9 lines:
 *
 *  This function is very similar to the previous function, except that because order 
 *  now matters, we don't have to determine whether the combination is unique,
 *  and simply increment like a base 3 system. So our function can very simply return 3^n
 *  for the number of permutations, and print out the permutations without calling
 *  get_comb_val()
 *
 */

unsigned permABC(unsigned n) {
    
    int score , rounds;
    rounds = score = 0;
    // perm_map will hold all letter permutations, heap allocated once and continously
    // mutated
    unsigned char * perm_map = (unsigned char *) calloc(n,sizeof(unsigned char));
    
    // Initialze with A's
    for (int i=0; i < n; ++i) {
        perm_map[i] = 'A';
    }

    do {
        printf("%s\n", perm_map);
        score++;
        
        // Here we implement a 'psuedo' base 3 system, by checking for 'C'
        // on the first digit of perm_map, if it is not yet C, we can increment it
        if (perm_map[0] != 'C') {
            perm_map[0]++;
        }
        else {
            // Otherwise call inc_base_n, which properly increment the string in base 3
            // see function for details
            inc_base_n(perm_map, 0);
        }

        // Count the total iterations for incrementing
        rounds++;
    }
    // We can't possibly have more iterations than 3^n, as 3^n 
    // represents the largest value in an 'n' digit number in base 3
    while (rounds < pow(3,n)); 


    // When finished, make sure comb_map is still a valid pointer, a free it
    perm_map ? free(perm_map) : free(NULL);

    return score;



}


/*
 *  unsigned f(unsigned a, unsigned b, unsigned c);
 *  Compute and return the number of strings of a A's, b B's, and c C's. 
 *  For example, f(1, 2, 1) returns 12 because there are 12 strings made 
 *  up of 1 A, 2 B's, and 1 C:
 *
 */

unsigned f(unsigned a, unsigned b, unsigned c) {

    int score , rounds, n;
    rounds = score = 0;

    // Because a b and c are the 'digits' in the string, the total number should
    // be our 'n' for how many digits to begin permutations/combinations
    n = a+b+c;

    // perm_map will hold all letter permutations, heap allocated once and continously
    // mutated
    unsigned char * perm_map = (unsigned char *) calloc(n,sizeof(unsigned char));
    
    // Initialze with A's
    for (int i=0; i < n; ++i) {
        perm_map[i] = 'A';
    }

    do {

        // Here we call get_comb_val with the required counts for a,b and c
        // which will return 1 (true) if we have passed it a string ( perm_map ) 
        // that contains the specified counts of A B and C characters
        //
        // We are also passing NULL to our vector parameter that was used in previous
        // functions to store unique combinations of 'A' 'B' and 'C', since it is not
        // required for this function f()
        //
        if (get_comb_val(perm_map, NULL, n, a, b, c)) {
            printf("%s\n", perm_map);
            score++;
        }
        
        // Here we implement a 'psuedo' base 3 system, by checking for 'C'
        // on the first digit of perm_map, if it is not yet C, we can increment it
        if (perm_map[0] != 'C') {
            perm_map[0]++;
        }
        else {
            // Otherwise call inc_base_n, which properly increments the string in base 3
            // see function for details
            inc_base_n(perm_map, 0);
        }

        // Count the total iterations for incrementing
        rounds++;
    }
    // We can't possibly have more iterations than 3^n, as 3^n 
    // represents the largest value in an 'n' digit number in base 3
    while (rounds < pow(3,n)); 


    // When finished, make sure comb_map is still a valid pointer, a free it
    perm_map ? free(perm_map) : free(NULL);

    return score;



}





// This function determines whether the given combination 'AAA...' has been seen before
// Or if optionally called with the default parameters, determines whether the given
// permutation/combination supplied contains the amount of A's B's and C's specified
int get_comb_val(unsigned char * p_map, std::vector<unsigned char *> * v_map, int n, 
        int a_count, int b_count, int c_count) {

    // We create here an array of values that will be used to reperesent
    // the occurances of each character in the perm_map string, null terminated at pos 3
    unsigned char counts[] = {0x1,0x1,0x1,0x0};

    // Iterate through the given combination
    for (int x=0; x < n; ++x) {
        unsigned char val = p_map[x];
        switch (val) {

            // Incrementing each position per value
            case 'A':
                counts[0]++; break;
            case 'B':
                counts[1]++; break;
            case 'C':
                counts[2]++; break;
        }
    }

    // If called with a,b, or c count values, no need to enter unique entries
    // just return true or false if count[] values match specified values
    if (a_count || b_count || c_count) {
        if ((counts[0] == a_count+1) && (counts[1] == b_count+1) 
            && (counts[2] == c_count+1)) {
            return 1;
        }
        return 0;
    }


    // Allocate a new combination string off the heap to store in our vector v_map
    unsigned char * comb_str = (unsigned char *) calloc(4, sizeof(unsigned char));

    // Copy the values from the stack array counts[]
    for (int r=0; r<3; ++r) {
        memcpy(comb_str+r,&counts[r],1);
    }

    // Check if value is in value array
    for (int g=0; g < v_map->size(); ++g) {

        // We need to cast our values to a const char time for strcmp to work properly
        if (!strcmp((const char *) comb_str, (const char *) v_map->at(g))) {

            // If strcmp returns zero, then the string of values has been found in v_map
            // and thus is not unique, so we return zero back to our function so it knows
            // not to increment our score counter
            return 0;
        }
    }

    // Though if its not in the vector, lets add it and return 1
    v_map->push_back(comb_str);
    return 1;
}



// This function recursively increments the perm_map string as if it
// were a base three number
void inc_base_n(unsigned char * perm_map, int pos) {

    // First, we know that if this function was called, it was because
    // the current position given was a 'C', so it needs to be reset to
    // our zeroth digit 'A'
    perm_map[pos] = 'A';

    // Next since we still need to increment some value, we check if we
    // can do that for the following digit, by checking if it is incrementable
    // or if it requires the same process as before ( resetting to A )
    if (perm_map[pos+1] != 'C') {

        // If not we can simply increment and return
        perm_map[pos+1]++;
        return;
    }

    // But if it is C, we need to call this function again, with the position being
    // the following digit
    inc_base_n(perm_map, pos+1);
}
    












// Helper functions, get power n^k
int pow(int n,int k) {
    int val = n;
    for (int x=0; x < k-1; ++x) {
        n *= val;
    }
    return n;
}


// Helper function, free all of the pointers stored in v_map
void dealloc_comb_vec(std::vector<unsigned char *> * v_map) {
    for (int g=0; g < v_map->size(); ++g) {
        free((v_map->at(g)));
    }
}
