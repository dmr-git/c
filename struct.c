/*
 * Purpose:
 * Parameters:
*/

#include <stdio.h>
#include "drutils.h"

/* function prototypes */


int main(int argc, const char * argv[]) {
    // copy command line args to param[] array on heap to allow for edits
    char* param[argc-1];
    for (int i = 0; i < argc; i++) {
        param[i] = MakeStringInHeap(argv[i]);
    }


    return 0;
}
