/*
 * Purpose:
 * Parameters:
 * Return value:
*/

#include <stdio.h>
#include "drutils.h"

/* function prototypes */


int main(int argc, const char * argv[]) 
    
    // copy command line args to param[] on heap for edits
    char* param[argc-1];
    for (int i = 0; i < argc; i++) {
        param[i] = MakeStringInHeap(argv[i]);
    }

    return 0;
} 
