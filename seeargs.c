/*
 * Purpose: decode and display the command line arguments to stdout
 * Parameters:
 * Return value:
*/

#include <stdio.h>

// function prototypes

int main(int argc, const char * argv[]) {
    int i;
    for (i = 0; i < argc; i++) {
        printf("argv[%d] = '%s'\n", i, argv[i]);
    }    
    return 0;
} // main()
