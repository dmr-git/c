/*
 * Purpose:
 * Parameters:
*/

#include <stdio.h>
#include "drutils.h"
#include <stdlib.h>
#include <string.h>

int main(void) {
    char foo[] = "Jack Ourdum";
    printf("%s\n",foo);

    *(foo+5) = 'P';
    printf("%s\n",foo);
    
    char * day[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };
    char day2[7][10] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };
    
    int sar = 0;
    int sar2 = 0;

    for (int i = 0; i < 7; i++) {
        printf("%s\n", day[i]);
        sar += strlen(day[i]);
        printf("%s\n", day2[i]);
        sar2 += strlen(day2[i]);
    }    

    printf("%d\n",sar);
    printf("%d\n",sar2);
    
    char * day3[7];
    day3[0] = (char *) (malloc(7));
    strcpy(day3[0], "Sunday");
    day3[1] = (char *) (malloc(7));
    strcpy(day3[1], "Monday");
    day3[2] = (char *) (malloc(8));
    strcpy(day3[2], "Tuesday");

    for (int i = 0; i < 3; i++) {
        printf("%s\n", day3[i]);
    }

    return 0;
}
