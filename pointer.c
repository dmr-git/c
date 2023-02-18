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
#include <string.h>
#include <stdlib.h>  // for malloc()

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
    scanf("%d", &c);   // note passing in address
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

    char string[256];
    printf("Enter a string:\n");
    fgetc(stdin);
    fgets(string, 265, stdin);
    string[strlen(string)-1] = '\0';
    printf("Length of string = %lu\n", strlen(string));
    printf("%s\n", string);


    //  ask for number of ints, create an array of that size
    //  without using pointers. Note we ask at run time for the size
    //  of the array to build.
    int numInts;
    printf("\nHow many integers in your array?\n");
    scanf("%d", &numInts);

    int foo[numInts];

    // ask for the values
    for (int i = 0; i < numInts; i++) {
        printf("Enter integer %d : ", i+1);
        scanf("%d", &foo[i]);
        printf("\n");
    }    
    // print the results to verify
    printf("Numbers are:\n");
    for (int i=0; i < numInts; i++) {
        printf("%p\t", &foo[i]);
        printf("%d\n", foo[i]);
    }    
    
    // declare a generic pointer to an int via malloc
    int *ptr2;
    ptr2 = (int*)malloc(sizeof(int));
    ptr2 = NULL;

    free(ptr2);

    // declare and initialize in one step (array of 4 ints);
    int *my_ptr = (int*)malloc(4 * sizeof(int));
    my_ptr[0] = 4;
    my_ptr[1] = 5;
    my_ptr[2] = 7;
    my_ptr[3] = 1;



    return 0;
} // main()

