#include <cstdlib>
#include <cstdio>
#include <vector>


//typedef unsigned int unsigned;
unsigned factorial(unsigned n);
unsigned comb(unsigned n, unsigned k);




int main() {

    unsigned x = factorial(4);
    printf("%d\n", x);
    x = comb(5,2);
    printf("%d\n", x);
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
    // For loop, start at n, traverse to 0 at interval k, decrement n, traverse to 0 add to total
    //
    int score = 0;
    for ( ; n > 0; --n) {
        for (int x=n-1; x > 0; x-=(k-1)) {
            score++;
        }
    }
    return score;
}


