/*
 * Purpose: demonstrate handling string arrays
 * Parameters:
*/

#include <stdio.h>
#include "drutils.h"
#include <string.h>
#include <stdlib.h>

/* function prototypes */


int main(int argc, const char * argv[]) {
    // copy command line args to param[] array on heap to allow for edits
    char* param[argc-1];
    for (int i = 0; i < argc; i++) {
        param[i] = MakeStringInHeap(argv[i]);
    }

    char memberNames[100][20];
    strcpy(memberNames[0], "Dennis Richter");
    strcpy(memberNames[1], "Karen Richter");

    printf("%s\n", memberNames[0]);            // Dennis Richter
    printf("%c\n", memberNames[0][0]);         // D
    printf("%p\n", &memberNames[0][0]);        // address of array in hex
    printf("%p\n", &memberNames);              // address of array in hex

    unsigned long bigNumber = (unsigned long) memberNames;
    printf("%lu\n", bigNumber);                // address of array in decimal
                                               
    static const char* strings[] = {"Dennis", "Karen", "Will", "Ben", "Claire", 0};
    const char** ptr = strings;


    // if you set the max_size of all strings, the code to iterate is simpler
    // the below allows addition of additional elements in the future
    char myStrings[][20] = {"Dennis", "Karen", "Will", "Ben", "Claire", "Hobo"};
    
    for (int i = 0; i < (sizeof(myStrings)/sizeof(myStrings[0])); i++) {
        printf("%s\n", myStrings[i]);
    }    
    printf("\n");

    // other examples
    char foo[] = "Jack Ourdum";
    printf("%s\n",foo);

    *(foo+5) = 'P';
    printf("%s\n",foo);
    
    char * day[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", 0 };
    
    char **ptr2 = day;

    while (*ptr2 != 0) {
        printf("%s\n", *ptr2);
        ++ptr2;
    }
    printf("\n");

    char day2[7][10] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };
    
    // to use the minimum amount of memory
    char * day3[7];
    day3[0] = (char *) (malloc(7));
    strcpy(day3[0], "Sunday");
    day3[1] = (char *) (malloc(7));
    strcpy(day3[1], "Monday");
    day3[2] = (char *) (malloc(8));
    strcpy(day3[2], "Tuesday");
    day3[3] = (char *) (malloc(10));
    strcpy(day3[3], "Wednesday");
    day3[4] = (char *) (malloc(9));
    strcpy(day3[4], "Thursday");
    day3[5] = (char *) (malloc(7));
    strcpy(day3[5], "Friday");
    day3[6] = (char *) (malloc(9));
    strcpy(day3[6], "Saturday");

    for (int i = 0; i < 7; i++) {
        printf("%s\n", day3[i]);
    }

    // show how to use strtok()
    char str[80] = "This is - www.tutorialspoint.com - website";
    const char s[2] = "-";
    char *token;
    
    /* get the first token */
    token = strtok(str, s);
    
    /* walk through other tokens */
    while( token != NULL ) {
       printf( "%s\n", token );
       token = strtok(NULL, s);
    }
    
    // another method
    char str2[] = "Now is the time for all good men";
    for (char *p = strtok(str2," "); p != NULL; p = strtok(NULL, " "))
    {
      puts(p);
    }

    return 0;
}
