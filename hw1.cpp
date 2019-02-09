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
int pow(int n,int k);
void inc_base_n(unsigned char * perm_map, int pos);



int main() {

    unsigned x = factorial(4);
    printf("Factorial 4: %d\n", x);

    x = comb(5,2);
    printf("Combinations for 5,2: %d\n", x);

    x = perm(5,2);
    printf("Permuatations for 5,2: %d\n", x);
    
    x = combABC(4);
    printf("Comb ABC for 4: %d\n", x);
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
        printf("%s\n", perm_map);
        if (perm_map[0] != 'C') {
            perm_map[0]++;
        }
        else {
            inc_base_n(perm_map, 0);
        }
        /*
        for (int z=0; z < n; ++z) {
            if (perm_map[z] != 'C') {
                perm_map[z]++;
                break;
            }
            else {
                perm_map[z] = 'A';
                break;
            }
        }
        */
        rounds++;
    }
    while (rounds < pow(3,n)); // TODO: Pow 3
    perm_map ? free(perm_map) : free(NULL);
    return score;

}

int pow(int n,int k) {
    int val = n;
    for (int x=0; x < k-1; ++x) {
        n *= val;
    }
    return n;
}

int get_comb_val(unsigned char * p_map, std::vector<int> * v_map, int n) {

    int score = 0;
    // Return value of combination array 
    for (int i=0; i < n; ++i) {
        score += (int) p_map[i];
    }
    
    // Check if value is in value array
    if (std::find(v_map->begin(), v_map->end(), score) != v_map->end()) {
       return 0;
    }
    v_map->push_back(score);
    return 1;
}


void inc_base_n(unsigned char * perm_map, int pos) {
    perm_map[pos] = 'A';
    if (perm_map[pos+1] != 'C') {
        perm_map[pos+1]++;
        return;
    }
    inc_base_n(perm_map, pos+1);
}
    












