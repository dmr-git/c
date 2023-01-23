/*
 * Purpose: Prints the printable ASCII characters to stdout
 * Parameters: none
 * Return value: 0
*/

#include <stdio.h>

// function prototypes
void PrintChars(char low, char high);

int main(int argc, const char * argv[]) {
    PrintChars(32, 47);    
    PrintChars(48, 57);    
    PrintChars(58, 64);    
    PrintChars(65, 90);    
    PrintChars(91, 96);    
    PrintChars(97, 122);    
    PrintChars(123, 126);    
    return 0;
} // main()


/*
 * Purpose: Prints a string of characters
 * Parameters: none
 * Return value: 0
*/
void PrintChars(char low, char high) {
    printf("%d to %d ---> ", low, high);
    for (int i = low; i <= high; i++) {
        printf("%c", i);
    }
    putchar('\n');  // output a single character to stdout
}    

