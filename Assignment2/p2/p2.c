#include <stdio.h>

int sumOfDigits(int n)
{
    if (n == 0) return 0;
    return (n % 10) + sumOfDigits(n / 10);
}

int main()
{
    int n;

    while(1)
    {
        printf("Enter a number: ");
        if(scanf("%d", &n) == 1)
        {
            if(n >= 0)
            {
                break;
            }
            else
            {
                printf("A number should be positive number.\n");
            }
        }
        else
        {
            printf("Invalid input.\n");
            while (getchar() != '\n');
        }
    }
    printf("Sum of digits = %d\n", sumOfDigits(n));

    return 0;
}