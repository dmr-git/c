/*
 * Purpose: simulate rolling a pair of dice and print the results to the screen
 * Parameters: none
 * Return value: 0
*/

#include <stdio.h>
#include <time.h>    // for clock()
#include <stdlib.h>  // for srand() and rand()A

#define NUMROLLS 4000
#define DICEARRAYSIZE 13

// function prototypes
int RollOne( void );
void PrintRolls( int rolls[] );
void PrintX( int howMany );
void test( void);

int main (int argc, const char * argv[])
{
    int rolls[ DICEARRAYSIZE ], twoDice, i;  // rolls[2] stores number of 2's
                                             // rolls[0] and rolls[1] go unused
    
    srand( clock() );                        // seed random()
    
    for  ( i = 0; i < DICEARRAYSIZE; i++ )
        rolls[ i ] = 0;
    
    for ( i = 1; i <= NUMROLLS; i++ ) {
        twoDice = RollOne() + RollOne();
        ++ rolls[ twoDice ];
    }
    
    PrintRolls( rolls );
    
    return 0;
}


int    RollOne( void )
{
    return ( rand() % 6 ) + 1;  // rand() returns number between 0 and mavvalue
                                // of int
}


void PrintRolls( int rolls[] )
{
    int i;
    
    for ( i = 2; i <= 12; i++ ) {
        printf( "%2d (%3d):  ", i, rolls[ i ] );
        PrintX( rolls[ i ] / 10 );
        putchar( '\n' );
    }
}


void PrintX( int howMany )
{
    int    i;
    
    for ( i = 1; i <= howMany; i++ )
        putchar( 'x' );
}
