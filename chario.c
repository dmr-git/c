/*
 * Purpose: read from stdin - write to stdout - one char at a time
 * Parameters: none
 * Return value: 0
*/

#include <stdio.h>

// function prototypes

int main(int argc, const char * argv[]) {
    int c;
    int nSpaces = 0;
    int nTabs = 0;
    int nNewLines = 0;

    while ( (c = getchar()) != EOF) {  // <ctrl-d> to exit
        if (c == ' ') nSpaces++;
        if (c == '\t') nTabs++;
        if (c == '\n') nNewLines++;
    }
    printf("%5d %5d %5d\n", nSpaces, nTabs, nNewLines);
    return 0;
} // main()
