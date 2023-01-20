/*
 * Purpose: Print a table of farenheit to celsius conversion 
 * Parameters: none
 * Return value: 0
*/

#include <stdio.h> 

// function declarations

int main(int argc, const char * argv[]) {
    float start = -50.0;
    float end = 500.0;
    float step = 25.0;
    float c;                // temp variable to hold fahrenheit

    printf("Farenheit  Celsius\n");
    printf("==================\n");
    for (float f = start; f <= end; f+=step) {
        c = (f - 32.0) * (5.0/9.0);
        printf("%9.1f%9.1f\n", f, c);    
    }    
}    

