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
void MakeLower(char * Str);

int main(int argc, const char * argv[]) {

    enum colors {BLACK, BROWN, RED, ORANGE, YELLOW, GREEN, BLUE,
        PURPLE, GRAY, WHITE, GOLD = -1, SILVER = -2};

    // copy command line args to param[] on heap for edits
    char* param[argc-1];
    for (int i = 0; i < argc; i++) {
        param[i] = MakeStringInHeap(argv[i]);
        MakeUpper(param[i]);
        printf("%s\n", param[i]);
    }

    return 0;
}
