#include <stdio.h>

int main(void) {
    int x,y;

    /* Print out header */
    printf("Please enter sets of two integers:\n\n"
            "X\tY\tZ\n\n");

    /* As long as there is continued input, */
    while (scanf("%d\t%d", &x, &y) >= 0){

        /* Print out x, y, and their sum */
        printf("%d\t%d\t%d\n\n",x,y,x+y);

        /* If their sum is 0, we can break the loop
         * and terminate the program */
        if (!(x+y))
            break;
    }
    return 0;
}

