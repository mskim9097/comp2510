#include <stdio.h>
#include <string.h>

int main() {

    char s1[] = "This is an initialized string!";
    char *u = "for concat test";

    printf("\ns1[0] = %s", s1[0]); // "T"
    printf("Length: %d", strlen(s1));

    return 0;
}