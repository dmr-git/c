/*
 * Purpose: print out the size of all C data types to screen
 * Parameters: none
 * Return value: 0
*/

#include <stdio.h>
#include <stdint.h>  // for definitions of additional data types
#include <stdbool.h> // for bool
#include <limits.h>
#include <float.h>
#include "drutils.h"

// function prototypes
void PrintSizes(void);
void PrintRanges(void);

int main(int argc, const char * argv[]) {
    PrintSizes();
    PrintRanges();
    return 0;
} // main()


/*
 * Purpose: prints the number of bytes for each of C11's data types
 * note - sizeof() is returning an unsigned long.  It is an operator and can
 * work with a type or a variable passed to it in the ()
 * Parameters: none
 * Return value: 0
*/
void PrintSizes(void) {
    printf("Size of C data types\n\n");
    printf("Type                Bytes\n");
    printf("==================  =====\n");
    printf(RED "char                %5lu\n" OFF, sizeof(char));
    printf("int8_t              %5lu\n", sizeof(int8_t));
    printf("unsigned char       %5lu\n", sizeof(unsigned char));
    printf("uint8_t             %5lu\n", sizeof(uint8_t));
    printf(RED "short               %5lu\n" OFF, sizeof(short));
    printf("int16_t             %5lu\n", sizeof(int16_t));
    printf("uint16_t            %5lu\n", sizeof(uint16_t));
    printf(RED "int                 %5lu\n" OFF, sizeof(int));
    printf("unsigned            %5lu\n", sizeof(unsigned));
    printf(RED "long                %5lu\n" OFF, sizeof(long));
    printf("unsigned long       %5lu\n", sizeof(unsigned long));
    printf("int32_t             %5lu\n", sizeof(int32_t));
    printf("uint32_t            %5lu\n", sizeof(uint32_t));
    printf("long long           %5lu\n", sizeof(long long));
    printf("int64_t             %5lu\n", sizeof(int64_t));
    printf("unsigned long long  %5lu\n", sizeof(unsigned long long));
    printf("uint64_t            %5lu\n", sizeof(uint64_t));
    printf("size_t              %5lu\n", sizeof(size_t));
    printf("intmax_t            %5lu\n", sizeof(intmax_t));
    printf("\n");
    printf(RED "float               %5lu\n" OFF, sizeof(float));
    printf(RED "double              %5lu\n" OFF, sizeof(double));
    printf(RED "long double         %5lu\n" OFF,
                                           sizeof(long double));
    printf("\n");
    printf(RED "pointer             %5lu\n", sizeof(void*));
    
    printf("\n");
    printf(RED "bool                %5lu\n" OFF, sizeof(bool));
    printf("_Bool               %5lu\n", sizeof(_Bool));
    printf("\n");
    return;
}

/*
 * Purpose: prints the ranges for each of C11's data types
 * Parameters: none
 * Return value: 0
*/
void PrintRanges() {
    printf("Ranges for integer data types in C\n\n");
    printf("int8_t   %20d %20d\n", SCHAR_MIN, SCHAR_MAX);
    printf("int16_t  %20d %20d\n", SHRT_MIN, SHRT_MAX);
    printf("int32_t  %20d %20d\n", INT_MIN, INT_MAX);
    printf("int64_t  %20lld %20lld\n", LLONG_MIN, LLONG_MAX);
    printf("uint8_t  %20d %20d\n", 0, UCHAR_MAX);
    printf("uint16_t %20d %20d\n", 0, USHRT_MAX);
    printf("uint32_t %20d %20u\n", 0, UINT_MAX);
    printf("uint64_t %20d %20llu\n", 0, ULLONG_MAX);
    printf("\n");
    printf("Ranges for real number data types in C\n\n");
    printf("float       %14.7g %14.7g\n", FLT_MIN, FLT_MAX);
    printf("double      %14.7g %14.7g\n", DBL_MIN, DBL_MAX);
    printf("long double %14.7Lg %14.7Lg\n", LDBL_MIN, LDBL_MAX);
    printf("\n");
}
