/*
 * Purpose:
 * Parameters:
*/

#include <stdio.h>
#include "drutils.h"
#define CARDSINDECK 52
#define SUITS 4
#define RANKS 13

/* function prototypes */


int main(int argc, const char * argv[]) {
    // copy command line args to param[] array on heap to allow for edits
    char* param[argc-1];
    for (int i = 0; i < argc; i++) {
        param[i] = MakeStringInHeap(argv[i]);
    }

    enum suits {clubs, diamonds, hearts, spades};
    const char * SUIT[] = {"CLUBS", "DIAMONDS", "HEARTS", "SPADES"};

    struct card {
        int rank;
        enum suits suit;
    };

    // instantiate a deck of cards
    struct card mycards[CARDSINDECK];
    for (int i = 0; i < SUITS; i++) {
        for (int j = 0; j < RANKS; j++) {
            mycards[i].suit = i;
            mycards[i].rank = j+1;
            printf("%d of %s\n", mycards[i].rank, SUIT[mycards[i].suit]);
        }    
    }    


    return 0;
}
