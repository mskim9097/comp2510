#include <stdio.h>
#define CLASS_SIZE 73

int main() {

    float a[CLASS_SIZE];
    int j = sizeof(a);
    printf("%d\n", j); // 292

    double b[CLASS_SIZE];
    int i = sizeof(b);
    printf("%d\n", i); // 584

    int c[CLASS_SIZE];
    int k = sizeof(c);
    printf("%d\n", k); // 292

    return 0;
}