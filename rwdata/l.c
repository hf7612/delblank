#include <stdio.h>

int main(void) {
    char *foo = "AAAAAA";

    printf("printing string foo %s\n", foo);
    foo[0] = 'B';
    printf("printing string foo %s\n", foo);
    
    return 0;
}