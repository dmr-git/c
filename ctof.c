/*
 * Purpose: Print a table of celsius to farenheit conversion 
 * Parameters: none
 * Return value: 0
*/

#include <stdio.h> 

// function declarations

int main(int argc, const char * argv[]) {
    float start = -40.0;
    float end = 260.0;
    float step = 10.0;
    float f;                // temp variable to hold fahrenheit

    printf("Celcius  Farenheit\n");
    printf("==================\n");
    for (float c = start; c <= end; c+=step) {
        f = (c * (9.0/5.0) + 32.0);
        printf("%7.1f%11.1f\n", c, f);    
    }    
}    

