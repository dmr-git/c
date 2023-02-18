/*
 * Purpose:
 * Parameters:
*/

#include <stdio.h>
#include "drutils.h"
#include <sqlite3.h>

/* function prototypes */

int main(int argc, const char * argv[]) {
    // copy command line args to param[] array on heap to allow for edits
    char* param[argc-1];
    for (int i = 0; i < argc; i++) {
        param[i] = MakeStringInHeap(argv[i]);
    }

    sqlite3 *db;
    char *zErrMsg = 0;
    int rc;

    rc = sqlite3_open("test.db", &db);

    if( rc ) {
       fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
       return(0);
    } else {
       fprintf(stderr, "Opened database successfully\n");
    }
    sqlite3_close(db);

    return 0;
}
