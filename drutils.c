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
#include <stdbool.h>

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

/* Places a string with the day of week abbreviation associated with the 
 * integer value of the day of week into the char array passed in.
*/ 
void IntToDayStr(int dayInt, char* dayStr) {
    static char* days[] = { "sun", "mon", "tue", "wed", "thu", "fri", "sat" };
    if ((dayInt >= 0) && (dayInt <=6)) {
        strcpy(dayStr, days[dayInt]);
    } else {
        strcpy(dayStr, "???");
    }    
    return;
}

/* Return a int value 1 if year is leap year, else return int value 0
 * A year that is divisible by 4 is a leap year.  However, years divisible by
 * 100 are not leap years while those divisible by 400 are
*/
int IsLeapYear(int year) {
    if (((year %4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
        return 1;
    else
        return 0;
} 

/* If digit character is passed, return an int of that character.
 * Else, return -1
*/
int MakeInt(char digitChar) {
    if ((digitChar >= '0') && (digitChar <= '9')) {
        return (digitChar - '0');
    } else {
        return -1;
    }    
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

// return a sorted array.  uses optimized bubble sort
void SortArray(int arr[], int length) {
    bool swapped;
    int i = 0;

    do {
        swapped = false;
        for (int j = 0; j < (length -1 -i); j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                swapped = true;
            }        
        }    
        i++;
    } while (swapped);    
}    

// swap two integers (pass in using &)
void SwapInt(int* a, int* b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
    return;
}
