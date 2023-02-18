/*
 * Purpose: read a line from the console and count the number of words
 * Parameters: none
 * Return value: 0
*/

#include <stdio.h>
#include <ctype.h>     //This is to bring in the declaration of isspace()
#include <stdbool.h>   //This is to bring in the define of true

#define MAXLINELENGTH 200

// function prototypes
void ReadLine(char *line);
int  CountWords(char *line);

int main (int argc, const char * argv[])
{
    char line[MAXLINELENGTH+1];  // room for MAXLINELENGTH chars + one NUL
    int	 numWords;
    
    printf("Type a line of text:\n");
    
    ReadLine(line);
    numWords = CountWords(line);
    
    printf( "\n---- This line has %d word%s. ---\n", numWords, ( numWords!=1 ? "s" : "" ) );
    printf( "%s\n", line );
    
    return 0;
}

void ReadLine( char *line )
{
    int numCharsRead = 0;
    int c;       //getchar() returns an int
    
    while ( (c = getchar()) != EOF
           && c != '\n'
           && ++numCharsRead <= MAXLINELENGTH ) {
        *line++ = c;
    }
    *line = '\0';
}

int	CountWords( char *line )
{
    int numWords;
    bool inWord;
    
    numWords = 0;
    inWord = false;
    
    while ( *line != '\0' ) {
        if ( isspace( *line ) ) {
            inWord = false;
        }
        else {
            if ( ! inWord ) {
                numWords++;
                inWord = true;
            }
        }
        line++;
    }
    
    return numWords;
}

