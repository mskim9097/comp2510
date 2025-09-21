#include <stdio.h>

int main()
{
    int x;
    printf("Enter a value...");
    scanf("%d", &x);
    printf("\nYou entered: %d", x);

    char s[20];
    printf("\n\nHow are you doing? ...");
    scanf("%s", s);
    printf("\nYou enterd: %s", s);

    return 0;
}