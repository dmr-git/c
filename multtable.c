/*
 * Purpose: display simple multiplication table
 * Parameters: none
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
    int multTable[10][10];

    // load up the array
    for (int row = 0; row < 10; row++) {
        for (int column = 0; column < 10; column++) {
            multTable[row][column] = row * column;
        }
    }

    // print the array, with highlights
    for (int row = 1; row < 10; row++) {
        for (int column = 1; column < 10; column++) {
            if ((column == 1) || (row == 1)) {
                printf(BRIGHTWHITE "%2d" OFF, multTable[row][column]);
                if (column < 9)
                    printf("\t");
            }
            else {
                printf("%2d", multTable[row][column]);
                if (column < 9)
                    printf("\t");
            }
            if ((column % 9) == 0)
                printf("\n");
        }
    }

    return 0;
}
