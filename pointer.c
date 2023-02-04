/*
 * Purpose:  to display the use of pointers
 * Parameters: none
 * Return value: none
 *
 * Notes:  pointes are useful to pass to functions to have functions change
 * data, and to allocate variables with a varying amount of memory space (for
 * example, structs, arrays, etc.
 *
*/

#include <stdio.h>
#include "drutils.h"

// function prototypes
void SwapInt(int *ptrA, int *ptrB);

int main(int argc, const char * argv[]) {

    int num = 15;
    int *ptrNum = &num;
    printf("num: %d\n", num);
    printf("&num: %p\n", &num);
    printf("ptrNum: %p\n", ptrNum);
    printf("&ptrNum: %p\n", &ptrNum);
    *ptrNum = 20;
    printf("num: %d\n\n", num);

    int a = 100;
    int b = 200;
    printf("a: %d\n", a);
    printf("b: %d\n", b);
    SwapInt(&a, &b);
    printf("a: %d\n", a);
    printf("b: %d\n\n", b);
    
    int c = 0;
    printf("Enter a number for c: ");
    // pass the addresses into the function
    scanf("%d", &c);
    printf("a+b+c = %d\n\n", a+b+c);

    // a string literal cannot be modified, but it can be replaced and it's
    // chars can be accessed
    char *str = "Hello World!";
    printf("str = %s\n", str);  
    printf("first 3 characters = %.3s\n",str);
    printf("first 3 characters in field of 5 = %5.3s\n",str);
    printf("fifth character = %c\n", *(str+4));
    puts(str);
    printf("\n");
    char str2[11];
    printf("Enter a string value\n");
    scanf("%10s", str2);  //  %s disregards white space;  also, use a size
                          //  delimeter here
    puts(str2);


    return 0;
} // main()

