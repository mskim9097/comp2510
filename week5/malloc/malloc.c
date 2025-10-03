#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *getTextFromSomewhere()
{
    char *t;
    int stringLength = 20;
    t = malloc(stringLength);
    if ( t == NULL) {
        return NULL;
    }

    strcpy(t, "Hello, World!");
    return t;
}

int main() 
{
    char *txt;

    txt = getTextFromSomewhere();

    if(txt != NULL) {
        printf("The text is %s.\n", txt);
        free(txt);
    } else {
        printf("Memory allocation failed!\n");
    }

    return 0;
}