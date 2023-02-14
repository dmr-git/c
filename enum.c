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
    enum days {SUNDAY, MONDAY, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY, SATURDAY, END};
    enum suit {spade=4, heart=3, diamond=2, club=1}; 
    
    // iterate over an enum
    for (int i = SUNDAY; i < END; i++) {
            printf("%d\n",i);
    }   

    enum suit card = club;
    printf("%d\n\n",card);

    // iterate over suit
    for (int i=club; i <=spade; i++) {
        printf("%d\n",i);
    }    
    
    return 0;
}
