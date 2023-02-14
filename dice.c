/*
 * Purpose: Rolls a user defined number of dice and prints result to stdout
 * Parameters: Command line: number of dice to throw
*/

#include <stdio.h>
#include "drutils.h"
#include <stdlib.h>
#include <time.h>

/* function prototypes */

int main(int argc, const char * argv[]) {
    
    // copy command line args to param[] on heap for edits
    char* param[argc-1];
    for (int i = 0; i < argc; i++) {
        param[i] = MakeStringInHeap(argv[i]);
    }

    int numDice;
    numDice = ((argc == 1) ? 1 : atoi(param[1]));

    if (numDice == 0) {
        printf("Usage: dice <integer>\n");
        return 1;
    }
    
    int dice[numDice];

    /* initialize random number generator */
    srand( clock() );

    /* roll the dice  and print the results */
    for (int i = 0; i < numDice; i++) {
        dice[i] = (rand() % 6) + 1;
        printf("%d\n",dice[i]);
    }
     
    return 0;
} 
