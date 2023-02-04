/*
 * Purpose:  demonstrate how to manipulate files in C
*/

#include "drutils.h"     // SetWDHome()

#include <stdio.h>
#include <stdlib.h>      // exit()
#include <unistd.h>      // chdir()

// function prototypes

int main(int argc, const char * argv[]) {
    FILE* fptr;
    FILE* fptr2;

    /* SetWD("code/data"); */

    SetWDHome();
    chdir("./code/data");

    if ((fptr = fopen("temp.txt", "r")) == NULL) {
            printf("Can not open file\n");
            exit(1);
    }  

    printf("File contents:\n");
    int c;
    while ((c = fgetc(fptr)) != EOF) {
        putchar(c);
    }
    fclose(fptr);

    //  now open the file for reading, but write to a second file
    if ((fptr = fopen("temp.txt", "r")) == NULL) {
            printf("Can not open file\n");
            exit(1);
    }        
    if ((fptr2 = fopen("temp2.txt", "w")) == NULL) {
            printf("Can not open file\n");
            exit(1);
    }
    while ((c = fgetc(fptr)) != EOF) {
        fputc(c, fptr2);
    }    
    fclose(fptr);
    fclose(fptr2);

    return 0;
} // main()
