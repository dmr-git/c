/*
  Purpose: sum numbers and display the result to stdout
  Parameters: if one parameter is givem we sum from 1 to that number
              if two arguments on the command line, we sum from the first to the second
              if no arguments are give, we sum from 1 to 10
  Return value: 0 to signify success
*/

#include <stdio.h>
#include <stdlib.h>   // for atoi()

// function declarations

int main (int argc, const char * argv[]) {
    long sum = 0;
    int bottom = 1;
    int top = 10;

    switch (argc) {
        case 2:
              top = atoi(argv[1]);
              break;
        case 3:
              bottom = atoi(argv[1]);
              top = atoi(argv[2]);
              if (top <= bottom) {
                  printf("Second argument must be greater than the first argument.\n");
                  return 1;
              }    
    }
    
    for (int number = bottom; number <= top; number++) {
          sum += number;
    }
    printf("The sum of the numbers from %d to %d is %ld.\n", bottom, top, sum);
    return 0;
}        
