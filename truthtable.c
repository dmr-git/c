/*
 * Purpose: print a truth table to stdout
 * Parameters: none
 * Return value: none
*/

#include <stdio.h>
#include <stdbool.h>

/* #include "drutils.h" */

// function prototypes

int main(int argc, const char * argv[]) {

    printf("%4s %4s %4s %4s %4s %4s %4s %4s\n",
             "i", "j", "AND", "NAND", "OR", "NOR", "XOR",  "NXOR");

    for (int i=0; i<2; i++) {
        for (int j=0; j<2; j++) {
            printf("%4d %4d %4d %4d %4d %4d %4d %4d",
                    i, j, i&&j, !(i&&j), i||j, !(i||j), i^j, !(i^j));
            putchar('\n');
        }    
    }    

    return 0;
} // main()
