/*
 * Purpose:  On a 2x16 LCD display, we want the second line to be able to
 * scroll long messages from right to left.
*/

#include <stdio.h>
#include "drutils.h"
#include <string.h>
#include <stdlib.h>

#define LCDWIDTH 16

/* function prototypes */


int main(int argc, const char * argv[]) {
    // copy command line args to param[] array on heap to allow for edits
    char* param[argc-1];
    for (int i = 0; i < argc; i++) {
        param[i] = MakeStringInHeap(argv[i]);
    }
    
    char msg[] = "Now is the time for all good men to come to the aid of their country.";
    // make new string wider than the input string and pad with spaces for 
    // size of the LCD display
    char * buffer;
    buffer = (char *) malloc((strlen(msg) + LCDWIDTH) * sizeof(char));
    strcpy(buffer, msg);

    for (int i = 0; i < LCDWIDTH; i ++) {
        *(buffer + strlen(msg) + i) = ' ';
    }    
    *(buffer + strlen(msg) + LCDWIDTH) = '\0';        

    //  get the substrings
    char dsptxt[LCDWIDTH+1];

    for (int i = 0; i <= strlen(msg); i++) {
        strncpy(dsptxt, (buffer+i), LCDWIDTH);
       // printf("%s",dsptxt);
       puts(dsptxt);
        Delay(1);
    }    
    free(buffer);
    buffer = NULL;

    return 0;
}
