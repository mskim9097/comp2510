#include <stdio.h>

int main () {

    int x = 0;
    {
        int x = 5;
        printf("Inside: x = %d\n", x);
    }
    printf("Outside: x = %d\n", x);

    // Inside: x = 5
    // Outside: x = 0
    // Inside this block, the inner x= 5 is used,
    // not the outer x = 0

    printf("\n");

    // if Statement
    // if(<condition>) <statement>
    // single statement
    if (2 < 5)
        printf("2 is less than 5. \n");

    // block
    if (2 < 5) {
        printf("I'll always aprint this line. \n");
        printf("because 2 is always less than 5!\n");
    }

    // if-else Statement
    // if (<condition>) <statement1> else <statement2>

    int y = 0;
    if (y < 0) {
        printf("%d is negative.\n", y);
    } else {
        printf("%d is non-negative.\n", y);
    }

    printf("\n");

    // if-else Statement Pitfalls
    // 다시체크
    int a = 71;
    if (a > 70) {
        if (a > 80) {
            printf("grade = B\n");
        }
    } else {
        printf("grade < B\n");
        printf("Fail.\n");
    }
    printf("Done.\n");

    return 0;
}