/*
 * Purpose:  Make a deck of cards.  
*/

#include <stdio.h>
#include "drutils.h"
#include <stdlib.h>
#include <string.h>

typedef struct _card {
    int suit;
    int value;
} card;

typedef struct _deck {
    int num_cards;
    card **cards;
} deck;

card *make_card(int suit, int value)
{
    card *newCard = malloc(sizeof(card));
    newCard->suit = suit;
    newCard->value = value;

    return newCard;
}

deck *make_standard_deck( void )
{
    deck *newDeck = malloc( sizeof(deck) );

    newDeck->num_cards = 52;
    newDeck->cards = malloc( 52 * sizeof(card *) );

    int index = 0;
    for ( int suit = 0; suit < 4; suit++ )
        for ( int value = 1; value <= 13; value++ )
            newDeck->cards[index++] = make_card( suit, value );

    return newDeck;
}

int main( void )
{
    int i;

    deck *stdDeck = make_standard_deck();

    for ( i = 0; i < stdDeck->num_cards; i++ )
        printf( "suit=%d value=%2d\n", stdDeck->cards[i]->suit, stdDeck->cards[i]->value );

    /* free the deck when we're done with it */
    for ( i = 0; i < stdDeck->num_cards; i++ )
        free( stdDeck->cards[i] );
    free( stdDeck->cards );
    free( stdDeck );
}
