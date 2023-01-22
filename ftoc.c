/*
 * Purpose: If no command line arguments given, print a table of farenheit to
 * celsius.  Else, print a conversion for the first command line argument.
 * Parameters: optionally, the temp in farenheit to convert.
 * Return value: 0
*/

#include <stdio.h>
#include <stdlib.h>  // for atof()

#define START -50.0
#define END 200.0
#define STEP 25.0

// function declarations

int main(int argc, const char * argv[]) {
    if (argc > 1) {
        double degF = atof(argv[1]);
        printf("%6.1f farenheit = %6.1f celsius\n", degF,
                ((degF-32.0)*5.0/9.0));
    }    
    else {
        printf("Farenheit  Celsius\n");
        printf("==================\n");

        for (float f = START; f <= END; f+=STEP) {
            printf("%9.1f%9.1f\n", f, ((f-32.0)*5.0/9.0));
        }
    }
    return 0;
} // main()

