// Basic Hello World program.

#include <stdio.h>
#include <string.h>

int main() {
    char name[20];
    printf("First name: ");
    scanf("%19s", name);  // use the width specifier to specify the maximum
                          // size of string to read (one less thant the length
                          // of the char aerray)
    printf("Hello, %s\n", name);
    printf("Your name has %zu character%s.\n", strlen(name),
                      (strlen(name)>1 ? "s" : ""));
    return 0;
} // main()
