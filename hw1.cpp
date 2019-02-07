#include <cstdlib>
#include <cstdio>

typedef unsigned int uint;
uint factorial(uint n);

int main() {
    uint x = factorial(4);
    printf("%d\n", x);
    return 0;

    
}

uint factorial(uint n) {
    uint ret=1;
    for(int i=n; i>0; --i){
       ret *= i;
    }
    return ret;
}
