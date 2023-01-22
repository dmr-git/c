/*
 * Purpose: If no command line arguments are given, print a table of celsius
 * to farenheit. Else, print the conversion for the temperature given.
 * Parameters: none
 * Return value: 0
*/

#include <stdio.h>
#include <stdlib.h>  // for atof()

#define START -40.0
#define END 260.0
#define STEP 10.0

// function declarations

int main(int argc, const char * argv[]) {
    if (argc > 1) {
        double tempC = atof(argv[1]);
        printf("%6.1f celsius = %6.1f farenheit\n", tempC,
                (tempC*9.0/5.0)+32.0);
    }
    else {
        printf("Celcius  Farenheit\n");
        printf("==================\n");
        for (float c = START; c <= END; c+=STEP) {
            printf("%7.1f%11.1f\n", c, (c*(9.0/5.0)+32.0));
        }
    }    
    return 0;
} // main()
