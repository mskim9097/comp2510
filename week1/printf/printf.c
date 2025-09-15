/*
printf(format string, val1, val2);
    ► format string can include placeholders that specify how the
    arguments val1, val2, etc. should be formatted
    ► %c : format as a character
    ► %d : format as an integer
    ► %f : format as a floating-point number
    ► %% : print a % character

► Placeholders can also specify widths and precisions
    ► %10d : add spaces to take up at least 10 characters
    ► %010d : add zeros to take up at least 10 characters
    ► %.2f : print only 2 digits after decimal point
    ► %5.2f : print 2 decimal digit, add spaces to take up 5 chars    
*/

#include <stdio.h>

int main() {
    float f = 0.95;
    printf("f = %f%%\n", f * 100);
    printf("f = %.2f%%\n", f * 100);
    // f = 95.00%
    printf("f = %10.2f%%\n", f * 100);
    // f =      95.00%
    
    int d = 10;
    printf("d = %d\n", d);
    printf("d = %10d\n", d);
    // d =           10
    printf("d = %010d\n", d);
    // d = 000000000010

    return 0;
}