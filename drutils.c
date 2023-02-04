/*
 * Purpose: useful utility functions which can be called from other programs
*/

#include <ctype.h>    // toLower()
#include <pwd.h>      // getpwuid()
#include <stdio.h>
#include <stdlib.h>   // malloc()
#include <string.h>
#include <time.h>     // clock()
#include <unistd.h>   // getuid(), chdir()

#include "drutils.h"

// ring the BEL
void Bel(void) {
    putchar('\x07');  // \a should also work
    return;
}

// convert a temperature in Celcius to Fahrenheit
float CelsiusToFahrenheit(float tempC) {
    return ((tempC*9.0/5.0) + 32.0);
}

// add an approximate delay to the program.
void Delay(int numSeconds)
{
    // Storing start time
    clock_t startTime = clock();

    // looping till required time is not achieved
    while (clock() < startTime + (numSeconds * CLOCKS_PER_SEC)) {
        ;
    }
    return;
}

// print a string within a flower box of '*'
void FlowerBox(const char* str) {
    for (int i=0; i < (strlen(str) + 4); i++) {
        putchar('*');
    }
    printf("\n* %s *\n", str);
    for (int i=0; i < (strlen(str) + 4); i++) {
        putchar('*');
    }
    putchar('\n');
    return;
}

// convert a temperature in farenheit to Celcius
float FahrenheitToCelsius(float tempF) {
    return ((tempF-32.0)*5.0/9.0);
}

// converts a string to lowercase
void MakeLower(char * str) {
    do {
        *str = tolower(*str);
    } while (*++str);

}

// converts a string to uppercase
void MakeUpper(char * str) {
    do {
        *str = toupper(*str);
    } while (*++str);

}
/*
 * Takes a C string as input and makea a copy of that string in the heap.
 * The caller takes over ownership of the new string and is responsible
 * for freeing it.
*/
char* MakeStringInHeap(const char* source) {
    char* newString;

    newString = (char*) malloc(strlen(source)+1); // for '\0'
    strcpy(newString, source);
    return(newString);
}
// set the working directory to the string passed in under the user's current
// home directory.
void SetWD(const char* path) {
    struct passwd *pw;
    pw = getpwuid(getuid());

    char newDir[100];
    strcpy(newDir, pw->pw_dir);

    //  append a leading slash if the user forgot to add
    if (path[0] != '/')
        strcat(newDir, "/");

    strcat(newDir, path);
    chdir(newDir);
    return;
}

// set the working directory to the current users home directory
void SetWDHome(void) {
    struct passwd *pw;
    pw = getpwuid(getuid());
    chdir(pw->pw_dir);
    return;
}

// swap two integers (pass in using &)
void SwapInt(int* a, int* b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
    return;
}