/*
 * Purpose:
 * Parameters:
 * Return value:
*/

#include <stdio.h>
#include <ctype.h>   // tolower()
#include <string.h>
#include "drutils.h"

#define MAXBANDS 4

// function prototypes

int main(int argc, const char * argv[]) {

    enum colors {black, brown, red, orange, yellow, green, blue,
        purple, gray, white, gold = -1, silver = -2};

    // copy command line args to param[] on heap and make lower case
    char* param[argc-1];
    for (int i = 0; i < argc; i++) {
        param[i] = MakeStringInHeap(argv[i]);
        MakeLower(param[i]);
    }

    if (argc < 4) {
        printf("Usage: resistor band1 band2 band3 band4\n");
    }    

    return 0;
}
