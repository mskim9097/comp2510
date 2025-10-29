#include <stdio.h>

#define MIN_VALUE -128
#define MAX_VALUE 127
#define MASK 0x0A

int areSecondAndFourthBitsOn(int n)
{
    return ((n & MASK) == MASK) ? 1 : 0;
}

void printBinary8(int n)
{
    printf("Binary: ");
    for (int i = 7; i >= 0; --i)
    {
        putchar((n >> i) & 1 ? '1' : '0');
    }
    putchar('\n');
}

int main()
{
    int n;

    while(1)
    {
        printf("Enter an integer: ");
        if(scanf("%d", &n) == 1)
        {
            if(n >= MIN_VALUE && n <= MAX_VALUE)
            {
                break;
            }
            else
            {
                printf("A value should be between %d and %d\n", MIN_VALUE, MAX_VALUE);
            }
        }
        else
        {
            printf("Invalid input.\n");
            while (getchar() != '\n');
        }
    }
    printBinary8(n);
    
    if(areSecondAndFourthBitsOn(n))
    {
        printf("Second and fourth bits are ON.\n");
    }
    else
    {
        printf("Second and fourth bits are NOT both ON.\n");
    }

    return 0;
}