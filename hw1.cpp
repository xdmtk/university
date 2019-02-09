#include <cstdlib>
#include <vector>
#include <cstdio>
#include <cassert>


//typedef unsigned int unsigned;
unsigned factorial(unsigned n);
unsigned comb(unsigned n, unsigned k);
unsigned perm(unsigned n, unsigned k);
unsigned combABC(unsigned n);




int main() {

    unsigned x = factorial(4);
    printf("Factorial 4: %d\n", x);

    x = comb(5,2);
    printf("Combinations for 5,2: %d\n", x);

    x = perm(5,2);
    printf("Permuatations for 5,2: %d\n", x);
    return 0;

    
}

unsigned factorial(unsigned n) {
    unsigned ret=1;
    for(int i=n; i>0; --i){
       ret *= i;
    }
    return ret;
}

unsigned comb(unsigned n, unsigned k) {
    return factorial(n)/(factorial(k)*factorial(n-k));
}

unsigned perm(unsigned n, unsigned k) {
    return factorial(n)/factorial(n-k);
}

/*
 * combABC outputs each combination of n letters, where each letter is A, B, or C. 
 * For example, combABC 4) would output 15 lines:
 *
 */

unsigned combABC(unsigned n) {
    
    int score = 0;
    unsigned char * perm_map = (unsigned char *) calloc(n,sizeof(unsigned char));
    std::vector<int> val_map;

    // Initialize counting
    for (int i=0; i < n; ++i) {
        perm_map[i] = 'A';
    }
    
    score = get_comb_val(perm_map, &val_map);
    
    
    
    AAA
    BAA
    CAA
    ABA
    BBA
    CBA
    ACA
    BCA
    CCA
    AAB
    BAB
    CAB
    ABB
    BBB
    CBB
    ACB
    BCB
    CCB
    AAC
    BAC
    CAC
    ABC
    BBC
    CBC
    ACC
    BCC
    CCC


}
