#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cassert>

#include <vector>
#include <algorithm>

//typedef unsigned int unsigned;
unsigned factorial(unsigned n);
unsigned comb(unsigned n, unsigned k);
unsigned perm(unsigned n, unsigned k);
unsigned combABC(unsigned n);
int get_comb_val(unsigned char * p_map, std::vector<unsigned char *> * v_map, int n);
int pow(int n,int k);
void inc_base_n(unsigned char * perm_map, int pos);
void dealloc_comb_vec(std::vector<unsigned char *> * v_map);



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
    std::vector<unsigned char *> val_map;

    // Initialize counting
    for (int i=0; i < n; ++i) {
        perm_map[i] = 'A';
    }
    
    do {
        if (get_comb_val(perm_map, &val_map, n)) {
            score++;
            printf("%s\n", perm_map);
        }

        if (perm_map[0] != 'C') {
            perm_map[0]++;
        }
        else {
            inc_base_n(perm_map, 0);
        }
        rounds++;
    }
    while (rounds < pow(3,n)); // TODO: Pow 3
    perm_map ? free(perm_map) : free(NULL);
    dealloc_comb_vec(&val_map);
    return score;

}

int pow(int n,int k) {
    int val = n;
    for (int x=0; x < k-1; ++x) {
        n *= val;
    }
    return n;
}

void dealloc_comb_vec(std::vector<unsigned char *> * v_map) {
    for (int g=0; g < v_map->size(); ++g) {
        free((v_map->at(g)));
    }
}


int get_comb_val(unsigned char * p_map, std::vector<unsigned char *> * v_map, int n) {

    int score = 0;
    
    unsigned char counts[] = {0x1,0x1,0x1,0x1};

    for (int x=0; x < n; ++x) {
        unsigned char val = p_map[x];
        switch (val) {
            case 'A':
                counts[0]++; break;
            case 'B':
                counts[1]++; break;
            case 'C':
                counts[2]++; break;
        }
    }
    unsigned char * comb_str = (unsigned char *) calloc(4, sizeof(unsigned char));
    for (int r=0; r<3; ++r) {
        memcpy(comb_str+r,&counts[r],1);
    }
    if (!strcmp((const char *) comb_str, "")) {
        int deb = 0;
    }
    // Check if value is in value array
    for (int g=0; g < v_map->size(); ++g) {
        if (!strcmp((const char *) comb_str, (const char *) v_map->at(g))) {
            return 0;
        }
    }
    v_map->push_back(comb_str);
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
    












