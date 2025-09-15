#include <stdio.h>

int main() {
    int z[] = {6, 5, 8, 10, 67, 43, 200};

    printf("%d\n", z[5]); // 43

    int x[7] = {0, 1, 5, 2, 3, 8 ,6};
    int y = x[2] * x[4];
    printf("%d\n", y);
    
    int i[] = {9, 4, 1, 8, 34, 6, 8, 56, 87};
    int j = 42;
    int k = j - (i[2] * i[4]);
    printf("%d", k);
    return 0;
}