#include <stdio.h>
int main()
{
    char str[100];
    fputs("Input something\n", stdout);
    fgets(str, 100, stdin);
    fputs(str, stdout);
    return 0;
}