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