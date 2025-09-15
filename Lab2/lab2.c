#include <stdio.h>

void numberAnalysis(int n) {
    printf("Multiplication table of %d:\n", n);
    for(int i = 1; i <= 10; ++i) {
        printf("%d * %d = %d\n", n, i, n * i);
    }

    if(n < 0) {
        printf("\nSum not applicable for negative numbers.\n");
    } else {
        int sum = 0;
        int i = 1;
        while (i <= n) {
            sum += i;
            ++i;
        }
        printf("\nSum from %d to %d = %d\n", 1, n, sum);
    }

    int code;
    if (n < 0) {
        code = -1;
    } else if (n == 0) {
        code = 0;
    } else {
        code = 1;
    }

    switch (code)
    {
        case -1:
            printf("\nThe number is Negative.\n");
            break;
        case 0:
            printf("\nThe number is Zero.\n");
            break;
        default:
            printf("\nThe number is Positive.\n");
    }
}

int main() {
    
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    numberAnalysis(n);

    return 0;
}