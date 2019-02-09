#include <cstdlib>
#include <cstdio>
#include <cassert>

#include <vector>
#include <algorithm>

//typedef unsigned int unsigned;
unsigned factorial(unsigned n);
unsigned comb(unsigned n, unsigned k);
unsigned perm(unsigned n, unsigned k);
unsigned combABC(unsigned n);
int get_comb_val(unsigned char * p_map, std::vector<int> * v_map, int n);




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
    int rounds = 0;
    unsigned char * perm_map = (unsigned char *) calloc(n,sizeof(unsigned char));
    std::vector<int> val_map;

    // Initialize counting
    for (int i=0; i < n; ++i) {
        perm_map[i] = 'A';
    }
    
    do {
        score += get_comb_val(perm_map, &val_map, n);
        for (int z=0; z < n; ++z) {
            if (perm_map[z] != 'C') {
                perm_map[z]++;
                break;
            }
            else {
                perm_map[z] = 'A';
                perm_map[++z]++;
            }
        }
        rounds++;
    }
    while (rounds < 3); // TODO: Pow 3
    perm_map ? free(perm_map) : free(NULL);
    return score;

}

int get_comb_val(unsigned char * p_map, std::vector<int> * v_map, int n) {

    int score = 0;
    // Return value of combination array 
    for (int i=0; i < n; ++i) {
        score += (int) p_map[i];
    }
    
    // Check if value is in value array
    if (std::find(v_map->begin(), v_map->end(), score) != v_map->end()) {
       return 1;
    }
    return 0;
}











