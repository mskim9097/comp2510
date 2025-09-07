#include <stdio.h>

int main() {

    int n = 10;
    while (1) {
        printf("%d\n", n);
        if (!n) {
            printf("stop.\n\n");
            break;
        }
        --n;
    }

    int i;
    for (i = 0; i < 10; ++i) {
        if (i == 0) {
            continue;
        }
        //skip to the next loop iteration
        // will not print 0
        printf("%d\n", i);
    }

    return 0;
}