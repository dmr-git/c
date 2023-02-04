
#include <stdio.h>
#include <stdlib.h>  // for malloc()
#include <string.h>  // for strcpy()

/* #include "drutils.h" */

#define MAXNAMELENGTH 30

// test struct
struct app {
    char appName[MAXNAMELENGTH+1];
    long citrixUsers;
    int physicalServers;
    struct app *next;
};


// function prototypes

int main(int argc, const char * argv[]) {
    struct app MarshApps[10];
    // print info on the structure created
    printf("sizeof(MarshApps[0].appName) = %zu\n",sizeof(MarshApps[0].appName));
    printf("sizeof(MarshApps[0].citrixUsers) = %zu\n",sizeof(MarshApps[0].citrixUsers));
    printf("sizeof(MarshApps[0].physicalServers) = %zu\n",sizeof(MarshApps[0].physicalServers));
    printf("sizeof(MarshApps) = %zu\n",sizeof(MarshApps));
    printf("&MarshApps = %p\n", &MarshApps);        
    
    // assign values
    strcpy(MarshApps[0].appName, "mdocs");

    /* MarshApps[0].appName[0] = 'm'; */
    /* MarshApps[0].appName[1] = 'd'; */
    /* MarshApps[0].appName[2] = 'o'; */
    /* MarshApps[0].appName[3] = 'c'; */
    /* MarshApps[0].appName[4] = 's'; */
    /* MarshApps[0].appName[5] = '\0'; */

    MarshApps[0].citrixUsers = 3;
    MarshApps[0].physicalServers = 4;
    
    // print values
    printf("%s\t%ld\t%d\n", MarshApps[0].appName, MarshApps[0].citrixUsers, MarshApps[0].physicalServers);

    // alternative definition
    struct app *ptrApps;
    ptrApps = malloc(sizeof(struct app));

    printf("sizeof(*ptrApps) = %zu\n", sizeof(*ptrApps));
    printf("ptrApps = %p\n", ptrApps);        

    strlcpy(ptrApps->appName, "mmdfdfsdfmm", sizeof(ptrApps->appName));
    ptrApps->citrixUsers = 5;
    ptrApps->physicalServers = 10;
    ptrApps->next = NULL;

    // print values
    printf("%s\t%ld\t%d\t%p\n", ptrApps->appName, ptrApps->citrixUsers, ptrApps->physicalServers, ptrApps->next);
   
    // add a second record
    ptrApps->next = malloc(sizeof(struct app));
    ptrApps->next->next = NULL;

    // print values
    printf("%s\t%ld\t%d\t%p\n", ptrApps->appName, ptrApps->citrixUsers, ptrApps->physicalServers, ptrApps->next);

    
    printf("sizeof(*ptrApps) = %zu\n", sizeof(*ptrApps));
    printf("ptrApps = %p\n", ptrApps);        


    free(ptrApps);  // return the memory
    
    return 0;
} //
  //main()
